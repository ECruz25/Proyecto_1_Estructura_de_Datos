#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->regalar_btn->hide();
    ui->regalar_edit->hide();
    ui->select_btn->hide();
    ui->select_btn->hide();
    ui->progressBar_actividad_desechos->hide();
    ui->progressBar_actividad_hambre->hide();
    ui->progressBar_actividad_salud->hide();
    ui->progressBar_actividad_sueno->hide();
    ui->progressBar_salud->hide();
    ui->ir_al_bano_btn->hide();
    ui->comer_btn->hide();
    ui->curar_btn->hide();
    ui->dormir_btn->hide();
    ui->label->hide();
    ui->limpiar_desechos->hide();
    ui->limpiar_enfermedad->hide();
    ui->limpiar_hambre->hide();
    ui->limpiar_sueno->hide();

    create_window.show();

    pila_desechos = new Pila;
    pila_enfermedades = new Pila;
    pila_hambre = new Pila;
    pila_sueno = new Pila;

    estados = new Cola;

    ganar = "Acaba de recibir una victoria";
    perder = "Acabas de tener una derrota";

    mTimer = new QTimer(this);
    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(refrescar_barras()));

    danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
    safe = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refrescar_barras()
{
    if(ui->progressBar_salud->value()<60)
    {
        ui->progressBar_salud->setStyleSheet(danger);
    }
    else
    {
        ui->progressBar_salud->setStyleSheet(safe);
    }
    if(ui->progressBar_actividad_desechos->value()>40)
    {
        ui->progressBar_actividad_desechos->setStyleSheet(danger);
    }
    else
    {
        ui->progressBar_actividad_desechos->setStyleSheet(safe);
    }
    if(ui->progressBar_actividad_hambre->value()>40)
    {
        ui->progressBar_actividad_hambre->setStyleSheet(danger);
    }
    else
    {
        ui->progressBar_actividad_hambre->setStyleSheet(safe);
    }
    if(ui->progressBar_actividad_salud->value()>40)
    {
        ui->progressBar_actividad_salud->setStyleSheet(danger);
    }
    else
    {
        ui->progressBar_actividad_salud->setStyleSheet(safe);
    }
    if(ui->progressBar_actividad_sueno->value()>40)
    {
        ui->progressBar_actividad_sueno->setStyleSheet(danger);
    }
    else
    {
        ui->progressBar_actividad_sueno->setStyleSheet(safe);
    }
}

void MainWindow::on_curar_btn_clicked()
{ 
    if(create_window.granja->getPos(buscar(get_nombre()))->enfermedad > 0 &&
            create_window.granja->getPos(buscar(get_nombre()))->enfermedad <= 100)
    {
        if(pila_enfermedades->getTope())
        {
            std::cout<<pila_enfermedades->getTope()->valor<<std::endl;
            pila_enfermedades->sacar();
            if(pila_enfermedades->getTope())
            {
                create_window.granja->getPos(buscar(get_nombre()))->enfermedad = pila_enfermedades->getTope()->valor;
            }
            else
            {
                create_window.granja->getPos(buscar(get_nombre()))->enfermedad = 0;
            }
        }
        else
        {
            std::cout<<"No entro"<<std::endl;
        }
    }
    actualizar_valores(get_nombre());
    disable_buttons();
}

void MainWindow::on_ir_al_bano_btn_clicked()
{
    if(create_window.granja->getPos(buscar(get_nombre()))->desechos > 0 &&
            create_window.granja->getPos(buscar(get_nombre()))->desechos <= 100)
    {
        if(pila_desechos->getTope())
        {
            std::cout<<pila_desechos->getTope()->valor<<std::endl;
            pila_desechos->sacar();
            if(pila_desechos->getTope())
            {
                create_window.granja->getPos(buscar(get_nombre()))->desechos = pila_desechos->getTope()->valor;
            }
            else
            {
                create_window.granja->getPos(buscar(get_nombre()))->desechos = 0;
            }
        }
        else
        {
            std::cout<<"No entro"<<std::endl;
        }
    }
    actualizar_valores(get_nombre());
    disable_buttons();
}

void MainWindow::on_comer_btn_clicked()
{
    if(create_window.granja->getPos(buscar(get_nombre()))->hambre > 0 &&
            create_window.granja->getPos(buscar(get_nombre()))->hambre <= 100)
    {
        if(pila_hambre->getTope())
        {
            std::cout<<pila_hambre->getTope()->valor<<std::endl;
            pila_hambre->sacar();
            if(pila_hambre->getTope())
            {
                create_window.granja->getPos(buscar(get_nombre()))->hambre = pila_hambre->getTope()->valor;
            }
            else
            {
                create_window.granja->getPos(buscar(get_nombre()))->hambre = 0;
            }
        }
        else
        {
            //std::cout<<"No entro"<<std::endl;
        }
    }
    actualizar_valores(get_nombre());
    disable_buttons();
}

void MainWindow::on_dormir_btn_clicked()
{
    if(create_window.granja->getPos(buscar(get_nombre()))->sueno > 0 &&
            create_window.granja->getPos(buscar(get_nombre()))->sueno <= 100)
    {
        if(pila_sueno->getTope())
        {
            std::cout<<pila_sueno->getTope()->valor<<std::endl;
            pila_sueno->sacar();
            if(pila_sueno->getTope())
            {
                create_window.granja->getPos(buscar(get_nombre()))->sueno = pila_sueno->getTope()->valor;
            }
            else
            {
                create_window.granja->getPos(buscar(get_nombre()))->sueno = 0;
            }
        }
    }
    actualizar_valores(get_nombre());
    disable_buttons();
}

void MainWindow::on_actionCreate_new_triggered()
{
    create_window.show();
}

void MainWindow::on_refresh_btn_clicked()
{
    if(create_window.granja->size > 0)
    {
        ui->select_btn->show();
    }

    ui->comboBox->clear();

    for(int x = 0; x < create_window.granja->size; x++)
    {
        ui->comboBox->addItem(create_window.granja->getPos(x)->nombre);
    }
}

int MainWindow::buscar(QString name)
{
    for(int x = 0; x<create_window.granja->size; x++)
    {
        if(create_window.granja->getPos(x)->nombre == name)
        {
            tamagotchi_pos = x;
        }
    }
    if(tamagotchi_pos == 0 && create_window.granja->getPos(0)->nombre!=name)
    {
        return -1;
    }

    return tamagotchi_pos;
}

void MainWindow::actualizar_valores(QString name)
{
    refrescar_barras();
    ui->progressBar_salud->setValue(create_window.granja->getPos(buscar(get_nombre()))->vida);
    ui->progressBar_actividad_desechos->setValue(create_window.granja->getPos(buscar(get_nombre()))->desechos);
    ui->progressBar_actividad_salud->setValue(create_window.granja->getPos(buscar(get_nombre()))->enfermedad);
    ui->progressBar_actividad_sueno->setValue(create_window.granja->getPos(buscar(get_nombre()))->sueno);
    ui->progressBar_actividad_hambre->setValue(create_window.granja->getPos(buscar(get_nombre()))->hambre);
    QTimer::singleShot(1000, this, SLOT(chequear_monedas()));
    QTimer::singleShot(1000, this, SLOT(chequear_progress()));
}

QString MainWindow::get_nombre()
{
    return ui->comboBox->currentText();
}

void MainWindow::on_select_btn_clicked()
{
    if(create_window.granja->getPos(buscar(get_nombre()))->tipo == "Fuerte")
    {
        QPixmap pix("/home/ecruz25/Documents/Clases Unitec/Estructura de Datos/Proyecto 1/Proyecto1/Nikatchi.png");
        ui->label->setPixmap(pix);
    }
    else if(create_window.granja->getPos(buscar(get_nombre()))->tipo == "Inteligente")
    {
        QPixmap pix("/home/ecruz25/Documents/Clases Unitec/Estructura de Datos/Proyecto 1/Proyecto1/Zuccitchi.png");
        ui->label->setPixmap(pix);
    }
    else if(create_window.granja->getPos(buscar(get_nombre()))->tipo == "Habil")
    {
        QPixmap pix("/home/ecruz25/Documents/Clases Unitec/Estructura de Datos/Proyecto 1/Proyecto1/Zuccitchi.png");
        ui->label->setPixmap(pix);
    }

    actualizar_valores(get_nombre());
    ui->progressBar_actividad_desechos->show();
    ui->progressBar_actividad_hambre->show();
    ui->progressBar_actividad_salud->show();
    ui->progressBar_actividad_sueno->show();
    ui->progressBar_salud->show();
    ui->ir_al_bano_btn->show();
    ui->comer_btn->show();
    ui->curar_btn->show();
    ui->dormir_btn->show();
    ui->label->show();
    ui->regalar_btn->show();
    ui->regalar_edit->show();
    connect(timer, SIGNAL(timeout()), this, SLOT(hacer_dano()));
    connect(timer, SIGNAL(timeout()),this, SLOT(perder_vida()));
    timer->start(2000);
}

void MainWindow::hacer_dano()
{
    switch(rand()%4)
    {
    case 0:
        if(create_window.granja->getPos(buscar(get_nombre()))->desechos >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->desechos < 100)
        {
            if(pila_desechos->getTope())
            {
                if(pila_desechos->getTope()->valor >= 0)
                {
                    Actividad* temp = new Actividad(pila_desechos->getTope()->valor+10);
                    pila_desechos->meter(temp);
                    //std::cout<< "desehcos: "<<pila_desechos->getTope()->valor<<std::endl;
                }
            }
            else if(!pila_desechos->getTope())
            {
                ir_al_bano = new Actividad(10);
                pila_desechos->meter(ir_al_bano);
            }
            create_window.granja->getPos(buscar(get_nombre()))->desechos = pila_desechos->getTope()->valor;
        }
        actualizar_valores(get_nombre());
        break;
    case 1:
        if(create_window.granja->getPos(buscar(get_nombre()))->hambre >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->hambre < 100)
        {
            if(pila_hambre->getTope())
            {
                if(pila_hambre->getTope()->valor >= 0)
                {
                    Actividad* temp = new Actividad(pila_hambre->getTope()->valor+10);
                    pila_hambre->meter(temp);
                    //std::cout<< "hambre: "<<pila_hambre->getTope()->valor<<std::endl;
                }
            }
            else if(!pila_hambre->getTope())
            {
                comer = new Actividad(10);
                pila_hambre->meter(comer);
            }
            create_window.granja->getPos(buscar(get_nombre()))->hambre = pila_hambre->getTope()->valor;
        }
        actualizar_valores(get_nombre());
        break;
    case 2:
        if(create_window.granja->getPos(buscar(get_nombre()))->enfermedad >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->enfermedad < 100)
        {
            if(pila_enfermedades->getTope())
            {
                if(pila_enfermedades->getTope()->valor >= 0)
                {
                    Actividad* temp = new Actividad(pila_enfermedades->getTope()->valor+10);
                    pila_enfermedades->meter(temp);
                    QTimer::singleShot(750, this, SLOT(enable_buttons()));
                    //std::cout<< "enfermedad: "<<pila_enfermedades->getTope()->valor<<std::endl;
                }
            }
            else if(!pila_enfermedades->getTope())
            {
                sanar = new Actividad(10);
                pila_enfermedades->meter(sanar);
            }
            create_window.granja->getPos(buscar(get_nombre()))->enfermedad = pila_enfermedades->getTope()->valor;
        }
        actualizar_valores(get_nombre());
        break;
    case 3:
        if(create_window.granja->getPos(buscar(get_nombre()))->sueno >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->sueno < 100)
        {
            if(pila_sueno->getTope())
            {
                if(pila_sueno->getTope()->valor >= 0)
                {
                    Actividad* temp = new Actividad(pila_sueno->getTope()->valor+10);
                    pila_sueno->meter(temp);
                    //std::cout<< "Sueño: "<<pila_sueno->getTope()->valor<<std::endl;
                }
            }
            else if(!pila_sueno->getTope())
            {
                dormir = new Actividad(10);
                pila_sueno->meter(dormir);
            }
            create_window.granja->getPos(buscar(get_nombre()))->sueno = pila_sueno->getTope()->valor;
        }
        actualizar_valores(get_nombre());
        break;
    }
}

void MainWindow::showTime()
{

}

void MainWindow::on_actionSettings_triggered()
{
}

void MainWindow::perder_vida()
{
    int dano = ui->progressBar_actividad_desechos->value() +
            (ui->progressBar_actividad_hambre->value() - create_window.granja->getPos(buscar(get_nombre()))->resistencia_hambre) +
            (ui->progressBar_actividad_salud->value() - create_window.granja->getPos(buscar(get_nombre()))->resistencia_hambre) +
            (ui->progressBar_actividad_sueno->value() - create_window.granja->getPos(buscar(get_nombre()))->resistencia_enfermedades);
    create_window.granja->getPos(buscar(get_nombre()))->vida = 100 - (dano * 0.25);
    actualizar_valores(get_nombre());
}

void MainWindow::on_actionTransacciones_triggered()
{
    transacciones.show();
}

void MainWindow::disable_buttons()
{
    ui->comer_btn->hide();
    ui->curar_btn->hide();
    ui->dormir_btn->hide();
    ui->ir_al_bano_btn->hide();
    QTimer::singleShot(750, this, SLOT(enable_buttons()));
}

void MainWindow::enable_buttons()
{
    ui->comer_btn->show();
    ui->curar_btn->show();
    ui->dormir_btn->show();
    ui->ir_al_bano_btn->show();
}

void MainWindow::chequear_estado(QProgressBar* progressbar)
{
    if(progressbar->value() == 100)
    {
        estados->ponerCola(new QNodo(perder));
        //std::cout<<perder.toStdString()<<std::endl;
    }
    else
    {
        estados->ponerCola(new QNodo(ganar));
        switch (rand()%50) {
        case 3:
            ui->log->addItem("Ganaste moneda");
            create_window.granja->getPos(buscar(get_nombre()))->monedas_ganadas->poner(new Moneda(rand()%4));
            break;
        }
    }
}

void MainWindow::imprimir_victorias_derrotas()
{
    ui->log->addItem(estados->getFrente()->string);
    estados->quitarCola();
}

void MainWindow::chequear_progress()
{
    chequear_estado(ui->progressBar_actividad_desechos);
    chequear_estado(ui->progressBar_actividad_hambre);
    chequear_estado(ui->progressBar_actividad_salud);
    chequear_estado(ui->progressBar_actividad_sueno);
    imprimir_victorias_derrotas();
}

void MainWindow::on_regalar_btn_clicked()
{
    if(create_window.granja->getPos(buscar(ui->regalar_edit->text())))
    {
        if(create_window.granja->getPos(buscar(get_nombre()))->monedas_ganadas->size > 0)
        {
            std::cout<<"regalado a :"<<create_window.granja->getPos(buscar(ui->regalar_edit->text()))->nombre.toStdString()<<"     "<<create_window.granja->getPos(buscar(get_nombre()))->monedas_ganadas->size<<std::endl;
            create_window.granja->getPos(buscar(ui->regalar_edit->text()))->monedas_recibidas->poner(create_window.granja->getPos(buscar(get_nombre()))->monedas_ganadas->getFrente());
            create_window.granja->getPos(buscar(get_nombre()))->monedas_ganadas->quitar();
        }
        else
        {
            std::cout<<"monedas insuficientes"<<std::endl;
        }
    }
    else
    {
        std::cout<<ui->regalar_edit->text().toStdString()<<"---"<<std::endl;
        std::cout<<"No existe esa mascota"<<std::endl;
        return;
    }
}
void MainWindow::chequear_monedas()
{
    if(create_window.granja->getPos(buscar(get_nombre()))->monedas_recibidas->size > 0)
    {
        std::cout<<"tiene una moneda disponible"<< create_window.granja->getPos(buscar(get_nombre()))->nombre.toStdString()<< std::endl;
        if(create_window.granja->getPos(buscar(get_nombre()))->monedas_recibidas->getFrente()->valor == 1)
        {
            ui->limpiar_desechos->show();
            ui->limpiar_enfermedad->hide();
            ui->limpiar_hambre->hide();
            ui->limpiar_sueno->hide();
        }
        else if(create_window.granja->getPos(buscar(get_nombre()))->monedas_recibidas->getFrente()->valor == 2)
        {
            ui->limpiar_desechos->show();
            ui->limpiar_enfermedad->show();
            ui->limpiar_hambre->hide();
            ui->limpiar_sueno->hide();
        }
        else if(create_window.granja->getPos(buscar(get_nombre()))->monedas_recibidas->getFrente()->valor == 3)
        {
            ui->limpiar_desechos->show();
            ui->limpiar_enfermedad->show();
            ui->limpiar_hambre->show();
            ui->limpiar_sueno->hide();
        }
        else if(create_window.granja->getPos(buscar(get_nombre()))->monedas_recibidas->getFrente()->valor == 4)
        {
            ui->limpiar_desechos->show();
            ui->limpiar_enfermedad->show();
            ui->limpiar_hambre->show();
            ui->limpiar_sueno->show();
        }
    }
}

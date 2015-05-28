#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("/home/ecruz25/Documents/Clases Unitec/Estructura de Datos/Proyecto 1/Proyecto1/Zuccitchi.png");

    ui->label->setPixmap(pix);

    ui->select_btn->hide();

    pila_desechos = new Pila;
    pila_enfermedades = new Pila;
    pila_hambre = new Pila;
    pila_sueno = new Pila;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refrescar_barras()));

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
        ui->progressBar_salud->setStyleSheet(danger);
    else
        ui->progressBar_salud->setStyleSheet(safe);

    if(ui->progressBar_actividad_desechos->value()>40)
        ui->progressBar_actividad_desechos->setStyleSheet(danger);
    else
        ui->progressBar_actividad_desechos->setStyleSheet(safe);

    if(ui->progressBar_actividad_hambre->value()>40)
        ui->progressBar_actividad_hambre->setStyleSheet(danger);
    else
        ui->progressBar_actividad_hambre->setStyleSheet(safe);

    if(ui->progressBar_actividad_salud->value()>40)
        ui->progressBar_actividad_salud->setStyleSheet(danger);
    else
        ui->progressBar_actividad_salud->setStyleSheet(safe);

    if(ui->progressBar_actividad_sueno->value()>40)
        ui->progressBar_actividad_sueno->setStyleSheet(danger);
    else
        ui->progressBar_actividad_sueno->setStyleSheet(safe);
}

void MainWindow::on_curar_btn_clicked()
{ 
    create_window.granja->getPos(buscar(get_nombre()))->vida -= 10;
}

void MainWindow::on_ir_al_bano_btn_clicked()
{

}

void MainWindow::on_comer_btn_clicked()
{

}

void MainWindow::on_dormir_btn_clicked()
{
    refrescar_barras();
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
    return tamagotchi_pos;
}

void MainWindow::actualizar_valores(QString name)
{
    ui->progressBar_salud->setValue(create_window.granja->getPos(buscar(name))->vida);
    ui->progressBar_actividad_desechos->setValue(create_window.granja->getPos(buscar(name))->desechos);
    ui->progressBar_actividad_salud->setValue(create_window.granja->getPos(buscar(name))->enfermedad);
    ui->progressBar_actividad_sueno->setValue(create_window.granja->getPos(buscar(name))->sueno);
    ui->progressBar_actividad_hambre->setValue(create_window.granja->getPos(buscar(name))->hambre);

    refrescar_barras();
}

QString MainWindow::get_nombre()
{
    return ui->comboBox->currentText();
}

void MainWindow::on_select_btn_clicked()
{
    actualizar_valores(get_nombre());
    connect(timer, SIGNAL(timeout()), this, SLOT(hacer_dano()));
    timer->start(250);

}

void MainWindow::hacer_dano()
{
    valor = rand()%4;

    switch(valor)
    {
        case 0:
        if(create_window.granja->getPos(buscar(get_nombre()))->desechos >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->desechos < 100)
        {
            if(pila_desechos->getTope() != NULL)
            {
                create_window.granja->getPos(buscar(get_nombre()))->desechos += pila_desechos->getTope()->valor;
            }
            else
            {
                ir_al_bano = new Actividad(1);
                pila_desechos->meter(ir_al_bano);
            }
        }
        actualizar_valores(get_nombre());
        break;
        case 1:
        if(create_window.granja->getPos(buscar(get_nombre()))->hambre >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->hambre < 100)
        {
            if(pila_hambre->getTope() != NULL)
            {
                create_window.granja->getPos(buscar(get_nombre()))->hambre += pila_hambre->getTope()->valor;
            }
            else
            {
                comer = new Actividad(1);
                pila_hambre->meter(comer);
            }
        }
        actualizar_valores(get_nombre());
        break;
        case 2:
        if(create_window.granja->getPos(buscar(get_nombre()))->enfermedad >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->enfermedad < 100)
        {
            if(pila_enfermedades->getTope() != NULL)
            {
                create_window.granja->getPos(buscar(get_nombre()))->enfermedad += pila_enfermedades->getTope()->valor;
            }
            else
            {
                sanar = new Actividad(1);
                pila_enfermedades->meter(sanar);
            }
        }
        actualizar_valores(get_nombre());
        break;
        case 3:
        if(create_window.granja->getPos(buscar(get_nombre()))->sueno >= 0 &&
                create_window.granja->getPos(buscar(get_nombre()))->sueno < 100)
        {
            if(pila_sueno->getTope() != NULL)
            {
                create_window.granja->getPos(buscar(get_nombre()))->sueno += pila_sueno->getTope()->valor;
            }
            else
            {
                dormir = new Actividad(1);
                pila_sueno->meter(dormir);
            }
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

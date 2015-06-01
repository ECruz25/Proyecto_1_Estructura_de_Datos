#include "transacciones.h"
#include "ui_transacciones.h"

Transacciones::Transacciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transacciones)
{
    ui->setupUi(this);
}

Transacciones::~Transacciones()
{
    delete ui;
}

void Transacciones::on_regalar_btn_clicked()
{
//    main->create_window.granja->getPos(main->buscar(main->get_nombre()))
//    create_window.granja->getPos(buscar(get_nombre()))
}

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

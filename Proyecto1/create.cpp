#include "create.h"
#include "ui_create.h"

#include <iostream>

Create::Create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
    granja = new Granja();
    ui->comboBox->addItem("Fuerte");
    ui->comboBox->addItem("Inteligente");
    ui->comboBox->addItem("Habil");
}

Create::~Create()
{
    delete ui;
}

void Create::on_buttonBox_accepted()
{
    granja->add(ui->name_edit->text(), ui->comboBox->currentText());
}

void Create::on_Create_destroyed(){}

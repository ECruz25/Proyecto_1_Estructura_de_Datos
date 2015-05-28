#include "create.h"
#include "ui_create.h"

#include <iostream>

Create::Create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
    granja = new Granja();
    ui->comboBox->addItem("Perro");
    ui->comboBox->addItem("Gato");
    ui->comboBox->addItem("Caballo");
}

Create::~Create()
{
    delete ui;
}

void Create::on_buttonBox_accepted()
{
    granja->add(ui->name_edit->text(), ui->comboBox->currentText());
    std::cout<<ui->comboBox->itemData(ui->comboBox->currentIndex()).toString().toStdString()<<std::endl;
}

void Create::on_Create_destroyed(){}

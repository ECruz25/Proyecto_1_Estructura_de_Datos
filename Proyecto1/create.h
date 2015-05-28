#ifndef CREATE_H
#define CREATE_H

#include <QDialog>
#include <iostream>
#include "granja.h"

namespace Ui {
class Create;
}

class Create : public QDialog
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = 0);
    ~Create();
    QString name;
    Granja* granja;
    int times;


private slots:
    void on_buttonBox_accepted();

    void on_Create_destroyed();

private:
    Ui::Create *ui;
};

#endif // CREATE_H

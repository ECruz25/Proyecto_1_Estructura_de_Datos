#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H

#include <QDialog>

namespace Ui {
class Transacciones;
}

class Transacciones : public QDialog
{
    Q_OBJECT

public:
    explicit Transacciones(QWidget *parent = 0);
    ~Transacciones();

private slots:
    void on_regalar_btn_clicked();

private:
    Ui::Transacciones *ui;
};

#endif // TRANSACCIONES_H

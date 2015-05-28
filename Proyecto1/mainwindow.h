#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "granja.h"
#include "create.h"
#include "Estructuras/pila.h"
#include "actividad.h"
#include "stdlib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer* timer;

private slots:
    void on_curar_btn_clicked();

    void on_ir_al_bano_btn_clicked();

    void on_comer_btn_clicked();

    void on_dormir_btn_clicked();

    void on_actionCreate_new_triggered();

    void on_refresh_btn_clicked();

    void on_select_btn_clicked();

    void refrescar_barras();

    void hacer_dano();

    void showTime();

    int buscar(QString name);

    QString get_nombre();

    void actualizar_valores(QString name);

private:
    Pila* pila_desechos;
    Pila* pila_enfermedades;
    Pila* pila_bano;
    Pila* pila_sueno;

    Actividad* dormir;
    Actividad* ir_al_bano;
    Actividad* comer;
    Actividad* sanar;

    Granja* granja;

    QString create;
    QString safe;
    QString danger;

    Ui::MainWindow *ui;

    Create create_window;

    int tamagotchi_pos;
};

#endif // MAINWINDOW_H
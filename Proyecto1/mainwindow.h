#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QProgressBar>
#include <QQueue>
#include <iostream>
#include "granja.h"
#include "create.h"
#include "transacciones.h"
#include "Estructuras/pila.h"
#include "Estructuras/cola.h"
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
    QTimer* mTimer;

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
    void actualizar_valores(QString name);
    void on_actionSettings_triggered();
    void perder_vida();
    void on_actionTransacciones_triggered();
    void disable_buttons();
    void enable_buttons();
    void chequear_estado(QProgressBar* progress);
    void imprimir_victorias_derrotas();
    int buscar(QString name);
    QString get_nombre();
    void chequear_progress();
    void chequear_monedas();
    void on_regalar_btn_clicked();

private:
    Ui::MainWindow *ui;

    Pila* pila_desechos;
    Pila* pila_enfermedades;
    Pila* pila_hambre;
    Pila* pila_sueno;

    Cola* estados;

    QNodo* nodo;

    Actividad* dormir;
    Actividad* ir_al_bano;
    Actividad* comer;
    Actividad* sanar;

    Granja* granja;

    QString create;
    QString safe;
    QString danger;
    QString loguear;
    QString ganar;
    QString perder;

    Create create_window;

    int tamagotchi_pos;
    int valor;

    Transacciones transacciones;
};

#endif // MAINWINDOW_H

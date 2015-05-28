/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_new;
    QWidget *centralWidget;
    QPushButton *ir_al_bano_btn;
    QPushButton *dormir_btn;
    QPushButton *comer_btn;
    QPushButton *curar_btn;
    QLabel *label;
    QGraphicsView *graphicsView;
    QProgressBar *progressBar_salud;
    QProgressBar *progressBar_actividad_desechos;
    QProgressBar *progressBar_actividad_hambre;
    QProgressBar *progressBar_actividad_salud;
    QProgressBar *progressBar_actividad_sueno;
    QComboBox *comboBox;
    QPushButton *refresh_btn;
    QPushButton *select_btn;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(455, 393);
        actionCreate_new = new QAction(MainWindow);
        actionCreate_new->setObjectName(QStringLiteral("actionCreate_new"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ir_al_bano_btn = new QPushButton(centralWidget);
        ir_al_bano_btn->setObjectName(QStringLiteral("ir_al_bano_btn"));
        ir_al_bano_btn->setGeometry(QRect(30, 300, 71, 21));
        dormir_btn = new QPushButton(centralWidget);
        dormir_btn->setObjectName(QStringLiteral("dormir_btn"));
        dormir_btn->setGeometry(QRect(270, 300, 71, 21));
        comer_btn = new QPushButton(centralWidget);
        comer_btn->setObjectName(QStringLiteral("comer_btn"));
        comer_btn->setGeometry(QRect(110, 300, 71, 21));
        curar_btn = new QPushButton(centralWidget);
        curar_btn->setObjectName(QStringLiteral("curar_btn"));
        curar_btn->setGeometry(QRect(190, 300, 71, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 80, 81, 91));
        label->setText(QStringLiteral(""));
        label->setTextFormat(Qt::PlainText);
        label->setPixmap(QPixmap(QString::fromUtf8("Zuccitchi.png")));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(120, 70, 111, 111));
        progressBar_salud = new QProgressBar(centralWidget);
        progressBar_salud->setObjectName(QStringLiteral("progressBar_salud"));
        progressBar_salud->setGeometry(QRect(90, 20, 181, 21));
        progressBar_salud->setMinimum(0);
        progressBar_salud->setMaximum(100);
        progressBar_salud->setValue(40);
        progressBar_salud->setFormat(QStringLiteral("%p%"));
        progressBar_actividad_desechos = new QProgressBar(centralWidget);
        progressBar_actividad_desechos->setObjectName(QStringLiteral("progressBar_actividad_desechos"));
        progressBar_actividad_desechos->setGeometry(QRect(50, 230, 31, 61));
        progressBar_actividad_desechos->setValue(24);
        progressBar_actividad_desechos->setOrientation(Qt::Vertical);
        progressBar_actividad_hambre = new QProgressBar(centralWidget);
        progressBar_actividad_hambre->setObjectName(QStringLiteral("progressBar_actividad_hambre"));
        progressBar_actividad_hambre->setGeometry(QRect(130, 230, 31, 61));
        progressBar_actividad_hambre->setValue(24);
        progressBar_actividad_hambre->setOrientation(Qt::Vertical);
        progressBar_actividad_salud = new QProgressBar(centralWidget);
        progressBar_actividad_salud->setObjectName(QStringLiteral("progressBar_actividad_salud"));
        progressBar_actividad_salud->setGeometry(QRect(210, 230, 31, 61));
        progressBar_actividad_salud->setValue(24);
        progressBar_actividad_salud->setOrientation(Qt::Vertical);
        progressBar_actividad_sueno = new QProgressBar(centralWidget);
        progressBar_actividad_sueno->setObjectName(QStringLiteral("progressBar_actividad_sueno"));
        progressBar_actividad_sueno->setGeometry(QRect(290, 230, 31, 61));
        progressBar_actividad_sueno->setValue(24);
        progressBar_actividad_sueno->setOrientation(Qt::Vertical);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(250, 120, 85, 27));
        refresh_btn = new QPushButton(centralWidget);
        refresh_btn->setObjectName(QStringLiteral("refresh_btn"));
        refresh_btn->setGeometry(QRect(260, 150, 61, 27));
        select_btn = new QPushButton(centralWidget);
        select_btn->setObjectName(QStringLiteral("select_btn"));
        select_btn->setGeometry(QRect(340, 120, 81, 27));
        MainWindow->setCentralWidget(centralWidget);
        ir_al_bano_btn->raise();
        dormir_btn->raise();
        comer_btn->raise();
        curar_btn->raise();
        graphicsView->raise();
        label->raise();
        progressBar_salud->raise();
        progressBar_actividad_desechos->raise();
        progressBar_actividad_hambre->raise();
        progressBar_actividad_salud->raise();
        progressBar_actividad_sueno->raise();
        comboBox->raise();
        refresh_btn->raise();
        select_btn->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 25));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNew->menuAction());
        menuNew->addAction(actionCreate_new);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCreate_new->setText(QApplication::translate("MainWindow", "Create new..", 0));
        ir_al_bano_btn->setText(QApplication::translate("MainWindow", "Ir al ba\303\261o", 0));
        dormir_btn->setText(QApplication::translate("MainWindow", "Dormir", 0));
        comer_btn->setText(QApplication::translate("MainWindow", "Comer", 0));
        curar_btn->setText(QApplication::translate("MainWindow", "Curar", 0));
        refresh_btn->setText(QApplication::translate("MainWindow", "Refresh", 0));
        select_btn->setText(QApplication::translate("MainWindow", "Select", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "New..", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

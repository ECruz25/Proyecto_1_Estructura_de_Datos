/********************************************************************************
** Form generated from reading UI file 'create.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Create
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *name_edit;

    void setupUi(QDialog *Create)
    {
        if (Create->objectName().isEmpty())
            Create->setObjectName(QStringLiteral("Create"));
        Create->resize(400, 300);
        buttonBox = new QDialogButtonBox(Create);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Create);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 71, 16));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Create);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 100, 71, 21));
        label_2->setFont(font);
        comboBox = new QComboBox(Create);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 100, 171, 31));
        name_edit = new QLineEdit(Create);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setGeometry(QRect(160, 60, 113, 27));

        retranslateUi(Create);
        QObject::connect(buttonBox, SIGNAL(accepted()), Create, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Create, SLOT(reject()));

        QMetaObject::connectSlotsByName(Create);
    } // setupUi

    void retranslateUi(QDialog *Create)
    {
        Create->setWindowTitle(QApplication::translate("Create", "Dialog", 0));
        label->setText(QApplication::translate("Create", "Name:", 0));
        label_2->setText(QApplication::translate("Create", "Type:", 0));
    } // retranslateUi

};

namespace Ui {
    class Create: public Ui_Create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H

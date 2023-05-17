/********************************************************************************
** Form generated from reading UI file 'alterarcarro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERARCARRO_H
#define UI_ALTERARCARRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlterarCarro
{
public:
    QCommandLinkButton *commandButtonVoltar;
    QTableView *tableViewModulosCarro;
    QLabel *label_2;
    QPushButton *btnCriarCarro;

    void setupUi(QWidget *AlterarCarro)
    {
        if (AlterarCarro->objectName().isEmpty())
            AlterarCarro->setObjectName("AlterarCarro");
        AlterarCarro->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AlterarCarro->setWindowIcon(icon);
        AlterarCarro->setStyleSheet(QString::fromUtf8("background:white"));
        commandButtonVoltar = new QCommandLinkButton(AlterarCarro);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, 0, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        tableViewModulosCarro = new QTableView(AlterarCarro);
        tableViewModulosCarro->setObjectName("tableViewModulosCarro");
        tableViewModulosCarro->setGeometry(QRect(10, 110, 771, 311));
        label_2 = new QLabel(AlterarCarro);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 261, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_2->setFont(font);
        btnCriarCarro = new QPushButton(AlterarCarro);
        btnCriarCarro->setObjectName("btnCriarCarro");
        btnCriarCarro->setGeometry(QRect(650, 440, 121, 41));
        QFont font1;
        font1.setPointSize(10);
        btnCriarCarro->setFont(font1);
        btnCriarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnCriarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(255, 245, 166);\n"
"	border:none;\n"
"	color:rgb(95, 91, 61);\n"
"	border -bottom: 5px solid rgb(162, 155, 105)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(229, 217, 150);\n"
"	border-bottom: 5px solid rgb(162, 155, 105)\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:rgb(255, 242, 165);\n"
"	border-bottom: 5px solid rgb(162, 155, 105)\n"
"}"));

        retranslateUi(AlterarCarro);

        QMetaObject::connectSlotsByName(AlterarCarro);
    } // setupUi

    void retranslateUi(QWidget *AlterarCarro)
    {
        AlterarCarro->setWindowTitle(QCoreApplication::translate("AlterarCarro", "Alterar de Carro", nullptr));
        commandButtonVoltar->setText(QString());
        label_2->setText(QCoreApplication::translate("AlterarCarro", "Selecionar Carro:", nullptr));
        btnCriarCarro->setText(QCoreApplication::translate("AlterarCarro", "Criar Carro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlterarCarro: public Ui_AlterarCarro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERARCARRO_H

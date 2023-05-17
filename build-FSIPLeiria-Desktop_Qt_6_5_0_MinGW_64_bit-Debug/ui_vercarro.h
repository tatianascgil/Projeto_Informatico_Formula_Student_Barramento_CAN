/********************************************************************************
** Form generated from reading UI file 'vercarro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERCARRO_H
#define UI_VERCARRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerCarro
{
public:
    QPushButton *btnDefinicoes;
    QPushButton *btnEstatistica;
    QPushButton *btnAlterarCarro;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelNomeCarro;
    QLabel *labelMarcaCarro;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *labelObsCarro;
    QLabel *labelObsCarro_2;
    QCommandLinkButton *commandButtonVoltar;

    void setupUi(QWidget *VerCarro)
    {
        if (VerCarro->objectName().isEmpty())
            VerCarro->setObjectName("VerCarro");
        VerCarro->resize(712, 338);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        VerCarro->setWindowIcon(icon);
        VerCarro->setStyleSheet(QString::fromUtf8("\n"
"	background-color:white"));
        btnDefinicoes = new QPushButton(VerCarro);
        btnDefinicoes->setObjectName("btnDefinicoes");
        btnDefinicoes->setGeometry(QRect(530, 60, 161, 51));
        QFont font;
        font.setPointSize(10);
        btnDefinicoes->setFont(font);
        btnDefinicoes->setCursor(QCursor(Qt::PointingHandCursor));
        btnDefinicoes->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnEstatistica = new QPushButton(VerCarro);
        btnEstatistica->setObjectName("btnEstatistica");
        btnEstatistica->setGeometry(QRect(530, 140, 161, 51));
        btnEstatistica->setFont(font);
        btnEstatistica->setCursor(QCursor(Qt::PointingHandCursor));
        btnEstatistica->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnAlterarCarro = new QPushButton(VerCarro);
        btnAlterarCarro->setObjectName("btnAlterarCarro");
        btnAlterarCarro->setGeometry(QRect(530, 220, 161, 51));
        btnAlterarCarro->setFont(font);
        btnAlterarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnAlterarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label = new QLabel(VerCarro);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 40, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(VerCarro);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 90, 91, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(VerCarro);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 140, 91, 31));
        label_3->setFont(font1);
        labelNomeCarro = new QLabel(VerCarro);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(130, 40, 121, 31));
        QFont font2;
        font2.setPointSize(16);
        labelNomeCarro->setFont(font2);
        labelMarcaCarro = new QLabel(VerCarro);
        labelMarcaCarro->setObjectName("labelMarcaCarro");
        labelMarcaCarro->setGeometry(QRect(140, 90, 121, 31));
        labelMarcaCarro->setFont(font2);
        scrollArea = new QScrollArea(VerCarro);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(60, 170, 431, 131));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 129));
        labelObsCarro = new QLabel(scrollAreaWidgetContents);
        labelObsCarro->setObjectName("labelObsCarro");
        labelObsCarro->setGeometry(QRect(10, 10, 301, 31));
        labelObsCarro->setFont(font2);
        labelObsCarro_2 = new QLabel(scrollAreaWidgetContents);
        labelObsCarro_2->setObjectName("labelObsCarro_2");
        labelObsCarro_2->setGeometry(QRect(10, 40, 261, 31));
        labelObsCarro_2->setFont(font2);
        scrollArea->setWidget(scrollAreaWidgetContents);
        commandButtonVoltar = new QCommandLinkButton(VerCarro);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(10, 10, 31, 41));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);

        retranslateUi(VerCarro);

        QMetaObject::connectSlotsByName(VerCarro);
    } // setupUi

    void retranslateUi(QWidget *VerCarro)
    {
        VerCarro->setWindowTitle(QCoreApplication::translate("VerCarro", "Ver Carrro", nullptr));
        btnDefinicoes->setText(QCoreApplication::translate("VerCarro", "Defini\303\247\303\265es", nullptr));
        btnEstatistica->setText(QCoreApplication::translate("VerCarro", "Estat\303\255sticas", nullptr));
        btnAlterarCarro->setText(QCoreApplication::translate("VerCarro", "Alterar de Carro", nullptr));
        label->setText(QCoreApplication::translate("VerCarro", "Carro:", nullptr));
        label_2->setText(QCoreApplication::translate("VerCarro", "Marca:", nullptr));
        label_3->setText(QCoreApplication::translate("VerCarro", "OBS:", nullptr));
        labelNomeCarro->setText(QCoreApplication::translate("VerCarro", "Carro XPTO", nullptr));
        labelMarcaCarro->setText(QCoreApplication::translate("VerCarro", "Marca Xpto", nullptr));
        labelObsCarro->setText(QCoreApplication::translate("VerCarro", "Ano Xptodsajbjdkbk,a,bd", nullptr));
        labelObsCarro_2->setText(QCoreApplication::translate("VerCarro", "hsagbjbgdhjbkj,d", nullptr));
        commandButtonVoltar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VerCarro: public Ui_VerCarro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERCARRO_H

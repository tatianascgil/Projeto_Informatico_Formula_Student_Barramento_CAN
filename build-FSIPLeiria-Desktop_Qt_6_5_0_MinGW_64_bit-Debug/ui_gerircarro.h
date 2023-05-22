/********************************************************************************
** Form generated from reading UI file 'gerircarro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERIRCARRO_H
#define UI_GERIRCARRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GerirCarro
{
public:
    QCommandLinkButton *commandButtonVoltar;
    QLabel *label;
    QLabel *labelNomeCarro;
    QTableView *tableViewCarro;
    QTableView *tableViewModulosCarro;
    QLabel *label_2;
    QFrame *line;
    QPushButton *btnApagarCarro;
    QPushButton *btnGuardarCarro;
    QPushButton *btnCriarModulo;

    void setupUi(QWidget *GerirCarro)
    {
        if (GerirCarro->objectName().isEmpty())
            GerirCarro->setObjectName("GerirCarro");
        GerirCarro->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GerirCarro->setWindowIcon(icon);
        GerirCarro->setStyleSheet(QString::fromUtf8("background:white"));
        commandButtonVoltar = new QCommandLinkButton(GerirCarro);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, -10, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        label = new QLabel(GerirCarro);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 81, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        labelNomeCarro = new QLabel(GerirCarro);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(120, 20, 211, 31));
        QFont font1;
        font1.setPointSize(16);
        labelNomeCarro->setFont(font1);
        tableViewCarro = new QTableView(GerirCarro);
        tableViewCarro->setObjectName("tableViewCarro");
        tableViewCarro->setGeometry(QRect(20, 60, 761, 61));
        tableViewModulosCarro = new QTableView(GerirCarro);
        tableViewModulosCarro->setObjectName("tableViewModulosCarro");
        tableViewModulosCarro->setGeometry(QRect(20, 250, 761, 191));
        label_2 = new QLabel(GerirCarro);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 210, 311, 31));
        label_2->setFont(font);
        line = new QFrame(GerirCarro);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 190, 791, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnApagarCarro = new QPushButton(GerirCarro);
        btnApagarCarro->setObjectName("btnApagarCarro");
        btnApagarCarro->setGeometry(QRect(530, 140, 121, 41));
        QFont font2;
        font2.setPointSize(10);
        btnApagarCarro->setFont(font2);
        btnApagarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnApagarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnGuardarCarro = new QPushButton(GerirCarro);
        btnGuardarCarro->setObjectName("btnGuardarCarro");
        btnGuardarCarro->setGeometry(QRect(660, 140, 121, 41));
        btnGuardarCarro->setFont(font2);
        btnGuardarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnCriarModulo = new QPushButton(GerirCarro);
        btnCriarModulo->setObjectName("btnCriarModulo");
        btnCriarModulo->setGeometry(QRect(660, 450, 121, 41));
        btnCriarModulo->setFont(font2);
        btnCriarModulo->setCursor(QCursor(Qt::PointingHandCursor));
        btnCriarModulo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(GerirCarro);

        QMetaObject::connectSlotsByName(GerirCarro);
    } // setupUi

    void retranslateUi(QWidget *GerirCarro)
    {
        GerirCarro->setWindowTitle(QCoreApplication::translate("GerirCarro", "Gerir Carro", nullptr));
        commandButtonVoltar->setText(QString());
        label->setText(QCoreApplication::translate("GerirCarro", "Carro", nullptr));
        labelNomeCarro->setText(QCoreApplication::translate("GerirCarro", "Carro XPTO", nullptr));
        label_2->setText(QCoreApplication::translate("GerirCarro", "M\303\263dulos deste Carro:", nullptr));
        btnApagarCarro->setText(QCoreApplication::translate("GerirCarro", "Apagar Carro", nullptr));
        btnGuardarCarro->setText(QCoreApplication::translate("GerirCarro", "Guardar", nullptr));
        btnCriarModulo->setText(QCoreApplication::translate("GerirCarro", "Criar M\303\263dulo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerirCarro: public Ui_GerirCarro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERIRCARRO_H

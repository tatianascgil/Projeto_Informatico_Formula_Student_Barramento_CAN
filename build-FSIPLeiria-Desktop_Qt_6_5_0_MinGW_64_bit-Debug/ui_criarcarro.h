/********************************************************************************
** Form generated from reading UI file 'criarcarro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIARCARRO_H
#define UI_CRIARCARRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriarCarro
{
public:
    QPushButton *btnCriarCarro;
    QCommandLinkButton *commandButtonVoltar;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QTextEdit *textEditNomeCarro;
    QTextEdit *textEditObsCarro;
    QComboBox *btnTipoCarro;

    void setupUi(QWidget *CriarCarro)
    {
        if (CriarCarro->objectName().isEmpty())
            CriarCarro->setObjectName("CriarCarro");
        CriarCarro->resize(568, 252);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CriarCarro->setWindowIcon(icon);
        CriarCarro->setStyleSheet(QString::fromUtf8("background:white"));
        btnCriarCarro = new QPushButton(CriarCarro);
        btnCriarCarro->setObjectName("btnCriarCarro");
        btnCriarCarro->setGeometry(QRect(10, 200, 121, 41));
        QFont font;
        font.setPointSize(10);
        btnCriarCarro->setFont(font);
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
        commandButtonVoltar = new QCommandLinkButton(CriarCarro);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(10, 0, 31, 41));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        label_2 = new QLabel(CriarCarro);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 80, 71, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_2->setFont(font1);
        label = new QLabel(CriarCarro);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 91, 31));
        label->setFont(font1);
        label_3 = new QLabel(CriarCarro);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 130, 51, 21));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label_3->setFont(font2);
        textEditNomeCarro = new QTextEdit(CriarCarro);
        textEditNomeCarro->setObjectName("textEditNomeCarro");
        textEditNomeCarro->setGeometry(QRect(160, 20, 361, 41));
        QFont font3;
        font3.setPointSize(12);
        textEditNomeCarro->setFont(font3);
        textEditNomeCarro->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEditNomeCarro->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        textEditObsCarro = new QTextEdit(CriarCarro);
        textEditObsCarro->setObjectName("textEditObsCarro");
        textEditObsCarro->setGeometry(QRect(240, 130, 281, 111));
        textEditObsCarro->setFont(font3);
        textEditObsCarro->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEditObsCarro->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        btnTipoCarro = new QComboBox(CriarCarro);
        btnTipoCarro->setObjectName("btnTipoCarro");
        btnTipoCarro->setGeometry(QRect(160, 80, 361, 41));
        btnTipoCarro->setFont(font3);
        btnTipoCarro->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));

        retranslateUi(CriarCarro);

        btnTipoCarro->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CriarCarro);
    } // setupUi

    void retranslateUi(QWidget *CriarCarro)
    {
        CriarCarro->setWindowTitle(QCoreApplication::translate("CriarCarro", "Criar Carro", nullptr));
        btnCriarCarro->setText(QCoreApplication::translate("CriarCarro", "Criar Carro", nullptr));
        commandButtonVoltar->setText(QString());
        label_2->setText(QCoreApplication::translate("CriarCarro", "Tipo:", nullptr));
        label->setText(QCoreApplication::translate("CriarCarro", "Nome:", nullptr));
        label_3->setText(QCoreApplication::translate("CriarCarro", "Obs:", nullptr));
        btnTipoCarro->setPlaceholderText(QCoreApplication::translate("CriarCarro", "<Selecionar Tipo de Carro>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CriarCarro: public Ui_CriarCarro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARCARRO_H

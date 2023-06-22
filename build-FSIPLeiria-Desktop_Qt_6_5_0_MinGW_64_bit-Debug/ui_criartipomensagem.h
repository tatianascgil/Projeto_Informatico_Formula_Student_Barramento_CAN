/********************************************************************************
** Form generated from reading UI file 'criartipomensagem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIARTIPOMENSAGEM_H
#define UI_CRIARTIPOMENSAGEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CriarTipoMensagem
{
public:
    QLabel *label_5;
    QPushButton *btnCriarTipoMensagem;
    QCommandLinkButton *commandButtonVoltar;
    QLabel *labelNomeCarro;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *labelNomeModulo;
    QPlainTextEdit *plainTextEditObs;
    QPlainTextEdit *plainTextEditCodHex;

    void setupUi(QDialog *CriarTipoMensagem)
    {
        if (CriarTipoMensagem->objectName().isEmpty())
            CriarTipoMensagem->setObjectName("CriarTipoMensagem");
        CriarTipoMensagem->resize(700, 250);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CriarTipoMensagem->setWindowIcon(icon);
        CriarTipoMensagem->setStyleSheet(QString::fromUtf8("background: white"));
        label_5 = new QLabel(CriarTipoMensagem);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 71, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_5->setFont(font);
        btnCriarTipoMensagem = new QPushButton(CriarTipoMensagem);
        btnCriarTipoMensagem->setObjectName("btnCriarTipoMensagem");
        btnCriarTipoMensagem->setGeometry(QRect(10, 200, 171, 41));
        QFont font1;
        font1.setPointSize(10);
        btnCriarTipoMensagem->setFont(font1);
        btnCriarTipoMensagem->setCursor(QCursor(Qt::PointingHandCursor));
        btnCriarTipoMensagem->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        commandButtonVoltar = new QCommandLinkButton(CriarTipoMensagem);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(10, 10, 31, 41));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        commandButtonVoltar->setStyleSheet(QString::fromUtf8("QCommandLinkButton\n"
"{\n"
"	border: none;\n"
"}\n"
"\n"
"QCommandLinkButton:hover\n"
"{\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        labelNomeCarro = new QLabel(CriarTipoMensagem);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(100, 50, 131, 31));
        labelNomeCarro->setFont(font);
        label_2 = new QLabel(CriarTipoMensagem);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 50, 141, 31));
        label_2->setFont(font);
        label_3 = new QLabel(CriarTipoMensagem);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 130, 51, 21));
        label_3->setFont(font);
        label = new QLabel(CriarTipoMensagem);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 71, 31));
        label->setFont(font);
        labelNomeModulo = new QLabel(CriarTipoMensagem);
        labelNomeModulo->setObjectName("labelNomeModulo");
        labelNomeModulo->setGeometry(QRect(110, 100, 211, 31));
        labelNomeModulo->setFont(font);
        plainTextEditObs = new QPlainTextEdit(CriarTipoMensagem);
        plainTextEditObs->setObjectName("plainTextEditObs");
        plainTextEditObs->setGeometry(QRect(320, 140, 351, 101));
        plainTextEditObs->setFont(font1);
        plainTextEditObs->setStyleSheet(QString::fromUtf8("background: rgb(220, 220, 220)"));
        plainTextEditCodHex = new QPlainTextEdit(CriarTipoMensagem);
        plainTextEditCodHex->setObjectName("plainTextEditCodHex");
        plainTextEditCodHex->setGeometry(QRect(400, 50, 71, 31));
        plainTextEditCodHex->setFont(font1);

        retranslateUi(CriarTipoMensagem);

        QMetaObject::connectSlotsByName(CriarTipoMensagem);
    } // setupUi

    void retranslateUi(QDialog *CriarTipoMensagem)
    {
        CriarTipoMensagem->setWindowTitle(QCoreApplication::translate("CriarTipoMensagem", "Criar Tipo de Mensagem", nullptr));
        label_5->setText(QCoreApplication::translate("CriarTipoMensagem", "Carro", nullptr));
        btnCriarTipoMensagem->setText(QCoreApplication::translate("CriarTipoMensagem", "Criar Tipo de Mensagem", nullptr));
        commandButtonVoltar->setText(QString());
        labelNomeCarro->setText(QCoreApplication::translate("CriarTipoMensagem", "INDEFINIDO", nullptr));
        label_2->setText(QCoreApplication::translate("CriarTipoMensagem", "C\303\263digo Hex: 0x", nullptr));
        label_3->setText(QCoreApplication::translate("CriarTipoMensagem", "Obs:", nullptr));
        label->setText(QCoreApplication::translate("CriarTipoMensagem", "M\303\263dulo:", nullptr));
        labelNomeModulo->setText(QCoreApplication::translate("CriarTipoMensagem", "INDEFINIDO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CriarTipoMensagem: public Ui_CriarTipoMensagem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARTIPOMENSAGEM_H

/********************************************************************************
** Form generated from reading UI file 'criarmodulo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIARMODULO_H
#define UI_CRIARMODULO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriarModulo
{
public:
    QPushButton *btnCriarModulo;
    QPushButton *btnCancelar;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEditNomeModulo;
    QTextEdit *textEditObsModulo;
    QTextEdit *textEditModeloModulo;
    QCommandLinkButton *commandButtonVoltar;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *radioButton_Littleendian;
    QRadioButton *radioButton_Bigendian;
    QComboBox *comboBoxCarro;

    void setupUi(QWidget *CriarModulo)
    {
        if (CriarModulo->objectName().isEmpty())
            CriarModulo->setObjectName("CriarModulo");
        CriarModulo->resize(600, 250);
        CriarModulo->setStyleSheet(QString::fromUtf8("background:white"));
        btnCriarModulo = new QPushButton(CriarModulo);
        btnCriarModulo->setObjectName("btnCriarModulo");
        btnCriarModulo->setGeometry(QRect(10, 190, 121, 41));
        QFont font;
        font.setPointSize(10);
        btnCriarModulo->setFont(font);
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
        btnCancelar = new QPushButton(CriarModulo);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(140, 190, 121, 41));
        btnCancelar->setFont(font);
        btnCancelar->setCursor(QCursor(Qt::PointingHandCursor));
        btnCancelar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label = new QLabel(CriarModulo);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 90, 91, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(CriarModulo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 140, 91, 31));
        label_2->setFont(font1);
        textEditNomeModulo = new QTextEdit(CriarModulo);
        textEditNomeModulo->setObjectName("textEditNomeModulo");
        textEditNomeModulo->setGeometry(QRect(80, 90, 221, 31));
        QFont font2;
        font2.setPointSize(12);
        textEditNomeModulo->setFont(font2);
        textEditNomeModulo->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEditObsModulo = new QTextEdit(CriarModulo);
        textEditObsModulo->setObjectName("textEditObsModulo");
        textEditObsModulo->setGeometry(QRect(320, 30, 251, 121));
        textEditObsModulo->setFont(font2);
        textEditObsModulo->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEditModeloModulo = new QTextEdit(CriarModulo);
        textEditModeloModulo->setObjectName("textEditModeloModulo");
        textEditModeloModulo->setGeometry(QRect(90, 140, 211, 31));
        textEditModeloModulo->setFont(font2);
        textEditModeloModulo->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        commandButtonVoltar = new QCommandLinkButton(CriarModulo);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, 0, 31, 41));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon);
        label_3 = new QLabel(CriarModulo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 0, 91, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(CriarModulo);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 160, 51, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(CriarModulo);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 40, 91, 31));
        label_5->setFont(font1);
        radioButton_Littleendian = new QRadioButton(CriarModulo);
        radioButton_Littleendian->setObjectName("radioButton_Littleendian");
        radioButton_Littleendian->setGeometry(QRect(330, 190, 111, 31));
        radioButton_Littleendian->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_Littleendian->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        radioButton_Littleendian->setChecked(true);
        radioButton_Bigendian = new QRadioButton(CriarModulo);
        radioButton_Bigendian->setObjectName("radioButton_Bigendian");
        radioButton_Bigendian->setGeometry(QRect(460, 190, 131, 31));
        radioButton_Bigendian->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_Bigendian->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        comboBoxCarro = new QComboBox(CriarModulo);
        comboBoxCarro->setObjectName("comboBoxCarro");
        comboBoxCarro->setGeometry(QRect(80, 40, 221, 31));
        comboBoxCarro->setCursor(QCursor(Qt::PointingHandCursor));
        comboBoxCarro->setStyleSheet(QString::fromUtf8("background:white"));

        retranslateUi(CriarModulo);

        QMetaObject::connectSlotsByName(CriarModulo);
    } // setupUi

    void retranslateUi(QWidget *CriarModulo)
    {
        CriarModulo->setWindowTitle(QCoreApplication::translate("CriarModulo", "Form", nullptr));
        btnCriarModulo->setText(QCoreApplication::translate("CriarModulo", "Criar M\303\263dulo", nullptr));
        btnCancelar->setText(QCoreApplication::translate("CriarModulo", "Cancelar", nullptr));
        label->setText(QCoreApplication::translate("CriarModulo", "Nome:", nullptr));
        label_2->setText(QCoreApplication::translate("CriarModulo", "Modelo:", nullptr));
        commandButtonVoltar->setText(QString());
        label_3->setText(QCoreApplication::translate("CriarModulo", "Obs:", nullptr));
        label_4->setText(QCoreApplication::translate("CriarModulo", "Tipo:", nullptr));
        label_5->setText(QCoreApplication::translate("CriarModulo", "Carro:", nullptr));
        radioButton_Littleendian->setText(QCoreApplication::translate("CriarModulo", "Litlle-endian", nullptr));
        radioButton_Bigendian->setText(QCoreApplication::translate("CriarModulo", "Big-Endian", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CriarModulo: public Ui_CriarModulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARMODULO_H
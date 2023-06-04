/********************************************************************************
** Form generated from reading UI file 'tabeladados.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABELADADOS_H
#define UI_TABELADADOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableView *tableViewTabelaDados;
    QCommandLinkButton *commandButtonVoltar;
    QLabel *label_3;
    QLabel *label;
    QLabel *labelNomeCarro;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEditValor;
    QPlainTextEdit *plainTextEditPesquisa;
    QComboBox *comboBoxModulo;
    QComboBox *comboBoxCodigoHEX;
    QComboBox *comboBoxCampo;
    QComboBox *comboBoxCampo2;
    QLabel *label_6;
    QLabel *labelNMensagens;
    QPushButton *btnFiltrar;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(984, 626);
        Form->setStyleSheet(QString::fromUtf8("background:white\n"
""));
        tableViewTabelaDados = new QTableView(Form);
        tableViewTabelaDados->setObjectName("tableViewTabelaDados");
        tableViewTabelaDados->setGeometry(QRect(10, 180, 961, 431));
        commandButtonVoltar = new QCommandLinkButton(Form);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, 0, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon);
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 71, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_3->setFont(font);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 91, 31));
        label->setFont(font);
        labelNomeCarro = new QLabel(Form);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(90, 30, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        labelNomeCarro->setFont(font1);
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 131, 31));
        label_2->setFont(font);
        label_4 = new QLabel(Form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 81, 31));
        label_4->setFont(font);
        label_5 = new QLabel(Form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 140, 81, 31));
        label_5->setFont(font);
        plainTextEditValor = new QPlainTextEdit(Form);
        plainTextEditValor->setObjectName("plainTextEditValor");
        plainTextEditValor->setGeometry(QRect(450, 140, 91, 31));
        plainTextEditPesquisa = new QPlainTextEdit(Form);
        plainTextEditPesquisa->setObjectName("plainTextEditPesquisa");
        plainTextEditPesquisa->setGeometry(QRect(710, 10, 251, 31));
        comboBoxModulo = new QComboBox(Form);
        comboBoxModulo->setObjectName("comboBoxModulo");
        comboBoxModulo->setGeometry(QRect(120, 70, 151, 21));
        comboBoxCodigoHEX = new QComboBox(Form);
        comboBoxCodigoHEX->setObjectName("comboBoxCodigoHEX");
        comboBoxCodigoHEX->setGeometry(QRect(150, 110, 151, 21));
        comboBoxCampo = new QComboBox(Form);
        comboBoxCampo->setObjectName("comboBoxCampo");
        comboBoxCampo->setGeometry(QRect(110, 150, 151, 21));
        comboBoxCampo2 = new QComboBox(Form);
        comboBoxCampo2->setObjectName("comboBoxCampo2");
        comboBoxCampo2->setGeometry(QRect(290, 150, 71, 21));
        label_6 = new QLabel(Form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(720, 140, 191, 31));
        label_6->setFont(font);
        labelNMensagens = new QLabel(Form);
        labelNMensagens->setObjectName("labelNMensagens");
        labelNMensagens->setGeometry(QRect(910, 140, 41, 31));
        labelNMensagens->setFont(font1);
        btnFiltrar = new QPushButton(Form);
        btnFiltrar->setObjectName("btnFiltrar");
        btnFiltrar->setGeometry(QRect(710, 100, 251, 31));
        QFont font2;
        font2.setPointSize(10);
        btnFiltrar->setFont(font2);
        btnFiltrar->setCursor(QCursor(Qt::PointingHandCursor));
        btnFiltrar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        commandButtonVoltar->setText(QString());
        label_3->setText(QCoreApplication::translate("Form", "Carro", nullptr));
        label->setText(QCoreApplication::translate("Form", "M\303\263dulo :", nullptr));
        labelNomeCarro->setText(QCoreApplication::translate("Form", "Carro", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "C\303\263digo HEX:", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Campo:", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Valor:", nullptr));
        plainTextEditPesquisa->setPlainText(QCoreApplication::translate("Form", "Pesquisar", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "N\302\272 de Mensagens:", nullptr));
        labelNMensagens->setText(QCoreApplication::translate("Form", "000", nullptr));
        btnFiltrar->setText(QCoreApplication::translate("Form", "Filtrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABELADADOS_H

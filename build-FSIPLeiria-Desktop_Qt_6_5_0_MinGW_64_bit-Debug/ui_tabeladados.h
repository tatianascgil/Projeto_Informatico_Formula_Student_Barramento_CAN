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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TabelaDados
{
public:
    QTableView *tableViewTabelaDados;
    QPushButton *btnFiltrar;
    QComboBox *comboBoxModulo;
    QComboBox *comboBoxOperador;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *labelNMensagens;
    QLabel *label_2;
    QComboBox *comboBoxCampo;
    QLabel *labelNomeCarro;
    QComboBox *comboBoxCodigoHEX;
    QLabel *label;
    QLabel *label_3;
    QCommandLinkButton *commandButtonVoltar;
    QPlainTextEdit *plainTextEditValor;
    QPushButton *btnGuardar;

    void setupUi(QDialog *TabelaDados)
    {
        if (TabelaDados->objectName().isEmpty())
            TabelaDados->setObjectName("TabelaDados");
        TabelaDados->resize(1000, 700);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        TabelaDados->setWindowIcon(icon);
        TabelaDados->setStyleSheet(QString::fromUtf8("background: white;"));
        tableViewTabelaDados = new QTableView(TabelaDados);
        tableViewTabelaDados->setObjectName("tableViewTabelaDados");
        tableViewTabelaDados->setGeometry(QRect(20, 190, 961, 431));
        QFont font;
        font.setPointSize(10);
        tableViewTabelaDados->setFont(font);
        btnFiltrar = new QPushButton(TabelaDados);
        btnFiltrar->setObjectName("btnFiltrar");
        btnFiltrar->setGeometry(QRect(720, 70, 251, 31));
        btnFiltrar->setFont(font);
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
        comboBoxModulo = new QComboBox(TabelaDados);
        comboBoxModulo->setObjectName("comboBoxModulo");
        comboBoxModulo->setGeometry(QRect(120, 70, 151, 31));
        comboBoxModulo->setFont(font);
        comboBoxModulo->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        comboBoxOperador = new QComboBox(TabelaDados);
        comboBoxOperador->setObjectName("comboBoxOperador");
        comboBoxOperador->setGeometry(QRect(300, 150, 71, 31));
        comboBoxOperador->setFont(font);
        comboBoxOperador->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        label_4 = new QLabel(TabelaDados);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 150, 81, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_4->setFont(font1);
        label_6 = new QLabel(TabelaDados);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(710, 150, 171, 31));
        label_6->setFont(font1);
        label_5 = new QLabel(TabelaDados);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 150, 81, 31));
        label_5->setFont(font1);
        labelNMensagens = new QLabel(TabelaDados);
        labelNMensagens->setObjectName("labelNMensagens");
        labelNMensagens->setGeometry(QRect(880, 150, 101, 31));
        QFont font2;
        font2.setPointSize(14);
        labelNMensagens->setFont(font2);
        label_2 = new QLabel(TabelaDados);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 131, 31));
        label_2->setFont(font1);
        comboBoxCampo = new QComboBox(TabelaDados);
        comboBoxCampo->setObjectName("comboBoxCampo");
        comboBoxCampo->setGeometry(QRect(120, 150, 161, 31));
        comboBoxCampo->setFont(font);
        comboBoxCampo->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        labelNomeCarro = new QLabel(TabelaDados);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(100, 40, 91, 31));
        QFont font3;
        font3.setPointSize(12);
        labelNomeCarro->setFont(font3);
        comboBoxCodigoHEX = new QComboBox(TabelaDados);
        comboBoxCodigoHEX->setObjectName("comboBoxCodigoHEX");
        comboBoxCodigoHEX->setGeometry(QRect(160, 110, 171, 31));
        comboBoxCodigoHEX->setFont(font);
        comboBoxCodigoHEX->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        label = new QLabel(TabelaDados);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 91, 31));
        label->setFont(font1);
        label_3 = new QLabel(TabelaDados);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 40, 71, 31));
        label_3->setFont(font1);
        commandButtonVoltar = new QCommandLinkButton(TabelaDados);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(10, 10, 31, 31));
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
        plainTextEditValor = new QPlainTextEdit(TabelaDados);
        plainTextEditValor->setObjectName("plainTextEditValor");
        plainTextEditValor->setGeometry(QRect(460, 150, 91, 31));
        plainTextEditValor->setFont(font);
        plainTextEditValor->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        btnGuardar = new QPushButton(TabelaDados);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(720, 120, 251, 31));
        btnGuardar->setFont(font);
        btnGuardar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(TabelaDados);

        comboBoxOperador->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TabelaDados);
    } // setupUi

    void retranslateUi(QDialog *TabelaDados)
    {
        TabelaDados->setWindowTitle(QCoreApplication::translate("TabelaDados", "Tabela de Dados", nullptr));
        btnFiltrar->setText(QCoreApplication::translate("TabelaDados", "Filtrar", nullptr));
        comboBoxModulo->setPlaceholderText(QCoreApplication::translate("TabelaDados", "<Selecionar M\303\263dulo>", nullptr));
        comboBoxOperador->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("TabelaDados", "Campo:", nullptr));
        label_6->setText(QCoreApplication::translate("TabelaDados", "N\302\272 de Mensagens:", nullptr));
        label_5->setText(QCoreApplication::translate("TabelaDados", "Valor:", nullptr));
        labelNMensagens->setText(QCoreApplication::translate("TabelaDados", "000", nullptr));
        label_2->setText(QCoreApplication::translate("TabelaDados", "C\303\263digo HEX:", nullptr));
        comboBoxCampo->setPlaceholderText(QCoreApplication::translate("TabelaDados", "<Selecionar Campo>", nullptr));
        labelNomeCarro->setText(QCoreApplication::translate("TabelaDados", "Carro", nullptr));
        comboBoxCodigoHEX->setPlaceholderText(QCoreApplication::translate("TabelaDados", "<Selecionar C\303\263digo Hex>", nullptr));
        label->setText(QCoreApplication::translate("TabelaDados", "M\303\263dulo :", nullptr));
        label_3->setText(QCoreApplication::translate("TabelaDados", "Carro", nullptr));
        commandButtonVoltar->setText(QString());
        btnGuardar->setText(QCoreApplication::translate("TabelaDados", "Guardar Ficheiro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TabelaDados: public Ui_TabelaDados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABELADADOS_H

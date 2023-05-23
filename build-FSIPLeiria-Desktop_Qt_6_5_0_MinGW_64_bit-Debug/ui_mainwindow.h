/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnReadFile;
    QPushButton *btnEstatisticas;
    QComboBox *btnCreateFile;
    QTableView *tableView;
    QPushButton *btnSaveFile;
    QPushButton *btnTempoReal;
    QPushButton *btnTabelaDados;
    QLabel *label;
    QComboBox *comboBoxCarro;
    QPushButton *btnCriarCarro;
    QPushButton *btnVerCarro;
    QPushButton *btnLocalConf;
    QPushButton *btnCarregamentoDados;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(850, 686);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background:white"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnReadFile = new QPushButton(centralwidget);
        btnReadFile->setObjectName("btnReadFile");
        btnReadFile->setGeometry(QRect(620, 130, 201, 51));
        QFont font;
        font.setPointSize(10);
        btnReadFile->setFont(font);
        btnReadFile->setCursor(QCursor(Qt::PointingHandCursor));
        btnReadFile->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnEstatisticas = new QPushButton(centralwidget);
        btnEstatisticas->setObjectName("btnEstatisticas");
        btnEstatisticas->setGeometry(QRect(610, 530, 211, 61));
        btnEstatisticas->setFont(font);
        btnEstatisticas->setCursor(QCursor(Qt::PointingHandCursor));
        btnEstatisticas->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnCreateFile = new QComboBox(centralwidget);
        btnCreateFile->addItem(QString());
        btnCreateFile->addItem(QString());
        btnCreateFile->setObjectName("btnCreateFile");
        btnCreateFile->setGeometry(QRect(620, 0, 201, 61));
        btnCreateFile->setFont(font);
        btnCreateFile->setCursor(QCursor(Qt::PointingHandCursor));
        btnCreateFile->setStyleSheet(QString::fromUtf8("\n"
"	background-color:rgb(255, 245, 166);\n"
"	border:none;\n"
"	color:rgb(95, 91, 61);\n"
"	border -left: 1px solid rgb(162, 155, 105);\n"
"	border -right: 1px solid rgb(162, 155, 105);\n"
"	border -bottom: 5px solid rgb(162, 155, 105);"));
        btnCreateFile->setMaxCount(2147483634);
        btnCreateFile->setDuplicatesEnabled(true);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 10, 581, 241));
        btnSaveFile = new QPushButton(centralwidget);
        btnSaveFile->setObjectName("btnSaveFile");
        btnSaveFile->setEnabled(true);
        btnSaveFile->setGeometry(QRect(620, 70, 201, 51));
        btnSaveFile->setFont(font);
        btnSaveFile->setCursor(QCursor(Qt::PointingHandCursor));
        btnSaveFile->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(125, 216, 133);\n"
"	border:none;\n"
"	color:black;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(99, 171, 105);\n"
"	border-left: 1px solid rgb(75, 130, 80);\n"
"	border-right: 1px solid rgb(75, 130, 80);\n"
"	border-bottom: 5px solid rgb(75, 130, 80);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:rgb(125, 220, 145);\n"
"	border-left: 1px solid rgb(75, 130, 80);\n"
"	border-right: 1px solid rgb(75, 130, 80);\n"
"	border-bottom: 5px solid rgb(75, 130, 80);\n"
"}"));
        btnTempoReal = new QPushButton(centralwidget);
        btnTempoReal->setObjectName("btnTempoReal");
        btnTempoReal->setGeometry(QRect(610, 350, 211, 61));
        btnTempoReal->setFont(font);
        btnTempoReal->setCursor(QCursor(Qt::PointingHandCursor));
        btnTempoReal->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnTabelaDados = new QPushButton(centralwidget);
        btnTabelaDados->setObjectName("btnTabelaDados");
        btnTabelaDados->setGeometry(QRect(610, 260, 211, 61));
        btnTabelaDados->setFont(font);
        btnTabelaDados->setCursor(QCursor(Qt::PointingHandCursor));
        btnTabelaDados->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 340, 251, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        comboBoxCarro = new QComboBox(centralwidget);
        comboBoxCarro->setObjectName("comboBoxCarro");
        comboBoxCarro->setGeometry(QRect(70, 390, 211, 31));
        comboBoxCarro->setCursor(QCursor(Qt::PointingHandCursor));
        comboBoxCarro->setStyleSheet(QString::fromUtf8("background:white"));
        btnCriarCarro = new QPushButton(centralwidget);
        btnCriarCarro->setObjectName("btnCriarCarro");
        btnCriarCarro->setGeometry(QRect(70, 460, 151, 61));
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
        btnVerCarro = new QPushButton(centralwidget);
        btnVerCarro->setObjectName("btnVerCarro");
        btnVerCarro->setGeometry(QRect(240, 460, 161, 61));
        btnVerCarro->setFont(font);
        btnVerCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnVerCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnLocalConf = new QPushButton(centralwidget);
        btnLocalConf->setObjectName("btnLocalConf");
        btnLocalConf->setGeometry(QRect(70, 530, 331, 61));
        btnLocalConf->setFont(font);
        btnLocalConf->setCursor(QCursor(Qt::PointingHandCursor));
        btnLocalConf->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnCarregamentoDados = new QPushButton(centralwidget);
        btnCarregamentoDados->setObjectName("btnCarregamentoDados");
        btnCarregamentoDados->setGeometry(QRect(610, 440, 211, 61));
        btnCarregamentoDados->setFont(font);
        btnCarregamentoDados->setCursor(QCursor(Qt::PointingHandCursor));
        btnCarregamentoDados->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnCreateFile->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FSLeiria", nullptr));
        btnReadFile->setText(QCoreApplication::translate("MainWindow", "Ler ficheiro", nullptr));
        btnEstatisticas->setText(QCoreApplication::translate("MainWindow", "Estat\303\255sticas", nullptr));
        btnCreateFile->setItemText(0, QCoreApplication::translate("MainWindow", "Configurar BD", nullptr));
        btnCreateFile->setItemText(1, QCoreApplication::translate("MainWindow", "Criar Mensagem", nullptr));

        btnCreateFile->setCurrentText(QString());
        btnCreateFile->setPlaceholderText(QCoreApplication::translate("MainWindow", "Configurar", nullptr));
        btnSaveFile->setText(QCoreApplication::translate("MainWindow", "Guardar Ficheiro", nullptr));
        btnTempoReal->setText(QCoreApplication::translate("MainWindow", "Tempo Real", nullptr));
        btnTabelaDados->setText(QCoreApplication::translate("MainWindow", "Tabela de Dados", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Escolha o carro:", nullptr));
        comboBoxCarro->setPlaceholderText(QCoreApplication::translate("MainWindow", "<Selecionar Carro>", nullptr));
        btnCriarCarro->setText(QCoreApplication::translate("MainWindow", "Criar Carro", nullptr));
        btnVerCarro->setText(QCoreApplication::translate("MainWindow", "Ver Dados do Carro", nullptr));
        btnLocalConf->setText(QCoreApplication::translate("MainWindow", "Localiza\303\247\303\243o  das Configura\303\247\303\265es  ", nullptr));
        btnCarregamentoDados->setText(QCoreApplication::translate("MainWindow", "Carregamento de Dados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

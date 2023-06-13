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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnEstatisticas;
    QPushButton *btnTempoReal;
    QPushButton *btnTabelaDados;
    QComboBox *comboBoxCarro;
    QPushButton *btnCriarCarro;
    QPushButton *btnVerCarro;
    QPushButton *btnDuplicarCarro;
    QLabel *label;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_2;
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
        btnEstatisticas = new QPushButton(centralwidget);
        btnEstatisticas->setObjectName("btnEstatisticas");
        btnEstatisticas->setGeometry(QRect(560, 280, 211, 61));
        QFont font;
        font.setPointSize(10);
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
        btnTempoReal = new QPushButton(centralwidget);
        btnTempoReal->setObjectName("btnTempoReal");
        btnTempoReal->setGeometry(QRect(560, 190, 211, 61));
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
        btnTabelaDados->setGeometry(QRect(560, 100, 211, 61));
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
        comboBoxCarro = new QComboBox(centralwidget);
        comboBoxCarro->setObjectName("comboBoxCarro");
        comboBoxCarro->setGeometry(QRect(150, 200, 211, 31));
        comboBoxCarro->setFont(font);
        comboBoxCarro->setCursor(QCursor(Qt::PointingHandCursor));
        comboBoxCarro->setStyleSheet(QString::fromUtf8("background:rgb(234, 234, 234)"));
        btnCriarCarro = new QPushButton(centralwidget);
        btnCriarCarro->setObjectName("btnCriarCarro");
        btnCriarCarro->setGeometry(QRect(320, 550, 191, 61));
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
        btnVerCarro->setEnabled(true);
        btnVerCarro->setGeometry(QRect(290, 280, 161, 61));
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
        btnVerCarro->setCheckable(false);
        btnDuplicarCarro = new QPushButton(centralwidget);
        btnDuplicarCarro->setObjectName("btnDuplicarCarro");
        btnDuplicarCarro->setGeometry(QRect(80, 280, 161, 61));
        btnDuplicarCarro->setFont(font);
        btnDuplicarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnDuplicarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label->setGeometry(QRect(150, 150, 251, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 20, 471, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(-10, 440, 471, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(430, 20, 471, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(450, 440, 471, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 500, 151, 41));
        label_2->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FSLeiria", nullptr));
        btnEstatisticas->setText(QCoreApplication::translate("MainWindow", "Estat\303\255sticas", nullptr));
        btnTempoReal->setText(QCoreApplication::translate("MainWindow", "Tempo Real", nullptr));
        btnTabelaDados->setText(QCoreApplication::translate("MainWindow", "Tabela de Dados", nullptr));
        comboBoxCarro->setPlaceholderText(QCoreApplication::translate("MainWindow", "<Selecionar Carro>", nullptr));
        btnCriarCarro->setText(QCoreApplication::translate("MainWindow", "Criar", nullptr));
        btnVerCarro->setText(QCoreApplication::translate("MainWindow", "Ver Dados do Carro", nullptr));
        btnDuplicarCarro->setText(QCoreApplication::translate("MainWindow", "Duplicar Carro", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Escolha o carro:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cria o teu Carro:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

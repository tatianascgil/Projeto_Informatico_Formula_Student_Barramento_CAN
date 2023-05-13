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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QPushButton *btnStat;
    QComboBox *btnCreateFile;
    QTableView *tableView;
    QPushButton *btnSaveFile;
    QFrame *frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1331, 758);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("background:white"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnReadFile = new QPushButton(centralwidget);
        btnReadFile->setObjectName("btnReadFile");
        btnReadFile->setGeometry(QRect(1000, 0, 141, 61));
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
        btnStat = new QPushButton(centralwidget);
        btnStat->setObjectName("btnStat");
        btnStat->setGeometry(QRect(880, 0, 121, 61));
        btnStat->setCursor(QCursor(Qt::PointingHandCursor));
        btnStat->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnCreateFile->setGeometry(QRect(1130, 0, 141, 61));
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
        tableView->setGeometry(QRect(30, 70, 1271, 561));
        btnSaveFile = new QPushButton(centralwidget);
        btnSaveFile->setObjectName("btnSaveFile");
        btnSaveFile->setEnabled(true);
        btnSaveFile->setGeometry(QRect(1120, 650, 151, 51));
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
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(330, 100, 591, 401));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1331, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnCreateFile->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FSLeiria", nullptr));
        btnReadFile->setText(QCoreApplication::translate("MainWindow", "Ler ficheiro", nullptr));
        btnStat->setText(QCoreApplication::translate("MainWindow", "Estat\303\255sticas", nullptr));
        btnCreateFile->setItemText(0, QCoreApplication::translate("MainWindow", "Configurar BD", nullptr));
        btnCreateFile->setItemText(1, QCoreApplication::translate("MainWindow", "Criar Mensagem", nullptr));

        btnCreateFile->setCurrentText(QCoreApplication::translate("MainWindow", "Configurar BD", nullptr));
        btnCreateFile->setPlaceholderText(QCoreApplication::translate("MainWindow", "Configurar", nullptr));
        btnSaveFile->setText(QCoreApplication::translate("MainWindow", "Guardar Ficheiro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

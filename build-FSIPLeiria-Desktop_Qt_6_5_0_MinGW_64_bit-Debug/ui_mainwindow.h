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
    QPushButton *btnMenu;
    QPushButton *btnStat;
    QComboBox *btnCreateFile;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1325, 710);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnReadFile = new QPushButton(centralwidget);
        btnReadFile->setObjectName("btnReadFile");
        btnReadFile->setGeometry(QRect(910, 0, 171, 61));
        btnReadFile->setCursor(QCursor(Qt::PointingHandCursor));
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(10, 0, 151, 61));
        btnMenu->setCursor(QCursor(Qt::PointingHandCursor));
        btnStat = new QPushButton(centralwidget);
        btnStat->setObjectName("btnStat");
        btnStat->setGeometry(QRect(160, 0, 161, 61));
        btnStat->setCursor(QCursor(Qt::PointingHandCursor));
        btnCreateFile = new QComboBox(centralwidget);
        btnCreateFile->addItem(QString());
        btnCreateFile->addItem(QString());
        btnCreateFile->setObjectName("btnCreateFile");
        btnCreateFile->setGeometry(QRect(1130, 0, 141, 61));
        btnCreateFile->setStyleSheet(QString::fromUtf8("text-align:center"));
        btnCreateFile->setDuplicatesEnabled(true);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 80, 1241, 561));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1325, 21));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnReadFile->setText(QCoreApplication::translate("MainWindow", "Ler ficheiro", nullptr));
        btnMenu->setText(QCoreApplication::translate("MainWindow", "Menu Principal", nullptr));
        btnStat->setText(QCoreApplication::translate("MainWindow", "Estat\303\255sticas", nullptr));
        btnCreateFile->setItemText(0, QCoreApplication::translate("MainWindow", "Criar M\303\263dulo", nullptr));
        btnCreateFile->setItemText(1, QCoreApplication::translate("MainWindow", "Criar Mensagem", nullptr));

        btnCreateFile->setPlaceholderText(QCoreApplication::translate("MainWindow", "          Criar Ficheiro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

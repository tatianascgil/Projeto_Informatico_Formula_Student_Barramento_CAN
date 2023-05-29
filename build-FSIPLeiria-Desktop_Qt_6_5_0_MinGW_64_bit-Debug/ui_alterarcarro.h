/********************************************************************************
** Form generated from reading UI file 'alterarcarro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERARCARRO_H
#define UI_ALTERARCARRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlterarCarro
{
public:
    QCommandLinkButton *commandButtonVoltar;
    QTableView *tableViewModulosCarro;
    QLabel *label_2;

    void setupUi(QWidget *AlterarCarro)
    {
        if (AlterarCarro->objectName().isEmpty())
            AlterarCarro->setObjectName("AlterarCarro");
        AlterarCarro->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AlterarCarro->setWindowIcon(icon);
        AlterarCarro->setStyleSheet(QString::fromUtf8("background:white"));
        commandButtonVoltar = new QCommandLinkButton(AlterarCarro);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, 0, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        tableViewModulosCarro = new QTableView(AlterarCarro);
        tableViewModulosCarro->setObjectName("tableViewModulosCarro");
        tableViewModulosCarro->setGeometry(QRect(10, 110, 771, 311));
        label_2 = new QLabel(AlterarCarro);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 261, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_2->setFont(font);

        retranslateUi(AlterarCarro);

        QMetaObject::connectSlotsByName(AlterarCarro);
    } // setupUi

    void retranslateUi(QWidget *AlterarCarro)
    {
        AlterarCarro->setWindowTitle(QCoreApplication::translate("AlterarCarro", "Alterar de Carro", nullptr));
        commandButtonVoltar->setText(QString());
        label_2->setText(QCoreApplication::translate("AlterarCarro", "Selecionar Carro:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlterarCarro: public Ui_AlterarCarro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERARCARRO_H

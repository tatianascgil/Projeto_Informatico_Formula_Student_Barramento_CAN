/********************************************************************************
** Form generated from reading UI file 'estatisticas.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTATISTICAS_H
#define UI_ESTATISTICAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estatisticas
{
public:
    QCommandLinkButton *commandButtonVoltar;

    void setupUi(QWidget *Estatisticas)
    {
        if (Estatisticas->objectName().isEmpty())
            Estatisticas->setObjectName("Estatisticas");
        Estatisticas->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Estatisticas->setWindowIcon(icon);
        Estatisticas->setStyleSheet(QString::fromUtf8("background:white"));
        commandButtonVoltar = new QCommandLinkButton(Estatisticas);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, -10, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);

        retranslateUi(Estatisticas);

        QMetaObject::connectSlotsByName(Estatisticas);
    } // setupUi

    void retranslateUi(QWidget *Estatisticas)
    {
        Estatisticas->setWindowTitle(QCoreApplication::translate("Estatisticas", "Estat\303\255stica", nullptr));
        commandButtonVoltar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Estatisticas: public Ui_Estatisticas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTATISTICAS_H

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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CriarTipoMensagem
{
public:

    void setupUi(QDialog *CriarTipoMensagem)
    {
        if (CriarTipoMensagem->objectName().isEmpty())
            CriarTipoMensagem->setObjectName("CriarTipoMensagem");
        CriarTipoMensagem->resize(733, 333);

        retranslateUi(CriarTipoMensagem);

        QMetaObject::connectSlotsByName(CriarTipoMensagem);
    } // setupUi

    void retranslateUi(QDialog *CriarTipoMensagem)
    {
        CriarTipoMensagem->setWindowTitle(QCoreApplication::translate("CriarTipoMensagem", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CriarTipoMensagem: public Ui_CriarTipoMensagem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARTIPOMENSAGEM_H

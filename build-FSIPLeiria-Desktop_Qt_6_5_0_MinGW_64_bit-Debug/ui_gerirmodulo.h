/********************************************************************************
** Form generated from reading UI file 'gerirmodulo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERIRMODULO_H
#define UI_GERIRMODULO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_GerirModulo
{
public:
    QTableView *tableViewTipodeMensagemModulo;
    QCommandLinkButton *commandButtonVoltar;
    QPushButton *btnApagarModulo;
    QFrame *line;
    QLabel *label;
    QTableView *tableViewModulo;
    QPushButton *btnGuardarModulo;
    QLabel *labelNomeModulo;
    QLabel *label_2;
    QPushButton *btnCriarTipoMensagem;

    void setupUi(QDialog *GerirModulo)
    {
        if (GerirModulo->objectName().isEmpty())
            GerirModulo->setObjectName("GerirModulo");
        GerirModulo->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GerirModulo->setWindowIcon(icon);
        GerirModulo->setStyleSheet(QString::fromUtf8("background:white\n"
""));
        tableViewTipodeMensagemModulo = new QTableView(GerirModulo);
        tableViewTipodeMensagemModulo->setObjectName("tableViewTipodeMensagemModulo");
        tableViewTipodeMensagemModulo->setGeometry(QRect(20, 250, 761, 191));
        commandButtonVoltar = new QCommandLinkButton(GerirModulo);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, -10, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        btnApagarModulo = new QPushButton(GerirModulo);
        btnApagarModulo->setObjectName("btnApagarModulo");
        btnApagarModulo->setGeometry(QRect(500, 140, 141, 41));
        QFont font;
        font.setPointSize(10);
        btnApagarModulo->setFont(font);
        btnApagarModulo->setCursor(QCursor(Qt::PointingHandCursor));
        btnApagarModulo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        line = new QFrame(GerirModulo);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 190, 791, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(GerirModulo);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 111, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        tableViewModulo = new QTableView(GerirModulo);
        tableViewModulo->setObjectName("tableViewModulo");
        tableViewModulo->setGeometry(QRect(20, 60, 761, 61));
        btnGuardarModulo = new QPushButton(GerirModulo);
        btnGuardarModulo->setObjectName("btnGuardarModulo");
        btnGuardarModulo->setGeometry(QRect(650, 140, 121, 41));
        btnGuardarModulo->setFont(font);
        btnGuardarModulo->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardarModulo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        labelNomeModulo = new QLabel(GerirModulo);
        labelNomeModulo->setObjectName("labelNomeModulo");
        labelNomeModulo->setGeometry(QRect(140, 20, 211, 31));
        QFont font2;
        font2.setPointSize(16);
        labelNomeModulo->setFont(font2);
        label_2 = new QLabel(GerirModulo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 210, 441, 31));
        label_2->setFont(font1);
        btnCriarTipoMensagem = new QPushButton(GerirModulo);
        btnCriarTipoMensagem->setObjectName("btnCriarTipoMensagem");
        btnCriarTipoMensagem->setGeometry(QRect(520, 450, 251, 41));
        btnCriarTipoMensagem->setFont(font);
        btnCriarTipoMensagem->setCursor(QCursor(Qt::PointingHandCursor));
        btnCriarTipoMensagem->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(GerirModulo);

        QMetaObject::connectSlotsByName(GerirModulo);
    } // setupUi

    void retranslateUi(QDialog *GerirModulo)
    {
        GerirModulo->setWindowTitle(QCoreApplication::translate("GerirModulo", "Gerir M\303\263dulo", nullptr));
        commandButtonVoltar->setText(QString());
        btnApagarModulo->setText(QCoreApplication::translate("GerirModulo", "Apagar M\303\263dulo", nullptr));
        label->setText(QCoreApplication::translate("GerirModulo", "M\303\263dulo", nullptr));
        btnGuardarModulo->setText(QCoreApplication::translate("GerirModulo", "Guardar", nullptr));
        labelNomeModulo->setText(QCoreApplication::translate("GerirModulo", "modulo xpto", nullptr));
        label_2->setText(QCoreApplication::translate("GerirModulo", "Tipo de Mensagem deste M\303\263dulo:", nullptr));
        btnCriarTipoMensagem->setText(QCoreApplication::translate("GerirModulo", "Criar Tipo de Mensagem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerirModulo: public Ui_GerirModulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERIRMODULO_H
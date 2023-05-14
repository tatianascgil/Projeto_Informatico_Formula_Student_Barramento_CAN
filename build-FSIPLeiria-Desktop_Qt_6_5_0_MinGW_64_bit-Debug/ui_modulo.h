/********************************************************************************
** Form generated from reading UI file 'modulo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULO_H
#define UI_MODULO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Modulo
{
public:
    QTableView *tableView;
    QCommandLinkButton *commandLinkButton;
    QPushButton *pushButton;
    QTextEdit *textEditNomeModulo;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *label1;
    QTextEdit *textEdit_Nome1;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit_Offset1;
    QTextEdit *textEdit_Fator1;
    QTextEdit *textEdit_Unidade1;
    QSpinBox *spinBox_Inicial1;
    QSpinBox *spinBox_Final1;
    QTextEdit *textEdit_Unidade2;
    QLabel *label2;
    QTextEdit *textEdit_Nome2;
    QSpinBox *spinBox_Final2;
    QTextEdit *textEdit_Offset2;
    QSpinBox *spinBox_Inicial2;
    QTextEdit *textEdit_Fator2;
    QTextEdit *textEdit_Unidade3;
    QLabel *label3;
    QTextEdit *textEdit_Nome3;
    QSpinBox *spinBox_Final3;
    QTextEdit *textEdit_Offset3;
    QSpinBox *spinBox_Inicial3;
    QTextEdit *textEdit_Fator3;
    QLabel *label6;
    QTextEdit *textEdit_Nome5;
    QTextEdit *textEdit_Unidade4;
    QSpinBox *spinBox_Inicial5;
    QLabel *label4;
    QTextEdit *textEdit_Offset6;
    QTextEdit *textEdit_Offset5;
    QTextEdit *textEdit_Fator5;
    QTextEdit *textEdit_Unidade5;
    QTextEdit *textEdit_Nome6;
    QLabel *label5;
    QTextEdit *textEdit_Fator6;
    QTextEdit *textEdit_Nome4;
    QSpinBox *spinBox_Final4;
    QTextEdit *textEdit_Offset4;
    QSpinBox *spinBox_Final6;
    QTextEdit *textEdit_Unidade6;
    QSpinBox *spinBox_Inicial4;
    QSpinBox *spinBox_Final5;
    QSpinBox *spinBox_Inicial6;
    QTextEdit *textEdit_Fator4;
    QSpinBox *spinBox_Inicial8;
    QTextEdit *textEdit_Fator8;
    QSpinBox *spinBox_Final8;
    QSpinBox *spinBox_Final7;
    QLabel *label8;
    QTextEdit *textEdit_Offset8;
    QSpinBox *spinBox_Inicial7;
    QTextEdit *textEdit_Fator7;
    QTextEdit *textEdit_Nome8;
    QTextEdit *textEdit_Unidade7;
    QTextEdit *textEdit_Unidade8;
    QTextEdit *textEdit_Nome7;
    QTextEdit *textEdit_Offset7;
    QLabel *label7;
    QLabel *label_15;
    QLabel *label_16;
    QRadioButton *radioButton_Bigendian;
    QRadioButton *radioButton_Littleendian;
    QLabel *label_17;
    QLabel *label_4;
    QTextEdit *textEditNModeloMensagem;

    void setupUi(QDialog *Modulo)
    {
        if (Modulo->objectName().isEmpty())
            Modulo->setObjectName("Modulo");
        Modulo->resize(1344, 556);
        Modulo->setLayoutDirection(Qt::LeftToRight);
        Modulo->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        tableView = new QTableView(Modulo);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(700, 60, 631, 471));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        commandLinkButton = new QCommandLinkButton(Modulo);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(1310, -10, 31, 41));
        commandLinkButton->setLayoutDirection(Qt::LeftToRight);
        commandLinkButton->setStyleSheet(QString::fromUtf8("QPushButton{border:none;}"));
        commandLinkButton->setIconSize(QSize(30, 30));
        commandLinkButton->setAutoDefault(true);
        commandLinkButton->setDefault(false);
        pushButton = new QPushButton(Modulo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(540, 480, 131, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(255, 245, 166);\n"
"	border:none;\n"
"	color:rgb(95, 91, 61);\n"
"	border -left: 1px solid rgb(162, 155, 105);\n"
"	border -right: 1px solid rgb(162, 155, 105);\n"
"	border -bottom: 5px solid rgb(162, 155, 105)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(229, 217, 150);\n"
"	border-left: 1px solid rgb(162, 155, 105);\n"
"	border-right: 1px solid rgb(162, 155, 105);\n"
"	border-bottom: 5px solid rgb(162, 155, 105)\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:rgb(255, 242, 165);\n"
"	border-left: 1px solid rgb(162, 155, 105);\n"
"	border-right: 1px solid rgb(162, 155, 105);\n"
"	border-bottom: 5px solid rgb(162, 155, 105)\n"
"}"));
        textEditNomeModulo = new QTextEdit(Modulo);
        textEditNomeModulo->setObjectName("textEditNomeModulo");
        textEditNomeModulo->setGeometry(QRect(120, 20, 261, 31));
        textEditNomeModulo->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label = new QLabel(Modulo);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 101, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        spinBox = new QSpinBox(Modulo);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(150, 110, 91, 21));
        spinBox->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox->setMaximum(8);
        label_2 = new QLabel(Modulo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 110, 121, 21));
        label_3 = new QLabel(Modulo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 70, 101, 31));
        label_3->setCursor(QCursor(Qt::ForbiddenCursor));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";"));
        label_3->setScaledContents(false);
        label_3->setOpenExternalLinks(false);
        line = new QFrame(Modulo);
        line->setObjectName("line");
        line->setGeometry(QRect(390, 80, 281, 20));
        line->setCursor(QCursor(Qt::ForbiddenCursor));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Modulo);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 80, 261, 16));
        line_2->setCursor(QCursor(Qt::ForbiddenCursor));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label1 = new QLabel(Modulo);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(40, 150, 51, 21));
        textEdit_Nome1 = new QTextEdit(Modulo);
        textEdit_Nome1->setObjectName("textEdit_Nome1");
        textEdit_Nome1->setEnabled(true);
        textEdit_Nome1->setGeometry(QRect(90, 150, 191, 31));
        textEdit_Nome1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_5 = new QLabel(Modulo);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 120, 51, 21));
        label_6 = new QLabel(Modulo);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(540, 120, 51, 21));
        label_7 = new QLabel(Modulo);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(610, 120, 51, 21));
        textEdit_Offset1 = new QTextEdit(Modulo);
        textEdit_Offset1->setObjectName("textEdit_Offset1");
        textEdit_Offset1->setGeometry(QRect(470, 150, 51, 31));
        textEdit_Offset1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Fator1 = new QTextEdit(Modulo);
        textEdit_Fator1->setObjectName("textEdit_Fator1");
        textEdit_Fator1->setGeometry(QRect(540, 150, 51, 31));
        textEdit_Fator1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade1 = new QTextEdit(Modulo);
        textEdit_Unidade1->setObjectName("textEdit_Unidade1");
        textEdit_Unidade1->setGeometry(QRect(610, 150, 51, 31));
        textEdit_Unidade1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial1 = new QSpinBox(Modulo);
        spinBox_Inicial1->setObjectName("spinBox_Inicial1");
        spinBox_Inicial1->setGeometry(QRect(310, 150, 51, 31));
        spinBox_Inicial1->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial1->setMinimum(0);
        spinBox_Inicial1->setMaximum(7);
        spinBox_Inicial1->setSingleStep(1);
        spinBox_Inicial1->setValue(0);
        spinBox_Inicial1->setDisplayIntegerBase(7);
        spinBox_Final1 = new QSpinBox(Modulo);
        spinBox_Final1->setObjectName("spinBox_Final1");
        spinBox_Final1->setGeometry(QRect(390, 150, 51, 31));
        spinBox_Final1->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final1->setMinimum(0);
        spinBox_Final1->setMaximum(7);
        spinBox_Final1->setSingleStep(1);
        spinBox_Final1->setValue(0);
        textEdit_Unidade2 = new QTextEdit(Modulo);
        textEdit_Unidade2->setObjectName("textEdit_Unidade2");
        textEdit_Unidade2->setGeometry(QRect(610, 190, 51, 31));
        textEdit_Unidade2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label2 = new QLabel(Modulo);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(40, 190, 51, 21));
        textEdit_Nome2 = new QTextEdit(Modulo);
        textEdit_Nome2->setObjectName("textEdit_Nome2");
        textEdit_Nome2->setGeometry(QRect(90, 190, 191, 31));
        textEdit_Nome2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Final2 = new QSpinBox(Modulo);
        spinBox_Final2->setObjectName("spinBox_Final2");
        spinBox_Final2->setGeometry(QRect(390, 190, 51, 31));
        spinBox_Final2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final2->setMinimum(0);
        spinBox_Final2->setMaximum(7);
        spinBox_Final2->setSingleStep(1);
        spinBox_Final2->setValue(0);
        textEdit_Offset2 = new QTextEdit(Modulo);
        textEdit_Offset2->setObjectName("textEdit_Offset2");
        textEdit_Offset2->setGeometry(QRect(470, 190, 51, 31));
        textEdit_Offset2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial2 = new QSpinBox(Modulo);
        spinBox_Inicial2->setObjectName("spinBox_Inicial2");
        spinBox_Inicial2->setGeometry(QRect(310, 190, 51, 31));
        spinBox_Inicial2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial2->setMinimum(0);
        spinBox_Inicial2->setMaximum(7);
        spinBox_Inicial2->setValue(0);
        textEdit_Fator2 = new QTextEdit(Modulo);
        textEdit_Fator2->setObjectName("textEdit_Fator2");
        textEdit_Fator2->setGeometry(QRect(540, 190, 51, 31));
        textEdit_Fator2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade3 = new QTextEdit(Modulo);
        textEdit_Unidade3->setObjectName("textEdit_Unidade3");
        textEdit_Unidade3->setGeometry(QRect(610, 230, 51, 31));
        textEdit_Unidade3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label3 = new QLabel(Modulo);
        label3->setObjectName("label3");
        label3->setGeometry(QRect(40, 230, 51, 21));
        textEdit_Nome3 = new QTextEdit(Modulo);
        textEdit_Nome3->setObjectName("textEdit_Nome3");
        textEdit_Nome3->setEnabled(true);
        textEdit_Nome3->setGeometry(QRect(90, 230, 191, 31));
        textEdit_Nome3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Final3 = new QSpinBox(Modulo);
        spinBox_Final3->setObjectName("spinBox_Final3");
        spinBox_Final3->setGeometry(QRect(390, 230, 51, 31));
        spinBox_Final3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final3->setMinimum(0);
        spinBox_Final3->setMaximum(7);
        spinBox_Final3->setSingleStep(1);
        spinBox_Final3->setValue(0);
        textEdit_Offset3 = new QTextEdit(Modulo);
        textEdit_Offset3->setObjectName("textEdit_Offset3");
        textEdit_Offset3->setGeometry(QRect(470, 230, 51, 31));
        textEdit_Offset3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial3 = new QSpinBox(Modulo);
        spinBox_Inicial3->setObjectName("spinBox_Inicial3");
        spinBox_Inicial3->setGeometry(QRect(310, 230, 51, 31));
        spinBox_Inicial3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial3->setMinimum(0);
        spinBox_Inicial3->setMaximum(7);
        spinBox_Inicial3->setValue(0);
        textEdit_Fator3 = new QTextEdit(Modulo);
        textEdit_Fator3->setObjectName("textEdit_Fator3");
        textEdit_Fator3->setGeometry(QRect(540, 230, 51, 31));
        textEdit_Fator3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label6 = new QLabel(Modulo);
        label6->setObjectName("label6");
        label6->setGeometry(QRect(40, 350, 51, 21));
        textEdit_Nome5 = new QTextEdit(Modulo);
        textEdit_Nome5->setObjectName("textEdit_Nome5");
        textEdit_Nome5->setGeometry(QRect(90, 310, 191, 31));
        textEdit_Nome5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade4 = new QTextEdit(Modulo);
        textEdit_Unidade4->setObjectName("textEdit_Unidade4");
        textEdit_Unidade4->setGeometry(QRect(610, 270, 51, 31));
        textEdit_Unidade4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial5 = new QSpinBox(Modulo);
        spinBox_Inicial5->setObjectName("spinBox_Inicial5");
        spinBox_Inicial5->setGeometry(QRect(310, 310, 51, 31));
        spinBox_Inicial5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial5->setMinimum(0);
        spinBox_Inicial5->setMaximum(7);
        spinBox_Inicial5->setSingleStep(1);
        spinBox_Inicial5->setValue(0);
        label4 = new QLabel(Modulo);
        label4->setObjectName("label4");
        label4->setGeometry(QRect(40, 270, 51, 21));
        textEdit_Offset6 = new QTextEdit(Modulo);
        textEdit_Offset6->setObjectName("textEdit_Offset6");
        textEdit_Offset6->setGeometry(QRect(470, 350, 51, 31));
        textEdit_Offset6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Offset5 = new QTextEdit(Modulo);
        textEdit_Offset5->setObjectName("textEdit_Offset5");
        textEdit_Offset5->setGeometry(QRect(470, 310, 51, 31));
        textEdit_Offset5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Fator5 = new QTextEdit(Modulo);
        textEdit_Fator5->setObjectName("textEdit_Fator5");
        textEdit_Fator5->setGeometry(QRect(540, 310, 51, 31));
        textEdit_Fator5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade5 = new QTextEdit(Modulo);
        textEdit_Unidade5->setObjectName("textEdit_Unidade5");
        textEdit_Unidade5->setGeometry(QRect(610, 310, 51, 31));
        textEdit_Unidade5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome6 = new QTextEdit(Modulo);
        textEdit_Nome6->setObjectName("textEdit_Nome6");
        textEdit_Nome6->setGeometry(QRect(90, 350, 191, 31));
        textEdit_Nome6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label5 = new QLabel(Modulo);
        label5->setObjectName("label5");
        label5->setGeometry(QRect(40, 310, 41, 21));
        textEdit_Fator6 = new QTextEdit(Modulo);
        textEdit_Fator6->setObjectName("textEdit_Fator6");
        textEdit_Fator6->setGeometry(QRect(540, 350, 51, 31));
        textEdit_Fator6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome4 = new QTextEdit(Modulo);
        textEdit_Nome4->setObjectName("textEdit_Nome4");
        textEdit_Nome4->setGeometry(QRect(90, 270, 191, 31));
        textEdit_Nome4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Final4 = new QSpinBox(Modulo);
        spinBox_Final4->setObjectName("spinBox_Final4");
        spinBox_Final4->setGeometry(QRect(390, 270, 51, 31));
        spinBox_Final4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final4->setMinimum(0);
        spinBox_Final4->setMaximum(7);
        spinBox_Final4->setSingleStep(1);
        spinBox_Final4->setValue(0);
        spinBox_Final4->setDisplayIntegerBase(10);
        textEdit_Offset4 = new QTextEdit(Modulo);
        textEdit_Offset4->setObjectName("textEdit_Offset4");
        textEdit_Offset4->setGeometry(QRect(470, 270, 51, 31));
        textEdit_Offset4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Final6 = new QSpinBox(Modulo);
        spinBox_Final6->setObjectName("spinBox_Final6");
        spinBox_Final6->setGeometry(QRect(390, 350, 51, 31));
        spinBox_Final6->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final6->setMinimum(0);
        spinBox_Final6->setMaximum(7);
        spinBox_Final6->setValue(0);
        textEdit_Unidade6 = new QTextEdit(Modulo);
        textEdit_Unidade6->setObjectName("textEdit_Unidade6");
        textEdit_Unidade6->setGeometry(QRect(610, 350, 51, 31));
        textEdit_Unidade6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial4 = new QSpinBox(Modulo);
        spinBox_Inicial4->setObjectName("spinBox_Inicial4");
        spinBox_Inicial4->setGeometry(QRect(310, 270, 51, 31));
        spinBox_Inicial4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial4->setMinimum(0);
        spinBox_Inicial4->setMaximum(7);
        spinBox_Inicial4->setSingleStep(1);
        spinBox_Inicial4->setValue(0);
        spinBox_Final5 = new QSpinBox(Modulo);
        spinBox_Final5->setObjectName("spinBox_Final5");
        spinBox_Final5->setGeometry(QRect(390, 310, 51, 31));
        spinBox_Final5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final5->setMinimum(0);
        spinBox_Final5->setMaximum(7);
        spinBox_Final5->setValue(0);
        spinBox_Inicial6 = new QSpinBox(Modulo);
        spinBox_Inicial6->setObjectName("spinBox_Inicial6");
        spinBox_Inicial6->setGeometry(QRect(310, 350, 51, 31));
        spinBox_Inicial6->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial6->setMinimum(0);
        spinBox_Inicial6->setMaximum(7);
        spinBox_Inicial6->setValue(0);
        textEdit_Fator4 = new QTextEdit(Modulo);
        textEdit_Fator4->setObjectName("textEdit_Fator4");
        textEdit_Fator4->setGeometry(QRect(540, 270, 51, 31));
        textEdit_Fator4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial8 = new QSpinBox(Modulo);
        spinBox_Inicial8->setObjectName("spinBox_Inicial8");
        spinBox_Inicial8->setGeometry(QRect(310, 430, 51, 31));
        spinBox_Inicial8->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial8->setMinimum(0);
        spinBox_Inicial8->setMaximum(7);
        spinBox_Inicial8->setValue(0);
        textEdit_Fator8 = new QTextEdit(Modulo);
        textEdit_Fator8->setObjectName("textEdit_Fator8");
        textEdit_Fator8->setGeometry(QRect(540, 430, 51, 31));
        textEdit_Fator8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Final8 = new QSpinBox(Modulo);
        spinBox_Final8->setObjectName("spinBox_Final8");
        spinBox_Final8->setGeometry(QRect(390, 430, 51, 31));
        spinBox_Final8->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final8->setMinimum(0);
        spinBox_Final8->setMaximum(7);
        spinBox_Final8->setSingleStep(1);
        spinBox_Final8->setStepType(QAbstractSpinBox::DefaultStepType);
        spinBox_Final8->setValue(0);
        spinBox_Final8->setDisplayIntegerBase(10);
        spinBox_Final7 = new QSpinBox(Modulo);
        spinBox_Final7->setObjectName("spinBox_Final7");
        spinBox_Final7->setGeometry(QRect(390, 390, 51, 31));
        spinBox_Final7->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final7->setMinimum(0);
        spinBox_Final7->setMaximum(7);
        spinBox_Final7->setValue(0);
        label8 = new QLabel(Modulo);
        label8->setObjectName("label8");
        label8->setGeometry(QRect(40, 430, 51, 21));
        textEdit_Offset8 = new QTextEdit(Modulo);
        textEdit_Offset8->setObjectName("textEdit_Offset8");
        textEdit_Offset8->setGeometry(QRect(470, 430, 51, 31));
        textEdit_Offset8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_Inicial7 = new QSpinBox(Modulo);
        spinBox_Inicial7->setObjectName("spinBox_Inicial7");
        spinBox_Inicial7->setGeometry(QRect(310, 390, 51, 31));
        spinBox_Inicial7->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial7->setMinimum(0);
        spinBox_Inicial7->setMaximum(7);
        spinBox_Inicial7->setValue(0);
        textEdit_Fator7 = new QTextEdit(Modulo);
        textEdit_Fator7->setObjectName("textEdit_Fator7");
        textEdit_Fator7->setGeometry(QRect(540, 390, 51, 31));
        textEdit_Fator7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome8 = new QTextEdit(Modulo);
        textEdit_Nome8->setObjectName("textEdit_Nome8");
        textEdit_Nome8->setGeometry(QRect(90, 430, 191, 31));
        textEdit_Nome8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade7 = new QTextEdit(Modulo);
        textEdit_Unidade7->setObjectName("textEdit_Unidade7");
        textEdit_Unidade7->setGeometry(QRect(610, 390, 51, 31));
        textEdit_Unidade7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade8 = new QTextEdit(Modulo);
        textEdit_Unidade8->setObjectName("textEdit_Unidade8");
        textEdit_Unidade8->setGeometry(QRect(610, 430, 51, 31));
        textEdit_Unidade8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome7 = new QTextEdit(Modulo);
        textEdit_Nome7->setObjectName("textEdit_Nome7");
        textEdit_Nome7->setGeometry(QRect(90, 390, 191, 31));
        textEdit_Nome7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Offset7 = new QTextEdit(Modulo);
        textEdit_Offset7->setObjectName("textEdit_Offset7");
        textEdit_Offset7->setGeometry(QRect(470, 390, 51, 31));
        textEdit_Offset7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label7 = new QLabel(Modulo);
        label7->setObjectName("label7");
        label7->setGeometry(QRect(40, 390, 41, 21));
        label_15 = new QLabel(Modulo);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(300, 120, 71, 21));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_16 = new QLabel(Modulo);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(380, 120, 71, 21));
        radioButton_Bigendian = new QRadioButton(Modulo);
        radioButton_Bigendian->setObjectName("radioButton_Bigendian");
        radioButton_Bigendian->setGeometry(QRect(230, 480, 131, 31));
        radioButton_Bigendian->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_Bigendian->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        radioButton_Littleendian = new QRadioButton(Modulo);
        radioButton_Littleendian->setObjectName("radioButton_Littleendian");
        radioButton_Littleendian->setGeometry(QRect(100, 480, 111, 31));
        radioButton_Littleendian->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_Littleendian->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        radioButton_Littleendian->setChecked(true);
        label_17 = new QLabel(Modulo);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 480, 51, 21));
        label_4 = new QLabel(Modulo);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 20, 141, 31));
        label_4->setFont(font);
        textEditNModeloMensagem = new QTextEdit(Modulo);
        textEditNModeloMensagem->setObjectName("textEditNModeloMensagem");
        textEditNModeloMensagem->setGeometry(QRect(560, 20, 101, 31));
        textEditNModeloMensagem->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        tableView->raise();
        commandLinkButton->raise();
        pushButton->raise();
        label->raise();
        spinBox->raise();
        label_2->raise();
        label_3->raise();
        line->raise();
        line_2->raise();
        label1->raise();
        textEdit_Nome1->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        textEdit_Offset1->raise();
        textEdit_Fator1->raise();
        textEdit_Unidade1->raise();
        textEdit_Unidade2->raise();
        label2->raise();
        textEdit_Nome2->raise();
        textEdit_Offset2->raise();
        textEdit_Fator2->raise();
        textEdit_Unidade3->raise();
        label3->raise();
        textEdit_Nome3->raise();
        textEdit_Offset3->raise();
        textEdit_Fator3->raise();
        label6->raise();
        textEdit_Nome5->raise();
        textEdit_Unidade4->raise();
        label4->raise();
        textEdit_Offset6->raise();
        textEdit_Offset5->raise();
        textEdit_Fator5->raise();
        textEdit_Unidade5->raise();
        textEdit_Nome6->raise();
        label5->raise();
        textEdit_Fator6->raise();
        textEdit_Nome4->raise();
        textEdit_Offset4->raise();
        textEdit_Unidade6->raise();
        textEdit_Fator4->raise();
        textEdit_Fator8->raise();
        label8->raise();
        textEdit_Offset8->raise();
        textEdit_Fator7->raise();
        textEdit_Nome8->raise();
        textEdit_Unidade7->raise();
        textEdit_Unidade8->raise();
        textEdit_Nome7->raise();
        textEdit_Offset7->raise();
        label7->raise();
        label_15->raise();
        label_16->raise();
        radioButton_Bigendian->raise();
        radioButton_Littleendian->raise();
        label_17->raise();
        spinBox_Inicial7->raise();
        spinBox_Inicial6->raise();
        spinBox_Inicial2->raise();
        spinBox_Inicial8->raise();
        spinBox_Final6->raise();
        spinBox_Final5->raise();
        spinBox_Inicial5->raise();
        spinBox_Inicial4->raise();
        spinBox_Final8->raise();
        spinBox_Final4->raise();
        spinBox_Final1->raise();
        spinBox_Final3->raise();
        spinBox_Final7->raise();
        spinBox_Inicial1->raise();
        spinBox_Final2->raise();
        spinBox_Inicial3->raise();
        textEditNomeModulo->raise();
        label_4->raise();
        textEditNModeloMensagem->raise();

        retranslateUi(Modulo);

        QMetaObject::connectSlotsByName(Modulo);
    } // setupUi

    void retranslateUi(QDialog *Modulo)
    {
        Modulo->setWindowTitle(QCoreApplication::translate("Modulo", "Modulo", nullptr));
        commandLinkButton->setText(QString());
        pushButton->setText(QCoreApplication::translate("Modulo", "Criar", nullptr));
        label->setText(QCoreApplication::translate("Modulo", "Nome Modulo:*", nullptr));
        label_2->setText(QCoreApplication::translate("Modulo", "Numero de campos:*", nullptr));
        label_3->setText(QCoreApplication::translate("Modulo", "Mensagem", nullptr));
        label1->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_5->setText(QCoreApplication::translate("Modulo", "Offset:", nullptr));
        label_6->setText(QCoreApplication::translate("Modulo", "Fator:", nullptr));
        label_7->setText(QCoreApplication::translate("Modulo", "Unidade:", nullptr));
        label2->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label3->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label6->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label4->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label5->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label8->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label7->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_15->setText(QCoreApplication::translate("Modulo", "Byte Inicial:*", nullptr));
        label_16->setText(QCoreApplication::translate("Modulo", "Byte Final:*", nullptr));
        radioButton_Bigendian->setText(QCoreApplication::translate("Modulo", "Big-Endian", nullptr));
        radioButton_Littleendian->setText(QCoreApplication::translate("Modulo", "Litlle-endian", nullptr));
        label_17->setText(QCoreApplication::translate("Modulo", "Tipo:*", nullptr));
        label_4->setText(QCoreApplication::translate("Modulo", "N\302\272 ModuloMensagem:*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modulo: public Ui_Modulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULO_H

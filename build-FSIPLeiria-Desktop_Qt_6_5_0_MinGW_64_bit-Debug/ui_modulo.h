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
    QTextEdit *textEdit;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QTextEdit *textEdit_6;
    QLabel *label_8;
    QTextEdit *textEdit_7;
    QSpinBox *spinBox_4;
    QTextEdit *textEdit_8;
    QSpinBox *spinBox_5;
    QTextEdit *textEdit_9;
    QTextEdit *textEdit_10;
    QLabel *label_9;
    QTextEdit *textEdit_11;
    QSpinBox *spinBox_6;
    QTextEdit *textEdit_12;
    QSpinBox *spinBox_7;
    QTextEdit *textEdit_13;
    QLabel *label_10;
    QTextEdit *textEdit_14;
    QTextEdit *textEdit_15;
    QSpinBox *spinBox_8;
    QLabel *label_11;
    QTextEdit *textEdit_16;
    QTextEdit *textEdit_17;
    QTextEdit *textEdit_18;
    QTextEdit *textEdit_19;
    QTextEdit *textEdit_20;
    QLabel *label_12;
    QTextEdit *textEdit_21;
    QTextEdit *textEdit_22;
    QSpinBox *spinBox_9;
    QTextEdit *textEdit_23;
    QSpinBox *spinBox_10;
    QTextEdit *textEdit_24;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_12;
    QSpinBox *spinBox_13;
    QTextEdit *textEdit_25;
    QSpinBox *spinBox_14;
    QTextEdit *textEdit_26;
    QSpinBox *spinBox_15;
    QSpinBox *spinBox_16;
    QLabel *label_13;
    QTextEdit *textEdit_27;
    QSpinBox *spinBox_17;
    QTextEdit *textEdit_28;
    QTextEdit *textEdit_29;
    QTextEdit *textEdit_30;
    QTextEdit *textEdit_31;
    QTextEdit *textEdit_32;
    QTextEdit *textEdit_33;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_17;

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
        textEdit = new QTextEdit(Modulo);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(120, 20, 261, 31));
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
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
        label_4 = new QLabel(Modulo);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 150, 51, 21));
        textEdit_2 = new QTextEdit(Modulo);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(90, 150, 191, 31));
        textEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_5 = new QLabel(Modulo);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 120, 51, 21));
        label_6 = new QLabel(Modulo);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(540, 120, 51, 21));
        label_7 = new QLabel(Modulo);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(610, 120, 51, 21));
        textEdit_3 = new QTextEdit(Modulo);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(470, 150, 51, 31));
        textEdit_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_4 = new QTextEdit(Modulo);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(540, 150, 51, 31));
        textEdit_4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_5 = new QTextEdit(Modulo);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(610, 150, 51, 31));
        textEdit_5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_2 = new QSpinBox(Modulo);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(310, 150, 51, 31));
        spinBox_2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_2->setMaximum(7);
        spinBox_3 = new QSpinBox(Modulo);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(390, 150, 51, 31));
        spinBox_3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_3->setMaximum(7);
        textEdit_6 = new QTextEdit(Modulo);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(610, 190, 51, 31));
        textEdit_6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_8 = new QLabel(Modulo);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 190, 51, 21));
        textEdit_7 = new QTextEdit(Modulo);
        textEdit_7->setObjectName("textEdit_7");
        textEdit_7->setGeometry(QRect(90, 190, 191, 31));
        textEdit_7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_4 = new QSpinBox(Modulo);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(390, 190, 51, 31));
        spinBox_4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_4->setMaximum(7);
        textEdit_8 = new QTextEdit(Modulo);
        textEdit_8->setObjectName("textEdit_8");
        textEdit_8->setGeometry(QRect(470, 190, 51, 31));
        textEdit_8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_5 = new QSpinBox(Modulo);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(310, 190, 51, 31));
        spinBox_5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_5->setMaximum(7);
        textEdit_9 = new QTextEdit(Modulo);
        textEdit_9->setObjectName("textEdit_9");
        textEdit_9->setGeometry(QRect(540, 190, 51, 31));
        textEdit_9->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_10 = new QTextEdit(Modulo);
        textEdit_10->setObjectName("textEdit_10");
        textEdit_10->setGeometry(QRect(610, 230, 51, 31));
        textEdit_10->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_9 = new QLabel(Modulo);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 230, 51, 21));
        textEdit_11 = new QTextEdit(Modulo);
        textEdit_11->setObjectName("textEdit_11");
        textEdit_11->setGeometry(QRect(90, 230, 191, 31));
        textEdit_11->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_6 = new QSpinBox(Modulo);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setGeometry(QRect(390, 230, 51, 31));
        spinBox_6->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_6->setMaximum(7);
        textEdit_12 = new QTextEdit(Modulo);
        textEdit_12->setObjectName("textEdit_12");
        textEdit_12->setGeometry(QRect(470, 230, 51, 31));
        textEdit_12->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_7 = new QSpinBox(Modulo);
        spinBox_7->setObjectName("spinBox_7");
        spinBox_7->setGeometry(QRect(310, 230, 51, 31));
        spinBox_7->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_7->setMaximum(7);
        textEdit_13 = new QTextEdit(Modulo);
        textEdit_13->setObjectName("textEdit_13");
        textEdit_13->setGeometry(QRect(540, 230, 51, 31));
        textEdit_13->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_10 = new QLabel(Modulo);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 350, 51, 21));
        textEdit_14 = new QTextEdit(Modulo);
        textEdit_14->setObjectName("textEdit_14");
        textEdit_14->setGeometry(QRect(90, 310, 191, 31));
        textEdit_14->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_15 = new QTextEdit(Modulo);
        textEdit_15->setObjectName("textEdit_15");
        textEdit_15->setGeometry(QRect(610, 270, 51, 31));
        textEdit_15->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_8 = new QSpinBox(Modulo);
        spinBox_8->setObjectName("spinBox_8");
        spinBox_8->setGeometry(QRect(310, 310, 51, 31));
        spinBox_8->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_8->setMaximum(7);
        label_11 = new QLabel(Modulo);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 270, 51, 21));
        textEdit_16 = new QTextEdit(Modulo);
        textEdit_16->setObjectName("textEdit_16");
        textEdit_16->setGeometry(QRect(470, 350, 51, 31));
        textEdit_16->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_17 = new QTextEdit(Modulo);
        textEdit_17->setObjectName("textEdit_17");
        textEdit_17->setGeometry(QRect(470, 310, 51, 31));
        textEdit_17->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_18 = new QTextEdit(Modulo);
        textEdit_18->setObjectName("textEdit_18");
        textEdit_18->setGeometry(QRect(540, 310, 51, 31));
        textEdit_18->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_19 = new QTextEdit(Modulo);
        textEdit_19->setObjectName("textEdit_19");
        textEdit_19->setGeometry(QRect(610, 310, 51, 31));
        textEdit_19->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_20 = new QTextEdit(Modulo);
        textEdit_20->setObjectName("textEdit_20");
        textEdit_20->setGeometry(QRect(90, 350, 191, 31));
        textEdit_20->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_12 = new QLabel(Modulo);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 310, 41, 21));
        textEdit_21 = new QTextEdit(Modulo);
        textEdit_21->setObjectName("textEdit_21");
        textEdit_21->setGeometry(QRect(540, 350, 51, 31));
        textEdit_21->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_22 = new QTextEdit(Modulo);
        textEdit_22->setObjectName("textEdit_22");
        textEdit_22->setGeometry(QRect(90, 270, 191, 31));
        textEdit_22->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_9 = new QSpinBox(Modulo);
        spinBox_9->setObjectName("spinBox_9");
        spinBox_9->setGeometry(QRect(390, 270, 51, 31));
        spinBox_9->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_9->setMaximum(7);
        textEdit_23 = new QTextEdit(Modulo);
        textEdit_23->setObjectName("textEdit_23");
        textEdit_23->setGeometry(QRect(470, 270, 51, 31));
        textEdit_23->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_10 = new QSpinBox(Modulo);
        spinBox_10->setObjectName("spinBox_10");
        spinBox_10->setGeometry(QRect(390, 350, 51, 31));
        spinBox_10->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_10->setMaximum(7);
        textEdit_24 = new QTextEdit(Modulo);
        textEdit_24->setObjectName("textEdit_24");
        textEdit_24->setGeometry(QRect(610, 350, 51, 31));
        textEdit_24->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_11 = new QSpinBox(Modulo);
        spinBox_11->setObjectName("spinBox_11");
        spinBox_11->setGeometry(QRect(310, 270, 51, 31));
        spinBox_11->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_11->setMaximum(7);
        spinBox_12 = new QSpinBox(Modulo);
        spinBox_12->setObjectName("spinBox_12");
        spinBox_12->setGeometry(QRect(390, 310, 51, 31));
        spinBox_12->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_12->setMaximum(7);
        spinBox_13 = new QSpinBox(Modulo);
        spinBox_13->setObjectName("spinBox_13");
        spinBox_13->setGeometry(QRect(310, 350, 51, 31));
        spinBox_13->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_13->setMaximum(7);
        textEdit_25 = new QTextEdit(Modulo);
        textEdit_25->setObjectName("textEdit_25");
        textEdit_25->setGeometry(QRect(540, 270, 51, 31));
        textEdit_25->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_14 = new QSpinBox(Modulo);
        spinBox_14->setObjectName("spinBox_14");
        spinBox_14->setGeometry(QRect(310, 430, 51, 31));
        spinBox_14->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_14->setMaximum(7);
        textEdit_26 = new QTextEdit(Modulo);
        textEdit_26->setObjectName("textEdit_26");
        textEdit_26->setGeometry(QRect(540, 430, 51, 31));
        textEdit_26->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_15 = new QSpinBox(Modulo);
        spinBox_15->setObjectName("spinBox_15");
        spinBox_15->setGeometry(QRect(390, 430, 51, 31));
        spinBox_15->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_15->setMaximum(7);
        spinBox_16 = new QSpinBox(Modulo);
        spinBox_16->setObjectName("spinBox_16");
        spinBox_16->setGeometry(QRect(390, 390, 51, 31));
        spinBox_16->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_16->setMaximum(7);
        label_13 = new QLabel(Modulo);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 430, 51, 21));
        textEdit_27 = new QTextEdit(Modulo);
        textEdit_27->setObjectName("textEdit_27");
        textEdit_27->setGeometry(QRect(470, 430, 51, 31));
        textEdit_27->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        spinBox_17 = new QSpinBox(Modulo);
        spinBox_17->setObjectName("spinBox_17");
        spinBox_17->setGeometry(QRect(310, 390, 51, 31));
        spinBox_17->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_17->setMaximum(7);
        textEdit_28 = new QTextEdit(Modulo);
        textEdit_28->setObjectName("textEdit_28");
        textEdit_28->setGeometry(QRect(540, 390, 51, 31));
        textEdit_28->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_29 = new QTextEdit(Modulo);
        textEdit_29->setObjectName("textEdit_29");
        textEdit_29->setGeometry(QRect(90, 430, 191, 31));
        textEdit_29->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_30 = new QTextEdit(Modulo);
        textEdit_30->setObjectName("textEdit_30");
        textEdit_30->setGeometry(QRect(610, 390, 51, 31));
        textEdit_30->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_31 = new QTextEdit(Modulo);
        textEdit_31->setObjectName("textEdit_31");
        textEdit_31->setGeometry(QRect(610, 430, 51, 31));
        textEdit_31->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_32 = new QTextEdit(Modulo);
        textEdit_32->setObjectName("textEdit_32");
        textEdit_32->setGeometry(QRect(90, 390, 191, 31));
        textEdit_32->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_33 = new QTextEdit(Modulo);
        textEdit_33->setObjectName("textEdit_33");
        textEdit_33->setGeometry(QRect(470, 390, 51, 31));
        textEdit_33->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_14 = new QLabel(Modulo);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 390, 41, 21));
        label_15 = new QLabel(Modulo);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(300, 120, 71, 21));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_16 = new QLabel(Modulo);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(380, 120, 71, 21));
        radioButton = new QRadioButton(Modulo);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(230, 480, 131, 31));
        radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        radioButton_2 = new QRadioButton(Modulo);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(100, 480, 111, 31));
        radioButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        radioButton_2->setChecked(true);
        label_17 = new QLabel(Modulo);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 480, 51, 21));
        tableView->raise();
        commandLinkButton->raise();
        pushButton->raise();
        label->raise();
        spinBox->raise();
        label_2->raise();
        label_3->raise();
        line->raise();
        line_2->raise();
        label_4->raise();
        textEdit_2->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        textEdit_3->raise();
        textEdit_4->raise();
        textEdit_5->raise();
        textEdit_6->raise();
        label_8->raise();
        textEdit_7->raise();
        textEdit_8->raise();
        textEdit_9->raise();
        textEdit_10->raise();
        label_9->raise();
        textEdit_11->raise();
        textEdit_12->raise();
        textEdit_13->raise();
        label_10->raise();
        textEdit_14->raise();
        textEdit_15->raise();
        label_11->raise();
        textEdit_16->raise();
        textEdit_17->raise();
        textEdit_18->raise();
        textEdit_19->raise();
        textEdit_20->raise();
        label_12->raise();
        textEdit_21->raise();
        textEdit_22->raise();
        textEdit_23->raise();
        textEdit_24->raise();
        textEdit_25->raise();
        textEdit_26->raise();
        label_13->raise();
        textEdit_27->raise();
        textEdit_28->raise();
        textEdit_29->raise();
        textEdit_30->raise();
        textEdit_31->raise();
        textEdit_32->raise();
        textEdit_33->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        radioButton->raise();
        radioButton_2->raise();
        label_17->raise();
        spinBox_17->raise();
        spinBox_13->raise();
        spinBox_5->raise();
        spinBox_14->raise();
        spinBox_10->raise();
        spinBox_12->raise();
        spinBox_8->raise();
        spinBox_11->raise();
        spinBox_15->raise();
        spinBox_9->raise();
        spinBox_3->raise();
        spinBox_6->raise();
        spinBox_16->raise();
        spinBox_2->raise();
        spinBox_4->raise();
        spinBox_7->raise();
        textEdit->raise();

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
        label_4->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_5->setText(QCoreApplication::translate("Modulo", "Offset:", nullptr));
        label_6->setText(QCoreApplication::translate("Modulo", "Fator:", nullptr));
        label_7->setText(QCoreApplication::translate("Modulo", "Unidade:", nullptr));
        label_8->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_9->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_10->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_11->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_12->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_13->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_14->setText(QCoreApplication::translate("Modulo", "Nome:*", nullptr));
        label_15->setText(QCoreApplication::translate("Modulo", "Byte Inicial:*", nullptr));
        label_16->setText(QCoreApplication::translate("Modulo", "Byte Final:*", nullptr));
        radioButton->setText(QCoreApplication::translate("Modulo", "Big-Endian", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Modulo", "Litlle-endian", nullptr));
        label_17->setText(QCoreApplication::translate("Modulo", "Tipo:*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modulo: public Ui_Modulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULO_H

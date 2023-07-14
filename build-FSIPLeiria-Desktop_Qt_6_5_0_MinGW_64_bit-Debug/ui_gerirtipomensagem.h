/********************************************************************************
** Form generated from reading UI file 'gerirtipomensagem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERIRTIPOMENSAGEM_H
#define UI_GERIRTIPOMENSAGEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GerirTipoMensagem
{
public:
    QCommandLinkButton *commandButtonVoltar;
    QSpinBox *spinBox_Final7;
    QSpinBox *spinBox_Final3;
    QLabel *labelOffset;
    QLabel *label6;
    QLabel *label2;
    QSpinBox *spinBox_Final4;
    QLabel *label7;
    QTextEdit *textEdit_Unidade4;
    QTextEdit *textEdit_Unidade5;
    QSpinBox *spinBox_Final8;
    QTextEdit *textEdit_Nome1;
    QTextEdit *textEdit_Nome4;
    QLabel *label_2;
    QLabel *label1;
    QSpinBox *spinBox_Inicial5;
    QTextEdit *textEdit_Unidade7;
    QSpinBox *spinBox_Inicial4;
    QSpinBox *spinBox_Inicial8;
    QLabel *label5;
    QTextEdit *textEdit_Unidade8;
    QTextEdit *textEdit_Nome6;
    QSpinBox *spinBox_Inicial3;
    QLabel *label_3;
    QTextEdit *textEdit_Unidade1;
    QSpinBox *spinBox_Inicial7;
    QLabel *label8;
    QSpinBox *spinBox;
    QLabel *labelUnidade;
    QTextEdit *textEdit_Unidade3;
    QTextEdit *textEdit_Nome2;
    QLabel *labelFator;
    QLabel *labelFinal;
    QLabel *labelInicial;
    QSpinBox *spinBox_Inicial6;
    QLabel *label3;
    QTextEdit *textEdit_Unidade2;
    QSpinBox *spinBox_Final1;
    QSpinBox *spinBox_Final5;
    QFrame *line;
    QTextEdit *textEdit_Nome8;
    QFrame *line_2;
    QSpinBox *spinBox_Final2;
    QTextEdit *textEdit_Unidade6;
    QLabel *label_17;
    QSpinBox *spinBox_Inicial1;
    QSpinBox *spinBox_Final6;
    QTextEdit *textEdit_Nome3;
    QLabel *label4;
    QTextEdit *textEdit_Nome7;
    QTextEdit *textEdit_Nome5;
    QLabel *labelNomeModulo;
    QLabel *labelNomeCarro;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *labelCodHex;
    QPushButton *btnGuardarCarro;
    QPlainTextEdit *plainTextEditObs;
    QSpinBox *spinBox_Inicial2;
    QCommandLinkButton *commandButtonMenuPrincipal;
    QPushButton *btnApagar;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_Offset1;
    QDoubleSpinBox *doubleSpinBox_Offset2;
    QDoubleSpinBox *doubleSpinBox_Offset3;
    QDoubleSpinBox *doubleSpinBox_Offset5;
    QDoubleSpinBox *doubleSpinBox_Offset6;
    QDoubleSpinBox *doubleSpinBox_Offset4;
    QDoubleSpinBox *doubleSpinBox_Offset8;
    QDoubleSpinBox *doubleSpinBox_Offset7;
    QDoubleSpinBox *doubleSpinBox_Fator1;
    QDoubleSpinBox *doubleSpinBox_Fator8;
    QDoubleSpinBox *doubleSpinBox_Fator7;
    QDoubleSpinBox *doubleSpinBox_Fator6;
    QDoubleSpinBox *doubleSpinBox_Fator5;
    QDoubleSpinBox *doubleSpinBox_Fator4;
    QDoubleSpinBox *doubleSpinBox_Fator3;
    QDoubleSpinBox *doubleSpinBox_Fator2;

    void setupUi(QDialog *GerirTipoMensagem)
    {
        if (GerirTipoMensagem->objectName().isEmpty())
            GerirTipoMensagem->setObjectName("GerirTipoMensagem");
        GerirTipoMensagem->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GerirTipoMensagem->setWindowIcon(icon);
        GerirTipoMensagem->setStyleSheet(QString::fromUtf8("background:white\n"
""));
        commandButtonVoltar = new QCommandLinkButton(GerirTipoMensagem);
        commandButtonVoltar->setObjectName("commandButtonVoltar");
        commandButtonVoltar->setGeometry(QRect(0, -10, 31, 31));
        commandButtonVoltar->setCursor(QCursor(Qt::PointingHandCursor));
        commandButtonVoltar->setStyleSheet(QString::fromUtf8("QCommandLinkButton\n"
"{\n"
"	border: none;\n"
"}\n"
"\n"
"QCommandLinkButton:hover\n"
"{\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../setavoltar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandButtonVoltar->setIcon(icon1);
        spinBox_Final7 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final7->setObjectName("spinBox_Final7");
        spinBox_Final7->setGeometry(QRect(400, 400, 51, 31));
        spinBox_Final7->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final7->setMinimum(0);
        spinBox_Final7->setMaximum(7);
        spinBox_Final7->setValue(0);
        spinBox_Final3 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final3->setObjectName("spinBox_Final3");
        spinBox_Final3->setGeometry(QRect(400, 240, 51, 31));
        spinBox_Final3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final3->setMinimum(0);
        spinBox_Final3->setMaximum(7);
        spinBox_Final3->setSingleStep(1);
        spinBox_Final3->setValue(0);
        labelOffset = new QLabel(GerirTipoMensagem);
        labelOffset->setObjectName("labelOffset");
        labelOffset->setGeometry(QRect(480, 130, 51, 21));
        label6 = new QLabel(GerirTipoMensagem);
        label6->setObjectName("label6");
        label6->setGeometry(QRect(20, 360, 51, 21));
        label2 = new QLabel(GerirTipoMensagem);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(20, 200, 51, 21));
        spinBox_Final4 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final4->setObjectName("spinBox_Final4");
        spinBox_Final4->setGeometry(QRect(400, 280, 51, 31));
        spinBox_Final4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final4->setMinimum(0);
        spinBox_Final4->setMaximum(7);
        spinBox_Final4->setSingleStep(1);
        spinBox_Final4->setValue(0);
        spinBox_Final4->setDisplayIntegerBase(10);
        label7 = new QLabel(GerirTipoMensagem);
        label7->setObjectName("label7");
        label7->setGeometry(QRect(20, 400, 51, 21));
        textEdit_Unidade4 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade4->setObjectName("textEdit_Unidade4");
        textEdit_Unidade4->setGeometry(QRect(620, 280, 51, 31));
        textEdit_Unidade4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        textEdit_Unidade5 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade5->setObjectName("textEdit_Unidade5");
        textEdit_Unidade5->setGeometry(QRect(620, 320, 51, 31));
        textEdit_Unidade5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final8 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final8->setObjectName("spinBox_Final8");
        spinBox_Final8->setGeometry(QRect(400, 440, 51, 31));
        spinBox_Final8->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final8->setMinimum(0);
        spinBox_Final8->setMaximum(7);
        spinBox_Final8->setSingleStep(1);
        spinBox_Final8->setStepType(QAbstractSpinBox::DefaultStepType);
        spinBox_Final8->setValue(0);
        spinBox_Final8->setDisplayIntegerBase(10);
        textEdit_Nome1 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome1->setObjectName("textEdit_Nome1");
        textEdit_Nome1->setEnabled(true);
        textEdit_Nome1->setGeometry(QRect(80, 160, 191, 31));
        textEdit_Nome1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        textEdit_Nome4 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome4->setObjectName("textEdit_Nome4");
        textEdit_Nome4->setGeometry(QRect(80, 280, 191, 31));
        textEdit_Nome4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        label_2 = new QLabel(GerirTipoMensagem);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 141, 21));
        label1 = new QLabel(GerirTipoMensagem);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(20, 160, 51, 21));
        spinBox_Inicial5 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial5->setObjectName("spinBox_Inicial5");
        spinBox_Inicial5->setGeometry(QRect(320, 320, 51, 31));
        spinBox_Inicial5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial5->setMinimum(0);
        spinBox_Inicial5->setMaximum(7);
        spinBox_Inicial5->setSingleStep(1);
        spinBox_Inicial5->setValue(0);
        textEdit_Unidade7 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade7->setObjectName("textEdit_Unidade7");
        textEdit_Unidade7->setGeometry(QRect(620, 400, 51, 31));
        textEdit_Unidade7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial4 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial4->setObjectName("spinBox_Inicial4");
        spinBox_Inicial4->setGeometry(QRect(320, 280, 51, 31));
        spinBox_Inicial4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial4->setMinimum(0);
        spinBox_Inicial4->setMaximum(7);
        spinBox_Inicial4->setSingleStep(1);
        spinBox_Inicial4->setValue(0);
        spinBox_Inicial8 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial8->setObjectName("spinBox_Inicial8");
        spinBox_Inicial8->setGeometry(QRect(320, 440, 51, 31));
        spinBox_Inicial8->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial8->setMinimum(0);
        spinBox_Inicial8->setMaximum(7);
        spinBox_Inicial8->setValue(0);
        label5 = new QLabel(GerirTipoMensagem);
        label5->setObjectName("label5");
        label5->setGeometry(QRect(20, 320, 51, 21));
        textEdit_Unidade8 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade8->setObjectName("textEdit_Unidade8");
        textEdit_Unidade8->setGeometry(QRect(620, 440, 51, 31));
        textEdit_Unidade8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        textEdit_Nome6 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome6->setObjectName("textEdit_Nome6");
        textEdit_Nome6->setGeometry(QRect(80, 360, 191, 31));
        textEdit_Nome6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial3 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial3->setObjectName("spinBox_Inicial3");
        spinBox_Inicial3->setGeometry(QRect(320, 240, 51, 31));
        spinBox_Inicial3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial3->setMinimum(0);
        spinBox_Inicial3->setMaximum(7);
        spinBox_Inicial3->setValue(0);
        label_3 = new QLabel(GerirTipoMensagem);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 80, 131, 31));
        label_3->setCursor(QCursor(Qt::ForbiddenCursor));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";"));
        label_3->setScaledContents(false);
        label_3->setOpenExternalLinks(false);
        textEdit_Unidade1 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade1->setObjectName("textEdit_Unidade1");
        textEdit_Unidade1->setGeometry(QRect(620, 160, 51, 31));
        textEdit_Unidade1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial7 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial7->setObjectName("spinBox_Inicial7");
        spinBox_Inicial7->setGeometry(QRect(320, 400, 51, 31));
        spinBox_Inicial7->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial7->setMinimum(0);
        spinBox_Inicial7->setMaximum(7);
        spinBox_Inicial7->setValue(0);
        label8 = new QLabel(GerirTipoMensagem);
        label8->setObjectName("label8");
        label8->setGeometry(QRect(20, 440, 51, 21));
        spinBox = new QSpinBox(GerirTipoMensagem);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(160, 120, 91, 21));
        spinBox->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox->setMaximum(8);
        labelUnidade = new QLabel(GerirTipoMensagem);
        labelUnidade->setObjectName("labelUnidade");
        labelUnidade->setGeometry(QRect(620, 130, 61, 21));
        textEdit_Unidade3 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade3->setObjectName("textEdit_Unidade3");
        textEdit_Unidade3->setGeometry(QRect(620, 240, 51, 31));
        textEdit_Unidade3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        textEdit_Nome2 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome2->setObjectName("textEdit_Nome2");
        textEdit_Nome2->setGeometry(QRect(80, 200, 191, 31));
        textEdit_Nome2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        labelFator = new QLabel(GerirTipoMensagem);
        labelFator->setObjectName("labelFator");
        labelFator->setGeometry(QRect(550, 130, 51, 21));
        labelFinal = new QLabel(GerirTipoMensagem);
        labelFinal->setObjectName("labelFinal");
        labelFinal->setGeometry(QRect(390, 130, 81, 21));
        labelInicial = new QLabel(GerirTipoMensagem);
        labelInicial->setObjectName("labelInicial");
        labelInicial->setGeometry(QRect(290, 130, 81, 21));
        labelInicial->setStyleSheet(QString::fromUtf8(""));
        spinBox_Inicial6 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial6->setObjectName("spinBox_Inicial6");
        spinBox_Inicial6->setGeometry(QRect(320, 360, 51, 31));
        spinBox_Inicial6->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial6->setMinimum(0);
        spinBox_Inicial6->setMaximum(7);
        spinBox_Inicial6->setValue(0);
        label3 = new QLabel(GerirTipoMensagem);
        label3->setObjectName("label3");
        label3->setGeometry(QRect(20, 240, 51, 21));
        textEdit_Unidade2 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade2->setObjectName("textEdit_Unidade2");
        textEdit_Unidade2->setGeometry(QRect(620, 200, 51, 31));
        textEdit_Unidade2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final1 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final1->setObjectName("spinBox_Final1");
        spinBox_Final1->setGeometry(QRect(400, 160, 51, 31));
        spinBox_Final1->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final1->setMinimum(0);
        spinBox_Final1->setMaximum(7);
        spinBox_Final1->setSingleStep(1);
        spinBox_Final1->setValue(0);
        spinBox_Final5 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final5->setObjectName("spinBox_Final5");
        spinBox_Final5->setGeometry(QRect(400, 320, 51, 31));
        spinBox_Final5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final5->setMinimum(0);
        spinBox_Final5->setMaximum(7);
        spinBox_Final5->setValue(0);
        line = new QFrame(GerirTipoMensagem);
        line->setObjectName("line");
        line->setGeometry(QRect(450, 90, 281, 20));
        line->setCursor(QCursor(Qt::ForbiddenCursor));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit_Nome8 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome8->setObjectName("textEdit_Nome8");
        textEdit_Nome8->setGeometry(QRect(80, 440, 191, 31));
        textEdit_Nome8->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        line_2 = new QFrame(GerirTipoMensagem);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 90, 261, 16));
        line_2->setCursor(QCursor(Qt::ForbiddenCursor));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        spinBox_Final2 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final2->setObjectName("spinBox_Final2");
        spinBox_Final2->setGeometry(QRect(400, 200, 51, 31));
        spinBox_Final2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final2->setMinimum(0);
        spinBox_Final2->setMaximum(7);
        spinBox_Final2->setSingleStep(1);
        spinBox_Final2->setValue(0);
        textEdit_Unidade6 = new QTextEdit(GerirTipoMensagem);
        textEdit_Unidade6->setObjectName("textEdit_Unidade6");
        textEdit_Unidade6->setGeometry(QRect(620, 360, 51, 31));
        textEdit_Unidade6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Unidade6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        label_17 = new QLabel(GerirTipoMensagem);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 480, 91, 31));
        spinBox_Inicial1 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial1->setObjectName("spinBox_Inicial1");
        spinBox_Inicial1->setGeometry(QRect(320, 160, 51, 31));
        spinBox_Inicial1->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial1->setMinimum(0);
        spinBox_Inicial1->setMaximum(7);
        spinBox_Inicial1->setSingleStep(1);
        spinBox_Inicial1->setValue(0);
        spinBox_Inicial1->setDisplayIntegerBase(7);
        spinBox_Final6 = new QSpinBox(GerirTipoMensagem);
        spinBox_Final6->setObjectName("spinBox_Final6");
        spinBox_Final6->setGeometry(QRect(400, 360, 51, 31));
        spinBox_Final6->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Final6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Final6->setMinimum(0);
        spinBox_Final6->setMaximum(7);
        spinBox_Final6->setValue(0);
        textEdit_Nome3 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome3->setObjectName("textEdit_Nome3");
        textEdit_Nome3->setEnabled(true);
        textEdit_Nome3->setGeometry(QRect(80, 240, 191, 31));
        textEdit_Nome3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        label4 = new QLabel(GerirTipoMensagem);
        label4->setObjectName("label4");
        label4->setGeometry(QRect(20, 280, 51, 21));
        textEdit_Nome7 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome7->setObjectName("textEdit_Nome7");
        textEdit_Nome7->setGeometry(QRect(80, 400, 191, 31));
        textEdit_Nome7->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        textEdit_Nome5 = new QTextEdit(GerirTipoMensagem);
        textEdit_Nome5->setObjectName("textEdit_Nome5");
        textEdit_Nome5->setGeometry(QRect(80, 320, 191, 31));
        textEdit_Nome5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_Nome5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        labelNomeModulo = new QLabel(GerirTipoMensagem);
        labelNomeModulo->setObjectName("labelNomeModulo");
        labelNomeModulo->setGeometry(QRect(120, 50, 371, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelNomeModulo->setFont(font);
        labelNomeModulo->setCursor(QCursor(Qt::ForbiddenCursor));
        labelNomeCarro = new QLabel(GerirTipoMensagem);
        labelNomeCarro->setObjectName("labelNomeCarro");
        labelNomeCarro->setGeometry(QRect(100, 10, 501, 31));
        labelNomeCarro->setFont(font);
        labelNomeCarro->setCursor(QCursor(Qt::ForbiddenCursor));
        label = new QLabel(GerirTipoMensagem);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 71, 31));
        label->setFont(font);
        label->setCursor(QCursor(Qt::ForbiddenCursor));
        label_4 = new QLabel(GerirTipoMensagem);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 50, 101, 31));
        label_4->setFont(font);
        label_4->setCursor(QCursor(Qt::ForbiddenCursor));
        label_8 = new QLabel(GerirTipoMensagem);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 10, 51, 31));
        label_8->setFont(font);
        label_8->setCursor(QCursor(Qt::ForbiddenCursor));
        labelCodHex = new QLabel(GerirTipoMensagem);
        labelCodHex->setObjectName("labelCodHex");
        labelCodHex->setGeometry(QRect(610, 50, 121, 31));
        labelCodHex->setFont(font);
        labelCodHex->setCursor(QCursor(Qt::ForbiddenCursor));
        btnGuardarCarro = new QPushButton(GerirTipoMensagem);
        btnGuardarCarro->setObjectName("btnGuardarCarro");
        btnGuardarCarro->setGeometry(QRect(650, 480, 131, 41));
        QFont font1;
        font1.setPointSize(10);
        btnGuardarCarro->setFont(font1);
        btnGuardarCarro->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardarCarro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        plainTextEditObs = new QPlainTextEdit(GerirTipoMensagem);
        plainTextEditObs->setObjectName("plainTextEditObs");
        plainTextEditObs->setGeometry(QRect(110, 480, 521, 91));
        plainTextEditObs->setFont(font1);
        plainTextEditObs->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial2 = new QSpinBox(GerirTipoMensagem);
        spinBox_Inicial2->setObjectName("spinBox_Inicial2");
        spinBox_Inicial2->setGeometry(QRect(320, 200, 51, 31));
        spinBox_Inicial2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_Inicial2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        spinBox_Inicial2->setMinimum(0);
        spinBox_Inicial2->setMaximum(7);
        spinBox_Inicial2->setValue(0);
        commandButtonMenuPrincipal = new QCommandLinkButton(GerirTipoMensagem);
        commandButtonMenuPrincipal->setObjectName("commandButtonMenuPrincipal");
        commandButtonMenuPrincipal->setGeometry(QRect(640, -10, 141, 31));
        commandButtonMenuPrincipal->setCursor(QCursor(Qt::PointingHandCursor));
        commandButtonMenuPrincipal->setStyleSheet(QString::fromUtf8("QCommandLinkButton{\n"
"color:black;\n"
"}\n"
"QCommandLinkButton:hover\n"
"{\n"
"  border: none;\n"
"  color: black;\n"
"}"));
        commandButtonMenuPrincipal->setIcon(icon);
        btnApagar = new QPushButton(GerirTipoMensagem);
        btnApagar->setObjectName("btnApagar");
        btnApagar->setGeometry(QRect(650, 530, 131, 41));
        btnApagar->setFont(font1);
        btnApagar->setCursor(QCursor(Qt::PointingHandCursor));
        btnApagar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label_5 = new QLabel(GerirTipoMensagem);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 580, 611, 16));
        doubleSpinBox_Offset1 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset1->setObjectName("doubleSpinBox_Offset1");
        doubleSpinBox_Offset1->setGeometry(QRect(480, 160, 51, 31));
        doubleSpinBox_Offset1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset1->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset1->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset2 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset2->setObjectName("doubleSpinBox_Offset2");
        doubleSpinBox_Offset2->setGeometry(QRect(480, 200, 51, 31));
        doubleSpinBox_Offset2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset2->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset2->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset3 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset3->setObjectName("doubleSpinBox_Offset3");
        doubleSpinBox_Offset3->setGeometry(QRect(480, 240, 51, 31));
        doubleSpinBox_Offset3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset3->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset3->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset5 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset5->setObjectName("doubleSpinBox_Offset5");
        doubleSpinBox_Offset5->setGeometry(QRect(480, 320, 51, 31));
        doubleSpinBox_Offset5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset5->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset5->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset6 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset6->setObjectName("doubleSpinBox_Offset6");
        doubleSpinBox_Offset6->setGeometry(QRect(480, 360, 51, 31));
        doubleSpinBox_Offset6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset6->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset6->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset4 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset4->setObjectName("doubleSpinBox_Offset4");
        doubleSpinBox_Offset4->setGeometry(QRect(480, 280, 51, 31));
        doubleSpinBox_Offset4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset4->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset4->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset8 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset8->setObjectName("doubleSpinBox_Offset8");
        doubleSpinBox_Offset8->setGeometry(QRect(480, 440, 51, 31));
        doubleSpinBox_Offset8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset8->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset8->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Offset7 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Offset7->setObjectName("doubleSpinBox_Offset7");
        doubleSpinBox_Offset7->setGeometry(QRect(480, 400, 51, 31));
        doubleSpinBox_Offset7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Offset7->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Offset7->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator1 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator1->setObjectName("doubleSpinBox_Fator1");
        doubleSpinBox_Fator1->setGeometry(QRect(550, 160, 51, 31));
        doubleSpinBox_Fator1->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator1->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator1->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator1->setValue(1.000000000000000);
        doubleSpinBox_Fator8 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator8->setObjectName("doubleSpinBox_Fator8");
        doubleSpinBox_Fator8->setGeometry(QRect(550, 440, 51, 31));
        doubleSpinBox_Fator8->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator8->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator8->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator8->setValue(1.000000000000000);
        doubleSpinBox_Fator7 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator7->setObjectName("doubleSpinBox_Fator7");
        doubleSpinBox_Fator7->setGeometry(QRect(550, 400, 51, 31));
        doubleSpinBox_Fator7->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator7->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator7->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator7->setValue(1.000000000000000);
        doubleSpinBox_Fator6 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator6->setObjectName("doubleSpinBox_Fator6");
        doubleSpinBox_Fator6->setGeometry(QRect(550, 360, 51, 31));
        doubleSpinBox_Fator6->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator6->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator6->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator6->setValue(1.000000000000000);
        doubleSpinBox_Fator5 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator5->setObjectName("doubleSpinBox_Fator5");
        doubleSpinBox_Fator5->setGeometry(QRect(550, 320, 51, 31));
        doubleSpinBox_Fator5->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator5->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator5->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator5->setValue(1.000000000000000);
        doubleSpinBox_Fator4 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator4->setObjectName("doubleSpinBox_Fator4");
        doubleSpinBox_Fator4->setGeometry(QRect(550, 280, 51, 31));
        doubleSpinBox_Fator4->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator4->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator4->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator4->setValue(1.000000000000000);
        doubleSpinBox_Fator3 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator3->setObjectName("doubleSpinBox_Fator3");
        doubleSpinBox_Fator3->setGeometry(QRect(550, 240, 51, 31));
        doubleSpinBox_Fator3->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator3->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator3->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator3->setValue(1.000000000000000);
        doubleSpinBox_Fator2 = new QDoubleSpinBox(GerirTipoMensagem);
        doubleSpinBox_Fator2->setObjectName("doubleSpinBox_Fator2");
        doubleSpinBox_Fator2->setGeometry(QRect(550, 200, 51, 31));
        doubleSpinBox_Fator2->setStyleSheet(QString::fromUtf8("background: rgb(220,220,220)"));
        doubleSpinBox_Fator2->setMinimum(-1000000000000000013287555072.000000000000000);
        doubleSpinBox_Fator2->setMaximum(100000000000000000000.000000000000000);
        doubleSpinBox_Fator2->setValue(1.000000000000000);

        retranslateUi(GerirTipoMensagem);

        QMetaObject::connectSlotsByName(GerirTipoMensagem);
    } // setupUi

    void retranslateUi(QDialog *GerirTipoMensagem)
    {
        GerirTipoMensagem->setWindowTitle(QCoreApplication::translate("GerirTipoMensagem", "Gerir Tipo de Mensagem", nullptr));
        commandButtonVoltar->setText(QCoreApplication::translate("GerirTipoMensagem", "Criar M\303\263dulo", nullptr));
        labelOffset->setText(QCoreApplication::translate("GerirTipoMensagem", "Offset:", nullptr));
        label6->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label2->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label7->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label_2->setText(QCoreApplication::translate("GerirTipoMensagem", "Numero de campos:*", nullptr));
        label1->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label5->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label_3->setText(QCoreApplication::translate("GerirTipoMensagem", "Mensagem", nullptr));
        label8->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        labelUnidade->setText(QCoreApplication::translate("GerirTipoMensagem", "Unidade:", nullptr));
        labelFator->setText(QCoreApplication::translate("GerirTipoMensagem", "Fator:", nullptr));
        labelFinal->setText(QCoreApplication::translate("GerirTipoMensagem", "Byte Final:*", nullptr));
        labelInicial->setText(QCoreApplication::translate("GerirTipoMensagem", "Byte Inicial:*", nullptr));
        label3->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        label_17->setText(QCoreApplication::translate("GerirTipoMensagem", "Observa\303\247\303\265es:", nullptr));
        label4->setText(QCoreApplication::translate("GerirTipoMensagem", "Nome:*", nullptr));
        labelNomeModulo->setText(QCoreApplication::translate("GerirTipoMensagem", "INDEFINIDO", nullptr));
        labelNomeCarro->setText(QCoreApplication::translate("GerirTipoMensagem", "INDEFINIDO", nullptr));
        label->setText(QCoreApplication::translate("GerirTipoMensagem", "M\303\263dulo:", nullptr));
        label_4->setText(QCoreApplication::translate("GerirTipoMensagem", "C\303\263digo: 0x", nullptr));
        label_8->setText(QCoreApplication::translate("GerirTipoMensagem", "Carro", nullptr));
        labelCodHex->setText(QCoreApplication::translate("GerirTipoMensagem", "INDEFINIDO", nullptr));
        btnGuardarCarro->setText(QCoreApplication::translate("GerirTipoMensagem", "Guardar", nullptr));
        commandButtonMenuPrincipal->setText(QCoreApplication::translate("GerirTipoMensagem", "Menu Principal", nullptr));
        btnApagar->setText(QCoreApplication::translate("GerirTipoMensagem", "Apagar", nullptr));
        label_5->setText(QCoreApplication::translate("GerirTipoMensagem", "Nota: Os campos assinalados com \"*\" s\303\243o de preenchimento obrigat\303\263rio.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerirTipoMensagem: public Ui_GerirTipoMensagem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERIRTIPOMENSAGEM_H

#include <QFileDialog>

#include "modulo.h"
#include "ui_modulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Modulo::Modulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modulo)
{
    ui->setupUi(this);
    //Campo 1
    ui->label1->hide();
    ui->textEdit_Nome1->hide();
    ui->spinBox_Inicial1->hide();
    ui->spinBox_Final1->hide();
    ui->textEdit_Offset1->hide();
    ui->textEdit_Fator1->hide();
    ui->textEdit_Unidade1->hide();
    //Campo 2
    ui->label2->hide();
    ui->textEdit_Nome2->hide();
    ui->spinBox_Inicial2->hide();
    ui->spinBox_Final2->hide();
    ui->textEdit_Offset2->hide();
    ui->textEdit_Fator2->hide();
    ui->textEdit_Unidade2->hide();
    //Campo 3
    ui->label3->hide();
    ui->textEdit_Nome3->hide();
    ui->spinBox_Inicial3->hide();
    ui->spinBox_Final3->hide();
    ui->textEdit_Offset3->hide();
    ui->textEdit_Fator3->hide();
    ui->textEdit_Unidade3->hide();
    //Campo 4
    ui->label4->hide();
    ui->textEdit_Nome4->hide();
    ui->spinBox_Inicial4->hide();
    ui->spinBox_Final4->hide();
    ui->textEdit_Offset4->hide();
    ui->textEdit_Fator4->hide();
    ui->textEdit_Unidade4->hide();
    //Campo 5
    ui->label5->hide();
    ui->textEdit_Nome5->hide();
    ui->spinBox_Inicial5->hide();
    ui->spinBox_Final5->hide();
    ui->textEdit_Offset5->hide();
    ui->textEdit_Fator5->hide();
    ui->textEdit_Unidade5->hide();
    //Campo 6
    ui->label6->hide();
    ui->textEdit_Nome6->hide();
    ui->spinBox_Inicial6->hide();
    ui->spinBox_Final6->hide();
    ui->textEdit_Offset6->hide();
    ui->textEdit_Fator6->hide();
    ui->textEdit_Unidade6->hide();
    //Campo 7
    ui->label7->hide();
    ui->textEdit_Nome7->hide();
    ui->spinBox_Inicial7->hide();
    ui->spinBox_Final7->hide();
    ui->textEdit_Offset7->hide();
    ui->textEdit_Fator7->hide();
    ui->textEdit_Unidade7->hide();
    //Campo 8
    ui->label8->hide();
    ui->textEdit_Nome8->hide();
    ui->spinBox_Inicial8->hide();
    ui->spinBox_Final8->hide();
    ui->textEdit_Offset8->hide();
    ui->textEdit_Fator8->hide();
    ui->textEdit_Unidade8->hide();
}

Modulo::~Modulo()
{
    delete ui;
}

void Modulo::on_commandLinkButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void Modulo::on_pushButton_clicked()
{
    QString caminhoArquivo = QFileDialog::getOpenFileName(this, tr("Escolha um arquivo .txt"), "", tr("Arquivos de texto (*.txt)"));
    if (!caminhoArquivo.isEmpty()) {
        QFile arquivo(caminhoArquivo);
        if (arquivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QStandardItemModel *modeloTabela = new QStandardItemModel();
            while (!arquivo.atEnd()) {
                QString linha = QString::fromUtf8(arquivo.readLine()).trimmed();
                QStringList itens = linha.split(";");
                QList<QStandardItem *> linhas;
                for (int i = 0; i < itens.count(); i++) {
                    linhas.append(new QStandardItem(itens[i]));
                }
                modeloTabela->appendRow(linhas);
            }
            ui->tableView->setModel(modeloTabela);
            arquivo.close();
        }
    }
}


void Modulo::on_spinBox_valueChanged(int arg1)
{

    // Mostrar os widgets correspondentes
    switch (arg1) {
    case 0:
        //Campo 1
        ui->label1->hide();
        ui->textEdit_Nome1->hide();
        ui->spinBox_Inicial1->hide();
        ui->spinBox_Final1->hide();
        ui->textEdit_Offset1->hide();
        ui->textEdit_Fator1->hide();
        ui->textEdit_Unidade1->hide();
        //Campo 2
        ui->label2->hide();
        ui->textEdit_Nome2->hide();
        ui->spinBox_Inicial2->hide();
        ui->spinBox_Final2->hide();
        ui->textEdit_Offset2->hide();
        ui->textEdit_Fator2->hide();
        ui->textEdit_Unidade2->hide();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->textEdit_Offset3->hide();
        ui->textEdit_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->textEdit_Offset4->hide();
        ui->textEdit_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->textEdit_Offset5->hide();
        ui->textEdit_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 1:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->hide();
        ui->textEdit_Nome2->hide();
        ui->spinBox_Inicial2->hide();
        ui->spinBox_Final2->hide();
        ui->textEdit_Offset2->hide();
        ui->textEdit_Fator2->hide();
        ui->textEdit_Unidade2->hide();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->textEdit_Offset3->hide();
        ui->textEdit_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->textEdit_Offset4->hide();
        ui->textEdit_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->textEdit_Offset5->hide();
        ui->textEdit_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 2:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->textEdit_Offset3->hide();
        ui->textEdit_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->textEdit_Offset4->hide();
        ui->textEdit_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->textEdit_Offset5->hide();
        ui->textEdit_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;

    case 3:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->textEdit_Offset4->hide();
        ui->textEdit_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->textEdit_Offset5->hide();
        ui->textEdit_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 4:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->textEdit_Offset4->show();
        ui->textEdit_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->textEdit_Offset5->hide();
        ui->textEdit_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 5:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->textEdit_Offset4->show();
        ui->textEdit_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->textEdit_Offset5->show();
        ui->textEdit_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->textEdit_Offset6->hide();
        ui->textEdit_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 6:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->textEdit_Offset4->show();
        ui->textEdit_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->textEdit_Offset5->show();
        ui->textEdit_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->textEdit_Offset6->show();
        ui->textEdit_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->textEdit_Offset7->hide();
        ui->textEdit_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 7:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->textEdit_Offset4->show();
        ui->textEdit_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->textEdit_Offset5->show();
        ui->textEdit_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->textEdit_Offset6->show();
        ui->textEdit_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->show();
        ui->textEdit_Nome7->show();
        ui->spinBox_Inicial7->show();
        ui->spinBox_Final7->show();
        ui->textEdit_Offset7->show();
        ui->textEdit_Fator7->show();
        ui->textEdit_Unidade7->show();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->textEdit_Offset8->hide();
        ui->textEdit_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;

    case 8:
        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->textEdit_Offset1->show();
        ui->textEdit_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->textEdit_Offset2->show();
        ui->textEdit_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->textEdit_Offset3->show();
        ui->textEdit_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->textEdit_Offset4->show();
        ui->textEdit_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->textEdit_Offset5->show();
        ui->textEdit_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->textEdit_Offset6->show();
        ui->textEdit_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->show();
        ui->textEdit_Nome7->show();
        ui->spinBox_Inicial7->show();
        ui->spinBox_Final7->show();
        ui->textEdit_Offset7->show();
        ui->textEdit_Fator7->show();
        ui->textEdit_Unidade7->show();
        //Campo 8
        ui->label8->show();
        ui->textEdit_Nome8->show();
        ui->spinBox_Inicial8->show();
        ui->spinBox_Final8->show();
        ui->textEdit_Offset8->show();
        ui->textEdit_Fator8->show();
        ui->textEdit_Unidade8->show();
        break;
}
}


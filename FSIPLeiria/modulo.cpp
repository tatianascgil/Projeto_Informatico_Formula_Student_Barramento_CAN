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
    // Conectar o sinal valueChanged da spinBox_Inicial1 para atualizar o valor mínimo da spinBox_Final1
    connect(ui->spinBox_Inicial1, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final1->setMinimum(ui->spinBox_Inicial1->value());});
    // Conectar o sinal valueChanged da spinBox_Final1 para atualizar o valor mínimo da spinBox_Inicial2 + 1
    connect(ui->spinBox_Final1, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial2->setMinimum(ui->spinBox_Final1->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial2 para atualizar o valor mínimo da spinBox_Final2
    connect(ui->spinBox_Inicial2, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final2->setMinimum(ui->spinBox_Inicial2->value());});
    // Conectar o sinal valueChanged da spinBox_Final2 para atualizar o valor mínimo da spinBox_Inicial3 + 1
    connect(ui->spinBox_Final2, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial3->setMinimum(ui->spinBox_Final2->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial3 para atualizar o valor mínimo da spinBox_Final3
    connect(ui->spinBox_Inicial3, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final3->setMinimum(ui->spinBox_Inicial3->value());});
    // Conectar o sinal valueChanged da spinBox_Final3 para atualizar o valor mínimo da spinBox_Inicial4 + 1
    connect(ui->spinBox_Final3, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial4->setMinimum(ui->spinBox_Final3->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial4 para atualizar o valor mínimo da spinBox_Final4
    connect(ui->spinBox_Inicial4, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final4->setMinimum(ui->spinBox_Inicial4->value());});
    // Conectar o sinal valueChanged da spinBox_Final4 para atualizar o valor mínimo da spinBox_Inicial5 + 1
    connect(ui->spinBox_Final4, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial5->setMinimum(ui->spinBox_Final4->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial5 para atualizar o valor mínimo da spinBox_Final5
    connect(ui->spinBox_Inicial5, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final5->setMinimum(ui->spinBox_Inicial5->value());});
    // Conectar o sinal valueChanged da spinBox_Final5 para atualizar o valor mínimo da spinBox_Inicial6 + 1
    connect(ui->spinBox_Final5, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial6->setMinimum(ui->spinBox_Final5->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial6 para atualizar o valor mínimo da spinBox_Final6
    connect(ui->spinBox_Inicial6, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final6->setMinimum(ui->spinBox_Inicial6->value());});
    // Conectar o sinal valueChanged da spinBox_Final6 para atualizar o valor mínimo da spinBox_Inicial7 + 1
    connect(ui->spinBox_Final6, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial7->setMinimum(ui->spinBox_Final6->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial7 para atualizar o valor mínimo da spinBox_Final7
    connect(ui->spinBox_Inicial7, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final7->setMinimum(ui->spinBox_Inicial7->value());});
    // Conectar o sinal valueChanged da spinBox_Final7 para atualizar o valor mínimo da spinBox_Inicial8 + 1
    connect(ui->spinBox_Final7, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial8->setMinimum(ui->spinBox_Final7->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial8 para atualizar o valor mínimo da spinBox_Final8
    connect(ui->spinBox_Inicial8, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final8->setMinimum(ui->spinBox_Inicial8->value());});
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
        ui->spinBox_Inicial1->setMaximum(0);

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
        ui->spinBox_Inicial1->setMaximum(0);

        ui->spinBox_Final1->setMaximum(7);
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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(7);

        ui->spinBox_Final1->setMaximum(6);
        ui->spinBox_Final2->setMaximum(7);
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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(6);
        ui->spinBox_Inicial3->setMaximum(7);

        ui->spinBox_Final1->setMaximum(5);
        ui->spinBox_Final2->setMaximum(6);
        ui->spinBox_Final3->setMaximum(7);

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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(5);
        ui->spinBox_Inicial3->setMaximum(6);
        ui->spinBox_Inicial4->setMaximum(7);

        ui->spinBox_Final1->setMaximum(4);
        ui->spinBox_Final2->setMaximum(5);
        ui->spinBox_Final3->setMaximum(6);
        ui->spinBox_Final4->setMaximum(7);

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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(4);
        ui->spinBox_Inicial3->setMaximum(5);
        ui->spinBox_Inicial4->setMaximum(6);
        ui->spinBox_Inicial5->setMaximum(7);

        ui->spinBox_Final1->setMaximum(3);
        ui->spinBox_Final2->setMaximum(4);
        ui->spinBox_Final3->setMaximum(5);
        ui->spinBox_Final4->setMaximum(6);
        ui->spinBox_Final5->setMaximum(7);

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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(3);
        ui->spinBox_Inicial3->setMaximum(4);
        ui->spinBox_Inicial4->setMaximum(5);
        ui->spinBox_Inicial5->setMaximum(6);
        ui->spinBox_Inicial6->setMaximum(7);

        ui->spinBox_Final1->setMaximum(2);
        ui->spinBox_Final2->setMaximum(3);
        ui->spinBox_Final3->setMaximum(4);
        ui->spinBox_Final4->setMaximum(5);
        ui->spinBox_Final5->setMaximum(6);
        ui->spinBox_Final6->setMaximum(7);

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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(2);
        ui->spinBox_Inicial3->setMaximum(3);
        ui->spinBox_Inicial4->setMaximum(4);
        ui->spinBox_Inicial5->setMaximum(5);
        ui->spinBox_Inicial6->setMaximum(6);
        ui->spinBox_Inicial7->setMaximum(7);

        ui->spinBox_Final1->setMaximum(1);
        ui->spinBox_Final2->setMaximum(2);
        ui->spinBox_Final3->setMaximum(3);
        ui->spinBox_Final4->setMaximum(4);
        ui->spinBox_Final5->setMaximum(5);
        ui->spinBox_Final6->setMaximum(6);
        ui->spinBox_Final7->setMaximum(7);

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
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(1);
        ui->spinBox_Inicial3->setMaximum(2);
        ui->spinBox_Inicial4->setMaximum(3);
        ui->spinBox_Inicial5->setMaximum(4);
        ui->spinBox_Inicial6->setMaximum(5);
        ui->spinBox_Inicial7->setMaximum(6);
        ui->spinBox_Inicial8->setMaximum(7);

        ui->spinBox_Final1->setMaximum(0);
        ui->spinBox_Final2->setMaximum(1);
        ui->spinBox_Final3->setMaximum(2);
        ui->spinBox_Final4->setMaximum(3);
        ui->spinBox_Final5->setMaximum(4);
        ui->spinBox_Final6->setMaximum(5);
        ui->spinBox_Final7->setMaximum(6);
        ui->spinBox_Final8->setMaximum(7);
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


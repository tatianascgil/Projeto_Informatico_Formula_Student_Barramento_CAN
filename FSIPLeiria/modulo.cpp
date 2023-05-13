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


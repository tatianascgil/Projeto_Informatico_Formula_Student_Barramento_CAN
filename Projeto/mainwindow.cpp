#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct MyData {
    int intValue;
    char stringValue[16];
};


void MainWindow::on_pushButton_clicked()
{
QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir arquivo"), "", tr("Arquivos binários (*.bin);;Arquivos do Excel (*.xlsx *.xls)"));
    if (fileName != "") {
        QFileInfo fileInfo(fileName);
        if (fileInfo.suffix() == "bin") { // se o arquivo é binário
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo."));
                return;
            }
            QByteArray data = file.readAll();
            file.close();
            QString decodedData = QString::fromUtf8(data);
            QMessageBox::information(this, tr("Dados do arquivo"), decodedData);
        } else if (fileInfo.suffix() == "xlsx" || fileInfo.suffix() == "xls") { // se o arquivo é Excel
            QXlsx::Document xlsx(fileName);
            if (!xlsx.load()) {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo."));
                return;
            }
            QStringList sheetNames = xlsx.sheetNames();
            QString decodedData = "";
            for (int i = 0; i < sheetNames.size(); i++) {
                QXlsx::Worksheet *sheet = xlsx.sheet(sheetNames[i]);
                QList<QXlsx::CellLocation> cells = sheet->dimension().toList();
                for (int j = 0; j < cells.size(); j++) {
                    QString cellValue = sheet->read(cells[j])->value().toString();
                    decodedData += cellValue + "\t";
                }
                decodedData += "\n";
            }
            QMessageBox::information(this, tr("Dados do arquivo"), decodedData);
        } else {
            QMessageBox::warning(this, tr("Aviso"), tr("O formato do arquivo não é suportado."));
            return;
        }
    }
}


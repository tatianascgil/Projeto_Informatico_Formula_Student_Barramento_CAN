#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarmodulo.h"
#include "ui_criarmodulo.h"

#include <QDir>
#include <QStandardItemModel>

GerirCarro::GerirCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GerirCarro)
{
    ui->setupUi(this);

    lerDadosCarro();
}

GerirCarro::~GerirCarro()
{
    delete ui;
}

void GerirCarro::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}

void GerirCarro::lerDadosCarro(){
// Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "caracteristicas.txt" file within the car's folder
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        // Read the data
        QString line = stream.readLine();
        QStringList values = line.split(";");
        QList<QStringList> data;
        data.append(values);

        file.close();

        // Display the data in the QTableView
        QStandardItemModel* model = new QStandardItemModel(data.count(), values.count(), this);

        // Set the headers
        model->setHorizontalHeaderLabels({"Nome", "Tipo", "Observações"});

        // Populate the model with data
        for (int row = 0; row < data.count(); ++row) {
            for (int col = 0; col < values.count(); ++col) {
                model->setItem(row, col, new QStandardItem(data[row][col]));
            }
        }

        // Set the model to the QTableView
        ui->tableViewCarro->setModel(model);
    }
}


void GerirCarro::on_commandButtonVoltar_clicked()
{
    const int vercarroWidth = 700;
    const int vercarroHeight = 350;

    // Cria a janela principal
    VerCarro *vercarro = new VerCarro();

    // Define o tamanho mínimo e máximo da janela
    vercarro->setMinimumSize(vercarroWidth, vercarroHeight);
    vercarro->setMaximumSize(vercarroWidth, vercarroHeight);
    vercarro->show();
    this->close();
}


void GerirCarro::on_btnCriarModulo_clicked()
{
    const int criarmoduloWidth = 600;
    const int criarmoduloHeight = 250;

    // Cria a janela
    CriarModulo *criarmodulo = new CriarModulo();

    // Define o tamanho mínimo e máximo da janela
    criarmodulo->setMinimumSize(criarmoduloWidth, criarmoduloHeight);
    criarmodulo->setMaximumSize(criarmoduloWidth, criarmoduloHeight);
    criarmodulo->show();
    this->close();

}


#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarmodulo.h"
#include "ui_criarmodulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"


#include <QDir>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>


GerirCarro::GerirCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GerirCarro)
{
    ui->setupUi(this);
    connect(ui->tableViewModulosCarro, &QTableView::doubleClicked, this, &GerirCarro::openGerirModuloWindow);

}

GerirCarro::~GerirCarro()
{
    delete ui;
}

void GerirCarro::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}

void GerirCarro::openGerirModuloWindow(const QModelIndex& index)
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableViewModulosCarro->model());
    if (!model)
        return;

    int row = index.row();
    QStringList rowData;

    for (int col = 0; col < model->columnCount(); ++col) {
        QString value = model->index(row, col).data().toString();
        rowData.append(value);
    }

    QString nomeModulo = rowData.at(0);

    this->close();
    const int gerirModuloWidth = 800;
    const int gerirModuloHeight = 500;

    GerirModulo* gerirModulo = new GerirModulo(this);

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    gerirModulo->setNome(nomeCarro);

    // Define o tamanho mínimo e máximo da janela
    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);

    gerirModulo->lerDadosModulo(nomeModulo); // Pass the filtered data to the new window
    gerirModulo->lerDadosTiposMensagem(nomeModulo);
    gerirModulo->show();

}


void GerirCarro::lerDadosCarro(const QString& nome){


// Construct the path to the car's folder
    QString folderName = nome;

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

        // Set the mode of resizing for other columns
        QHeaderView* horizontalHeader = ui->tableViewCarro->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
        horizontalHeader->setStretchLastSection(false);

        // Set the model to the QTableView
        ui->tableViewCarro->setModel(model);              
    }

    // Open the "modulos.txt" file within the car's folder
    QString modulosPath = folderPath + "/modulos.txt";
    QFile modulos(modulosPath);

    if (modulos.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&modulos);

        QList<QStringList> data;

        // Read all the lines and populate the data list
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            data.append(values);
        }

        modulos.close();

        if (!data.isEmpty()) {
            // Display the data in the QTableView
            QStandardItemModel* model = new QStandardItemModel(data.count(), data[0].count(), this);

            // Set the headers
            model->setHorizontalHeaderLabels({"Nome", "Endianess", "Observações"});

            // Populate the model with data
            for (int row = 0; row < data.count(); ++row) {
                for (int col = 0; col < data[row].count(); ++col) {
                    QStandardItem* item = new QStandardItem(data[row][col]);
                    item->setEditable(false); // Set the item as read-only
                    model->setItem(row, col, item);
                }
            }

            // Set the mode of resizing for other columns
            QHeaderView* horizontalHeader = ui->tableViewModulosCarro->horizontalHeader();
            horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
            horizontalHeader->setStretchLastSection(false);

            // Set the model to the QTableView
            ui->tableViewModulosCarro->setModel(model);
        }
    }

}

void GerirCarro::on_commandButtonVoltar_clicked()
{

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();


    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Check if folderPath exists
    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        // Folder does not exist, handle the error condition
        QMessageBox::critical(this, tr("Erro"), tr("A pasta" + folderName.toUtf8() + " não existe!"));
        return;
    }

    // Open the "caracteristicas.txt" file within the car's folder
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        // Read the data
        QString line = stream.readLine();
        QStringList values = line.split(";");

        file.close();

        const int verCarroWidth = 700;
        const int verCarroHeight = 350;

        // Cria a janela VerCarro
        VerCarro *verCarro = new VerCarro();

        // Define o tamanho mínimo e máximo da janela
        verCarro->setMinimumSize(verCarroWidth, verCarroHeight);
        verCarro->setMaximumSize(verCarroWidth, verCarroHeight);

        // Set the data in the "vercarro" window's QLabel widgets
        verCarro->setNome(values[0]);
        verCarro->setTipo(values[1]);
        verCarro->setObservacoes(values[2]);

        verCarro->show();
        this->close();
    }
}


void GerirCarro::on_btnCriarModulo_clicked()
{
    const int criarModuloWidth = 600;
    const int criarModuloHeight = 250;

    // Cria a janela
    CriarModulo *criarModulo = new CriarModulo();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    criarModulo->setNome(nomeCarro);

    // Define o tamanho mínimo e máximo da janela
    criarModulo->setMinimumSize(criarModuloWidth, criarModuloHeight);
    criarModulo->setMaximumSize(criarModuloWidth, criarModuloHeight);

    criarModulo->show();
    this->close();

}


void GerirCarro::on_btnApagarCarro_clicked()
{
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Display confirmation dialog
    QMessageBox confirmation(this);

    confirmation.setWindowTitle("Apagar Pasta");
    confirmation.setText("Tem certeza que deseja apagar a pasta " + folderName + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        QDir dir(folderPath);

        if (dir.exists()) {
            if (dir.removeRecursively()) {
                // Folder deleted successfully
                QMessageBox::information(this, "Pasta Removida", "A pasta \"" + folderName + "\" foi removida com sucesso!");

                this->close();
                MainWindow *mainWindow = new MainWindow();
                mainWindow->show();
            } else {
                // Failed to delete folder
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível apagar a pasta " + folderName.toUtf8() + "!"));
            }
        } else {
            // Folder does not exist
            QMessageBox::critical(this, tr("Erro"), tr("A pasta " +  folderName.toUtf8() + " não existe!"));
        }
    }
}


void GerirCarro::on_btnGuardarCarro_clicked()
{
    QAbstractItemModel* model = ui->tableViewCarro->model();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    // Create a QVector to store the data from the QTableView
    QVector<QStringList> tableViewData;
    for (int row = 0; row < rowCount; ++row) {
        QStringList rowData;
        for (int column = 0; column < columnCount; ++column) {
            QModelIndex index = model->index(row, column);
            QVariant data = model->data(index);
            rowData.append(data.toString());
        }
        tableViewData.append(rowData);
    }

    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;
    QString filePath = folderPath + "/caracteristicas.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        // Read the data from the file
        QVector<QStringList> fileData;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split(";");
            fileData.append(values);
        }

        file.close();

        bool allValuesMatch = true;
        // Compare the file data with the modified data from the QTableView
        for (int row = 0; row < tableViewData.size(); ++row) {
            QStringList tableViewRowData = tableViewData[row];
            QStringList fileRowData = fileData.value(row);

            if (fileRowData != tableViewRowData) {
                allValuesMatch = false;
                break;
            }
        }

        // If all values match, prompt the user with an error message
        if (allValuesMatch) {
            QMessageBox::critical(this, tr("Erro"), tr("Não houve dados alterados!"));
                return;
        }

        // Display confirmation dialog
        QMessageBox confirmation(this);
        confirmation.setWindowTitle("Confirmar Atualização");
        confirmation.setText("Algumas informações foram alteradas. Tem certeza de que deseja atualizar os dados?");
        confirmation.setIcon(QMessageBox::Question);

        // Translate the buttons
        QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
        confirmation.addButton("Não", QMessageBox::NoRole);

        confirmation.exec();

        if (confirmation.clickedButton() == yesButton) {
            // User confirmed, write the data from the QTableView to the file
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                for (const QStringList& rowData : tableViewData) {
                    out << rowData.join(";") << "\n";
                }
                file.close();

                // Inform the user about successful saving
                QMessageBox::information(this, tr("Sucesso"), tr("Dados salvos com sucesso!"));
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo para escrita."));
            }
        }

    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
    }
}


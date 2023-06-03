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
    this->close();
    const int gerirModuloWidth = 800;
    const int gerirModuloHeight = 500;

    GerirModulo* gerirModulo = new GerirModulo(this);

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    gerirModulo->setNome(nomeCarro);
    qDebug() << "Nome do carro: " << nomeCarro;

    // Define o tamanho mínimo e máximo da janela
    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);

    gerirModulo->loadModuloData(rowData); // Pass the filtered data to the new window
    gerirModulo->show();

}


void GerirCarro::lerDadosCarro(const QString& nome){


// Construct the path to the car's folder
    QString folderName = nome;
    folderName.remove(' ');

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "caracteristicas.txt" file within the car's folder
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);

    qDebug() << "File Path: " << filePath;
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
            model->setHorizontalHeaderLabels({"Nome", "Modulo", "Endianess", "Observações"});

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
        } else {
            // Handle the case when there is no data
            // For example, you can display an empty model or show a message to the user
        }
    }

}

void GerirCarro::on_commandButtonVoltar_clicked()
{

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();
    folderName.remove(' ');

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
    const int criarmoduloWidth = 600;
    const int criarmoduloHeight = 250;

    // Cria a janela
    CriarModulo *criarmodulo = new CriarModulo();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    criarmodulo->setNome(nomeCarro);

    qDebug() << "Nome do carro: " << nomeCarro;

    // Define o tamanho mínimo e máximo da janela
    criarmodulo->setMinimumSize(criarmoduloWidth, criarmoduloHeight);
    criarmodulo->setMaximumSize(criarmoduloWidth, criarmoduloHeight);

    criarmodulo->show();
    this->close();

}


void GerirCarro::on_btnApagarCarro_clicked()
{
    QString folderName = ui->labelNomeCarro->text();
    folderName.remove(' ');

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
                qDebug() << "Failed to delete folder: " << folderPath;
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível apagar a pasta " + folderName.toUtf8() + "!"));
            }
        } else {
            // Folder does not exist
            qDebug() << "Folder does not exist: " << folderPath;
            QMessageBox::critical(this, tr("Erro"), tr("A pasta " +  folderName.toUtf8() + " não existe!"));
        }
    } else {
        // User canceled the deletion
        qDebug() << "Folder deletion canceled by user.";
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
    folderName.remove(' ');

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;
    QString filePath = folderPath + "/caracteristicas.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        // Read the data from the file
        int row = 0;
        bool allValuesMatch = true;
        while (!in.atEnd() && row < tableViewData.size()) {
            QString line = in.readLine();

            // Split the line into values (assuming tab-separated values)
            QStringList fileData = line.split(";");

            // Compare each value with the corresponding value from the QTableView
            for (int column = 0; column < fileData.size(); ++column) {
                QString fileValue = fileData[column];
                QString tableViewValue = tableViewData[row][column];

                // Perform the necessary comparison
                if (fileValue != tableViewValue) {
                    allValuesMatch = false;
                    break;
                }
            }

            ++row;
        }

        file.close();

        // Update the visibility of the btnGuardarFicheiro button based on the comparison results
        ui->btnGuardarCarro->setVisible(!allValuesMatch);

        // If at least one value does not match, prompt the user for confirmation before updating the file
        if (!allValuesMatch) {
            // Set the translated button texts
            QMessageBox msgBox(QMessageBox::Question, tr("Confirmar Atualização"), tr("Algumas informações foram alteradas. Tem certeza de que deseja atualizar os dados?"), QMessageBox::Yes | QMessageBox::No, this);

            QAbstractButton* yesButton = msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
            msgBox.addButton(tr("Não"), QMessageBox::NoRole);

            msgBox.exec();

            if (msgBox.clickedButton() == yesButton) {
                // User confirmed, write the data from the QTableView to the file
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    for (const QStringList& rowData : tableViewData) {
                        out << rowData.join(";") << "\n";
                    }
                    file.close();
                } else {
                    QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
                }
            }
        }
    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
    }
}


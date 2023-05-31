#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarmodulo.h"
#include "ui_criarmodulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QDebug>


GerirCarro::GerirCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GerirCarro)
{
    ui->setupUi(this);

    // Connect the dataChanged signal to the updateButtonVisibility slot
    connect(ui->tableViewCarro->model(), &QAbstractItemModel::dataChanged, this, &GerirCarro::updateButtonVisibility);

}

GerirCarro::~GerirCarro()
{
    delete ui;
}

void GerirCarro::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
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

        // Set the model to the QTableView
        ui->tableViewCarro->setModel(model);
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

// Function to update the button visibility dynamically
void GerirCarro::updateButtonVisibility()
{
    qDebug() << "Im here!";
    QAbstractItemModel* model = ui->tableViewCarro->model();

    // Check if the current data matches the initial data
    bool anyValueDifferent = false;
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QVariant currentData = model->data(index);
            QVariant initialData = model->data(index, Qt::UserRole); // Assuming initial data is stored in UserRole

            if (currentData != initialData) {
                anyValueDifferent = true;
                break;
            }
        }

        if (anyValueDifferent) {
            break;
        }
    }

    ui->btnGuardarCarro->setVisible(anyValueDifferent);
}
void GerirCarro::on_btnGuardarCarro_clicked()
{
    QAbstractItemModel* model = ui->tableViewCarro->model();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

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

        int row = 0;
        bool allValuesMatch = true;
        while (!in.atEnd() && row < tableViewData.size()) {
            QString line = in.readLine();
            QStringList fileData = line.split(";");

            for (int column = 0; column < fileData.size(); ++column) {
                QString fileValue = fileData[column];
                QString tableViewValue = tableViewData[row][column];

                if (fileValue != tableViewValue) {
                    allValuesMatch = false;
                    break;
                }
            }

            ++row;
        }

        file.close();

        if (!allValuesMatch) {

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
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    for (const QStringList& rowData : tableViewData) {
                        out << rowData.join(";") << "\n";
                    }
                    file.close();

                    QMessageBox::information(this, "Dados guardados", "Os dados foram guardados com sucesso!");


                } else {
                    QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
                }
            }
        }
        else{
            QMessageBox::information(this, "Dados não alterados", "Não houve dados alterados!");
        }
    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
    }
}


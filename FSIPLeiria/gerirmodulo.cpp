#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "criartipomensagem.h"
#include "ui_criartipomensagem.h"
#include "gerirtipomensagem.h"
#include "ui_gerirtipomensagem.h"

#include <QElapsedTimer>
#include <QDir>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>


GerirModulo::GerirModulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirModulo)
{
    ui->setupUi(this);

    connect(ui->tableViewTipodeMensagemModulo, &QTableView::doubleClicked, this, &GerirModulo::openGerirTipoMensagemWindow);
}

GerirModulo::~GerirModulo()
{
    delete ui;
}

void GerirModulo::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
}

void GerirModulo::setNomeModulo(const QString& nome){
    ui->labelNomeModulo->setText(nome.trimmed());
}

void GerirModulo::openGerirTipoMensagemWindow(const QModelIndex& index)
{

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableViewTipodeMensagemModulo->model());
    if (!model)
        return;

    int row = index.row();
    QStringList rowData;

    for (int col = 0; col < model->columnCount(); ++col) {
        QString value = model->index(row, col).data().toString();
        rowData.append(value);
    }

    this->close();
    const int gerirTipoMensagemWidth = 800;
    const int gerirTipoMensagemHeight = 600;

    GerirTipoMensagem* gerirTipoMensagem = new GerirTipoMensagem(this);

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();
    QString codHex = rowData.at(0);
    QString obs = rowData.at(1);

    gerirTipoMensagem->setNome(nomeCarro);
    gerirTipoMensagem->setNomeModulo(nomeModulo);
    gerirTipoMensagem->setCodigoHexadecimal(codHex);
    gerirTipoMensagem->setObservacoes(obs);
    gerirTipoMensagem->lerDadosTipoMensagem();



    // Define o tamanho mínimo e máximo da janela
    gerirTipoMensagem->setMinimumSize(gerirTipoMensagemWidth, gerirTipoMensagemHeight);
    gerirTipoMensagem->setMaximumSize(gerirTipoMensagemWidth, gerirTipoMensagemHeight);

    gerirTipoMensagem->show();

}



void GerirModulo::lerDadosTiposMensagem(const QString& nomeModulo)
{

    ui->labelNomeModulo->setText(nomeModulo);
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString modulosPath = folderPath + "/tiposMensagem.txt";
    QFile modulos(modulosPath);


    if (modulos.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&modulos);

        QList<QStringList> filteredData; // To store the filtered data

        // Read all the lines and filter the data based on nomeModulo
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            if (values.size() > 0 && values.at(0) == nomeModulo) {
                filteredData.append(values.mid(1, 2));
            }
        }

        modulos.close();

        if (!filteredData.isEmpty()) {
            // Display the filtered data in the QTableView
            QStandardItemModel* model = new QStandardItemModel(filteredData.count(), filteredData[0].count(), this);


            // Set the headers
            model->setHorizontalHeaderLabels({"Código Hex", "Observações"});

            // Populate the model with filtered data
            for (int row = 0; row < filteredData.count(); ++row) {
                for (int col = 0; col < filteredData[row].count(); ++col) {
                    QStandardItem* item = new QStandardItem(filteredData[row][col]);
                    item->setEditable(false); // Set the item as read-only
                    model->setItem(row, col, item);
                }
            }

            // Set the mode of resizing for other columns
            QHeaderView* horizontalHeader = ui->tableViewTipodeMensagemModulo->horizontalHeader();

            horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
            horizontalHeader->setStretchLastSection(false);

            // Set the model to the QTableView
            ui->tableViewTipodeMensagemModulo->setModel(model);
        }
    }
}


void GerirModulo::lerDadosModulo(const QString& nomeModulo)
{

    ui->labelNomeModulo->setText(nomeModulo);
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString modulosPath = folderPath + "/modulos.txt";
    QFile modulos(modulosPath);

    if (modulos.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&modulos);

        QList<QStringList> filteredData; // To store the filtered data

        // Read all the lines and filter the data based on nomeModulo
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            if (values.size() > 0 && values.at(0) == nomeModulo) {
                filteredData.append(values.mid(0,3));
            }
        }

        modulos.close();

        if (!filteredData.isEmpty()) {
            // Display the filtered data in the QTableView
            QStandardItemModel* model = new QStandardItemModel(filteredData.count(), filteredData[0].count(), this);

            // Set the headers
            model->setHorizontalHeaderLabels({"Nome", "Endianess", "Observações"});

            // Populate the model with filtered data
            for (int row = 0; row < filteredData.count(); ++row) {
                for (int col = 0; col < filteredData[row].count(); ++col) {
                    model->setItem(row, col, new QStandardItem(filteredData[row][col]));
                }
            }

            // Set the mode of resizing for other columns
            QHeaderView* horizontalHeader = ui->tableViewModulosCarro->horizontalHeader();

            horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
            horizontalHeader->setStretchLastSection(false);

            // Set the model to the QTableView
            ui->tableViewModulosCarro->setModel(model);
        } else {
            // Handle the case when there is no filtered data
            // For example, you can display an empty model or show a message to the user
            QStandardItemModel* emptyModel = new QStandardItemModel(0, 4, this);
            // Set the headers
            emptyModel->setHorizontalHeaderLabels({"Nome", "Modulo", "Endianess", "Observações"});
            // Set the empty model to the QTableView
            ui->tableViewModulosCarro->setModel(emptyModel);
        }
    }
}



void GerirModulo::on_btnGuardarModulo_clicked()
{
    QAbstractItemModel* model = ui->tableViewModulosCarro->model();
    int selectedRow = ui->tableViewModulosCarro->currentIndex().row();
    int selectedColumn = ui->tableViewModulosCarro->currentIndex().column();

    // Make sure a valid cell is selected
    if (selectedRow >= 0 && selectedRow < model->rowCount() && selectedColumn >= 0 && selectedColumn < model->columnCount()) {
        QString folderName = ui->labelNomeCarro->text();
        QString currentPath = QDir::currentPath();
        QString targetDir = currentPath + "/../FSIPLeiria/settings";
        QString folderPath = targetDir + "/" + folderName;
        QString filePath = folderPath + "/modulos.txt";

        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Read the data from the file
            QStringList fileData;
            while (!file.atEnd()) {
                QString line = file.readLine().trimmed();
                fileData.append(line);
            }

            file.close();

            // Update the selected cell's value in the fileData
            if (selectedRow < fileData.size()) {
                QStringList rowData = fileData[selectedRow].split(";");
                if (selectedColumn < rowData.size()) {
                    rowData.replace(selectedColumn, model->data(model->index(selectedRow, selectedColumn)).toString());
                    fileData[selectedRow] = rowData.join(";");
                } else {
                    QMessageBox::critical(this, tr("Erro"), tr("A coluna selecionada não existe."));
                    return;
                }
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("A linha selecionada não existe."));
                return;
            }

            // Write the updated data to the file
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                for (const QString& line : fileData) {
                    out << line << "\n";
                }
                file.close();

                // Inform the user about successful saving
                QMessageBox::information(this, tr("Sucesso"), tr("Dados salvos com sucesso!"));
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
            }
        } else {
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
        }
    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Selecione uma célula válida para atualizar."));
    }


}



void GerirModulo::on_commandButtonVoltar_clicked()
{

    // Cria a janela GerirCarro
    GerirCarro *gerirCarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text();


    // Define o tamanho mínimo e máximo da janela
    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);

    gerirCarro->setNome(nomeCarro);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);

    gerirCarro->show();
    this->close();
}


void GerirModulo::on_btnApagarModulo_clicked()
{
    QString folderName = ui->labelNomeCarro->text().trimmed();
    QString moduloName = ui->labelNomeModulo->text().trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString modulosPath = folderPath + "/modulos.txt";


    qDebug() << "Modulos: " << modulosPath;

    // Check if the modulos.txt file exists
    if (!QFile::exists(modulosPath)) {
        QMessageBox::critical(this, tr("Erro"), tr("O arquivo modulos.txt não existe!"));
        return;
    }

    // Display confirmation dialog
    QMessageBox confirmation(this);

    confirmation.setWindowTitle("Apagar Módulo");
    confirmation.setText("Tem certeza que deseja apagar o módulo " + moduloName + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        // Open the modulos.txt file
        QFile modulosFile(modulosPath);

        if (modulosFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&modulosFile);

            // Read all the lines and create a new list without the line to be deleted
            QList<QStringList> newModulosData;
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                QStringList values = line.split(";");
                if (values[0] != moduloName) {  // Change index to match the column of the module name
                    newModulosData.append(values);
                }
            }

            modulosFile.resize(0); // Clear the file content

            // Write the updated data to the modulos.txt file
            for (const QStringList& rowData : newModulosData) {
                QString line = rowData.join(";") + "\n";
                stream << line;
            }

            modulosFile.close();

            // Folder deleted successfully
            QMessageBox::information(this, "Módulo Removido", "O módulo \"" + moduloName + "\" foi removido com sucesso!");

            this->close();

            // Cria a janela GerirCarro
            GerirCarro *gerirCarro = new GerirCarro();

            QString nomeCarro = ui->labelNomeCarro->text().trimmed();

            gerirCarro->setNome(nomeCarro);
            gerirCarro->lerDadosCarro(nomeCarro);
            gerirCarro->lerDadosModulo(nomeCarro);
            gerirCarro->show();

        } else {
            // Failed to open modulos.txt file for editing
            qDebug() << "Failed to open modulos.txt file for editing: " << modulosPath;
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo modulos.txt para edição!"));
        }
    } else {
        // User canceled the deletion
        qDebug() << "Module deletion canceled by user.";
    }
}


void GerirModulo::on_btnCriarTipoMensagem_clicked()
{

    const int criarTipoMensagemWidth = 700;
    const int criarTipoMensagemHeight = 250;

    CriarTipoMensagem* criarTipoMensagem = new CriarTipoMensagem(this);

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();

    criarTipoMensagem->setNome(nomeCarro);
    criarTipoMensagem->setNomeModulo(nomeModulo);


    // Define o tamanho mínimo e máximo da janela
    criarTipoMensagem->setMinimumSize(criarTipoMensagemWidth, criarTipoMensagemHeight);
    criarTipoMensagem->setMaximumSize(criarTipoMensagemWidth, criarTipoMensagemHeight);
    criarTipoMensagem->show();
    this->close();
}


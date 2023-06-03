#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtWidgets>
#include <QComboBox>
#include <QPushButton>
#include <QDir>
#include <QSettings>
#include <QDebug>

#include <QTextStream>
#include <QStandardItemModel>
#include <QStandardItem>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modulo.h"
#include "ui_modulo.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarcarro.h"
#include "ui_criarcarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Connect the currentIndexChanged signal of the comboBoxCarro to a custom slot
    connect(ui->comboBoxCarro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleComboBoxIndexChanged);

    // Update the initial visibility of the button
    handleComboBoxIndexChanged(ui->comboBoxCarro->currentIndex());


    // Load the last selected option:
    QString lastSelectedOption = loadLastSelectedOption();
    populateComboBox(lastSelectedOption);

    // Connect the currentIndexChanged signal of comboBoxCarro to a lambda slot:
    QObject::connect(ui->comboBoxCarro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
        QString selectedOption = ui->comboBoxCarro->currentText();
        saveLastSelectedOption(selectedOption);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

struct MyData {
    int intValue;
    char stringValue[16];
};\




void MainWindow::on_btnVerCarro_clicked()
{

    // Construct the path to the car's folder
    QString folderName = ui->comboBoxCarro->currentText();

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


void MainWindow::on_btnCriarCarro_clicked()
{
        const int criarcarroWidth = 600;
        const int criarcarroHeight = 250;


        // Cria a janela principal
        CriarCarro *criarcarro = new CriarCarro();


        // Define o tamanho mínimo e máximo da janela
        criarcarro->setMinimumSize(criarcarroWidth, criarcarroHeight);
        criarcarro->setMaximumSize(criarcarroWidth, criarcarroHeight);

        // Connect the carNameEntered signal to the setComboBoxSelectedValue slot
//        connect(criarcarro, &CriarCarro::carNameEntered, this, &MainWindow::setComboBoxSelectedValue);

        criarcarro->show();
        this->close();
}


void MainWindow::on_btnEstatisticas_clicked()
{
        const int estatisticasWidth = 800;
        const int estatisticasHeight = 500;

        // Cria a janela principal
        Estatisticas *estatisticas = new Estatisticas();

        // Define o tamanho mínimo e máximo da janela
        estatisticas->setMinimumSize(estatisticasWidth, estatisticasHeight);
        estatisticas->setMaximumSize(estatisticasWidth, estatisticasHeight);
        estatisticas->show();
        this->close();
}

QString MainWindow::loadLastSelectedOption()
{
        QSettings settings("FSIPLeiria", "FSIPLeiria");
        return settings.value("lastSelectedOption").toString();
}

void MainWindow::saveLastSelectedOption(const QString& selectedOption)
{
        QSettings settings("FSIPLeiria", "FSIPLeiria");
        settings.setValue("lastSelectedOption", selectedOption);
}


void MainWindow::populateComboBox(QString option)
{
        QComboBox* comboBox = ui->comboBoxCarro;

        QString settingsDir = QDir::currentPath() + "/../FSIPLeiria/settings";
        QDir directory(settingsDir);
        QStringList folders = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        qDebug() << "Folders: " << folders;
        ui->comboBoxCarro->clear();
        ui->comboBoxCarro->addItems(folders);

        qDebug() << "Combo Box Items: " << comboBox->count();

        ui->comboBoxCarro->setCurrentText(option);
}

void MainWindow::handleComboBoxIndexChanged(int index)
{
    if (ui->btnVerCarro && ui->btnDuplicarCarro) {
        // If index is -1, no option is selected
        bool isButtonVisible = (index != -1);
        ui->btnVerCarro->setVisible(isButtonVisible);
        ui->btnDuplicarCarro->setVisible(isButtonVisible);
    }
}




void MainWindow::on_btnDuplicarCarro_clicked()
{
    QString nomeCarro = ui->comboBoxCarro->currentText();

    QString folderName = nomeCarro.trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString sourceFolderPath = targetDir + "/" + folderName;

    // Ask the user for the new folder name
    QString newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite o nome da nova pasta:"));

    while (!newFolderName.isEmpty() && QDir(targetDir + "/" + newFolderName).exists()) {
        QMessageBox::critical(this, tr("Erro"), tr("A pasta com o nome especificado já existe!"));

        newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite outro nome para a nova pasta:"));
    }

    if (!newFolderName.isEmpty()) {

        // Check if the new folder name contains the invalid character ";"
        if (newFolderName.contains(';')) {
            QMessageBox::critical(this, tr("Erro"), tr("O nome da pasta não pode conter o caracter ';'."));

            newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite outro nome para a nova pasta:"));
        }

        QString newFolderPath = targetDir + "/" + newFolderName;

        // Create the new folder
        if (!QDir().mkdir(newFolderPath)) {
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível criar a nova pasta!"));
            return;
        }

        // Copy the contents of the source folder to the new folder
        QDir(sourceFolderPath).setNameFilters(QStringList("*.*"));
        QStringList files = QDir(sourceFolderPath).entryList();
        foreach (QString file, files) {
            QString sourceFilePath = sourceFolderPath + "/" + file;
            QString destFilePath = newFolderPath + "/" + file;
            QFile::copy(sourceFilePath, destFilePath);
        }

        // Iterate over the .txt files in the new folder and replace the first element with the new folder's name
        QDir newFolderDir(newFolderPath);
        QStringList txtFiles = QStringList("caracteristicas.txt");

        foreach (const QString& txtFile, txtFiles) {
            QString filePath = newFolderDir.absoluteFilePath(txtFile);

            QFile file(filePath);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                QString content = file.readAll();
                file.seek(0);

                // Replace the first element with the new folder's name
                QStringList elements = content.split(';');
                elements.replace(0, newFolderName);
                QString newContent = elements.join(';');

                file.write(newContent.toUtf8());
                file.close();
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo: ") + txtFile);
            }
        }


        // Inform the user that the folder has been duplicated
        QMessageBox::information(this, tr("Pasta Duplicada"), tr("A pasta foi duplicada com sucesso!"));

        populateComboBox(newFolderName);
    }
}





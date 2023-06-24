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
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "criarcarro.h"
#include "ui_criarcarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"
#include "tabeladados.h"
#include "ui_tabeladados.h"

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
    QString nomeCarro = ui->comboBoxCarro->currentText();

    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;

    // Cria a janela VerCarro
    GerirCarro *gerirCarro = new GerirCarro();

    // Define o tamanho mínimo e máximo da janela
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);


    // Set the data in the "vercarro" window's QLabel widgets
    gerirCarro->setNome(nomeCarro);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);

    gerirCarro->show();
    this->close();

}


void MainWindow::on_btnCriarCarro_clicked()
{
        const int criarCarroWidth = 600;
        const int criarCarroHeight = 250;


        // Cria a janela principal
        CriarCarro *criarCarro = new CriarCarro();


        // Define o tamanho mínimo e máximo da janela
        criarCarro->setMinimumSize(criarCarroWidth, criarCarroHeight);
        criarCarro->setMaximumSize(criarCarroWidth, criarCarroHeight);
        criarCarro->loadTiposCarro();

        criarCarro->show();
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





void MainWindow::on_btnTabelaDados_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(this, "Selecione um ficheiro", QDir::homePath(), "Text Files (*.txt)");

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        const int tabelaDadosWidth = 1000;
        const int tabelaDadosHeight = 700;

        // Cria a janela principal
        TabelaDados *tabelaDados = new TabelaDados();

        // Define o tamanho mínimo e máximo da janela
        tabelaDados->setMinimumSize(tabelaDadosWidth, tabelaDadosHeight);
        tabelaDados->setMaximumSize(tabelaDadosWidth, tabelaDadosHeight);

        QString nomeCarro = ui->comboBoxCarro->currentText().trimmed();
        tabelaDados->setNome(nomeCarro);
        tabelaDados->setModulos(nomeCarro);
        tabelaDados->setOperador();
        tabelaDados->loadMensagens(filePath);
        tabelaDados->show();
        this->close();
    }

}

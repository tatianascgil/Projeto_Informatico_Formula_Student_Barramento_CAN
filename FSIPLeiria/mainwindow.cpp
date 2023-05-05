#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtWidgets>
#include <QComboBox>

#include <QTextStream>
#include <QStandardItemModel>
#include <QStandardItem>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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


    // Connect the modelChanged() signal of the table view's model to a slot
    connect(ui->tableView->model(), SIGNAL(modelChanged()), this, SLOT(updateSaveButtonVisibility()));


    ui->btnCreateFile->setPlaceholderText("Criar Ficheiro");
    ui->btnSaveFile->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct MyData {
    int intValue;
    char stringValue[16];
};\

    void MainWindow::on_btnReadFile_clicked()
{
    // Open a file dialog to select a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Binary Files (*.bin);;Excel Files (*.xls *.xlsx *.csv)"));

    if (fileName.isEmpty()) {
        return;
    }

    // Determine the file type
    QString fileType = QFileInfo(fileName).suffix();

    if (fileType == "bin") {
        // Read the binary data from the file
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
            return;
        }

        QByteArray data = file.readAll();
        file.close();

        // Show the data in a new window
        QString decodedData = QString::fromUtf8(data);

//        // Add the text to the plainTextEdit
//        ui->plainTextEdit->appendPlainText(decodedData);

//        // Display the data in the plainTextEdit widget
//        ui->plainTextEdit->setPlainText(decodedData);
    }
    else if (fileType == "xls" || fileType == "xlsx") {
        QXlsx::Document xlsx(fileName);
        if (xlsx.load()) {
            QStringList headers;
            QList<QList<QString>> rows;
            for (int row = 1; row <= xlsx.dimension().rowCount(); ++row) {
                QList<QString> rowData;
                for (int col = 1; col <= xlsx.dimension().columnCount(); ++col) {
                    QXlsx::Cell *cell = xlsx.cellAt(row, col);
                    if (cell != nullptr) {
                        QString value = cell->value().toString();
                        if (row == 1) {
                            headers.append(value);
                        } else {
                            rowData.append(value);
                        }
                    }
                }
                if (row != 1 && !rowData.isEmpty()) {
                    rows.append(rowData);
                }
            }

            // Create a table model and add the headers and rows
            QStandardItemModel *model = new QStandardItemModel(rows.count(), headers.count(), this);
            model->setHorizontalHeaderLabels(headers);
            for (int i = 0; i < rows.count(); ++i) {
                QList<QString> row = rows.at(i);
                for (int j = 0; j < row.count(); ++j) {
                    QString value = row.at(j);
                    QStandardItem *item = new QStandardItem(value);
                    model->setItem(i, j, item);
                }
            }

            // Set the model for the existing table view
            ui->tableView->setModel(model);

            // Set the table view to resize the rows and columns to fit the contents
            ui->tableView->resizeColumnsToContents();
            ui->tableView->resizeRowsToContents();

        }
    }
    else if (fileType == "csv") {
        // Read the CSV data from the file
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
            return;
        }

        QTextStream stream(&file);
        QStringList headers;
        QList<QList<QString>> rows;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            if (headers.isEmpty()) {
                headers = values;
            } else {
                QList<QString> row;
                for (int i = 0; i < values.count(); ++i) {
                    QString value = values.at(i);
                    if (!value.isEmpty()) {
                        row.append(value);
                    }
                }
                if (!row.isEmpty()) {
                    rows.append(row);
                }
            }
        }
        file.close();

        // Create a table model and add the headers and rows
        QStandardItemModel *model = new QStandardItemModel(rows.count(), headers.count(), this);
        model->setHorizontalHeaderLabels(headers);
        for (int i = 0; i < rows.count(); ++i) {
            QList<QString> row = rows.at(i);
            for (int j = 0; j < row.count(); ++j) {
                QString value = row.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(i, j, item);
            }
        }

        // Set the model for the existing table view
        ui->tableView->setModel(model);

        // Set the table view to resize the rows and columns to fit the contents
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }


    else {
        // Show an error message if the file type is not supported
        QMessageBox::critical(this, tr("Error"), tr("Tipo de ficheiro não suportado."));
        return;
    }

    updateSaveButtonVisibility();
}


void MainWindow::updateSaveButtonVisibility()
{
    bool hasData = ui->tableView->model() && ui->tableView->model()->rowCount() > 0;
    ui->btnSaveFile->setVisible(hasData);
}










void MainWindow::on_btnSaveFile_clicked()
{
    // Create a QFileDialog object to allow the user to select the output file location and name.
    QFileDialog fileDialog;
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setDefaultSuffix("xlsx");
    QString fileName = fileDialog.getSaveFileName();

    // Check if the output file name is valid.
    if (fileName.isEmpty()) {
        return;
    }

    // Create a QXlsx::Document object to represent the Excel file.
    QXlsx::Document xlsxDoc(fileName);

    // Add a new worksheet to the Excel document.
    xlsxDoc.addSheet("Sheet1");

    // Traverse the QTableView and add the table data to the Excel worksheet.
    QAbstractItemModel* model = ui->tableView->model();
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QVariant data = model->data(index);
            if (data.isValid()) {
                xlsxDoc.write(row + 1, col + 1, data.toString());
            }
        }
    }

    // Save the Excel document to the output file.
    xlsxDoc.saveAs(fileName);

}


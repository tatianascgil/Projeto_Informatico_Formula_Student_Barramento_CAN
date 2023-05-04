#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtWidgets>
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
        QMessageBox::information(this, tr("Dados do arquivo"), decodedData);
    }
    else if (fileType == "xls" || fileType == "xlsx") {
        // Read the Excel data from the file
        QXlsx::Document xlsx(fileName);
        if (!xlsx.load()) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
            return;
        }

        QStringList sheetNames = xlsx.sheetNames();
        QString data;
        for (int i = 0; i < sheetNames.size(); i++) {
            QXlsx::AbstractSheet *abstractSheet = xlsx.sheet(sheetNames[i]);
            QXlsx::Worksheet *sheet = dynamic_cast<QXlsx::Worksheet*>(abstractSheet);
            if (sheet) {
                QXlsx::CellRange range = sheet->dimension();
                for (int row = range.firstRow(); row <= range.lastRow(); row++) {
                    for (int col = range.firstColumn(); col <= range.lastColumn(); col++) {
                        QXlsx::Cell *cell = sheet->cellAt(row, col);
                        if (cell) {
                            QString cellValue = cell->value().toString();
                            data += cellValue + "\t";
                        }
                    }
                }
                data += "\n";
            }
        }

        // Show the data in a new window
        QMessageBox::information(this, tr("Dados do arquivo"), data);


    }
    else if(fileType == "csv"){
        QFile file(fileName);
        QString data;
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split(",");
                // Process each field in the line
                for (int i = 0; i < fields.size(); i++) {
                    data += fields[i] + "\t";
                }
                data += "\n";
            }
            file.close();
        }

        // Show the data in a new window

        // Declare a QPlainTextEdit widget
        QPlainTextEdit *plainTextEdit = new QPlainTextEdit(this);
        plainTextEdit->setReadOnly(true); // Set the widget as read-only

        // Create a new layout and set it on the widget
        QVBoxLayout *layout = new QVBoxLayout();
        if (ui->plainTextEdit->layout() == nullptr) {
            ui->plainTextEdit->setLayout(layout);
        }

        // Add the text to the plainTextEdit
        ui->plainTextEdit->appendPlainText(data);

        // Display the data in the plainTextEdit widget
        plainTextEdit->setPlainText(data);

    }
    else {
        // Show an error message if the file type is not supported
        QMessageBox::critical(this, tr("Error"), tr("Unsupported file type."));
        return;
    }
}



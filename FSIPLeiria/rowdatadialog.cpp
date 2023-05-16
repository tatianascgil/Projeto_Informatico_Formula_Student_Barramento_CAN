#include "RowDataDialog.h"
#include "ui_RowDataDialog.h"
#include <QStandardItemModel>

RowDataDialog::RowDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RowDataDialog)
{
    ui->setupUi(this);
}

RowDataDialog::~RowDataDialog()
{
    delete ui;
}

void RowDataDialog::setRowData(const QList<QString>& rowData)
{
    // Create a model to store the row data
    QStandardItemModel* model = new QStandardItemModel(1, rowData.count(), this);

    // Set the data of the model
    for (int col = 0; col < rowData.count(); ++col) {
        QString value = rowData.at(col);
        QStandardItem* item = new QStandardItem(value);
        model->setItem(0, col, item);
    }

    // Set the model for the table view
    ui->tableView->setModel(model);
    // Set the table view to resize the rows and columns to fit the contents
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"

#include <QDir>

GerirModulo::GerirModulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirModulo)
{
    ui->setupUi(this);
}

GerirModulo::~GerirModulo()
{
    delete ui;
}

void GerirModulo::loadModuloData(const QStringList& data)
{
     QString nomeModulo = data.at(0);

    ui->labelNomeModulo->setText(nomeModulo);

   //  QString folderName = nome;

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "modulos.txt" file within the car's folder
    QString modulosPath = folderPath + "/modulos.txt";
    QFile modulos(modulosPath);

    qDebug() << "Modulos: " << modulosPath;
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
    }
}

void GerirModulo::on_btnGuardarModulo_clicked()
{

}


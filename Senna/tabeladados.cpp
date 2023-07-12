#include "tabeladados.h"
#include "ui_tabeladados.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include "xlsxdocument.h"

TabelaDados::TabelaDados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabelaDados)
{
    ui->setupUi(this);

    connect(ui->comboBoxModulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCodigosHex);
    connect(ui->comboBoxCodigoHEX, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCampos);

    connect(ui->comboBoxModulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::filtrarComboBoxs);
    connect(ui->comboBoxCodigoHEX, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::filtrarComboBoxs);
    connect(ui->comboBoxCampo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::filtrarComboBoxs);


}

TabelaDados::~TabelaDados()
{
    delete ui;
}

void TabelaDados::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
}

void TabelaDados::setModulos(const QString& nome){

    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/modulos.txt";
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);

    QString placeholderText = ui->comboBoxModulo->placeholderText();
    ui->comboBoxModulo->addItem(placeholderText);
    ui->comboBoxModulo->addItem("Desconhecido");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(";");

        for (const QString& value : values) {
            QString firstValue = value.trimmed();
            if (!firstValue.isEmpty()) {
                ui->comboBoxModulo->addItem(firstValue);
                break;  // Add only the first value of each line
            }
        }
    }

    file.close();

}

void TabelaDados::setCodigosHex(int index){

    QString selectedModulo = ui->comboBoxModulo->itemText(index);
    ui->comboBoxCodigoHEX->clear();

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);

    QString placeholderText = ui->comboBoxCodigoHEX->placeholderText();
    ui->comboBoxCodigoHEX->addItem(placeholderText);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(";");

        if (values.size() >= 2 && values.at(0).trimmed() == selectedModulo) {
            QString secondValue = values.at(1).trimmed();
            if (!secondValue.isEmpty()) {
                ui->comboBoxCodigoHEX->addItem(secondValue);
            }
        }
    }

    file.close();

}

void TabelaDados::setCampos(int index){
    QString selectedCodHex = ui->comboBoxCodigoHEX->itemText(index);
    ui->comboBoxCampo->clear();

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);
    QStringList campos;

    QString placeholderText = ui->comboBoxCampo->placeholderText();
    if (!placeholderText.isEmpty()) {
        campos.append(placeholderText);
    }

    // Read the file line by line
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(';');

        if (values.size() >= 5 && values.at(1).trimmed() == selectedCodHex) {
            QString value = values.at(4).trimmed();
            if (!value.isEmpty()) {
                campos.append(value);
            }
        }

        for (int i = 10; i < values.size(); i += 6) {
            if (values.size() >= i + 1 && values.at(1).trimmed() == selectedCodHex) {
                QString value = values.at(i).trimmed();
                if (!value.isEmpty()) {
                    campos.append(value);
                }
            }
        }
    }

    file.close();

    // Add the non-empty values to the comboBoxCampo
    ui->comboBoxCampo->clear();
    ui->comboBoxCampo->addItems(campos);
}




long TabelaDados::littleEndianConversion(const QStringList& fieldValues)
{
    QStringList binaryValues;
    QString line;

    for (int i = 0; i < fieldValues.length(); i++)
    {
        QString binary = QString::number(fieldValues[i].toInt(), 2).rightJustified(8, '0');
        binaryValues.append(binary);
        line += binary;
    }

    long decimalValue = line.toInt(nullptr, 2);

    return decimalValue;
}

long TabelaDados::bigEndianConversion(const QStringList& fieldValues)
{
    QStringList binaryValues;
    QString line;

    for (int i = fieldValues.length() - 1; i >= 0; i--)
    {
        QString binary = QString::number(fieldValues[i].toInt(), 2).rightJustified(8, '0');
        binaryValues.append(binary);
        line += binary;
    }

    long decimalValue = line.toInt(nullptr, 2);

    return decimalValue;
}



void TabelaDados::loadMensagens(const QString& filePath) {
    QString nomeCarro = ui->labelNomeCarro->text();
    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        model = new QStandardItemModel(this);

        // Step 1: Read "tiposMensagem.txt" and store its contents
        QMap<QString, QString> tiposMensagem;

        QString tiposMensagemPath = folderPath + "/tiposMensagem.txt";
        QFile tiposFile(tiposMensagemPath);
        if (tiposFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream tiposIn(&tiposFile);

            while (!tiposIn.atEnd()) {
                QString tiposLine = tiposIn.readLine();
                QStringList tiposColumns = tiposLine.split(';');

                if (tiposColumns.length() > 3) {
                    QString secondValue = tiposColumns[1];
                    tiposMensagem[secondValue] = tiposLine;
                }
            }

            tiposFile.close();
        }


        // Set headers for the first 3 columns
        model->setHorizontalHeaderItem(0, new QStandardItem("Timestamp"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Módulo"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Código Hexadecimal"));

        // Add headers "Campo 1" to "Campo 8"
        for (int i = 3; i < 11; ++i) {
            QString headerText = QString("Campo %1").arg(i - 2);
            model->setHorizontalHeaderItem(i, new QStandardItem(headerText));
        }

        int totalMensagens = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList columns = line.split(';');
            QString hexadecimalCode = QString::number(columns[1].toInt(), 16);

            QList<QStandardItem*> rowItems;
            totalMensagens++;
            ui->labelNMensagens->setText(QString::number(totalMensagens));



            if (columns.length() > 1 && tiposMensagem.contains(hexadecimalCode)) {
                QString tiposLine = tiposMensagem[hexadecimalCode];
                QStringList tiposColumns = tiposLine.split(';');

                // Append modified fields into the table
                QString timestamp = columns[0];
                QString moduleName = tiposColumns[0];
                QString hexCode = tiposColumns[1];
                QString formattedTimestamp;
                for(int i = 0; i < timestamp.length() - 1; i+=2){
                    formattedTimestamp += timestamp.mid(i,2) + ":";
                }
                formattedTimestamp.chop(1);

                rowItems.append(new QStandardItem(formattedTimestamp));
                rowItems.append(new QStandardItem(moduleName));
                rowItems.append(new QStandardItem(hexCode));

                // Check if the first value of tiposMensagem matches the first value of modulos.txt
                bool moduleNameMatch = false;
                QString endianessValue;

                QString modulosPath = folderPath + "/modulos.txt";
                QFile modulosFile(modulosPath);

                if (modulosFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream modulosIn(&modulosFile);

                    while (!modulosIn.atEnd()) {
                        QString modulosLine = modulosIn.readLine();
                        QStringList modulosColumns = modulosLine.split(';');

                        if (modulosColumns.length() > 0 && modulosColumns[0] == moduleName) {
                            moduleNameMatch = true;
                            endianessValue = modulosColumns[1];
                            break;
                        }
                    }

                    modulosFile.close();
                }

                if (moduleNameMatch) {
                    qDebug() << "Endianess:" << endianessValue;
                    // Calculate byte length of each field
                    int fieldCount = tiposColumns[3].toInt();
                    int columnIndex = 2;

                    for (int j = 0; j < fieldCount; j++) {
                        QString fieldName = tiposColumns[4 + (j * 6)] + ": ";
                        QString metric = tiposColumns[9 + (j * 6)];
                        int startByte = tiposColumns[5 + (j * 6)].toInt();
                        int endByte = tiposColumns[6 + (j * 6)].toInt();
                        int byteLength = endByte - startByte + 1;
                        QString offset = tiposColumns[7 + (j * 6)];
                        offset.replace(",",".");
                        QString factor = tiposColumns[8 + (j * 6)];
                        factor.replace(",",".");

                        QString fieldValue;
                        long fieldConversionResult;
                        if (byteLength == 1) {
                            fieldValue = columns[columnIndex++];
                            fieldName += fieldValue + metric;
                        } else {
                            QStringList fieldValues;
                            for (int k = 0; k < byteLength; k++) {
                                fieldValues.prepend(columns[columnIndex++]);
                            }
                            qDebug() << "Field Values:" << fieldValues;
                            fieldValue = fieldValues.join("");
                            if (endianessValue == "Little Endian") {
                                fieldConversionResult = littleEndianConversion(fieldValues);
                                qDebug() << "FieldConversionResult:" << fieldConversionResult;
                            } else {
                                fieldConversionResult = bigEndianConversion(fieldValues);
                                qDebug() << "FieldConversionResult:" << fieldConversionResult;
                            }

                            if(offset.isEmpty() && factor.isEmpty()){
                                 fieldName += QString::number(fieldConversionResult);
                            }
                            else if(!offset.isEmpty() && !factor.isEmpty()){
                                 fieldConversionResult += offset.toFloat();
                                 fieldConversionResult *= factor.toFloat();
                                 fieldName += QString::number(fieldConversionResult);
                                 qDebug() << "Converted FieldConversionResult:" << fieldConversionResult;
                                 qDebug() << "Offset:" << offset.toFloat() << " Factor:" << factor.toFloat() << "\n";
                            }
                            else if(!offset.isEmpty()){
                                 fieldConversionResult += offset.toFloat();
                                 fieldName += QString::number(fieldConversionResult);
                                 qDebug() << "Converted FieldConversionResult:" << fieldConversionResult;
                                 qDebug() << "Offset:" << offset.toFloat() << "\n";
                            }
                            else if(!factor.isEmpty()){
                                 fieldConversionResult *= factor.toFloat();
                                 fieldName += QString::number(fieldConversionResult);
                                 qDebug() << "Converted FieldConversionResult:" << fieldConversionResult;
                                 qDebug() << "Factor:" << factor.toFloat() << "\n";
                            }
                            if(!metric.isEmpty()){
                                 fieldName += metric;
                            }
                        }
                        rowItems.append(new QStandardItem(fieldName));
                    }
                }
            } else {
                QString timestamp = columns[0];
                QString formattedTimestamp;
                for (int i = 0; i < timestamp.length() - 1; i += 2) {
                    formattedTimestamp += timestamp.mid(i, 2) + ":";
                }
                formattedTimestamp.chop(1);

                rowItems.append(new QStandardItem(formattedTimestamp));
                rowItems.append(new QStandardItem("Desconhecido"));

                for (int i = 1; i < columns.size(); ++i) {
                    bool ok;
                    QString hexValue = QString::number(columns[i].toInt(), 16).toUpper();
                    rowItems.append(new QStandardItem(hexValue));
                }
            }
            model->appendRow(rowItems);
            ui->tableViewTabelaDados->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }

        file.close();


        // Step 3: Set the model for the tableViewTabelaDados
        ui->tableViewTabelaDados->setModel(model);
    }
}



void TabelaDados::filtrarComboBoxs()
{

    QString selectedModulo = ui->comboBoxModulo->currentText();
    QString selectedCodHex = ui->comboBoxCodigoHEX->currentText();
    QString selectedCampo = ui->comboBoxCampo->currentText();


    QString moduloPlaceholder = ui->comboBoxModulo->placeholderText();
    QString codHexPlaceholder = ui->comboBoxCodigoHEX->placeholderText();
    QString campoPlaceholder = ui->comboBoxCampo->placeholderText();




    if(selectedModulo == moduloPlaceholder){
        ui->tableViewTabelaDados->setModel(model);
        int totalMessages = model->rowCount();
        ui->labelNMensagens->setText(QString::number(totalMessages));

        return;
    }

    filteredModel = new QStandardItemModel(this);

    bool addHeaders = false;

    if ((selectedModulo.isEmpty() || selectedModulo == moduloPlaceholder) &&
        (selectedCodHex.isEmpty() || selectedCodHex == codHexPlaceholder) &&
        (selectedCampo.isEmpty() || selectedCampo == campoPlaceholder))
    {
        addHeaders = true;
    }



    QSet<QString> uniqueRows;
    if(selectedCodHex == codHexPlaceholder || selectedCodHex.isEmpty()){
        for (int row = 0; row < model->rowCount(); row++) {
            QStandardItem* moduloItem = model->item(row, 1);
            if (moduloItem) {
                QString modulo = moduloItem->text();
                if (modulo == selectedModulo) {
                    // Generate a unique identifier for the row
                    QString rowIdentifier = QString("%1").arg(row);

                    // Check if the row has already been added to the filteredModel
                    if (!uniqueRows.contains(rowIdentifier)) {
                        uniqueRows.insert(rowIdentifier);

                        QList<QStandardItem*> rowItems;
                        for (int col = 0; col < model->columnCount(); col++) {
                            QStandardItem* item = model->item(row, col);
                            if (item)
                                 rowItems.append(new QStandardItem(item->text()));
                        }
                        filteredModel->appendRow(rowItems);
                    }

                    filteredModel->setHorizontalHeaderItem(0, new QStandardItem("Timestamp"));
                    filteredModel->setHorizontalHeaderItem(1, new QStandardItem("Módulo"));
                    filteredModel->setHorizontalHeaderItem(2, new QStandardItem("Código Hexadecimal"));


                    ui->tableViewTabelaDados->setModel(filteredModel);

                    // Set the label with the partialMessages/totalMessages format
                    int partialMessages = filteredModel->rowCount();
                    int totalMessages = model->rowCount();
                    QString labelFormat = QString("%1/%2").arg(partialMessages).arg(totalMessages);
                    ui->labelNMensagens->setText(labelFormat);
                }
            }
        }
    }

    for (int row = 0; row < model->rowCount(); row++) {
        QStandardItem* moduloItem = model->item(row, 1);
        QStandardItem* codHexItem = model->item(row, 2);

        if (moduloItem && codHexItem) {
            QString modulo = moduloItem->text();
            QString codHex = codHexItem->text();
            if (modulo == selectedModulo) {
                addHeaders = true;
                if (codHex == selectedCodHex) {
                    addHeaders = false;
                    if (selectedCampo != campoPlaceholder && !selectedCampo.isEmpty()) {
                        QList<QStandardItem*> rowItems;
                        for (int col = 0; col < model->columnCount(); col++) {
                            if (col > 2) {
                                 QStandardItem* item = model->item(row, col);
                                 if (item) {
                                     QString text = item->text();
                                     QString fieldName;
                                     QString fieldValue;

                                     // Extract fieldName and fieldValue from text
                                     bool isFieldName = true;
                                     for (int i = 0; i < text.length(); i++) {
                                         if (text[i] == ':') {
                                             isFieldName = false;
                                         } else {
                                             if (isFieldName) {
                                                 fieldName += text[i];
                                             } else {
                                                 fieldValue += text[i];
                                             }
                                         }
                                     }

                                     if (fieldName == selectedCampo) {
                                         // Create QStandardItem for fieldValue only
                                         QStandardItem* fieldItem = new QStandardItem(fieldValue);
                                         rowItems.append(fieldItem);
                                         // Set the header of the column with fieldName
                                         filteredModel->setHorizontalHeaderItem(rowItems.size() - 1, new QStandardItem(fieldName));
                                     }
                                 }
                            } else {
                                 QStandardItem* item = model->item(row, col);
                                 if (item)
                                     rowItems.append(new QStandardItem(item->text()));
                            }
                        }
                        if (!rowItems.isEmpty()) {
                            filteredModel->appendRow(rowItems);
                        }
                    }else {
                        QList<QStandardItem*> rowItems;
                        for (int col = 0; col < model->columnCount(); col++) {
                            if(col > 2){
                                 QStandardItem* item = model->item(row, col);
                                 if (item) {
                                     QString text = item->text();
                                     QString fieldName;
                                     QString fieldValue;

                                     // Extract fieldName and fieldValue from text
                                     bool isFieldName = true;
                                     for (int i = 0; i < text.length(); i++) {
                                         if (text[i] == ':') {
                                             isFieldName = false;
                                         } else {
                                             if (isFieldName) {
                                                 fieldName += text[i];
                                             } else {
                                                 fieldValue += text[i];
                                             }
                                         }
                                     }

                                     // Create QStandardItem for fieldValue only
                                     QStandardItem* fieldItem = new QStandardItem(fieldValue);
                                     rowItems.append(fieldItem);
                                     // Set the header of the column with fieldName
                                     filteredModel->setHorizontalHeaderItem(col, new QStandardItem(fieldName));
                                 }
                            }else{
                                 QStandardItem* item = model->item(row, col);
                                 if (item)
                                     rowItems.append(new QStandardItem(item->text()));
                            }
                        }
                        filteredModel->appendRow(rowItems);
                    }
                }else if(selectedCodHex.isEmpty() || selectedCodHex == codHexPlaceholder){
                    // Generate a unique identifier for the row
                    QString rowIdentifier = QString("%1").arg(row);

                    // Check if the row has already been added to the filteredModel
                    if (!uniqueRows.contains(rowIdentifier)) {
                        uniqueRows.insert(rowIdentifier);

                        QList<QStandardItem*> rowItems;
                        for (int col = 0; col < model->columnCount(); col++) {
                            QStandardItem* item = model->item(row, col);
                            if (item)
                                 rowItems.append(new QStandardItem(item->text()));
                        }
                        filteredModel->appendRow(rowItems);
                    }
                }
            }

            if (addHeaders) {
                // Add headers "Campo 1" to "Campo 8"
                int columnCount = filteredModel->columnCount();
                qDebug() << "Column Count:" << columnCount;
                for (int i = 3; i < columnCount; ++i) {
                    QString headerText = QString("Campo %1").arg(i - 2);
                    filteredModel->setHorizontalHeaderItem(i, new QStandardItem(headerText));
                }
            }
        }
    }
    filteredModel->setHorizontalHeaderItem(0, new QStandardItem("Timestamp"));
    filteredModel->setHorizontalHeaderItem(1, new QStandardItem("Módulo"));
    filteredModel->setHorizontalHeaderItem(2, new QStandardItem("Código Hexadecimal"));

    ui->tableViewTabelaDados->setModel(filteredModel);

    // Set the label with the partialMessages/totalMessages format
    int partialMessages = filteredModel->rowCount();
    int totalMessages = model->rowCount();
    QString labelFormat = QString("%1/%2").arg(partialMessages).arg(totalMessages);
    ui->labelNMensagens->setText(labelFormat);
}



void TabelaDados::on_commandButtonVoltar_clicked()
{

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Voltar atrás");
    confirmation.setText("Tem a certeza que pretende voltar atrás?");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
     // User canceled the operation
     return;
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void TabelaDados::on_btnGuardar_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "XLSX Files (*.xlsx);;CSV Files (*.csv)");

    if (!filePath.isEmpty()) {
        // Get the table model
        QAbstractItemModel* tableModel = ui->tableViewTabelaDados->model();

        // Get the header information
        QStringList headers;
        for (int column = 0; column < tableModel->columnCount(); ++column) {
            QVariant headerData = tableModel->headerData(column, Qt::Horizontal);
            headers.append(headerData.toString());
        }

        // Save as XLSX
        if (filePath.endsWith(".xlsx")) {
            // Create a new Excel file
            QXlsx::Document xlsx;

            // Write the headers to the first row
            for (int column = 0; column < headers.size(); ++column) {
                xlsx.write(1, column + 1, headers.at(column));
            }

            // Get the number of rows and columns
            int rowCount = tableModel->rowCount();
            int columnCount = tableModel->columnCount();

            // Iterate over the table and save the data to the Excel file
            for (int row = 0; row < rowCount; ++row) {
                for (int column = 0; column < columnCount; ++column) {
                    QModelIndex index = tableModel->index(row, column);
                    QVariant data = tableModel->data(index);
                    xlsx.write(row + 2, column + 1, data); // Offset row by 1 due to headers
                }
            }

            // Save the Excel file
            xlsx.saveAs(filePath);
        }
        // Save as CSV
        else if (filePath.endsWith(".csv")) {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);

                // Write the headers to the CSV file
                for (int column = 0; column < headers.size(); ++column) {
                    out << headers.at(column);
                    if (column < headers.size() - 1) {
                        out << ",";
                    }
                }
                out << "\n";

                // Get the number of rows and columns
                int rowCount = tableModel->rowCount();
                int columnCount = tableModel->columnCount();

                // Iterate over the table and save the data to the CSV file
                for (int row = 0; row < rowCount; ++row) {
                    for (int column = 0; column < columnCount; ++column) {
                        QModelIndex index = tableModel->index(row, column);
                        QVariant data = tableModel->data(index);
                        out << data.toString();
                        if (column < columnCount - 1) {
                            out << ",";
                        }
                    }
                    out << "\n";
                }

                file.close();
            }
        }
    }
}


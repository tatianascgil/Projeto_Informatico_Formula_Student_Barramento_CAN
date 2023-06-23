#include "tabeladados.h"
#include "ui_tabeladados.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMessageBox>

TabelaDados::TabelaDados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabelaDados)
{
    ui->setupUi(this);


    connect(ui->comboBoxModulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCodigosHex);
    connect(ui->comboBoxCodigoHEX, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCampos);

    connect(ui->comboBoxModulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::filtrarComboBoxs);
    connect(ui->comboBoxCodigoHEX, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::filtrarComboBoxs);

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
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
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
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
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
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
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


void TabelaDados::setOperador(){
    ui->comboBoxOperador->setPlaceholderText(" ");
    QString placeholderText = ui->comboBoxOperador->placeholderText();

    ui->comboBoxOperador->addItem(placeholderText);
    ui->comboBoxOperador->addItem("=");
    ui->comboBoxOperador->addItem("<=");
    ui->comboBoxOperador->addItem(">=");
    ui->comboBoxOperador->addItem("<");
    ui->comboBoxOperador->addItem(">");
}

long TabelaDados::littleEndianConversion(const QStringList& fieldValues)
{
    QStringList binaryValues;
    QString line;

    for (int i = 0; i < fieldValues.length(); i++)
    {
        QString binary = QString::number(fieldValues[i].toInt(), 2).rightJustified(8, '0');
        qDebug() << "Binary:" << binary;
        binaryValues.append(binary);
        line += binary;
        qDebug() << "Line:" << line;
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
        qDebug() << "Binary:" << binary;
        binaryValues.append(binary);
        line += binary;
        qDebug() << "Line:" << line;
    }

    long decimalValue = line.toInt(nullptr, 2);

    return decimalValue;
}



void TabelaDados::loadMensagens(const QString& filePath) {
    QString nomeCarro = ui->labelNomeCarro->text();
    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
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

                rowItems.append(new QStandardItem(timestamp));
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

                        QString fieldValue;
                        QString decimalValue;
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
                                qDebug() << "Before Little Endian Conversion - fieldValue:" << fieldValue;
                                fieldConversionResult = littleEndianConversion(fieldValues);
                                qDebug() << "After Little Endian Conversion - fieldConversionResult:" << fieldConversionResult;
                            } else {
                                qDebug() << "Before Big Endian Conversion - fieldValue:" << fieldValue;
                                fieldConversionResult = bigEndianConversion(fieldValues);
                                qDebug() << "After Big Endian Conversion - fieldConversionResult:" << fieldConversionResult;
                            }
                            // Append the decimal value to fieldName before appending the metric
                            fieldName += QString::number(fieldConversionResult);
                            fieldName += metric;
                        }


                        rowItems.append(new QStandardItem(fieldName));
                    }

                }
            } else {
                for (const QString& column : columns) {
                    rowItems.append(new QStandardItem(column));
                }
            }

            model->appendRow(rowItems);
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


    if(selectedModulo == ui->comboBoxModulo->placeholderText()){
        ui->tableViewTabelaDados->setModel(model);
        int totalMessages = model->rowCount();
        ui->labelNMensagens->setText(QString::number(totalMessages));
        return;
    }

    QStandardItemModel* filteredModel = new QStandardItemModel(this);

    if(selectedCodHex == ui->comboBoxCodigoHEX->placeholderText()){
        for (int row = 0; row < model->rowCount(); row++) {
            QStandardItem* moduloItem = model->item(row, 1);
            if (moduloItem) {
                QString modulo = moduloItem->text();
                if (modulo == selectedModulo) {
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
    }



    for (int row = 0; row < model->rowCount(); row++) {
        QStandardItem* moduloItem = model->item(row, 1);
        QStandardItem* codHexItem = model->item(row, 2);

        if (moduloItem && codHexItem) {
            QString modulo = moduloItem->text();
            QString codHex = codHexItem->text();

            if (selectedModulo.isEmpty() || modulo == selectedModulo) {
                if (codHex == selectedCodHex) {
                    if (selectedCampo.isEmpty() || rowHasMatchingCampo(row, selectedCampo)) {
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
                }else if(selectedCodHex.isEmpty()){
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

bool TabelaDados::rowHasMatchingCampo(int row, const QString& selectedCampo) const
{
    QModelIndex index = model->index(row, 4);
    if (index.isValid()) {
        QString campo = index.data().toString();
        return campo.contains(selectedCampo, Qt::CaseInsensitive);
    }
    return false;
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


void TabelaDados::on_btnFiltrar_clicked()
{

}


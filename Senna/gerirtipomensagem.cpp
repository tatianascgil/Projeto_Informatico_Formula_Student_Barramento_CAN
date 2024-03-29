#include "gerirtipomensagem.h"
#include "ui_gerirtipomensagem.h"
#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>


GerirTipoMensagem::GerirTipoMensagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirTipoMensagem)
{
    ui->setupUi(this);

    // Conectar o sinal valueChanged da spinBox_Inicial1 para atualizar o valor mínimo da spinBox_Final1
    connect(ui->spinBox_Inicial1, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final1->setMinimum(ui->spinBox_Inicial1->value());});
    // Conectar o sinal valueChanged da spinBox_Final1 para atualizar o valor mínimo da spinBox_Inicial2 + 1
    connect(ui->spinBox_Final1, QOverload<int>::of(&QSpinBox::valueChanged), [=](){
        ui->spinBox_Inicial2->setMinimum(ui->spinBox_Final1->value() + 1);
    });
    // Conectar o sinal valueChanged da spinBox_Inicial2 para atualizar o valor mínimo da spinBox_Final2
    connect(ui->spinBox_Inicial2, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final2->setMinimum(ui->spinBox_Inicial2->value());});
    // Conectar o sinal valueChanged da spinBox_Final2 para atualizar o valor mínimo da spinBox_Inicial3 + 1
    connect(ui->spinBox_Final2, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial3->setMinimum(ui->spinBox_Final2->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial3 para atualizar o valor mínimo da spinBox_Final3
    connect(ui->spinBox_Inicial3, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final3->setMinimum(ui->spinBox_Inicial3->value());});
    // Conectar o sinal valueChanged da spinBox_Final3 para atualizar o valor mínimo da spinBox_Inicial4 + 1
    connect(ui->spinBox_Final3, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial4->setMinimum(ui->spinBox_Final3->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial4 para atualizar o valor mínimo da spinBox_Final4
    connect(ui->spinBox_Inicial4, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final4->setMinimum(ui->spinBox_Inicial4->value());});
    // Conectar o sinal valueChanged da spinBox_Final4 para atualizar o valor mínimo da spinBox_Inicial5 + 1
    connect(ui->spinBox_Final4, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial5->setMinimum(ui->spinBox_Final4->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial5 para atualizar o valor mínimo da spinBox_Final5
    connect(ui->spinBox_Inicial5, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final5->setMinimum(ui->spinBox_Inicial5->value());});
    // Conectar o sinal valueChanged da spinBox_Final5 para atualizar o valor mínimo da spinBox_Inicial6 + 1
    connect(ui->spinBox_Final5, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial6->setMinimum(ui->spinBox_Final5->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial6 para atualizar o valor mínimo da spinBox_Final6
    connect(ui->spinBox_Inicial6, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final6->setMinimum(ui->spinBox_Inicial6->value());});
    // Conectar o sinal valueChanged da spinBox_Final6 para atualizar o valor mínimo da spinBox_Inicial7 + 1
    connect(ui->spinBox_Final6, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial7->setMinimum(ui->spinBox_Final6->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial7 para atualizar o valor mínimo da spinBox_Final7
    connect(ui->spinBox_Inicial7, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final7->setMinimum(ui->spinBox_Inicial7->value());});
    // Conectar o sinal valueChanged da spinBox_Final7 para atualizar o valor mínimo da spinBox_Inicial8 + 1
    connect(ui->spinBox_Final7, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Inicial8->setMinimum(ui->spinBox_Final7->value()+1);});

    // Conectar o sinal valueChanged da spinBox_Inicial8 para atualizar o valor mínimo da spinBox_Final8
    connect(ui->spinBox_Inicial8, QOverload<int>::of(&QSpinBox::valueChanged), [=](){ ui->spinBox_Final8->setMinimum(ui->spinBox_Inicial8->value());});

    ui->labelInicial->hide();
    ui->labelFinal->hide();
    ui->labelOffset->hide();
    ui->labelFator->hide();
    ui->labelUnidade->hide();


    //Campo 1
    ui->label1->hide();
    ui->textEdit_Nome1->hide();
    ui->spinBox_Inicial1->hide();
    ui->spinBox_Final1->hide();
    ui->doubleSpinBox_Offset1->hide();
    ui->doubleSpinBox_Fator1->hide();
    ui->textEdit_Unidade1->hide();
    //Campo 2
    ui->label2->hide();
    ui->textEdit_Nome2->hide();
    ui->spinBox_Inicial2->hide();
    ui->spinBox_Final2->hide();
    ui->doubleSpinBox_Offset2->hide();
    ui->doubleSpinBox_Fator2->hide();
    ui->textEdit_Unidade2->hide();
    //Campo 3
    ui->label3->hide();
    ui->textEdit_Nome3->hide();
    ui->spinBox_Inicial3->hide();
    ui->spinBox_Final3->hide();
    ui->doubleSpinBox_Offset3->hide();
    ui->doubleSpinBox_Fator3->hide();
    ui->textEdit_Unidade3->hide();
    //Campo 4
    ui->label4->hide();
    ui->textEdit_Nome4->hide();
    ui->spinBox_Inicial4->hide();
    ui->spinBox_Final4->hide();
    ui->doubleSpinBox_Offset4->hide();
    ui->doubleSpinBox_Fator4->hide();
    ui->textEdit_Unidade4->hide();
    //Campo 5
    ui->label5->hide();
    ui->textEdit_Nome5->hide();
    ui->spinBox_Inicial5->hide();
    ui->spinBox_Final5->hide();
    ui->doubleSpinBox_Offset5->hide();
    ui->doubleSpinBox_Fator5->hide();
    ui->textEdit_Unidade5->hide();
    //Campo 6
    ui->label6->hide();
    ui->textEdit_Nome6->hide();
    ui->spinBox_Inicial6->hide();
    ui->spinBox_Final6->hide();
    ui->doubleSpinBox_Offset6->hide();
    ui->doubleSpinBox_Fator6->hide();
    ui->textEdit_Unidade6->hide();
    //Campo 7
    ui->label7->hide();
    ui->textEdit_Nome7->hide();
    ui->spinBox_Inicial7->hide();
    ui->spinBox_Final7->hide();
    ui->doubleSpinBox_Offset7->hide();
    ui->doubleSpinBox_Fator7->hide();
    ui->textEdit_Unidade7->hide();
    //Campo 8
    ui->label8->hide();
    ui->textEdit_Nome8->hide();
    ui->spinBox_Inicial8->hide();
    ui->spinBox_Final8->hide();
    ui->doubleSpinBox_Offset8->hide();
    ui->doubleSpinBox_Fator8->hide();
    ui->textEdit_Unidade8->hide();

}

GerirTipoMensagem::~GerirTipoMensagem()
{
    delete ui;
}


void GerirTipoMensagem::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
}

void GerirTipoMensagem::setNomeModulo(const QString& nome){
    ui->labelNomeModulo->setText(nome.trimmed());
}

void GerirTipoMensagem::setCodigoHexadecimal(const QString& codHex) {
    QString finalValue = codHex.mid(2); // Remove the first two characters (0x)
    ui->labelCodHex->setText(finalValue.trimmed());
}

void GerirTipoMensagem::setObservacoes(const QString& obs){
    ui->plainTextEditObs->setPlainText(obs.trimmed());
}

void GerirTipoMensagem::lerDadosTipoMensagem(){
    QString codHex = ui->labelCodHex->text().toUpper();
    QString nomeCarro = ui->labelNomeCarro->text();

    QString folderName = nomeCarro;

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QTextStream out(&file);

    QStringList updatedLines;  // Store updated lines

    while (!out.atEnd()) {
        QString currentLine = out.readLine();
        QStringList values = currentLine.split(';');
        // Check the 4th value
        if (values.size() >= 4 && values[1].trimmed().toUpper() == codHex) {
            // Index for widgets
            int index = 1;
            ui->spinBox->setValue(values[3].toInt());
            for (int i = 4; i + 5 < values.size(); i += 6) {
                QString valueNome = values[i].trimmed();
                QString valueInicial = values[i + 1].trimmed();
                QString valueFinal = values[i + 2].trimmed();
                QString valueOffset = values[i + 3].trimmed();
                QString valueFator = values[i + 4].trimmed();
                QString valueUnidade = values[i + 5].trimmed();

                QTextEdit *textEditNome = findChild<QTextEdit*>("textEdit_Nome" + QString::number(index));
                if (!textEditNome) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget textEdit_Nome" + QString::number(index));
                    return;
                }
                textEditNome->setPlainText(valueNome);

                QSpinBox *spinBoxInicial = findChild<QSpinBox*>("spinBox_Inicial" + QString::number(index));
                if (!spinBoxInicial) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget spinBox_Inicial" + QString::number(index));
                    return;
                }
                spinBoxInicial->setValue(valueInicial.toInt());

                QSpinBox *spinBoxFinal = findChild<QSpinBox*>("spinBox_Final" + QString::number(index));
                if (!spinBoxFinal) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget spinBox_Final" + QString::number(index));
                    return;
                }
                spinBoxFinal->setValue(valueFinal.toInt());

                QDoubleSpinBox *doubleSpinBoxOffset = findChild<QDoubleSpinBox*>("doubleSpinBox_Offset" + QString::number(index));
                if (!doubleSpinBoxOffset) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget doubleSpinBox_Offset" + QString::number(index));
                    return;
                }
                doubleSpinBoxOffset->setValue(valueOffset.toInt());

                QDoubleSpinBox *doubleSpinBoxFator = findChild<QDoubleSpinBox*>("doubleSpinBox_Fator" + QString::number(index));
                if (!doubleSpinBoxFator) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget doubleSpinBox_Fator" + QString::number(index));
                    return;
                }
                doubleSpinBoxFator->setValue(valueFator.toInt());

                QTextEdit *textEditUnidade = findChild<QTextEdit*>("textEdit_Unidade" + QString::number(index));
                if (!textEditUnidade) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget textEdit_Unidade" + QString::number(index));
                    return;
                }
                textEditUnidade->setPlainText(valueUnidade);

                // Increment the index for the next set of widgets
                index++;
            }

            // Update the current line with the new values
            currentLine = values.join(";");  // Reconstruct the line
        }

        updatedLines.append(currentLine);  // Store the updated line
    }


    file.close();
}

void GerirTipoMensagem::on_btnGuardarCarro_clicked()
{

    QString codHex = ui->labelCodHex->text();
    QString obs = ui->plainTextEditObs->toPlainText();
    QString nomeCarro = ui->labelNomeCarro->text();

    if (obs.contains(";")) {
        QMessageBox::critical(this, "Erro", "É proibido utilizar semi-vírgulas ';'!");
        return;
    }

    if(obs.contains("\n")){
        QMessageBox::critical(this, "Erro", "Não é permitido criar novas linhas no campo 'Observações'!");
        return;
    }


    QString folderName = nomeCarro.trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }


    QTextStream out(&file);

    int numFields = ui->spinBox->value();

    QString obsValue = ui->plainTextEditObs->toPlainText();

    QStringList updatedLines;  // Store updated lines

    while (!out.atEnd()) {
        QString currentLine = out.readLine();
        QStringList values = currentLine.split(';');
        if (values.size() >= 2 && values[1].trimmed() == codHex) {
            values[2] = obsValue;
            values[3] = QString::number(numFields);
            currentLine = values.mid(0, 4).join(';') + ";";  // Append semicolon after the first 4 values

            QString line = currentLine;

            QSet<QString> uniqueTextEditNome;

            for (int i = 1; i <= numFields; ++i) {
                QString index = QString::number(i);

                QTextEdit *textEditNome = findChild<QTextEdit*>("textEdit_Nome" + index);
                QSpinBox *spinBoxInicial = findChild<QSpinBox*>("spinBox_Inicial" + index);
                QSpinBox *spinBoxFinal = findChild<QSpinBox*>("spinBox_Final" + index);
                QDoubleSpinBox *doubleSpinBoxOffset = findChild<QDoubleSpinBox*>("doubleSpinBox_Offset" + index);
                QDoubleSpinBox *doubleSpinBoxFator = findChild<QDoubleSpinBox*>("doubleSpinBox_Fator" + index);
                QTextEdit *textEditUnidade = findChild<QTextEdit*>("textEdit_Unidade" + index);


                if (!textEditNome) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget textEdit_Nome" + index);
                    return;
                }

                bool textEditNomeIsEmpty = textEditNome->toPlainText().isEmpty();
                bool spinBoxInicialIsEmpty = spinBoxInicial->text().isEmpty();
                bool spinBoxFinalIsEmpty = spinBoxFinal->text().isEmpty();


                if (textEditNomeIsEmpty) {
                    QMessageBox::critical(this, "Erro", "O campo Nome não pode estar vazio!");
                        return;
                }

                if(textEditNome->toPlainText().contains("\n")){
                    QMessageBox::critical(this, "Erro", "Não é permitido criar novas linhas no campo 'Nome'!");
                    return;
                }

                if(textEditUnidade->toPlainText().contains("\n")){
                    QMessageBox::critical(this, "Erro", "Não é permitido criar novas linhas no campo 'Unidade'!");
                    return;
                }


                if (spinBoxInicialIsEmpty) {
                    QMessageBox::critical(this, "Erro", "O campo Byte Inicial não pode estar vazio!");
                        return;
                }

                if (spinBoxFinalIsEmpty) {
                    QMessageBox::critical(this, "Erro", "O campo Byte Final não pode estar vazio!");
                        return;
                }


                QString textEditNomeValue = textEditNome->toPlainText();

                if (uniqueTextEditNome.contains(textEditNomeValue)) {
                    // Handle error: Duplicate textEditNome found
                    QMessageBox::critical(this, "Erro", "O nome do campo " + index + " está duplicado.");
                    return;
                }

                // Add the textEditNome value to the set
                uniqueTextEditNome.insert(textEditNomeValue);


                line += textEditNome->toPlainText() + ";";

                if (i > 1) {
                    if (!spinBoxInicial || !spinBoxFinal) {
                        // Handle error: Widget not found
                        QMessageBox::critical(this, "Erro", "Não foi possível encontrar os widgets spinBox_Inicial" + index + " e spinBox_Final" + index);
                        return;
                    }

                    if (spinBoxInicial->value() == 0 || spinBoxFinal->value() == 0) {
                        // Handle error: spinBoxInicial or spinBoxFinal is 0
                        QMessageBox::critical(this, "Erro", "Os valores do campo " + index + " Byte Inicial e Byte Final não podem ser iguais a zero");
                        return;
                    }
                }

                line += spinBoxInicial->text() + ";";

                line += spinBoxFinal->text() + ";";

                if (!doubleSpinBoxOffset) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget doubleSpinBox_Offset" + index);
                    return;
                }

                line += doubleSpinBoxOffset->text() + ";";


                if (!doubleSpinBoxFator) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget doubleSpinBox_Fator" + index);
                    return;
                }

                line += doubleSpinBoxFator->text() + ";";


                if (!textEditUnidade) {
                    // Handle error: Widget not found
                    QMessageBox::critical(this, "Erro", "Não foi possível encontrar o widget textEdit_Unidade" + index);
                    return;
                }
                line += textEditUnidade->toPlainText() + ";";
            }
            currentLine = line;
        }
        updatedLines.append(currentLine);
    }

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Guardar Dados");
    confirmation.setText("Tem a certeza que pretende guardar os dados?");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
        // User canceled the operation
        return;
    }

    // Write the updated lines back to the file
    // Clear the file content
    file.resize(0);
    out << updatedLines.join("\n") << "\n";

    file.close();

    QMessageBox::information(this, "Sucesso", "Dados salvos com sucesso!");

}


void GerirTipoMensagem::previousWindow(){
    const int gerirModuloWidth = 800;
    const int gerirModuloHeight = 500;

    // Cria a janela GerirCarro
    GerirModulo *gerirModulo= new GerirModulo();

    QString nomeCarro = ui->labelNomeCarro->text();
    QString nomeModulo = ui->labelNomeModulo->text();

    gerirModulo->setNome(nomeCarro);
    gerirModulo->setNomeModulo(nomeModulo);

    // Define o tamanho mínimo e máximo da janela
    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->lerDadosModulo(nomeModulo);
    gerirModulo->lerDadosTiposMensagem(nomeModulo);

    gerirModulo->show();
    this->close();
}


void GerirTipoMensagem::on_commandButtonVoltar_clicked()
{

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Voltar atrás");
    confirmation.setText("Tem a certeza que pretende voltar atrás? Todos os dados serão perdidos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
     // User canceled the operation
     return;
    }

    previousWindow();

}

void GerirTipoMensagem::on_commandButtonMenuPrincipal_clicked()
{
    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Voltar ao Menu Principal");
    confirmation.setText("Tem a certeza que pretende voltar para o Menu Principal? Todos os dados serão perdidos!");
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

void GerirTipoMensagem::on_btnApagar_clicked()
{
    QString nomeCarro = ui->labelNomeCarro->text();
    QString folderName = nomeCarro.trimmed();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QString codHex = ui->labelCodHex->text();

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Apagar Tipo de Mensagem");
    confirmation.setText("Tem certeza que deseja apagar o Tipo de Mensagem 0x" + codHex + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        // Open the tiposMensagem.txt file
        QFile file(filePath);

        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&file);

            // Read all the lines and create a new list excluding the line to be deleted
            QStringList newTiposMensagemData;
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                QStringList values = line.split(";");
                if (values.count() >= 2 && values[1] != codHex) {
                    newTiposMensagemData.append(line);
                }
            }

            file.resize(0); // Clear the file content

            // Write the updated data to the tiposMensagem.txt file
            for (const QString& line : newTiposMensagemData) {
                stream << line << "\n";
            }

            file.close();

            // Line deleted successfully
            QMessageBox::information(this, "Tipo de Mensagem Removido", "O Tipo de Mensagem 0x" + codHex + " foi removido com sucesso!");

            this->close();
            previousWindow();
        }
    }
}




void GerirTipoMensagem::on_spinBox_valueChanged(int arg1)
{

    // Mostrar os widgets correspondentes
    switch (arg1) {
    case 0:
        ui->spinBox_Inicial1->setMaximum(0);

        ui->labelInicial->hide();
        ui->labelFinal->hide();
        ui->labelOffset->hide();
        ui->labelFator->hide();
        ui->labelUnidade->hide();

        //Campo 1
        ui->label1->hide();
        ui->textEdit_Nome1->hide();
        ui->spinBox_Inicial1->hide();
        ui->spinBox_Final1->hide();
        ui->doubleSpinBox_Offset1->hide();
        ui->doubleSpinBox_Fator1->hide();
        ui->textEdit_Unidade1->hide();
        //Campo 2
        ui->label2->hide();
        ui->textEdit_Nome2->hide();
        ui->spinBox_Inicial2->hide();
        ui->spinBox_Final2->hide();
        ui->doubleSpinBox_Offset2->hide();
        ui->doubleSpinBox_Fator2->hide();
        ui->textEdit_Unidade2->hide();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->doubleSpinBox_Offset3->hide();
        ui->doubleSpinBox_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->doubleSpinBox_Offset4->hide();
        ui->doubleSpinBox_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->doubleSpinBox_Offset5->hide();
        ui->doubleSpinBox_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 1:
        ui->spinBox_Inicial1->setMaximum(0);

        ui->spinBox_Final1->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->hide();
        ui->textEdit_Nome2->hide();
        ui->spinBox_Inicial2->hide();
        ui->spinBox_Final2->hide();
        ui->doubleSpinBox_Offset2->hide();
        ui->doubleSpinBox_Fator2->hide();
        ui->textEdit_Unidade2->hide();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->doubleSpinBox_Offset3->hide();
        ui->doubleSpinBox_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->doubleSpinBox_Offset4->hide();
        ui->doubleSpinBox_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->doubleSpinBox_Offset5->hide();
        ui->doubleSpinBox_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 2:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(7);

        ui->spinBox_Final1->setMaximum(6);
        ui->spinBox_Final2->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->hide();
        ui->textEdit_Nome3->hide();
        ui->spinBox_Inicial3->hide();
        ui->spinBox_Final3->hide();
        ui->doubleSpinBox_Offset3->hide();
        ui->doubleSpinBox_Fator3->hide();
        ui->textEdit_Unidade3->hide();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->doubleSpinBox_Offset4->hide();
        ui->doubleSpinBox_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->doubleSpinBox_Offset5->hide();
        ui->doubleSpinBox_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;

    case 3:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(6);
        ui->spinBox_Inicial3->setMaximum(7);

        ui->spinBox_Final1->setMaximum(5);
        ui->spinBox_Final2->setMaximum(6);
        ui->spinBox_Final3->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->hide();
        ui->textEdit_Nome4->hide();
        ui->spinBox_Inicial4->hide();
        ui->spinBox_Final4->hide();
        ui->doubleSpinBox_Offset4->hide();
        ui->doubleSpinBox_Fator4->hide();
        ui->textEdit_Unidade4->hide();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->doubleSpinBox_Offset5->hide();
        ui->doubleSpinBox_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 4:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(5);
        ui->spinBox_Inicial3->setMaximum(6);
        ui->spinBox_Inicial4->setMaximum(7);

        ui->spinBox_Final1->setMaximum(4);
        ui->spinBox_Final2->setMaximum(5);
        ui->spinBox_Final3->setMaximum(6);
        ui->spinBox_Final4->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->doubleSpinBox_Offset4->show();
        ui->doubleSpinBox_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->hide();
        ui->textEdit_Nome5->hide();
        ui->spinBox_Inicial5->hide();
        ui->spinBox_Final5->hide();
        ui->doubleSpinBox_Offset5->hide();
        ui->doubleSpinBox_Fator5->hide();
        ui->textEdit_Unidade5->hide();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 5:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(4);
        ui->spinBox_Inicial3->setMaximum(5);
        ui->spinBox_Inicial4->setMaximum(6);
        ui->spinBox_Inicial5->setMaximum(7);

        ui->spinBox_Final1->setMaximum(3);
        ui->spinBox_Final2->setMaximum(4);
        ui->spinBox_Final3->setMaximum(5);
        ui->spinBox_Final4->setMaximum(6);
        ui->spinBox_Final5->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->doubleSpinBox_Offset4->show();
        ui->doubleSpinBox_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->doubleSpinBox_Offset5->show();
        ui->doubleSpinBox_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->hide();
        ui->textEdit_Nome6->hide();
        ui->spinBox_Inicial6->hide();
        ui->spinBox_Final6->hide();
        ui->doubleSpinBox_Offset6->hide();
        ui->doubleSpinBox_Fator6->hide();
        ui->textEdit_Unidade6->hide();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 6:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(3);
        ui->spinBox_Inicial3->setMaximum(4);
        ui->spinBox_Inicial4->setMaximum(5);
        ui->spinBox_Inicial5->setMaximum(6);
        ui->spinBox_Inicial6->setMaximum(7);

        ui->spinBox_Final1->setMaximum(2);
        ui->spinBox_Final2->setMaximum(3);
        ui->spinBox_Final3->setMaximum(4);
        ui->spinBox_Final4->setMaximum(5);
        ui->spinBox_Final5->setMaximum(6);
        ui->spinBox_Final6->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->doubleSpinBox_Offset4->show();
        ui->doubleSpinBox_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->doubleSpinBox_Offset5->show();
        ui->doubleSpinBox_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->doubleSpinBox_Offset6->show();
        ui->doubleSpinBox_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->hide();
        ui->textEdit_Nome7->hide();
        ui->spinBox_Inicial7->hide();
        ui->spinBox_Final7->hide();
        ui->doubleSpinBox_Offset7->hide();
        ui->doubleSpinBox_Fator7->hide();
        ui->textEdit_Unidade7->hide();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;
    case 7:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(2);
        ui->spinBox_Inicial3->setMaximum(3);
        ui->spinBox_Inicial4->setMaximum(4);
        ui->spinBox_Inicial5->setMaximum(5);
        ui->spinBox_Inicial6->setMaximum(6);
        ui->spinBox_Inicial7->setMaximum(7);

        ui->spinBox_Final1->setMaximum(1);
        ui->spinBox_Final2->setMaximum(2);
        ui->spinBox_Final3->setMaximum(3);
        ui->spinBox_Final4->setMaximum(4);
        ui->spinBox_Final5->setMaximum(5);
        ui->spinBox_Final6->setMaximum(6);
        ui->spinBox_Final7->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->doubleSpinBox_Offset4->show();
        ui->doubleSpinBox_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->doubleSpinBox_Offset5->show();
        ui->doubleSpinBox_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->doubleSpinBox_Offset6->show();
        ui->doubleSpinBox_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->show();
        ui->textEdit_Nome7->show();
        ui->spinBox_Inicial7->show();
        ui->spinBox_Final7->show();
        ui->doubleSpinBox_Offset7->show();
        ui->doubleSpinBox_Fator7->show();
        ui->textEdit_Unidade7->show();
        //Campo 8
        ui->label8->hide();
        ui->textEdit_Nome8->hide();
        ui->spinBox_Inicial8->hide();
        ui->spinBox_Final8->hide();
        ui->doubleSpinBox_Offset8->hide();
        ui->doubleSpinBox_Fator8->hide();
        ui->textEdit_Unidade8->hide();
        break;

    case 8:
        ui->spinBox_Inicial1->setMaximum(0);
        ui->spinBox_Inicial2->setMaximum(ui->spinBox_Final1->value()+1);
        ui->spinBox_Inicial3->setMaximum(ui->spinBox_Final2->value()+1);
        ui->spinBox_Inicial4->setMaximum(ui->spinBox_Final3->value()+1);
        ui->spinBox_Inicial5->setMaximum(ui->spinBox_Final4->value()+1);
        ui->spinBox_Inicial6->setMaximum(ui->spinBox_Final5->value()+1);
        ui->spinBox_Inicial7->setMaximum(ui->spinBox_Final6->value()+1);
        ui->spinBox_Inicial8->setMaximum(ui->spinBox_Final7->value()+1);

        ui->spinBox_Final1->setMaximum(0);
        ui->spinBox_Final2->setMaximum(1);
        ui->spinBox_Final3->setMaximum(2);
        ui->spinBox_Final4->setMaximum(3);
        ui->spinBox_Final5->setMaximum(4);
        ui->spinBox_Final6->setMaximum(5);
        ui->spinBox_Final7->setMaximum(6);
        ui->spinBox_Final8->setMaximum(7);

        ui->labelInicial->show();
        ui->labelFinal->show();
        ui->labelOffset->show();
        ui->labelFator->show();
        ui->labelUnidade->show();

        //Campo 1
        ui->label1->show();
        ui->textEdit_Nome1->show();
        ui->spinBox_Inicial1->show();
        ui->spinBox_Final1->show();
        ui->doubleSpinBox_Offset1->show();
        ui->doubleSpinBox_Fator1->show();
        ui->textEdit_Unidade1->show();
        //Campo 2
        ui->label2->show();
        ui->textEdit_Nome2->show();
        ui->spinBox_Inicial2->show();
        ui->spinBox_Final2->show();
        ui->doubleSpinBox_Offset2->show();
        ui->doubleSpinBox_Fator2->show();
        ui->textEdit_Unidade2->show();
        //Campo 3
        ui->label3->show();
        ui->textEdit_Nome3->show();
        ui->spinBox_Inicial3->show();
        ui->spinBox_Final3->show();
        ui->doubleSpinBox_Offset3->show();
        ui->doubleSpinBox_Fator3->show();
        ui->textEdit_Unidade3->show();
        //Campo 4
        ui->label4->show();
        ui->textEdit_Nome4->show();
        ui->spinBox_Inicial4->show();
        ui->spinBox_Final4->show();
        ui->doubleSpinBox_Offset4->show();
        ui->doubleSpinBox_Fator4->show();
        ui->textEdit_Unidade4->show();
        //Campo 5
        ui->label5->show();
        ui->textEdit_Nome5->show();
        ui->spinBox_Inicial5->show();
        ui->spinBox_Final5->show();
        ui->doubleSpinBox_Offset5->show();
        ui->doubleSpinBox_Fator5->show();
        ui->textEdit_Unidade5->show();
        //Campo 6
        ui->label6->show();
        ui->textEdit_Nome6->show();
        ui->spinBox_Inicial6->show();
        ui->spinBox_Final6->show();
        ui->doubleSpinBox_Offset6->show();
        ui->doubleSpinBox_Fator6->show();
        ui->textEdit_Unidade6->show();
        //Campo 7
        ui->label7->show();
        ui->textEdit_Nome7->show();
        ui->spinBox_Inicial7->show();
        ui->spinBox_Final7->show();
        ui->doubleSpinBox_Offset7->show();
        ui->doubleSpinBox_Fator7->show();
        ui->textEdit_Unidade7->show();
        //Campo 8
        ui->label8->show();
        ui->textEdit_Nome8->show();
        ui->spinBox_Inicial8->show();
        ui->spinBox_Final8->show();
        ui->doubleSpinBox_Offset8->show();
        ui->doubleSpinBox_Fator8->show();
        ui->textEdit_Unidade8->show();
        break;
    }
}


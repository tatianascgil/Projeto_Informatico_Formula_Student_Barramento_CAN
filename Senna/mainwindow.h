#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void populateComboBox(QString option);


private slots:


    void on_btnVerCarro_clicked();

    void on_btnCriarCarro_clicked();

    void on_btnEstatisticas_clicked();




    void on_btnDuplicarCarro_clicked();

    void on_btnTabelaDados_clicked();

private:
    Ui::MainWindow *ui;
    QString loadLastSelectedOption();
    void saveLastSelectedOption(const QString& selectedOption);
    void handleComboBoxIndexChanged(int index);
};

#endif // MAINWINDOW_H

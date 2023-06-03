
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
//    void setComboBoxSelectedValue(const QString& value);


private slots:
    void on_btnReadFile_clicked();

    void on_btnSaveFile_clicked();

    void on_btnCreateFile_activated(int index);

    void on_btnVerCarro_clicked();

    void on_btnCriarCarro_clicked();

    void on_btnEstatisticas_clicked();

    void on_btnDuplicarCarro_clicked();

private:
    Ui::MainWindow *ui;
    void updateSaveButtonVisibility();
    QString loadLastSelectedOption();
    void saveLastSelectedOption(const QString& selectedOption);
    void populateComboBox(QString option);
    void handleComboBoxIndexChanged(int index);
};

#endif // MAINWINDOW_H

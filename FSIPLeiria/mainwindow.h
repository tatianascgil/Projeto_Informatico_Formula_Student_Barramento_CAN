
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QMessageBox>
#include "RowDataDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnReadFile_clicked();

    void on_tableView_clicked(const QModelIndex& index);

    void updateSaveButtonVisibility();

    void on_btnSaveFile_clicked();

    void on_btnCreateFile_activated(int index);

    void on_btnCreateFile_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "simulation.h"
#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void calculate();
    ~MainWindow();

private slots:
    void on_calcButton_clicked();
    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;

    Simulation* model;
    QVector<double> prey;
    QVector<double> predator;
    QVector<double> time;
};

#endif // MAINWINDOW_H

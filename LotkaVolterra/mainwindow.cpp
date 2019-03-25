#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Simulation setup
    model = new Simulation;
}

void MainWindow::calculate()
{
    //Calculation of model
    model->explEulerSolve();

    //Read model data
    prey = QVector<double>::fromStdVector(model->getB());
    predator = QVector<double>::fromStdVector(model->getR());
    time = QVector<double>::fromStdVector(model->getTime());

    //Plot data
    ui->LVPlot->addGraph();
    ui->LVPlot->addGraph();
    ui->LVPlot->graph(0)->setPen(QPen(QColor(Qt::GlobalColor::green)));
    ui->LVPlot->graph(0)->setData(time, prey);
    ui->LVPlot->graph(1)->setPen(QPen(QColor(Qt::GlobalColor::red)));
    ui->LVPlot->graph(1)->setData(time, predator);
    ui->LVPlot->yAxis->rescale();
    ui->LVPlot->xAxis->rescale();
    ui->LVPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcButton_clicked()
{
    calculate();
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

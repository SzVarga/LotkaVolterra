#include "include/mainwindow.h"
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
    //Set new parametrisation
    model->set_reprB(ui->alphaSpinBox->value());
    model->set_reprR(ui->deltaSpinBox->value());
    model->set_deathB(ui->betaSpinBox->value());
    model->set_deathR(ui->gammaSpinBox->value());
    model->set_timestep(ui->dtSpinBox->value());
    model->set_tMax(ui->tMaxSpinBox->value());

    //Calculation of model
    model->implEulerSolve();

    //Read model data
    prey = QVector<double>::fromStdVector(model->getB());
    predator = QVector<double>::fromStdVector(model->getR());
    time = QVector<double>::fromStdVector(model->getTime());

    //Plot data
    ui->LVPlot->clearGraphs();
    ui->LVPlot->addGraph();
    ui->LVPlot->addGraph();
    ui->LVPlot->graph(0)->setPen(QPen(QColor(Qt::GlobalColor::green)));
    ui->LVPlot->graph(0)->setName("Prey");
    ui->LVPlot->graph(0)->setData(time, prey);
    ui->LVPlot->graph(1)->setPen(QPen(QColor(Qt::GlobalColor::red)));
    ui->LVPlot->graph(1)->setName("Predator");
    ui->LVPlot->graph(1)->setData(time, predator);
    ui->LVPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    ui->LVPlot->yAxis->setTicker(logTicker);
    ui->LVPlot->yAxis->setNumberFormat("eb");
    ui->LVPlot->yAxis->setNumberPrecision(0);
    ui->LVPlot->yAxis->rescale();
    ui->LVPlot->xAxis->rescale();
    ui->LVPlot->legend->setVisible(true);
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

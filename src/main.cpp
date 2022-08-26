#include "include/mainwindow.h"
#include <QApplication>

#include <QDebug>
#include <iostream>
#include <vector>
#include "include/simulation.h"
using std::cout; using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include "randomfact.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    RandomFact p;
    w.show();
    p.show();

    return a.exec();
}

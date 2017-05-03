#include "mainwindow.h"
#include "randomfact.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Random Facts Generator");
    w.show();

    return a.exec();
}

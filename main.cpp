#include <QApplication>
#include "mainwindow.h"
#include "generatedclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}

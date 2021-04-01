#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Create main application object.
    MainWindow w;
    // Display application on the screen.
    w.show();

    // Put an application into infinite loop.
    // In this loop events which happen inside of application are going to be handled.
    return a.exec();
}

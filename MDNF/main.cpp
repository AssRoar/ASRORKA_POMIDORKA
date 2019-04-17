#include "mainwindow.h"
//#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Widget w2;
    w.show();
//    w2.show();

    return a.exec();
}

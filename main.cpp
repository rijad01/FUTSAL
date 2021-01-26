//#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "play.h"

 play *igra;

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    igra=new play();
    igra->show();
    igra->displayMainMenu();


    return a.exec();
}

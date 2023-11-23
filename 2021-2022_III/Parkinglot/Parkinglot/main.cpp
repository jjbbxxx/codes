#include "parkinglot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Parkinglot w;

    w.show();
    w.display();


    return a.exec();
}

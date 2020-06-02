#include "car.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    car w;
    w.show();
    return a.exec();
}

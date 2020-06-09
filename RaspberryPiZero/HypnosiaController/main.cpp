#include <QApplication>
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Factory pattern
    Factory myFactory;
    myFactory.buildSystem();

    return a.exec();
}

#include <QApplication>
#include "xf/xf-core/behavior.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    XF::initialize();

    //Factory pattern
    Factory myFactory;
    myFactory.buildSystem();

    return XF::exec();
}

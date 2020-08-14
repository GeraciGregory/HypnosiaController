#include <QApplication>
#include "xf/xf-core/behavior.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    //Initialize XF
    XF::initialize();

    //Factory pattern
    Factory myFactory;
    //Build all the system
    myFactory.buildSystem();

    //Start XF behavior
    return XF::exec();
}

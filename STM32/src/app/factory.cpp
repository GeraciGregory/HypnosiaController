#include "xf/xf.h"
#include "factory.h"

//--------------------------------------------------------
// Programming language used: C
void Factory_initialize()
{
    Factory::initialize();
}
void Factory_build()
{
    Factory::build();
}
//--------------------------------------------------------
// Programming language used: C++
Factory::Factory()
{}

//Initialize the system
void Factory::initialize()
{
	Controller::getInstance()->intitialize();
}

//Start behavior of the system
void Factory::build()
{
	Controller::getInstance()->start();
}
//--------------------------------------------------------


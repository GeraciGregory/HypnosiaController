#include "xf/xf.h"
#include "factory.h"

void Factory_initialize()
{
    Factory::initialize();
}

void Factory_build()
{
    Factory::build();
}


Factory::Factory()
{}

// static
void Factory::initialize()
{
	Controller::getInstance()->intitialize();
}

// static
void Factory::build()
{
	Controller::getInstance()->start();
}



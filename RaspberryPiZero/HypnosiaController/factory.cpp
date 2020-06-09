#include "factory.h"
#include <QApplication>
#include <QDesktopWidget>

//Constructor
Factory::Factory()
{
    int screenWidth = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    view = new View(screenWidth/2,screenHeight/2,300,100,"HYPNOSIA Controller");
    controller = new Controller();
    data = new Data();   
}

//Desctructor
Factory::~Factory()
{
    delete controller;
    delete data;
    delete view;
}

//Initialize relations of MVC model
void Factory::buildSystem()
{
    view->initializeRelation(controller);
    controller->initializeRelation(data);
    data->initializeRelation(view);
}

#include "factory.h"
#include <QApplication>
#include <QDesktopWidget>

//Constructor
Factory::Factory()
{
    view = new View(300,500,300,220,"HYPNOSIA Controller");
    view->show();
    controller = new Controller(1000);
    data = new Data();   
}

//Desctructor
Factory::~Factory()
{
    delete controller;
    delete data;
    delete view;
}

Controller* Factory::controller;

//Initialize relations of MVC model
void Factory::buildSystem()
{
    cout << "Build system" << endl;
    view->initializeRelation(controller);
    controller->initializeRelation(data, view);
    controller->startBehavior();
    data->initializeRelation(view);
    data->initializeSPI();
}

#include "factory.h"
#include <QApplication>
#include <QDesktopWidget>

//Constructor
Factory::Factory()
{
    //Create dynamic objects
    //Disable view for V2.0
    /*
    view = new View(300,500,300,220,"HYPNOSIA Controller");
    view->show();
    */
    bluetooth = new BluetoothInterface();
    controller = new Controller(1000);
    data = new Data();   
}

//Desctructor
Factory::~Factory()
{
    //Delete dynamic alocation
    delete controller;
    delete data;
    //delete view;
    delete bluetooth;
}

Controller* Factory::controller;

//Initialize relations of MVC model
void Factory::buildSystem()
{
    //Build all the system

    //View
    //view->initializeRelation(controller);
    bluetooth->initializeRelation(controller);

    //Controller
    //controller->initializeRelation(data, view);
    controller->initializeRelation(data, bluetooth);
    controller->startBehavior();

    //Model
    data->initializeRelation(bluetooth);
    data->initializeSPI();
}

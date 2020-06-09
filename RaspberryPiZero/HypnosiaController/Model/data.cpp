#include "data.h"

//Constructor
Data::Data()
{

}


//Desctructor
Data::~Data()
{

}

//Initialize relation
void Data::initializeRelation(Observer* observer)
{
    this->pObserver = observer;
}

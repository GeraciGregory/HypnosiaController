#include "view.h"

//Constructor
View::View(int x,int y,int width,int height,QString title)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->title = title;
    //anim1 = new Button(this);
    countDown = new Button(this);
    anim1 = new Button(this);
    setupUI();
}


//Desctructor
View::~View()
{

}

//Initialize relation
void View::initializeRelation(Controller *controller)
{
    this->pController = controller;
}

//Setup User Interface
void View::setupUI()
{
    this->setWindowTitle(this->title);
    this->setGeometry(x,y,width,height);
    this->countDown->setText("Countdown");
    this->countDown->setGeometry(15,30,120,30);
    this->anim1->setText("Animation 1");
    this->anim1->setGeometry(165,30,120,30);
    this->setVisible(true);
}

//Update view
void View::changed()
{

}

//Close view
void View::stop()
{

}

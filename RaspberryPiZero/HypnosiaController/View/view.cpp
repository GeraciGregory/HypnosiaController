#include "view.h"

//Constructor
View::View(int x,int y,int width,int height,QString title)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->title = title;

    //BUTTONS
    countDown = new Button(this);
    anim1 = new Button(this);
    plusBtn = new Button(this);
    minusBtn = new Button(this);
    //COMBOBOXS
    cbProcessor = new ComboBox(this);
    cbClock = new ComboBox(this);
    cbWatchPointer = new ComboBox(this);
    //LABELS
    lbProcessor = new Label(this);
    lbClock = new Label(this);
    lbWatchPointer = new Label(this);

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

    //BUTTONS
    this->countDown->setText("Countdown");
    this->countDown->setGeometry(15,30,120,30);
    this->anim1->setText("Animation 1");
    this->anim1->setGeometry(165,30,120,30);
    this->plusBtn->setText("+");
    this->plusBtn->setGeometry(50,80,50,50);
    this->minusBtn->setText("-");
    this->minusBtn->setGeometry(50,130,50,50);
    //COMBOBOX
    this->cbProcessor->setGeometry(165,80,50,20);
    for(int i=0; i<14; i++)
    {
        this->cbProcessor->addItem(QString::number(i));
    }
    this->cbClock->setGeometry(165,120,50,20);
    for(int i=0; i<6; i++)
    {
        this->cbClock->addItem(QString::number(i));
    }
    this->cbWatchPointer->setGeometry(165,160,50,20);
    for(int i=0; i<3; i++)
    {
        this->cbWatchPointer->addItem(QString::number(i));
    }
    //LABELS
    this->lbProcessor->setGeometry(220,80,50,20);
    this->lbProcessor->setText("Processor");
    this->lbClock->setGeometry(220,120,50,20);
    this->lbClock->setText("Clock");
    this->lbWatchPointer->setGeometry(220,160,50,20);
    this->lbWatchPointer->setText("WatchPtr");

    this->setVisible(true);
}

//Update view
void View::changed()
{
    //update();
}

//Close view
void View::stop()
{

}

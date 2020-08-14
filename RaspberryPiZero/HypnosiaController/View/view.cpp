#include "view.h"

//Constructor
//Initialize the GUI application
View::View(int x,int y,int width,int height,QString title, QWidget* parent)
    : QWidget(parent)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->title = title;

    //BUTTONS
    anim1 = new QPushButton(this);
    plusBtn = new QPushButton(this);
    minusBtn = new QPushButton(this);
    resetPosition = new QPushButton(this);
    btnPlusProc = new QPushButton(this);
    btnMinusProc = new QPushButton(this);
    btnPlusClock = new QPushButton(this);
    btnMinusClock = new QPushButton(this);
    btnPlusWatchPtr = new QPushButton(this);
    btnMinusWatchPtr = new QPushButton(this);
    //LABELS
    lbProcessor = new QLabel(this);
    lbClock = new QLabel(this);
    lbWatchPointer = new QLabel(this);

    //Setup user interface
    setupUI();
}

//Desctructor
View::~View()
{}

//Initialize relation
void View::initializeRelation(Controller *controller)
{
    this->pController = controller;
}

//Setup User Interface
void View::setupUI()
{
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(this->title);

    //Initialize BUTTONS
    anim1->setText("Go to ZERO");
    anim1->setGeometry(165,10,120,30);
    plusBtn->setText("+");
    plusBtn->setGeometry(50,70,50,50);
    minusBtn->setText("-");
    minusBtn->setGeometry(50,120,50,50);
    resetPosition->setText("RESET POSITION");
    resetPosition->setGeometry(15,190,270,20);

    btnPlusProc->setText("+");
    btnPlusProc->setGeometry(145,70,20,20);
    btnMinusProc->setText("-");
    btnMinusProc->setGeometry(125,70,20,20);

    btnPlusClock->setText("+");
    btnPlusClock->setGeometry(145,110,20,20);
    btnMinusClock->setText("-");
    btnMinusClock->setGeometry(125,110,20,20);

    btnPlusWatchPtr->setText("+");
    btnPlusWatchPtr->setGeometry(145,150,20,20);
    btnMinusWatchPtr->setText("-");
    btnMinusWatchPtr->setGeometry(125,150,20,20);
    //LABELS
    lbProcessor->setGeometry(170,70,100,20);
    lbProcessor->setText("Processor: 0");
    lbClock->setGeometry(170,110,100,20);
    lbClock->setText("Clock: 0");
    lbWatchPointer->setGeometry(170,150,100,20);
    lbWatchPointer->setText("Watch Ptr: 0");
}

//Update view
void View::changed()
{
    //update();
}

//Close view
void View::stop()
{}

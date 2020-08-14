#include "controller.h"
#include "Events/evrestart.h"
#include "Events/evcntdown.h"
#include "Events/evanim1.h"
#include "Events/evanim2.h"
#include "Events/evanim3.h"
#include "Events/evanim4.h"
#include "Events/evdone.h"
#include "Events/evplus.h"
#include "Events/evminus.h"
#include "Events/evrstpos.h"
#include "Events/evgotozero.h"
#include "Events/evbluetoothconnected.h"
#include "Events/evcalibration.h"
#include <QThread>

//Constructor
Controller::Controller(int repeatInterval)
    : _repeatInterval(repeatInterval)
{
    //Initialize state of the state machine
    _currentState = STATE_INITIAL;

    //Create animation objects
    animation1 = new Animation1(this);
    animation2 = new Animation2(this);
    animation3 = new Animation3(this);
    animation4 = new Animation4(this);

    this->lblProcValue = 0;
    this->lblClockValue = 0;
    this->lblWatchPtrValue = 0;
}

//Desctructor
Controller::~Controller()
{}

//**********************************************************************************************
//Initialize relation
void Controller::initializeRelation(Data *data, View* view)
{
    //Initialize relations
    this->pData = data;
    this->pView = view;

    //Connect all SIGNAL with the correct slot
    connect(pView->anim1, SIGNAL(clicked()),this,SLOT(onButtonAnim1Clicked()));
    connect(pView->plusBtn, SIGNAL(clicked()),this,SLOT(onButtonPlusClicked()));
    connect(pView->minusBtn, SIGNAL(clicked()),this,SLOT(onButtonMinusClicked()));
    connect(pView->resetPosition, SIGNAL(clicked()),this,SLOT(onButtonRstPosClicked()));

    connect(pView->btnPlusProc, SIGNAL(clicked()),this,SLOT(onBtnPlusProcClicked()));
    connect(pView->btnMinusProc, SIGNAL(clicked()),this,SLOT(onBtnMinusProcClicked()));
    connect(pView->btnPlusClock, SIGNAL(clicked()),this,SLOT(onBtnPlusClockClicked()));
    connect(pView->btnMinusClock, SIGNAL(clicked()),this,SLOT(onBtnMinusClockClicked()));
    connect(pView->btnPlusWatchPtr, SIGNAL(clicked()),this,SLOT(onBtnPlusWatchPtrClicked()));
    connect(pView->btnMinusWatchPtr, SIGNAL(clicked()),this,SLOT(onBtnMinusWatchPtrClicked()));

}
void Controller::initializeRelation(Data *data, BluetoothInterface* bluetooth)
{
    //Initialize relations
    this->pData = data;
    this->pBluetooth = bluetooth;
}
//**********************************************************************************************
// ALL SLOTS
void Controller::onButtonAnim1Clicked()
{
    GEN(evAnim1());
}
void Controller::onButtonAnim2Clicked()
{
    GEN(evAnim2());
}
void Controller::onButtonAnim3Clicked()
{
    GEN(evAnim3());
}
void Controller::onButtonAnim4Clicked()
{
    GEN(evAnim4());
}
void Controller::onButtonPlusClicked()
{
    GEN(evPlus());
}
void Controller::onButtonMinusClicked()
{
    GEN(evMinus());
}
void Controller::onButtonRstPosClicked()
{
    GEN(evRstPos());
}
void Controller::onButtonGoToZeroClicked()
{
    GEN(evGoToZero());
}
void Controller::onButtonCalibrationClicked()
{
    GEN(evCalibration());
}
void Controller::onBtnPlusProcClicked()
{
    if(lblProcValue < pData->getNbrOfProcessor()-1)
    {
        lblProcValue++;
    }
    pView->lbProcessor->setText("Processor: " + QString::number(lblProcValue));
}
void Controller::onBtnMinusProcClicked()
{
    if(lblProcValue > 0)
    {
        lblProcValue--;
    }
    pView->lbProcessor->setText("Processor: " + QString::number(lblProcValue));
}
void Controller::onBtnPlusClockClicked()
{
    if(lblClockValue < NBR_CLOCK_PER_PROCESSOR-1)
    {
        lblClockValue++;
    }
    pView->lbClock->setText("Clock: " + QString::number(lblClockValue));
}
void Controller::onBtnMinusClockClicked()
{
    if(lblClockValue > 0)
    {
        lblClockValue--;
    }
    pView->lbClock->setText("Clock: " + QString::number(lblClockValue));
}
void Controller::onBtnPlusWatchPtrClicked()
{
    if(lblWatchPtrValue < pData->getProcessor(0)->getClock(0)->getNbrOfWatchPointer()-1)
    {
        lblWatchPtrValue++;
    }
    pView->lbWatchPointer->setText("Watch Ptr: " + QString::number(lblWatchPtrValue));
}
void Controller::onBtnMinusWatchPtrClicked()
{
    if(lblWatchPtrValue > 0)
    {
        lblWatchPtrValue--;
    }
    pView->lbWatchPointer->setText("Watch Ptr: " + QString::number(lblWatchPtrValue));
}
//**********************************************************************************************
// state-machine
XFEventStatus Controller::processEvent()
{
    eEventStatus eventStatus = XFEventStatus::Unknown;
   _oldState = _currentState;

   //Test for nested state machine
   if(_currentState == STATE_ANIM1)
   {
       eventStatus = animation1->processEventAnim1(getCurrentEvent());
   }
   if(_currentState == STATE_ANIM2)
   {
       eventStatus = animation2->processEventAnim2(getCurrentEvent());
   }
   if(_currentState == STATE_ANIM3)
   {
       eventStatus = animation3->processEventAnim3(getCurrentEvent());
   }
   if(_currentState == STATE_ANIM4)
   {
       eventStatus = animation4->processEventAnim4(getCurrentEvent());
   }
   if(eventStatus == XFEventStatus::Consumed)
   {
       return eventStatus;
   }

   //-----------------------------------------------------------------------
   //Transition switch
   switch(_currentState)
   {
    case STATE_UNKNOWN:
       break;
    case STATE_INITIAL:
       if(getCurrentEvent()->getEventType() == XFEvent::Initial)
       {
           _currentState = STATE_WAIT;
           eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_WAIT:
       if (getCurrentEvent()->getEventType() == XFEvent::NullTransition)
       {
           _currentState = STATE_WAIT;
           eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evAnim1)
       {
            _currentState = STATE_ANIM1;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evAnim2)
       {
            _currentState = STATE_ANIM2;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evAnim3)
       {
            _currentState = STATE_ANIM3;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evAnim4)
       {
            _currentState = STATE_ANIM4;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evGoToZero)
       {
            _currentState = STATE_GOTOZERO;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evPlus)
       {
            _currentState = STATE_PLUS;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evMinus)
       {
            _currentState = STATE_MINUS;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evRstPos)
       {
            _currentState = STATE_RSTPOS;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evCalibration)
       {
            _currentState = STATE_CALIBRATION;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_ANIM1:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_ANIM2:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_ANIM3:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_ANIM4:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_GOTOZERO:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_PLUS:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_MINUS:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_RSTPOS:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   case STATE_CALIBRATION:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
            eventStatus = XFEventStatus::Consumed;
       }
       break;
   default:
       break;
   }
   //-----------------------------------------------------------------------
   //Action switch
   if(_oldState != _currentState)
   {
        switch(_currentState)
        {
        case STATE_UNKNOWN:
            break;
        case STATE_INITIAL:
            GEN(XFNullTransition());
            break;
        case STATE_WAIT:
            cout << "WAIT" << endl;
            break;
        case STATE_ANIM1:
            if(_oldState == STATE_WAIT)
            {
                SPI_anim1();
            }
            break;
        case STATE_ANIM2:
            if(_oldState == STATE_WAIT)
            {
                SPI_anim2();
            }
            break;
        case STATE_ANIM3:
            if(_oldState == STATE_WAIT)
            {
                SPI_anim3();
            }
            break;
        case STATE_ANIM4:
            if(_oldState == STATE_WAIT)
            {
                SPI_anim4();
            }
            break;
        case STATE_GOTOZERO:
            if(_oldState == STATE_WAIT)
            {
                SPI_goToZero();
            }
            break;
        case STATE_PLUS:
            if(_oldState == STATE_WAIT)
            {        
                SPI_plus();
            }
            break;
        case STATE_MINUS:
            if(_oldState == STATE_WAIT)
            {
                SPI_minus();
            }
            break;
        case STATE_RSTPOS:
            if(_oldState == STATE_WAIT)
            {
                SPI_resetPos();
            }
            break;
        case STATE_CALIBRATION:
            if(_oldState == STATE_WAIT)
            {
                SPI_calibration();
            }
            break;
        default:
            break;
        }
   }
   //-----------------------------------------------------------------------
   return eventStatus;
}
//**********************************************************************************************
//Generate event, called by the Animations class
void Controller::generateEvent(int i)
{
    switch(i)
    {
    case 0:
        GEN(XFNullTransition());
        break;

    case 1:
        GEN(evDone());
        break;

    default:
        break;
    }
}
//**********************************************************************************************
void Controller::SPI_plus()
{
    //Incement position
    pData->getProcessor(pBluetooth->_clockJsonObject.processor)
            ->getClock(pBluetooth->_clockJsonObject.clock)
            ->getWatchPointer(pBluetooth->_clockJsonObject.indexWatchPointer)
            ->incrementPosition();
    //Write on SPI
    pData->writeSPI(pBluetooth->_clockJsonObject.processor,
                    pBluetooth->_clockJsonObject.clock,
                    pBluetooth->_clockJsonObject.indexWatchPointer);
    //Trigger
    pData->triggerWriteSPI(pBluetooth->_clockJsonObject.processor);

    //Continue behavior of the state machine
    GEN(evDone());
}
void Controller::SPI_minus()
{
    //Incement position
    pData->getProcessor(pBluetooth->_clockJsonObject.processor)
            ->getClock(pBluetooth->_clockJsonObject.clock)
            ->getWatchPointer(pBluetooth->_clockJsonObject.indexWatchPointer)
            ->decrementPosition();
    //Write on SPI
    pData->writeSPI(pBluetooth->_clockJsonObject.processor,
                    pBluetooth->_clockJsonObject.clock,
                    pBluetooth->_clockJsonObject.indexWatchPointer);
    //Trigger
    pData->triggerWriteSPI(pBluetooth->_clockJsonObject.processor);

    //Continue behavior of the state machine
    GEN(evDone());
}
void Controller::SPI_resetPos()
{
    //Reset position 0
    pData->getProcessor(pBluetooth->_clockJsonObject.processor)
            ->getClock(pBluetooth->_clockJsonObject.clock)
            ->getWatchPointer(pBluetooth->_clockJsonObject.indexWatchPointer)
            ->resetPositionZero();
    //Write on SPI for reset position zero
    pData->resetPosZeroSPI(pBluetooth->_clockJsonObject.processor,
                    pBluetooth->_clockJsonObject.clock,
                    pBluetooth->_clockJsonObject.indexWatchPointer);

    //Continue behavior of the state machine
    GEN(evDone());
}
void Controller::SPI_goToZero()
{
    //Trigger to go to the zero position
    pData->goToZeroWriteSPI();

    //Continue behavior of the state machine
    GEN(evDone());
}
void Controller::SPI_anim1()
{
    //Continue behavior of the state machine
    GEN(XFNullTransition());
}
void Controller::SPI_anim2()
{
    //Continue behavior of the state machine
    GEN(XFNullTransition());
}
void Controller::SPI_anim3()
{
    //Continue behavior of the state machine
    GEN(XFNullTransition());
}
void Controller::SPI_anim4()
{
    //Continue behavior of the state machine
    GEN(XFNullTransition());
}
void Controller::SPI_calibration()
{
    cout << "CALIBRATION" << endl;

    //Update calibration positions for all watch pointers
    for(int i=0; i<pBluetooth->jsonCalibrationSize; i++)
    {
        pData->getProcessor(pBluetooth->_calibration->processor)
                ->getClock(pBluetooth->_calibration->clock)
                ->getWatchPointer(0)
                ->setNewPosition(pBluetooth->_calibration->newPosition_Hour);
        pData->getProcessor(pBluetooth->_calibration->processor)
                ->getClock(pBluetooth->_calibration->clock)
                ->getWatchPointer(1)
                ->setNewPosition(pBluetooth->_calibration->newPosition_Minute);
    }

    //Write new positions on SPI
    pData->writeSPI();

    //Trigger ALL watch pointers
    pData->triggerWriteSPI();

    //Continue behavior of the state machine
    GEN(evDone());
}

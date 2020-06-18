#include "controller.h"
#include "Events/evrestart.h"
#include "Events/evcntdown.h"
#include "Events/evanim1.h"
#include "Events/evdone.h"
#include "Events/evplus.h"
#include "Events/evminus.h"
#include "Events/evrstpos.h"

//Constructor
Controller::Controller(int repeatInterval)
    : _repeatInterval(repeatInterval)
{
    _currentState = STATE_INITIAL;

    countDown = new CountDown(this);

    this->lblProcValue = 0;
    this->lblClockValue = 0;
    this->lblWatchPtrValue = 0;
}

//Desctructor
Controller::~Controller()
{

}

//Initialize relation
void Controller::initializeRelation(Data *data, View* view)
{
    this->pData = data;
    this->pView = view;

    connect(pView->countDown, SIGNAL(clicked()),this,SLOT(onButtonCntDownClicked()));
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

//**********************************************************************
// SLOTS
void Controller::onButtonCntDownClicked()
{
    GEN(evCntDown());
}

void Controller::onButtonAnim1Clicked()
{
    GEN(evAnim1());
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
//**********************************************************************
// state-machine
XFEventStatus Controller::processEvent()
{
    eEventStatus eventStatus = XFEventStatus::Unknown;
   _oldState = _currentState;

   //Test for nested state machine
   if(_currentState == STATE_CNTDOWN)
   {
       eventStatus = countDown->processEventCntDown(getCurrentEvent());
   }
   if(eventStatus == XFEventStatus::Consumed)
   {
       return eventStatus;
   }

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
               getCurrentEvent()->getId() == EventId::evCntDown)
       {
            _currentState = STATE_CNTDOWN;
            eventStatus = XFEventStatus::Consumed;
       }
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evAnim1)
       {
            _currentState = STATE_ANIM1;
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
       break;

   case STATE_CNTDOWN:
       if(getCurrentEvent()->getEventType() == XFEvent::Event &&
               getCurrentEvent()->getId() == EventId::evDone)
       {
            _currentState = STATE_WAIT;
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

   default:
       break;
   }

   //Action switch
   if(_oldState != _currentState)
   {
        switch(_currentState)
        {
        case STATE_UNKNOWN:
            break;

        case STATE_INITIAL:
            cout << "STATE_WAIT" << endl;
            GEN(XFNullTransition());
            break;

        case STATE_WAIT:
            if(_oldState == STATE_INITIAL || _oldState == STATE_CNTDOWN || _oldState == STATE_ANIM1 ||
                    _oldState == STATE_PLUS || _oldState == STATE_MINUS)
            {
                cout << "STATE_WAIT" << endl;
            }
            break;

        case STATE_CNTDOWN:
            if(_oldState == STATE_WAIT)
            {
                cout << "STATE_CNTDOWN" << endl;
                GEN(XFNullTransition());
            }
            break;

        case STATE_ANIM1:
            if(_oldState == STATE_WAIT)
            {
                cout << "STATE_ANIM1" << endl;
                GEN(evDone());
            }
            break;

        case STATE_PLUS:
            if(_oldState == STATE_WAIT)
            {        
                //Incement position
                pData->getProcessor(lblProcValue)
                        ->getClock(lblClockValue)
                        ->getWatchPointer(lblWatchPtrValue)
                        ->incrementPosition();
                //Write on SPI
                pData->writeSPI(lblProcValue,
                                lblClockValue,
                                lblWatchPtrValue);

                //Trigger
                pData->triggerWriteSPI(lblProcValue);

                GEN(evDone());
            }
            break;

        case STATE_MINUS:
            if(_oldState == STATE_WAIT)
            {
                //Incement position
                pData->getProcessor(lblProcValue)
                        ->getClock(lblClockValue)
                        ->getWatchPointer(lblWatchPtrValue)
                        ->decrementPosition();
                //Write on SPI
                pData->writeSPI(lblProcValue,
                                lblClockValue,
                                lblWatchPtrValue);
                //Trigger
                pData->triggerWriteSPI(lblProcValue);
                GEN(evDone());
            }
            break;

        case STATE_RSTPOS:
            if(_oldState == STATE_WAIT)
            {
                //Reset position 0
                pData->getProcessor(lblProcValue)
                        ->getClock(lblClockValue)
                        ->getWatchPointer(lblWatchPtrValue)
                        ->resetPositionZero();
                //Write on SPI for reset position zero
                pData->resetPosZeroSPI(lblProcValue,
                                lblClockValue,
                                lblWatchPtrValue);
                GEN(evDone());
            }
            break;

        default:
            break;
        }
   }
   return eventStatus;
}

//Generate event
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

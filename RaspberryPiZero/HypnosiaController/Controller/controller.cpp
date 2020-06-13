#include "controller.h"
#include "Events/evrestart.h"
#include "Events/evcntdown.h"
#include "Events/evanim1.h"
#include "Events/evdone.h"
#include "Events/evplus.h"
#include "Events/evminus.h"

//Constructor
Controller::Controller(int repeatInterval)
    : _repeatInterval(repeatInterval)
{
    _currentState = STATE_INITIAL;

    countDown = new CountDown(this);
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
}

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
                pData->getProcessor(pView->cbProcessor->currentIndex())
                        ->getClock(pView->cbClock->currentIndex())
                        ->getWatchPointer(pView->cbWatchPointer->currentIndex())
                        ->incrementPosition();
                //Write on SPI
                pData->writeSPI(pView->cbProcessor->currentIndex(),
                                pView->cbClock->currentIndex(),
                                pView->cbWatchPointer->currentIndex());
                //Trigger
                pData->triggerWriteSPI(pView->cbProcessor->currentIndex());
                GEN(evDone());
            }
            break;

        case STATE_MINUS:
            if(_oldState == STATE_WAIT)
            {
                //Decrement position
                pData->getProcessor(pView->cbProcessor->currentIndex())
                        ->getClock(pView->cbClock->currentIndex())
                        ->getWatchPointer(pView->cbWatchPointer->currentIndex())
                        ->decrementPosition();
                //Write on SPI
                pData->writeSPI(pView->cbProcessor->currentIndex(),
                                pView->cbClock->currentIndex(),
                                pView->cbWatchPointer->currentIndex());
                //Trigger
                pData->triggerWriteSPI(pView->cbProcessor->currentIndex());
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

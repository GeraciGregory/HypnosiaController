#include "animation2.h"
#include "Events/evdone.h"

Animation2::Animation2(Controller* host)
{
    //Initialize relation
    this->host = host;
    //Initialize state of the state machine
    _currentAnim2 = STATE_INIT;
}

Animation2::~Animation2()
{}

eEventStatus Animation2::processEventAnim2(const XFEvent* ev)
{
    eEventStatus _eventStatusAnim = XFEventStatus::Unknown;
   _oldStateAnim2 = _currentAnim2;

   //-----------------------------------------------------------
   //Transition switch
   switch(_currentAnim2)
   {
   case STATE_INIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim2 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_WAIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim2 = STATE_1;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_1:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_2;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_2:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_3;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_3:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_4;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_4:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_5;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_5:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_6;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_6:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_7;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_7:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_8;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_8:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim2)
       {
           _currentAnim2 = STATE_END;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_END:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim2 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   default:
       break;
   }
   //-----------------------------------------------------------
   //Action switch
   if(_oldStateAnim2 != _currentAnim2)
   {
        switch(_currentAnim2)
        {
        case STATE_INIT:
            break;
        case STATE_WAIT:
            if(_oldStateAnim2 == STATE_INIT)
            {
                host->generateEvent(0); //GEN(XFNullTransition());
            }
            if(_oldStateAnim2 == STATE_END)
            {
                host->generateEvent(1); //GEN(evDone());
            }
            break;
        case STATE_1:
            if(_oldStateAnim2 == STATE_WAIT)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(0);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_2:
            if(_oldStateAnim2 == STATE_1)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);;

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(1);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_3:
            if(_oldStateAnim2 == STATE_2)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(2);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_4:
            if(_oldStateAnim2 == STATE_3)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(3);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_5:
            if(_oldStateAnim2 == STATE_4)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(4);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_6:
            if(_oldStateAnim2 == STATE_5)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(5);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_7:
            if(_oldStateAnim2 == STATE_6)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Write new position on registers & write new values via SPI
                host->pData->writeTest(6);

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_8:
            if(_oldStateAnim2 == STATE_7)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim2, DELAY_2);

                //Trigger to go to zero position
                host->pData->goToZeroWriteSPI();
            }
            break;
        case STATE_END:
            if(_oldStateAnim2 == STATE_8)
            {
                //Continue behavior of the state machine
                host->generateEvent(0);
            }
            break;
        default:
            break;
        }
   }
   //-----------------------------------------------------------
   return _eventStatusAnim;
}


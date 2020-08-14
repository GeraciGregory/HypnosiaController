#include "animation1.h"
#include "Events/evdone.h"
#include <time.h>

#define CEST    2    //Central European Summer Time

Animation1::Animation1(Controller* host)
{
    //Initialize relation
    this->host = host;
    //Initialize state of the state machine
    _currentAnim1 = STATE_INIT;
}

Animation1::~Animation1()
{}

eEventStatus Animation1::processEventAnim1(const XFEvent* ev)
{
    eEventStatus _eventStatusAnim = XFEventStatus::Unknown;
   _oldStateAnim1 = _currentAnim1;

   //-----------------------------------------------------------
   //Transition switch
   switch(_currentAnim1)
   {
   case STATE_INIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim1 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_WAIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim1 = STATE_3;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_3:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim1)
       {
           _currentAnim1 = STATE_2;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_2:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim1)
       {
           _currentAnim1 = STATE_1;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_1:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim1)
       {
           _currentAnim1 = STATE_END;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_END:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim1 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   default:
       break;
   }
   //-----------------------------------------------------------
   //Action switch
   if(_oldStateAnim1 != _currentAnim1)
   {
        switch(_currentAnim1)
        {
        case STATE_INIT:
            break;
        case STATE_WAIT:
            if(_oldStateAnim1 == STATE_INIT)
            {
                host->generateEvent(0); //GEN(XFNullTransition());
            }
            if(_oldStateAnim1 == STATE_END)
            {
                host->generateEvent(1); //GEN(evDone());
            }
            break;
        case STATE_3:
            if(_oldStateAnim1 == STATE_WAIT)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim1, DELAY_1);

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 1, 'T');
                host->pData->writeOnMatrix(MATRIX_6x14, 5, 'i');
                host->pData->writeOnMatrix(MATRIX_6x14, 7, 'M');
                host->pData->writeOnMatrix(MATRIX_6x14, 11, 'E');

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_2:
            if(_oldStateAnim1 == STATE_3)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim1, DELAY_1);

                //Trigger to go to zero position
                host->pData->goToZeroWriteSPI();
            }
            break;
        case STATE_1:
            if(_oldStateAnim1 == STATE_2)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim1, DELAY_1);

                //GET REAL TIME
                time_t rawTime;
                struct tm* ptrTime;
                time(&rawTime);
                ptrTime = gmtime(&rawTime);
                char hourDozen = ((ptrTime->tm_hour+CEST)%24)/10 + '0';
                char hourUnit = ((ptrTime->tm_hour+CEST)%24)%10 + '0';
                char minuteDozen = (ptrTime->tm_min)/10 + '0';
                char minuteUnit = (ptrTime->tm_min)%10 + '0';

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 1, hourDozen);
                host->pData->writeOnMatrix(MATRIX_6x14, 4, hourUnit);
                host->pData->writeOnMatrix(MATRIX_6x14, 7, ':');
                host->pData->writeOnMatrix(MATRIX_6x14, 9, minuteDozen);
                host->pData->writeOnMatrix(MATRIX_6x14, 12, minuteUnit);

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_END:
            if(_oldStateAnim1 == STATE_1)
            {
                //Write new position
                host->pData->goToZeroWriteSPI();

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

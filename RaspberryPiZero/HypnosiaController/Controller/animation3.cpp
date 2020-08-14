#include "animation3.h"
#include "Events/evdone.h"

Animation3::Animation3(Controller* host)
{
    //Initialize relation
    this->host = host;
    //Initialize state of the state machine
    _currentAnim3 = STATE_INIT;
}

Animation3::~Animation3()
{}

eEventStatus Animation3::processEventAnim3(const XFEvent* ev)
{
    eEventStatus _eventStatusAnim = XFEventStatus::Unknown;
   _oldStateAnim3 = _currentAnim3;

   //-----------------------------------------------------------
   //Transition switch
   switch(_currentAnim3)
   {
   case STATE_INIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim3 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_WAIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim3 = STATE_1;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_1:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim3)
       {
           _currentAnim3 = STATE_2;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_2:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim3)
       {
           _currentAnim3 = STATE_3;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_3:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutAnim3)
       {
           _currentAnim3 = STATE_END;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_END:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim3 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   default:
       break;
   }
   //-----------------------------------------------------------
   //Action switch
   if(_oldStateAnim3 != _currentAnim3)
   {
        switch(_currentAnim3)
        {
        case STATE_INIT:
            break;
        case STATE_WAIT:
            if(_oldStateAnim3 == STATE_INIT)
            {
                host->generateEvent(0); //GEN(XFNullTransition());
            }
            if(_oldStateAnim3 == STATE_END)
            {
                host->generateEvent(1); //GEN(evDone());
            }
            break;
        case STATE_1:
            if(_oldStateAnim3 == STATE_WAIT)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim3, DELAY_3);

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 2, 'H');
                host->pData->writeOnMatrix(MATRIX_6x14, 6, 'E');
                host->pData->writeOnMatrix(MATRIX_6x14, 10, 'S');

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_2:
            if(_oldStateAnim3 == STATE_1)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim3, DELAY_3);

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 2, 'H');
                host->pData->writeOnMatrix(MATRIX_6x14, 6, 'E');
                host->pData->writeOnMatrix(MATRIX_6x14, 10, 'I');

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_3:
            if(_oldStateAnim3 == STATE_2)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim3, DELAY_3);

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 2, 'H');
                host->pData->writeOnMatrix(MATRIX_6x14, 6, 'E');
                host->pData->writeOnMatrix(MATRIX_6x14, 10, 'G');

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_END:
            if(_oldStateAnim3 == STATE_3)
            {
                //Trigger to go to zero position
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


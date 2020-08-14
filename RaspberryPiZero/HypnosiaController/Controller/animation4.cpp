#include "animation4.h"
#include "Events/evdone.h"

Animation4::Animation4(Controller* host)
{
    //Initialize relation
    this->host = host;
    //Initialize state of the state machine
    _currentAnim4 = STATE_INIT;
}

Animation4::~Animation4()
{}

eEventStatus Animation4::processEventAnim4(const XFEvent* ev)
{
    eEventStatus _eventStatusAnim = XFEventStatus::Unknown;
   _oldStateAnim4 = _currentAnim4;

   //-----------------------------------------------------------
   //Transition switch
   switch(_currentAnim4)
   {
   case STATE_INIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim4 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_WAIT:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim4 = STATE_WRITE;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_WRITE:
       if (ev->getEventType() == XFEvent::Timeout &&
                ev->getId() == TimeoutAnim4)
       {
           _currentAnim4 = STATE_END;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   case STATE_END:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentAnim4 = STATE_WAIT;
           _eventStatusAnim = XFEventStatus::Consumed;
       }
       break;
   default:
       break;
   }
   //-----------------------------------------------------------
   //Action switch
   if(_oldStateAnim4 != _currentAnim4)
   {
        switch(_currentAnim4)
        {
        case STATE_INIT:
            break;
        case STATE_WAIT:
            if(_oldStateAnim4 == STATE_INIT)
            {
                host->generateEvent(0); //GEN(XFNullTransition());
            }
            if(_oldStateAnim4 == STATE_END)
            {
                host->generateEvent(1); //GEN(evDone());
            }
            break;
        case STATE_WRITE:
            if(_oldStateAnim4 == STATE_WAIT)
            {
                //Schedule timeout
                host->scheduleTimeout(TimeoutAnim4, DELAY_4);

                //Write new position on registers
                host->pData->writeOnMatrix(MATRIX_6x14, 1, 'S');
                host->pData->writeOnMatrix(MATRIX_6x14, 5, 'i');
                host->pData->writeOnMatrix(MATRIX_6x14, 7, 'O');
                host->pData->writeOnMatrix(MATRIX_6x14, 11, 'N');

                //Write new values via SPI
                host->pData->writeSPI();

                //Trigger ALL watch pointers
                host->pData->triggerWriteSPI();
            }
            break;
        case STATE_END:
            if(_oldStateAnim4 == STATE_WRITE)
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

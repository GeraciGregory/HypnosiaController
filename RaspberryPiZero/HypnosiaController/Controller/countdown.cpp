#include "countdown.h"
#include "Events/evdone.h"

CountDown::CountDown(Controller* host)
{
    this->host = host;
    _currentStateCntDown = STATE_INIT_CNTDOWN;
}

CountDown::~CountDown()
{

}

eEventStatus CountDown::processEventCntDown(const XFEvent* ev)
{
    eEventStatus _eventStatusCntDown = XFEventStatus::Unknown;
   _oldStateCntDown = _currentStateCntDown;

   //Transition switch
   switch(_currentStateCntDown)
   {
   case STATE_INIT_CNTDOWN:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentStateCntDown = STATE_WAIT_CNTDOWN;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   case STATE_WAIT_CNTDOWN:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentStateCntDown = STATE_3;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   case STATE_3:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutCntDown)
       {
           _currentStateCntDown = STATE_2;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   case STATE_2:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutCntDown)
       {
           _currentStateCntDown = STATE_1;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   case STATE_1:
       if (ev->getEventType() == XFEvent::Timeout &&
           ev->getId() == TimeoutCntDown)
       {
           _currentStateCntDown = STATE_END;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   case STATE_END:
       if (ev->getEventType() == XFEvent::NullTransition)
       {
           _currentStateCntDown = STATE_WAIT_CNTDOWN;
           _eventStatusCntDown = XFEventStatus::Consumed;
       }
       break;

   default:
       break;
   }

   //Action switch
   if(_oldStateCntDown != _currentStateCntDown)
   {
        switch(_currentStateCntDown)
        {
        case STATE_INIT_CNTDOWN:
            break;

        case STATE_WAIT_CNTDOWN:
            if(_oldStateCntDown == STATE_INIT_CNTDOWN)
            {
                host->generateEvent(0); //GEN(XFNullTransition());
            }
            if(_oldStateCntDown == STATE_END)
            {
                host->generateEvent(1); //GEN(evDone());
            }
            break;

        case STATE_3:
            if(_oldStateCntDown == STATE_WAIT_CNTDOWN)
            {
                host->scheduleTimeout(TimeoutCntDown, 1000);
                host->pData->set_3_8(0);
            }
            break;

        case STATE_2:
            if(_oldStateCntDown == STATE_3)
            {
                host->scheduleTimeout(TimeoutCntDown, 1000);
            }
            break;

        case STATE_1:
            if(_oldStateCntDown == STATE_2)
            {
                host->scheduleTimeout(TimeoutCntDown, 1000);
            }
            break;

        case STATE_END:
            if(_oldStateCntDown == STATE_1)
            {
                host->generateEvent(0);
            }
            break;

        default:
            break;
        }
   }
   return _eventStatusCntDown;
}


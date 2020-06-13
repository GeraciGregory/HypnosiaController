#include "customevent.h"

XFCustomEvent::XFCustomEvent(int id, interface::XFReactive * pBehavior)
    : XFEvent(XFEvent::Event, id, pBehavior),
      _bDeleteAfterConsume(true)
{

}

bool XFCustomEvent::deleteAfterConsume() const { return _bDeleteAfterConsume; }

void XFCustomEvent::setDeleteAfterConsume(bool bDeleteAfterConsume) { _bDeleteAfterConsume = bDeleteAfterConsume; }

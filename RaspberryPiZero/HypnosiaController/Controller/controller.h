#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/data.h"
#include "View/view.h"
//#include "xf-core/behavior.h"
#include "xf/xf-core/behavior.h"
#include "countdown.h"
#include <iostream>
#include <QObject>

using namespace  std;

class CountDown;
class View;

class Controller : public QObject,
                   public XFBehavior

{
    Q_OBJECT
public:
    Controller(int repeatInterval);
    ~Controller();
    void initializeRelation(Data* data, View* view);
    void generateEvent(int i);

public:
    Data* pData;
private:
    View* pView;
    CountDown* countDown;

protected:
    virtual XFEventStatus processEvent();								///< Remplementation from XFBehavior

    inline int getRepeatInterval() const { return _repeatInterval; }	///< Returns repeat interval. Accessor for #_repeatInterval.

public slots:
    void onButtonCntDownClicked();
    void onButtonAnim1Clicked();
    void onButtonPlusClicked();
    void onButtonMinusClicked();

protected:
    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_UNKNOWN = 0,			///< Unknown state
        STATE_INITIAL = 1,			///< Initial state
        STATE_WAIT = 2,             ///< Wait state
        STATE_CNTDOWN = 3,
        STATE_ANIM1 = 4,
        STATE_PLUS = 5,
        STATE_MINUS = 6
    } eMainState;

    eMainState _currentState;		///< Attribute indicating currently active state
    eMainState _oldState;           ///< Attribute indicating old state

    int _repeatInterval;			///< Interval in milliseconds to repeat text in state machine
};

#endif // CONTROLLER_H

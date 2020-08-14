#ifndef CONTROLLER_H
#define CONTROLLER_H

//---------------------------------------INCLUDE----------------------------------------
#include "Model/data.h"
#include "View/view.h"
#include "View/bluetoothinterface.h"
#include "xf/xf-core/behavior.h"
#include <iostream>
#include <QObject>
#include <QBluetoothSocket>
#include "animation1.h"
#include "animation2.h"
#include "animation3.h"
#include "animation4.h"
//--------------------------------------------------------------------------------------
using namespace  std;
class Animation1;
class Animation2;
class Animation3;
class Animation4;
class View;
class BluetoothInterface;
//--------------------------------------------------------------------------------------
class Controller : public QObject,
                   public XFBehavior

{
    Q_OBJECT
public:
    Controller(int repeatInterval);                                         //Constructor
    ~Controller();                                                          //Destructor
    void initializeRelation(Data* data, View* view);                        //Initialize relation with view
    void initializeRelation(Data* data, BluetoothInterface* bluetooth);     //Initialize relation with bluetooth
    void generateEvent(int i);                                              //Generate an event according to the index

    //-----------------------------
    //Generate at a change of state
    void SPI_plus();
    void SPI_minus();
    void SPI_resetPos();
    void SPI_goToZero();
    void SPI_anim1();
    void SPI_anim2();
    void SPI_anim3();
    void SPI_anim4();
    void SPI_bthConnected();
    void SPI_calibration();
    //-----------------------------

public:
    Data* pData;
    //Used for "View" class
    int lblProcValue;
    int lblClockValue;
    int lblWatchPtrValue;

private:
    //Private objects
    View* pView;
    BluetoothInterface* pBluetooth;
    Animation1* animation1;
    Animation2* animation2;
    Animation3* animation3;
    Animation4* animation4;

protected:
    virtual XFEventStatus processEvent();								///< Remplementation from XFBehavior
    inline int getRepeatInterval() const { return _repeatInterval; }	///< Returns repeat interval. Accessor for #_repeatInterval.

    //Slot, used when we clicked on a button
public slots:
    void onButtonAnim1Clicked();
    void onButtonAnim2Clicked();
    void onButtonAnim3Clicked();
    void onButtonAnim4Clicked();
    void onButtonPlusClicked();
    void onButtonMinusClicked();
    void onButtonRstPosClicked();
    void onButtonGoToZeroClicked();
    void onButtonCalibrationClicked();

    void onBtnPlusProcClicked();
    void onBtnMinusProcClicked();
    void onBtnPlusClockClicked();
    void onBtnMinusClockClicked();
    void onBtnPlusWatchPtrClicked();
    void onBtnMinusWatchPtrClicked();

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
        STATE_ANIM1 = 4,
        STATE_ANIM2 = 5,
        STATE_ANIM3 = 6,
        STATE_ANIM4 = 7,
        STATE_PLUS = 8,
        STATE_MINUS = 9,
        STATE_RSTPOS = 10,
        STATE_GOTOZERO = 11,
        STATE_CALIBRATION = 13
    } eMainState;

    eMainState _currentState;		///< Attribute indicating currently active state
    eMainState _oldState;           ///< Attribute indicating old state

    int _repeatInterval;			///< Interval in milliseconds to repeat text in state machine
};

#endif // CONTROLLER_H

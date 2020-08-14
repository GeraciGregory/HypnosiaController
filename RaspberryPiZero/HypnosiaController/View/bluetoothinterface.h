#ifndef BLUETOOTHINTERFACE_H
#define BLUETOOTHINTERFACE_H

#include "observer.h"
#include "Controller/controller.h"

#include <QWidget>
#include <QObject>
#include <QJsonObject>
#include "QtBluetooth/QBluetoothDeviceInfo"
#include "QtBluetooth/QBluetoothServiceInfo"
#include "QtBluetooth/QBluetoothServer"

using namespace std;

class Controller;

class BluetoothInterface : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit BluetoothInterface(QWidget* parent=0);                                     //Constructor
    ~BluetoothInterface();                                                              //Destructor

    void initializeRelation(Controller* controller);                                    //Initialize relation

    void changed();                                                                     //Interface method
    void stop();                                                                        //Interface method

    void startServer(const QBluetoothAddress &localAdapter = QBluetoothAddress());      //Start bluetooth server
    void stopServer();                                                                  //Stop bluetooth server

private:
    QString _jsonString;

public:
    //Structure used to structure data received by JSON files
    struct clockJsonObject{
        int processor;
        int clock;
        int indexWatchPointer;
        int newPosition_Hour;
        int newPosition_Minute;
    };

    struct clockJsonObject _clockJsonObject;
    struct clockJsonObject _calibration[NBR_PROCESSOR*NBR_CLOCK_PER_PROCESSOR];
    int jsonCalibrationSize;

    QString message;

private:
    //Used to generate event in order to continue the behavior of the main state machine
    void JSON_animation();
    void JSON_text();
    void JSON_plus();
    void JSON_minus();
    void JSON_calibration();
    void JSON_gotozero();
    void JSON_resetzero();

private:
    Controller* pController;
    QBluetoothServer* rfcommServer;
    QBluetoothServiceInfo serviceInfo;
    QList<QBluetoothSocket*> clientSockets;
    QJsonObject jsonObject;

private slots:
    //Used slot
    void clientConnected();
    void clientDisconnected();
    void readSocket();

};
#endif // BLUETOOTHINTERFACE_H

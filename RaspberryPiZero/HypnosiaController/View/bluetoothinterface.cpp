#include "bluetoothinterface.h"
#include "QtBluetooth/QBluetoothLocalDevice"
#include <QString>
#include "QtBluetooth/QBluetoothDeviceDiscoveryAgent"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

// Service UUID
static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");     //UUID for serail chat
//----------------------------------------------------------------------------------------------------------
//Constructor
BluetoothInterface::BluetoothInterface(QWidget* parent)
    : QWidget(parent)
{
    this->pController = nullptr;

    this->_jsonString = "";

    QList<QBluetoothHostInfo> localAdapters = QBluetoothLocalDevice::allDevices();
    QBluetoothLocalDevice localDevice(localAdapters.at(0).address());
    QString localDeviceName;

    if(localDevice.isValid()){
        localDevice.powerOn();
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // start server
        startServer();
    }
}
//----------------------------------------------------------------------------------------------------------
//Desctructor
BluetoothInterface::~BluetoothInterface()
{
    stopServer();
}
//----------------------------------------------------------------------------------------------------------
//Initialize relation
void BluetoothInterface::initializeRelation(Controller *controller)
{
    this->pController = controller;
}
//----------------------------------------------------------------------------------------------------------
//Update view
void BluetoothInterface::changed()
{
    //update();
}
//Close view
void BluetoothInterface::stop()
{}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::startServer(const QBluetoothAddress &localAdapter)
{
    // Start Server
    rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol,this);
    connect(rfcommServer, &QBluetoothServer::newConnection,this, QOverload<>::of(&BluetoothInterface::clientConnected));
    bool result = rfcommServer->listen(localAdapter);

    QBluetoothServiceInfo::Sequence profileSequence;
    QBluetoothServiceInfo::Sequence classId;
    classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));
    classId << QVariant::fromValue(quint16(0x100));
    profileSequence.append(QVariant::fromValue(classId));
    serviceInfo.setAttribute(QBluetoothServiceInfo::BluetoothProfileDescriptorList,profileSequence);

    classId.clear();
    classId << QVariant::fromValue(QBluetoothUuid(serviceUuid));
    classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceClassIds,classId);

    // service name, description and provider
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceName, tr("Bt Server"));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceDescription,tr("Bluetooth server"));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceProvider,tr("qt-project.org"));

    // Service UUID set
    serviceInfo.setServiceUuid(QBluetoothUuid(serviceUuid));

    // Service discoverability
    QBluetoothServiceInfo::Sequence publicBrowse;
    publicBrowse << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::PublicBrowseGroup));
    serviceInfo.setAttribute(QBluetoothServiceInfo::BrowseGroupList,publicBrowse);

    // Protocol descriptor list
    QBluetoothServiceInfo::Sequence protocolDescriptorList;
    QBluetoothServiceInfo::Sequence protocol;
    protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::L2cap));
    protocolDescriptorList.append(QVariant::fromValue(protocol));
    protocol.clear();
    protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::Rfcomm))
             << QVariant::fromValue(quint8(rfcommServer->serverPort()));
    protocolDescriptorList.append(QVariant::fromValue(protocol));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ProtocolDescriptorList,protocolDescriptorList);

    // Register service
    serviceInfo.registerService(localAdapter);
}
//----------------------------------------------------------------------------------------------------------
//Stop server
void BluetoothInterface::stopServer()
{
    serviceInfo.unregisterService();

    //Close socket
    qDeleteAll(clientSockets);

    //Close server
    delete rfcommServer;
    rfcommServer = nullptr;
}
//----------------------------------------------------------------------------------------------------------
//When a client is connected
void BluetoothInterface::clientConnected()
{
    QBluetoothSocket *socket = rfcommServer->nextPendingConnection();
    if(!socket)
        return;

    //Connect SIGNAL to the correct slot
    connect(socket,&QBluetoothSocket::readyRead,this,&BluetoothInterface::readSocket);
    connect(socket,&QBluetoothSocket::disconnected,this, QOverload<>::of(&BluetoothInterface::clientDisconnected));
    clientSockets.append(socket);
}
//----------------------------------------------------------------------------------------------------------
//When a client is disconnected
void BluetoothInterface::clientDisconnected()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
    if(!socket)
        return;

    // remove from the list
    clientSockets.removeOne(socket);

    socket->deleteLater();
}
//----------------------------------------------------------------------------------------------------------
//When data are transmitted via Bluetooth
void BluetoothInterface::readSocket()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());

    if(!socket)
        return;

    QJsonParseError jsonError;

    //Read JSON file
    _jsonString += socket->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(_jsonString.toUtf8(), &jsonError);

    //Check if there is an error
    if(jsonError.error != QJsonParseError::NoError)
    {
        qDebug() << jsonError.errorString() << endl;
    }
    else
    {
        //Otherwise, check the HEADER
        jsonObject = jsonResponse.object();

        QString readHeader = jsonObject["header"].toString();

        if(readHeader == "PLUS")
        {
            JSON_plus();
        }
        else if(readHeader == "MINUS")
        {
            JSON_minus();
        }
        else if (readHeader == "CALIBRATION")
        {
            JSON_calibration();
        }
        else if(readHeader == "TEXT")
        {
            JSON_text();
        }
        else if(readHeader == "ANIMATION")
        {
            JSON_animation();
        }
        else if(readHeader == "GOTOZERO")
        {
            JSON_gotozero();
        }
        else if(readHeader == "RESETZERO")
        {
            JSON_resetzero();
        }
        else
        {
            cout << "Error header type" << endl;
        }
        _jsonString = "";
    }
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_plus()
{
    QJsonValue jsonValue = jsonObject.value("body");

    //Read values present in the BODY
    _clockJsonObject.processor = jsonValue.toObject().value("processorID").toInt();
    _clockJsonObject.clock = jsonValue.toObject().value("clockID").toInt();
    _clockJsonObject.indexWatchPointer = jsonValue.toObject().value("watchpointerID").toInt();

    //Continue the behavior of the main state machine
    pController->onButtonPlusClicked();
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_minus()
{
    QJsonValue jsonValue = jsonObject.value("body");

    //Read values present in the BODY
    _clockJsonObject.processor = jsonValue.toObject().value("processorID").toInt();
    _clockJsonObject.clock = jsonValue.toObject().value("clockID").toInt();
    _clockJsonObject.indexWatchPointer = jsonValue.toObject().value("watchpointerID").toInt();

    //Continue the behavior of the main state machine
    pController->onButtonMinusClicked();
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_calibration()
{
    QJsonValue jsonValue = jsonObject.value("body");
    QJsonArray jsonArray = jsonValue.toArray();

    jsonCalibrationSize = 0;

    //Read values present in the BODY
    foreach(const QJsonValue &v, jsonArray)
    {
        _calibration[jsonCalibrationSize].processor = v.toObject().value("processorID").toInt();
        _calibration[jsonCalibrationSize].clock = v.toObject().value("clockID").toInt();
        _calibration[jsonCalibrationSize].newPosition_Hour = v.toObject().value("moveWP1").toInt();
        _calibration[jsonCalibrationSize].newPosition_Minute = v.toObject().value("moveWP2").toInt();
        jsonCalibrationSize++;
    }

    //Continue the behavior of the main state machine
    pController->onButtonCalibrationClicked();
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_text()
{
    //Read values present in the BODY
    message = jsonObject["body"].toString();
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_animation()
{
    //Read values present in the BODY
    int indexOfAnimation = jsonObject["body"].toInt() -1;

    //Continue the behavior of the main state machine
    switch(indexOfAnimation)
    {
    case 0:
        pController->onButtonAnim1Clicked();
        break;
    case 1:
        pController->onButtonAnim2Clicked();
        break;
    case 2:
        pController->onButtonAnim3Clicked();
        break;
    case 3:
        pController->onButtonAnim4Clicked();
        break;
    default:
        break;
    }
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_gotozero()
{
    //Continue the behavior of the main state machine
    pController->onButtonGoToZeroClicked();
}
//----------------------------------------------------------------------------------------------------------
void BluetoothInterface::JSON_resetzero()
{
    QJsonValue jsonValue = jsonObject.value("body");

    //Read values present in the BODY
    _clockJsonObject.processor = jsonValue.toObject().value("processorID").toInt();
    _clockJsonObject.clock = jsonValue.toObject().value("clockID").toInt();
    _clockJsonObject.indexWatchPointer = jsonValue.toObject().value("watchpointerID").toInt();

    //Continue the behavior of the main state machine
    pController->onButtonRstPosClicked();
}
//----------------------------------------------------------------------------------------------------------

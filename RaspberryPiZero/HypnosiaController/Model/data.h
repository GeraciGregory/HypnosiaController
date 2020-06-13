#ifndef DATA_H
#define DATA_H

#include "View/observer.h"
#include "processor.h"
#include <iostream>
#include <QVector>
using namespace std;
//#include "wiringPiSPI.h"

#define NBR_PROCESSOR           1
#define NBR_LINE_OF_PROCESSOR   1
#define NBR_COLUMN_OF_PROCESSOR 1
#define CHANNEL                 1
#define SPI_SPEED               500000  //500'000Hz to 32'000'000Hz
#define MAX_FRAME_SIZE          95      // 0x6F - 0x10 = 95d
#define NBR_REGISTER_PER_WATCHPTR 4

class Data
{
public:
    Data();
    ~Data();
    void initializeSPI();
    void initializeRelation(Observer* observer);


    void writeSPI(void);                                //Update all watch pointer of each clock of each processor
    void writeSPI(int iProc);                           //Update all watch pointer of each clock of one processor
    void writeSPI(int iProc, int iClock);               //Update all watch pointer of one clock of one processor
    void writeSPI(int iProc, int iClock, int iWatchPtr);//Update one watch pointer of one clock of one processor

    void writeSPIConfig(void);                          //Update the configuration of each processor
    void writeSPIConfig(int iProc);                     //Update the configuration of the processor

    void triggerWriteSPI(void);                         //Trigger the new values for each processor
    void triggerWriteSPI(int iProc);                    //Trigger the new values for one processor

    Processor* getProcessor(int index);
    void setPosition(bool incr, int proc, int clk, int watchPtr);

private:
    Observer* pObserver;
    Processor* processor[NBR_PROCESSOR];
    int fd;     //File Descriptor
    int result;

    typedef enum
    {
        CONNECTED = 0,
        IN_PROGRESS = 1,
        WAITING = 2,
        READY = 3
    } status;

    status systemSatus;

//NUMBERS
public:
    //2x3
    void set_3_1();
    void set_3_2();
    void set_3_3();
    void set_3_8(int iProc);
    //...

//LETTERS
public:
    void set_A();
    void set_B();
    //...

};

#endif // DATA_H

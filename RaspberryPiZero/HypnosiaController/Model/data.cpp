#include "data.h"

//Constructor
Data::Data()
{
    for(int i=0; i<NBR_PROCESSOR; i++)
    {
        processor[i] = new Processor();
    }
}

//Desctructor
Data::~Data()
{
}

void Data::initializeSPI()
{
    fd = wiringPiSPISetup(CHANNEL, SPI_SPEED);
    cout << "SPI initialized" << endl;
}

//Update all watch pointer of each clock of each processor
void Data::writeSPI(void)
{

}

//Update all watch pointer of each clock of one processor
// Use "+" befor the char to write with "cout" <=> static_cast<unsigned>
void Data::writeSPI(int iProc)
{
    //14 = 1 + 1 + 12
    //QVector<char> frame(14, 0x00);
    unsigned char frame[14];
    char configBit = 0x00;

    cout << "Processor : " << iProc << endl;

    for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
    {
        //Processor address
        frame[0] = (iProc << 2) + configBit;
        //Clock address
        frame[1] = i;
        for(int x=0; x< MAX_WATCHPOINTER; x++)
        {
            frame[2+(x*4)] = (processor[iProc]->getClock(i)->getWatchPointer(x)->getClockWise()<<3) +
                                processor[iProc]->getClock(i)->getWatchPointer(x)->getNbrTurns();
            frame[3+(x*4)] = processor[iProc]->getClock(i)->getWatchPointer(x)->getNewPosition();
            frame[4+(x*4)] = processor[iProc]->getClock(i)->getWatchPointer(x)->getTimeMovementDuration();
            frame[5+(x*4)] = processor[iProc]->getClock(i)->getWatchPointer(x)->getOffsetStartTime();
        }

        cout << "Clock : " << i << endl;
        for(int y=0; y<14; y++)
        {
            cout << hex << (int)frame[y] << ", " ;
        }
        cout << endl;
    }
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, 14); //14 = 1+1+12
}
//Update all watch pointer of one clock of one processor
void Data::writeSPI(int iProc, int iClock)
{
    cout << iProc << iClock << endl;
}

//Update one watch pointer of one clock of one processor
void Data::writeSPI(int iProc, int iClock, int iWatchPtr)
{
    //6 = 1 + 1 + 4
    unsigned char frame[6];
    char configBit = 0x00;

    //Processor address
    frame[0] = (iProc << 2) + configBit;
    //Clock address
    frame[1] = iClock;
    frame[2] = (processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getClockWise()<<3) +
                        processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getNbrTurns();
    frame[3] = processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getNewPosition();
    frame[4] = processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getTimeMovementDuration();
    frame[5] = processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getOffsetStartTime();


    cout << "Processor : " << iProc << endl;
    cout << "Clock : " << iClock << endl;
    cout << "Watch pointer : " << iWatchPtr << endl;
    for(int y=0; y<6; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, 6); //6 = 1+1+4
}

void Data::resetPosZeroSPI(int iProc, int iClock, int iWatchPtr)
{
    //3 = 1 + 1 + 1
    unsigned char frame[3];
    char configBit = 0x02;

    //Processor address
    frame[0] = (iProc << 2) + configBit;
    //Clock address
    frame[1] = iClock;
    frame[2] = iWatchPtr;

    cout << "Processor : " << iProc << endl;
    cout << "Clock : " << iClock << endl;
    cout << "Watch pointer : " << iWatchPtr << endl;
    for(int y=0; y<3; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, 3); //3 = 1+1+1
}

void Data::writeSPIConfig()
{

}

void Data::writeSPIConfig(int iProc)
{
    cout << iProc << endl;
}

void Data::triggerWriteSPI()
{

}

void Data::triggerWriteSPI(int iProc)
{

    //QVector<char> frame(2, 0x00);
    unsigned char frame[2];
    char configBit = 0x01;  //Config frame
    char trigger = 0x01;

    frame[0] = (iProc << 2) + configBit;
    frame[1] = (trigger<<4);


    cout << "Processor : " << iProc << endl;
    for(int y=0; y<2; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, 2); //2 = 1+1

}

Processor* Data::getProcessor(int index)
{
    return processor[index];
}

int Data::getNbrOfProcessor()
{
    return NBR_PROCESSOR;
}

//Initialize relation
void Data::initializeRelation(Observer* observer)
{
    this->pObserver = observer;
}

void Data::setPosition(bool incr, int proc, int clk, int watchPtr)
{
    if(incr == true)
    {
        //Increment
        processor[proc]->getClock(clk)->getWatchPointer(watchPtr)->incrementPosition();
    }
    else
    {
        //Decrement
        processor[proc]->getClock(clk)->getWatchPointer(watchPtr)->decrementPosition();
    }
}

//---------------------------------------------------------------------------------------------------
//NUMBERS
void Data::set_3_1()
{

}
void Data::set_3_2()
{

}
void Data::set_3_3()
{

}
void Data::set_3_8(int iProc)
{
    /*
    //Clock 0
    processor[iProc]->getClock(0)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(0)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(0)->getWatchPointer(2)->setNewPosition(0);
    //Clock 1
    processor[iProc]->getClock(1)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(1)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(1)->getWatchPointer(2)->setNewPosition(0);
    //Clock 2
    processor[iProc]->getClock(2)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(2)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(2)->getWatchPointer(2)->setNewPosition(0);
    //Clock 3
    processor[iProc]->getClock(3)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(3)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(3)->getWatchPointer(2)->setNewPosition(0);
    //Clock 4
    processor[iProc]->getClock(4)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(4)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(4)->getWatchPointer(2)->setNewPosition(0);
    //Clock 5
    processor[iProc]->getClock(5)->getWatchPointer(0)->setNewPosition(0);
    processor[iProc]->getClock(5)->getWatchPointer(1)->setNewPosition(0);
    processor[iProc]->getClock(5)->getWatchPointer(2)->setNewPosition(0);
    */

    writeSPI(iProc);
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//LETTERS
void Data::set_A()
{

}
void Data::set_B()
{

}
//---------------------------------------------------------------------------------------------------

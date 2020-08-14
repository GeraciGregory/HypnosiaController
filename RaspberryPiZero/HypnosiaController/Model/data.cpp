#include "data.h"

//Constructor
Data::Data()
{
    //Create dynamic objects
    for(int i=0; i<NBR_PROCESSOR; i++)
    {
        processor[i] = new Processor();
    }

    //------------------------------------------------------------------------------
    //---------------------------------DEFINE MATRIX---------------------------------
    //------------------------------------------------------------------------------
    //MATRIX 3x2
    //---------------------------------
    //Processor 0
    matrix_3_2[0][0].processorID = 0;
    matrix_3_2[0][0].clockID = 4;
    matrix_3_2[0][1].processorID = 0;
    matrix_3_2[0][1].clockID = 1;
    matrix_3_2[1][0].processorID = 0;
    matrix_3_2[1][0].clockID = 5;
    matrix_3_2[1][1].processorID = 0;
    matrix_3_2[1][1].clockID = 2;
    matrix_3_2[2][0].processorID = 0;
    matrix_3_2[2][0].clockID = 6;
    matrix_3_2[2][1].processorID = 0;
    matrix_3_2[2][1].clockID = 3;
    //------------------------------------------------------------------------------
    //MATRIX 3x8
    //---------------------------------
    //Processor 0
    matrix_3x8[0][0].processorID = 0;
    matrix_3x8[0][0].clockID = 4;
    matrix_3x8[0][1].processorID = 0;
    matrix_3x8[0][1].clockID = 1;
    matrix_3x8[1][0].processorID = 0;
    matrix_3x8[1][0].clockID = 5;
    matrix_3x8[1][1].processorID = 0;
    matrix_3x8[1][1].clockID = 2;
    matrix_3x8[2][0].processorID = 0;
    matrix_3x8[2][0].clockID = 6;
    matrix_3x8[2][1].processorID = 0;
    matrix_3x8[2][1].clockID = 3;
    //---------------------------------
    //Processor 1
    matrix_3x8[0][2].processorID = 1;
    matrix_3x8[0][2].clockID = 4;
    matrix_3x8[0][3].processorID = 1;
    matrix_3x8[0][3].clockID = 1;
    matrix_3x8[1][2].processorID = 1;
    matrix_3x8[1][2].clockID = 5;
    matrix_3x8[1][3].processorID = 1;
    matrix_3x8[1][3].clockID = 2;
    matrix_3x8[2][2].processorID = 1;
    matrix_3x8[2][2].clockID = 6;
    matrix_3x8[2][3].processorID = 1;
    matrix_3x8[2][3].clockID = 3;
    //---------------------------------
    //Processor 2
    matrix_3x8[0][4].processorID = 2;
    matrix_3x8[0][4].clockID = 4;
    matrix_3x8[0][5].processorID = 2;
    matrix_3x8[0][5].clockID = 1;
    matrix_3x8[1][4].processorID = 2;
    matrix_3x8[1][4].clockID = 5;
    matrix_3x8[1][5].processorID = 2;
    matrix_3x8[1][5].clockID = 2;
    matrix_3x8[2][4].processorID = 2;
    matrix_3x8[2][4].clockID = 6;
    matrix_3x8[2][5].processorID = 2;
    matrix_3x8[2][5].clockID = 3;
    //---------------------------------
    //Processor 3
    matrix_3x8[0][6].processorID = 3;
    matrix_3x8[0][6].clockID = 4;
    matrix_3x8[0][7].processorID = 3;
    matrix_3x8[0][7].clockID = 1;
    matrix_3x8[1][6].processorID = 3;
    matrix_3x8[1][6].clockID = 5;
    matrix_3x8[1][7].processorID = 3;
    matrix_3x8[1][7].clockID = 2;
    matrix_3x8[2][6].processorID = 3;
    matrix_3x8[2][6].clockID = 6;
    matrix_3x8[2][7].processorID = 3;
    matrix_3x8[2][7].clockID = 3;
    //------------------------------------------------------------------------------
    //MATRIX 6x14
    //---------------------------------
    //Processor 13
    matrix_6x14[0][0].processorID = 13;
    matrix_6x14[0][0].clockID = 4;
    matrix_6x14[0][1].processorID = 13;
    matrix_6x14[0][1].clockID = 1;
    matrix_6x14[1][0].processorID = 13;
    matrix_6x14[1][0].clockID = 5;
    matrix_6x14[1][1].processorID = 13;
    matrix_6x14[1][1].clockID = 2;
    matrix_6x14[2][0].processorID = 13;
    matrix_6x14[2][0].clockID = 6;
    matrix_6x14[2][1].processorID = 13;
    matrix_6x14[2][1].clockID = 3;
    //Processor 0
    matrix_6x14[3][0].processorID = 0;
    matrix_6x14[3][0].clockID = 4;
    matrix_6x14[3][1].processorID = 0;
    matrix_6x14[3][1].clockID = 1;
    matrix_6x14[4][0].processorID = 0;
    matrix_6x14[4][0].clockID = 5;
    matrix_6x14[4][1].processorID = 0;
    matrix_6x14[4][1].clockID = 2;
    matrix_6x14[5][0].processorID = 0;
    matrix_6x14[5][0].clockID = 6;
    matrix_6x14[5][1].processorID = 0;
    matrix_6x14[5][1].clockID = 3;
    //Processor 12
    matrix_6x14[0][2].processorID = 12;
    matrix_6x14[0][2].clockID = 4;
    matrix_6x14[0][3].processorID = 12;
    matrix_6x14[0][3].clockID = 1;
    matrix_6x14[1][2].processorID = 12;
    matrix_6x14[1][2].clockID = 5;
    matrix_6x14[1][3].processorID = 12;
    matrix_6x14[1][3].clockID = 2;
    matrix_6x14[2][2].processorID = 12;
    matrix_6x14[2][2].clockID = 6;
    matrix_6x14[2][3].processorID = 12;
    matrix_6x14[2][3].clockID = 3;
    //Processor 1
    matrix_6x14[3][2].processorID = 1;
    matrix_6x14[3][2].clockID = 4;
    matrix_6x14[3][3].processorID = 1;
    matrix_6x14[3][3].clockID = 1;
    matrix_6x14[4][2].processorID = 1;
    matrix_6x14[4][2].clockID = 5;
    matrix_6x14[4][3].processorID = 1;
    matrix_6x14[4][3].clockID = 2;
    matrix_6x14[5][2].processorID = 1;
    matrix_6x14[5][2].clockID = 6;
    matrix_6x14[5][3].processorID = 1;
    matrix_6x14[5][3].clockID = 3;
    //Processor 11
    matrix_6x14[0][4].processorID = 11;
    matrix_6x14[0][4].clockID = 4;
    matrix_6x14[0][5].processorID = 11;
    matrix_6x14[0][5].clockID = 1;
    matrix_6x14[1][4].processorID = 11;
    matrix_6x14[1][4].clockID = 5;
    matrix_6x14[1][5].processorID = 11;
    matrix_6x14[1][5].clockID = 2;
    matrix_6x14[2][4].processorID = 11;
    matrix_6x14[2][4].clockID = 6;
    matrix_6x14[2][5].processorID = 11;
    matrix_6x14[2][5].clockID = 3;
    //Processor 2
    matrix_6x14[3][4].processorID = 2;
    matrix_6x14[3][4].clockID = 4;
    matrix_6x14[3][5].processorID = 2;
    matrix_6x14[3][5].clockID = 1;
    matrix_6x14[4][4].processorID = 2;
    matrix_6x14[4][4].clockID = 5;
    matrix_6x14[4][5].processorID = 2;
    matrix_6x14[4][5].clockID = 2;
    matrix_6x14[5][4].processorID = 2;
    matrix_6x14[5][4].clockID = 6;
    matrix_6x14[5][5].processorID = 2;
    matrix_6x14[5][5].clockID = 3;
    //Processor 10
    matrix_6x14[0][6].processorID = 10;
    matrix_6x14[0][6].clockID = 4;
    matrix_6x14[0][7].processorID = 10;
    matrix_6x14[0][7].clockID = 1;
    matrix_6x14[1][6].processorID = 10;
    matrix_6x14[1][6].clockID = 5;
    matrix_6x14[1][7].processorID = 10;
    matrix_6x14[1][7].clockID = 2;
    matrix_6x14[2][6].processorID = 10;
    matrix_6x14[2][6].clockID = 6;
    matrix_6x14[2][7].processorID = 10;
    matrix_6x14[2][7].clockID = 3;
    //Processor 3
    matrix_6x14[3][6].processorID = 3;
    matrix_6x14[3][6].clockID = 4;
    matrix_6x14[3][7].processorID = 3;
    matrix_6x14[3][7].clockID = 1;
    matrix_6x14[4][6].processorID = 3;
    matrix_6x14[4][6].clockID = 5;
    matrix_6x14[4][7].processorID = 3;
    matrix_6x14[4][7].clockID = 2;
    matrix_6x14[5][6].processorID = 3;
    matrix_6x14[5][6].clockID = 6;
    matrix_6x14[5][7].processorID = 3;
    matrix_6x14[5][7].clockID = 3;
    //Processor 9
    matrix_6x14[0][8].processorID = 9;
    matrix_6x14[0][8].clockID = 4;
    matrix_6x14[0][9].processorID = 9;
    matrix_6x14[0][9].clockID = 1;
    matrix_6x14[1][8].processorID = 9;
    matrix_6x14[1][8].clockID = 5;
    matrix_6x14[1][9].processorID = 9;
    matrix_6x14[1][9].clockID = 2;
    matrix_6x14[2][8].processorID = 9;
    matrix_6x14[2][8].clockID = 6;
    matrix_6x14[2][9].processorID = 9;
    matrix_6x14[2][9].clockID = 3;
    //Processor 4
    matrix_6x14[3][8].processorID = 4;
    matrix_6x14[3][8].clockID = 4;
    matrix_6x14[3][9].processorID = 4;
    matrix_6x14[3][9].clockID = 1;
    matrix_6x14[4][8].processorID = 4;
    matrix_6x14[4][8].clockID = 5;
    matrix_6x14[4][9].processorID = 4;
    matrix_6x14[4][9].clockID = 2;
    matrix_6x14[5][8].processorID = 4;
    matrix_6x14[5][8].clockID = 6;
    matrix_6x14[5][9].processorID = 4;
    matrix_6x14[5][9].clockID = 3;
    //Processor 8
    matrix_6x14[0][10].processorID = 8;
    matrix_6x14[0][10].clockID = 4;
    matrix_6x14[0][11].processorID = 8;
    matrix_6x14[0][11].clockID = 1;
    matrix_6x14[1][10].processorID = 8;
    matrix_6x14[1][10].clockID = 5;
    matrix_6x14[1][11].processorID = 8;
    matrix_6x14[1][11].clockID = 2;
    matrix_6x14[2][10].processorID = 8;
    matrix_6x14[2][10].clockID = 6;
    matrix_6x14[2][11].processorID = 8;
    matrix_6x14[2][11].clockID = 3;
    //Processor 5
    matrix_6x14[3][10].processorID = 5;
    matrix_6x14[3][10].clockID = 4;
    matrix_6x14[3][11].processorID = 5;
    matrix_6x14[3][11].clockID = 1;
    matrix_6x14[4][10].processorID = 5;
    matrix_6x14[4][10].clockID = 5;
    matrix_6x14[4][11].processorID = 5;
    matrix_6x14[4][11].clockID = 2;
    matrix_6x14[5][10].processorID = 5;
    matrix_6x14[5][10].clockID = 6;
    matrix_6x14[5][11].processorID = 5;
    matrix_6x14[5][11].clockID = 3;
    //Processor 7
    matrix_6x14[0][12].processorID = 7;
    matrix_6x14[0][12].clockID = 4;
    matrix_6x14[0][13].processorID = 7;
    matrix_6x14[0][13].clockID = 1;
    matrix_6x14[1][12].processorID = 7;
    matrix_6x14[1][12].clockID = 5;
    matrix_6x14[1][13].processorID = 7;
    matrix_6x14[1][13].clockID = 2;
    matrix_6x14[2][12].processorID = 7;
    matrix_6x14[2][12].clockID = 6;
    matrix_6x14[2][13].processorID = 7;
    matrix_6x14[2][13].clockID = 3;
    //Processor 6
    matrix_6x14[3][12].processorID = 6;
    matrix_6x14[3][12].clockID = 4;
    matrix_6x14[3][13].processorID = 6;
    matrix_6x14[3][13].clockID = 1;
    matrix_6x14[4][12].processorID = 6;
    matrix_6x14[4][12].clockID = 5;
    matrix_6x14[4][13].processorID = 6;
    matrix_6x14[4][13].clockID = 2;
    matrix_6x14[5][12].processorID = 6;
    matrix_6x14[5][12].clockID = 6;
    matrix_6x14[5][13].processorID = 6;
    matrix_6x14[5][13].clockID = 3;
}
//------------------------------------------------------------------------------
//Desctructor
Data::~Data()
{}
//------------------------------------------------------------------------------
void Data::initializeSPI()
{
    fd = wiringPiSPISetup(CHANNEL, SPI_SPEED);  //Initialize SPI according to the channel and speed defined
}
//------------------------------------------------------------------------------
//Initialize relation
void Data::initializeRelation(Observer* observer)
{
    this->pObserver = observer;
}
//------------------------------------------------------------------------------
//Update all watch pointer of each clock of each processor
void Data::writeSPI(void)
{
    for(int i=0; i<getNbrOfProcessor(); i++)
    {
        writeSPI(i);
    }
}
//------------------------------------------------------------------------------
//Update all watch pointer of each clock of one processor
// Use "+" befor the char to write with "cout" <=> static_cast<unsigned>
void Data::writeSPI(int iProc)
{
    unsigned char frame[SPI_FRAME_SIZE];

    char configBit = 0x00;          //DATA FRAME
    char watchPtrAddress = 0x03;    //Used to write to all watch pointers
    int nbrOfWatchPtr;

    cout << "Processor : " << iProc << endl;

    for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
    {
        //Processor address
        frame[0] = (configBit << 6) + (iProc & 0x3F);
        //Clock address
        frame[1] = ((i & 0b00000111) << 2) + (watchPtrAddress); //Use all watch pointers

        nbrOfWatchPtr = processor[iProc]->getClock(i)->getNbrOfWatchPointer();
        switch(nbrOfWatchPtr)
        {
        //TWO WATCH POINTERS
        case 2:
            frame[2] = 5;
            frame[3] = (processor[iProc]->getClock(i)->getWatchPointer(1)->getClockWise() << 7) +
                        (processor[iProc]->getClock(i)->getWatchPointer(1)->getNbrTurns() << 4) +
                        (processor[iProc]->getClock(i)->getWatchPointer(0)->getClockWise() << 3) +
                         processor[iProc]->getClock(i)->getWatchPointer(0)->getNbrTurns();
            frame[4] = processor[iProc]->getClock(i)->getWatchPointer(0)->getNewPosition();
            frame[5] = (processor[iProc]->getClock(i)->getWatchPointer(0)->getTimeMovementDuration() << 4) +
                        processor[iProc]->getClock(i)->getWatchPointer(0)->getOffsetStartTime();
            frame[6] = processor[iProc]->getClock(i)->getWatchPointer(1)->getNewPosition();
            frame[7] = (processor[iProc]->getClock(i)->getWatchPointer(1)->getTimeMovementDuration() << 4) +
                        processor[iProc]->getClock(i)->getWatchPointer(1)->getOffsetStartTime();
            for(int i=8; i<SPI_FRAME_SIZE; i++)
            {
                frame[i] = DUMMY_BYTE;
            }

            cout << "Clock : " << i << endl;
            for(int y=0; y<SPI_FRAME_SIZE; y++)
            {
                cout << hex << (int)frame[y] << ", " ;
            }
            cout << endl;

            wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);      //Send data via SPI
            break;

        //THREE WATCH POINTERS
        case 3:
            frame[2] = 8;
            frame[3] = (processor[iProc]->getClock(i)->getWatchPointer(1)->getClockWise() << 7) +
                        (processor[iProc]->getClock(i)->getWatchPointer(1)->getNbrTurns() << 4) +
                        (processor[iProc]->getClock(i)->getWatchPointer(0)->getClockWise() << 3) +
                         processor[iProc]->getClock(i)->getWatchPointer(0)->getNbrTurns();
            frame[4] = processor[iProc]->getClock(i)->getWatchPointer(0)->getNewPosition();
            frame[5] = (processor[iProc]->getClock(i)->getWatchPointer(0)->getTimeMovementDuration() << 4) +
                        processor[iProc]->getClock(i)->getWatchPointer(0)->getOffsetStartTime();
            frame[6] = processor[iProc]->getClock(i)->getWatchPointer(1)->getNewPosition();
            frame[7] = (processor[iProc]->getClock(i)->getWatchPointer(1)->getTimeMovementDuration() << 4) +
                        processor[iProc]->getClock(i)->getWatchPointer(1)->getOffsetStartTime();
            frame[8] = (processor[iProc]->getClock(i)->getWatchPointer(2)->getClockWise() << 3) +
                        processor[iProc]->getClock(i)->getWatchPointer(2)->getNbrTurns();
            frame[9] = processor[iProc]->getClock(i)->getWatchPointer(2)->getNewPosition();
            frame[10] = (processor[iProc]->getClock(i)->getWatchPointer(2)->getTimeMovementDuration() << 4) +
                        processor[iProc]->getClock(i)->getWatchPointer(2)->getOffsetStartTime();

            cout << "Clock : " << i << endl;
            for(int y=0; y<SPI_FRAME_SIZE; y++)
            {
                cout << hex << (int)frame[y] << ", " ;
            }
            cout << endl;

            wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);      //Send data via SPI
            break;

        default:
            break;
        }
    }
    cout << endl;

}
//------------------------------------------------------------------------------
//Update all watch pointer of one clock of one processor
void Data::writeSPI(int iProc, int iClock)
{
    //Not used
}
//------------------------------------------------------------------------------
//Update one watch pointer of one clock of one processor
void Data::writeSPI(int iProc, int iClock, int iWatchPtr)
{
    //6 = 1 + 1 + 4 + 1
    unsigned char frame[SPI_FRAME_SIZE];

    char configBit = 0x00;  //DATA FRAME

    //Processor address
    frame[0] = (configBit << 6) + (iProc & 0x3F);
    //Clock address
    frame[1] = ((iClock & 0b00000111) << 2) + (iWatchPtr & 0x03);
    frame[2] = 3;
    frame[3] = (processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getClockWise() << 3) +
                 processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getNbrTurns();
    frame[4] = processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getNewPosition();
    frame[5] = (processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getTimeMovementDuration() << 4) +
                processor[iProc]->getClock(iClock)->getWatchPointer(iWatchPtr)->getOffsetStartTime();

    for(int i=6; i<SPI_FRAME_SIZE; i++)
    {
        frame[i] = DUMMY_BYTE;
    }

    cout << "Processor : " << iProc << endl;
    cout << "Clock : " << iClock << endl;
    cout << "Watch pointer : " << iWatchPtr << endl;
    for(int y=0; y<SPI_FRAME_SIZE; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);      //Send data via SPI
}
//------------------------------------------------------------------------------
void Data::resetPosZeroSPI(int iProc, int iClock, int iWatchPtr)
{
    //3 = 1 + 1 + 1
    unsigned char frame[SPI_FRAME_SIZE];

    char configBit = 0x03;  //RESET POSITION ZERO

    //Processor address
    frame[0] = (configBit << 6) + (iProc & 0x3F);
    //Clock address
    frame[1] = ((iClock & 0b00000111) << 2) + (iWatchPtr & 0x03);

    for(int i=2; i<SPI_FRAME_SIZE; i++)
    {
        frame[i] = DUMMY_BYTE;
    }

    cout << "Processor : " << iProc << endl;
    cout << "Clock : " << iClock << endl;
    cout << "Watch pointer : " << iWatchPtr << endl;
    for(int y=0; y<SPI_FRAME_SIZE; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);      //Send data via SPI
}
//------------------------------------------------------------------------------
void Data::writeSPIConfig()
{
    //Not used
}
//------------------------------------------------------------------------------
void Data::writeSPIConfig(int iProc)
{
    //Not used
}
//------------------------------------------------------------------------------
void Data::goToZeroWriteSPI()
{
    for(int i=getNbrOfProcessor()-1; i>=0; i--)
    {
        goToZeroWriteSPI(i);
    }
}
//------------------------------------------------------------------------------
void Data::goToZeroWriteSPI(int iProc)
{
    for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
    {
        for(int x=0; x<MAX_WATCHPOINTER; x++)
        {
            getProcessor(iProc)->getClock(i)->getWatchPointer(x)->resetPositionZero();
        }
    }

    unsigned char frame[SPI_FRAME_SIZE];
    char configBit = 0x01;                          //Config frame
    char trigger = 0x01;
    char goToZero = 0x01;

    frame[0] = (configBit << 6) + (iProc & 0x3F);
    frame[1] = 2;                                   //2 byte to send
    frame[2] = 0x00;                                //index of the register
    frame[3] = (goToZero<<5);                       //Update goToZero flag

    for(int i=4; i<SPI_FRAME_SIZE; i++)
    {
        frame[i] = DUMMY_BYTE;
    }


    cout << "Processor : " << iProc << endl;
    for(int y=0; y<SPI_FRAME_SIZE; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);      //Send data via SPI
}
//------------------------------------------------------------------------------
void Data::triggerWriteSPI()
{
    //Trigger to go to the new position
    for(int i=getNbrOfProcessor()-1; i>=0; i--)
    {
        triggerWriteSPI(i);
    }
}
//------------------------------------------------------------------------------
void Data::triggerWriteSPI(int iProc)
{
    unsigned char frame[SPI_FRAME_SIZE];
    char configBit = 0x01;                              //Config frame
    char trigger = 0x01;

    frame[0] = (configBit << 6) + (iProc & 0x3F);
    frame[1] = 2;                                       //2 byte to send
    frame[2] = 0x00;                                    //index of the register
    frame[3] = (trigger<<4);                            //Update flag trigger

    for(int i=4; i<SPI_FRAME_SIZE; i++)
    {
        frame[i] = DUMMY_BYTE;
    }

    cout << "Processor : " << iProc << endl;
    for(int y=0; y<SPI_FRAME_SIZE; y++)
    {
        cout << hex << (int)frame[y] << ", " ;
    }
    cout << endl;
    cout << endl;
    wiringPiSPIDataRW(CHANNEL, frame, SPI_FRAME_SIZE);  //Send data via SPI
}
//------------------------------------------------------------------------------
Processor* Data::getProcessor(int index)
{
    return processor[index];
}
//------------------------------------------------------------------------------
int Data::getNbrOfProcessor()
{
    return NBR_PROCESSOR;
}
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
void Data::writeOnMatrix(int matrix, int column, QChar c)
{
    //Get new position
    int nbrOfColumnToWrite = selectChar(matrix, c);

    //Write on SPI new position
    writeNewPosition(matrix, column, nbrOfColumnToWrite);
}
//------------------------------------------------------------------------------
int Data::selectChar(int matrix, QChar c)
{
    getNewPositions = nullptr;

    //Select char according to the parameter
    if(c == '0') {
        getNewPositions = pNumber.set_0(matrix);
    }
    else if (c == '1') {
        getNewPositions = pNumber.set_1(matrix);
    }
    else if (c == '2') {
        getNewPositions = pNumber.set_2(matrix);
    }
    else if (c == '3') {
        getNewPositions = pNumber.set_3(matrix);
    }
    else if (c == '4') {
        getNewPositions = pNumber.set_4(matrix);
    }
    else if (c == '5') {
        getNewPositions = pNumber.set_5(matrix);
    }
    else if (c == '6') {
        getNewPositions = pNumber.set_6(matrix);
    }
    else if (c == '7') {
        getNewPositions = pNumber.set_7(matrix);
    }
    else if (c == '8') {
        getNewPositions = pNumber.set_8(matrix);
    }
    else if (c == '9') {
        getNewPositions = pNumber.set_9(matrix);
    }
    else if (c == ':') {
        getNewPositions = pNumber.set_betweenTime(matrix);
    }
    else if (c == 'A') {
        getNewPositions = pLetter.set_A(matrix);
    }
    else if (c == 'B') {
        getNewPositions = pLetter.set_B(matrix);
    }
    else if (c == 'C') {
        getNewPositions = pLetter.set_C(matrix);
    }
    else if (c == 'D') {
        getNewPositions = pLetter.set_D(matrix);
    }
    else if (c == 'E') {
        getNewPositions = pLetter.set_E(matrix);
    }
    else if (c == 'F') {
        getNewPositions = pLetter.set_F(matrix);
    }
    else if (c == 'G') {
        getNewPositions = pLetter.set_G(matrix);
    }
    else if (c == 'H') {
        getNewPositions = pLetter.set_H(matrix);
    }
    else if (c == 'I') {
        getNewPositions = pLetter.set_I(matrix);
    }
    else if (c == 'i') {
        getNewPositions = pLetter.set_i(matrix);
    }
    else if (c == 'J') {
        getNewPositions = pLetter.set_J(matrix);
    }
    else if (c == 'K') {
        getNewPositions = pLetter.set_K(matrix);
    }
    else if (c == 'L') {
        getNewPositions = pLetter.set_L(matrix);
    }
    else if (c == 'M') {
        getNewPositions = pLetter.set_M(matrix);
    }
    else if (c == 'N') {
        getNewPositions = pLetter.set_N(matrix);
    }
    else if (c == 'O') {
        getNewPositions = pLetter.set_O(matrix);
    }
    else if (c == 'P') {
        getNewPositions = pLetter.set_P(matrix);
    }
    else if (c == 'Q') {
        getNewPositions = pLetter.set_Q(matrix);
    }
    else if (c == 'R') {
        getNewPositions = pLetter.set_R(matrix);
    }
    else if (c == 'S') {
        getNewPositions = pLetter.set_S(matrix);
    }
    else if (c == 'T') {
        getNewPositions = pLetter.set_T(matrix);
    }
    else if (c == 'U') {
        getNewPositions = pLetter.set_U(matrix);
    }
    else if (c == 'V') {
        getNewPositions = pLetter.set_V(matrix);
    }
    else if (c == 'W') {
        getNewPositions = pLetter.set_W(matrix);
    }
    else if (c == 'X') {
        getNewPositions = pLetter.set_X(matrix);
    }
    else if (c == 'Y') {
        getNewPositions = pLetter.set_Y(matrix);
    }
    else if (c == 'Z') {
        getNewPositions = pLetter.set_Z(matrix);
    }

    //Check if it's a number
    if( (c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )
    {
        if( (matrix == MATRIX_3x2) || (matrix == MATRIX_3x8) )
        {
            return NBR_OF_COLUMN_SMALL_NUMBER;
        }
        else if(matrix == MATRIX_6x14)
        {
            return NBR_OF_COLUMN_BIG_NUMBER;
        }
        else
        {
            return 0;
        }
    }
    //Check if it's a letter
    else if( (c == 'A') || (c == 'B') || (c == 'C') || (c == 'D') || (c == 'E') || (c == 'F') || (c == 'G') || (c == 'H') || (c == 'I') || (c == 'J') ||
             (c == 'K') || (c == 'L') || (c == 'M') || (c == 'N') || (c == 'O') || (c == 'P') || (c == 'Q') || (c == 'R') || (c == 'S') || (c == 'T') ||
             (c == 'U') || (c == 'V') || (c == 'W') || (c == 'X') || (c == 'Y') || (c == 'Z') )
    {
        if(matrix == MATRIX_6x14)
        {
            return NBR_OF_COLUMN_BIG_LETTER;
        }
        else
        {
            return 0;
        }
    }
    else if( (c == 'i') )   //Special char
    {
        if(matrix == MATRIX_6x14)
        {
            return NBR_OF_COLUMN_SMALL_LETTER;
        }
        else
        {
            return 0;
        }
    }
    //Check if it's others
    else if( (c == ':') )
    {
        if( (matrix == MATRIX_3x2) || (matrix == MATRIX_3x8) )
        {
            return NBR_OF_COLUMN_SMALL_OTHERS;
        }
        else if(matrix == MATRIX_6x14)
        {
            return NBR_OF_COLUMN_BIG_OTHERS;
        }
        else
        {
            return 0;
        }
    }
}
//------------------------------------------------------------------------------
void Data::writeNewPosition(int matrix, int columnSelected, int nbrOfColumn)
{
    //1) Select the correct number of column to write
    //2) Write new positions

    int procID = 0;
    int clockID = 0;
    int newPos = 0;
    int outputAngle = 0;
    int nbrRow = 0;

    //1)
    switch(matrix)
    {
    case MATRIX_3x2:
    case MATRIX_3x8:
        nbrRow = 3;
        break;
    case MATRIX_6x14:
        nbrRow = 6;
        break;
    default:
        nbrRow = 0;
        break;
    }

    //2)
    for(int c=0; c< nbrOfColumn; c++)
    {
        for(int row=0; row<nbrRow; row++)
        {
            //Select procID and clockID to the correct matrix
            switch(matrix)
            {
            case MATRIX_3x2:
                procID = matrix_3_2[row][c+(columnSelected-1)].processorID; //0 to 13
                clockID = matrix_3_2[row][c+(columnSelected-1)].clockID - 1;//Rows 1 to 14
                break;
            case MATRIX_3x8:
                procID = matrix_3x8[row][c+(columnSelected-1)].processorID; //0 to 13
                clockID = matrix_3x8[row][c+(columnSelected-1)].clockID - 1;//Rows 1 to 14
                break;
            case MATRIX_6x14:
                procID = matrix_6x14[row][c+(columnSelected-1)].processorID; //0 to 13
                clockID = matrix_6x14[row][c+(columnSelected-1)].clockID - 1;//Rows 1 to 14
                break;
            default:
                procID = 0;
                clockID = 0;
                break;
            }

            //Update positions
            for(int wp=0; wp<MAX_WATCHPOINTER; wp++)
            {
                outputAngle = getProcessor(procID)->getClock(clockID)->getWatchPointer(wp)->getOutputAngle();
                newPos = getNewPositions[row][c][wp]/ outputAngle;
                getProcessor(procID)->getClock(clockID)->getWatchPointer(wp)->setNewPosition(newPos);
            }
        }
    }
}
//------------------------------------------------------------------------------
void Data::writeTest(int index)
{
    //Used only by the animation n°2
    int outputAngle;
    int newPos;

    switch(index)
    {
    case 0:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = UP_RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = UP_LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 1:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 2:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = DOWN_RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = DOWN_LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 3:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = DOWN/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = DOWN/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 4:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = DOWN_RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = DOWN_LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 5:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    case 6:
        for(int a=0; a<NBR_PROCESSOR; a++)
        {
            for(int b=0; b<NBR_CLOCK_PER_PROCESSOR; b++)
            {
                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(0)->getOutputAngle();
                newPos = UP_RIGHT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(0)->setNewPosition(newPos);

                outputAngle = getProcessor(a)->getClock(b)->getWatchPointer(1)->getOutputAngle();
                newPos = UP_LEFT/ outputAngle;
                getProcessor(a)->getClock(b)->getWatchPointer(1)->setNewPosition(newPos);
            }
        }
        break;
    default:
        break;
    }

    //Write new positions via SPI
    writeSPI();
}
//------------------------------------------------------------------------------

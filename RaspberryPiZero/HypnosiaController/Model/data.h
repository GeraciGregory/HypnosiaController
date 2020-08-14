#ifndef DATA_H
#define DATA_H

//---------------------------------------INCLUDE----------------------------------------
#include "Library/letterlibrary.h"
#include "Library/numberlibrary.h"
#include "View/observer.h"
#include "processor.h"
#include <iostream>
#include "wiringPiSPI.h"
#include "wiringPiSPI.h"
#include <QString>
#include <QChar>
//---------------------------------------DEFINE-----------------------------------------
#define NBR_PROCESSOR           14      //For the matrix 6x14
#define NBR_LINE_OF_PROCESSOR   7       //For the matrix 6x14
#define NBR_COLUMN_OF_PROCESSOR 2       //For the matrix 6x14
#define CHANNEL                 0       //Used for SPI communication
#define SPI_SPEED               1000000 //500'000Hz to 32'000'000Hz, SPI speed communication
#define SPI_FRAME_SIZE          11      //Max frame size
#define DUMMY_BYTE              0xFF
//Define an index for each type of matrix
#define MATRIX_3x2              0
#define MATRIX_3x8              1
#define MATRIX_6x14             2
//Define value for each type of matrix
#define MATRIX_3x2_COLUMN       2
#define MATRIX_3x2_LINE         3
#define MATRIX_3x8_COLUMN       3
#define MATRIX_3x8_LINE         8
#define MATRIX_6x14_COLUMN      6
#define MATRIX_6x14_LINE        14
//Used for the NUMBER & LETTER library
#define NBR_OF_COLUMN_SMALL_OTHERS  1
#define NBR_OF_COLUMN_BIG_OTHERS    2
#define NBR_OF_COLUMN_SMALL_NUMBER  2
#define NBR_OF_COLUMN_BIG_NUMBER    3
#define NBR_OF_COLUMN_BIG_LETTER    4
#define NBR_OF_COLUMN_SMALL_LETTER  2
//--------------------------------------------------------------------------------------
using namespace std;
class Data
{
public:
    Data();                                                                 //Constructor
    ~Data();                                                                //Destructor
    void initializeSPI();                                                   //Initialize SPI protocol
    void initializeRelation(Observer* observer);                            //Initialize relation

    Processor* getProcessor(int index);                                     //Used to use the selected processor
    int getNbrOfProcessor();                                                //Return number of processor (for matrix 6x14)
    void setPosition(bool incr, int proc, int clk, int watchPtr);           //Set position of a specific watch pointer

private:
    Observer* pObserver;
    Processor* processor[NBR_PROCESSOR];

    //Used for SPI communication
    int fd;         //File Descriptor
    int result;

    typedef enum
    {
        CONNECTED = 0,
        IN_PROGRESS = 1,
        WAITING = 2,
        READY = 3
    } status;
    status systemSatus;

public:
    LetterLibrary pLetter;
    NumberLibrary pNumber;


    void writeOnMatrix(int matrix, int columnSelected, QChar c);            //Write a char on a matrix
    int selectChar(int matrix, QChar c);                                    //Select correct char
    void writeNewPosition(int matrix, int columnSelected, int nbrOfColumn); //Write new positions according to the selected char

    void writeTest(int index);                                              //Test, used for animation n°2

private:
    //To structure the entire matrix
    struct motor
    {
        int processorID;
        int clockID;
    };

    int*** getNewPositions;

    motor matrix_3_2[3][2];
    motor matrix_3x8[3][8];
    motor matrix_6x14[6][14];

public:
    //--------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------SPI--------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------
    void writeSPI(void);                                //Update all watch pointer of each clock of each processor
    void writeSPI(int iProc);                           //Update all watch pointer of each clock of one processor
    void writeSPI(int iProc, int iClock);               //Update all watch pointer of one clock of one processor
    void writeSPI(int iProc, int iClock, int iWatchPtr);//Update one watch pointer of one clock of one processor

    void writeSPIConfig(void);                          //Update the configuration of each processor
    void writeSPIConfig(int iProc);                     //Update the configuration of the processor

    void goToZeroWriteSPI(void);
    void goToZeroWriteSPI(int iProc);
    void triggerWriteSPI(void);                         //Trigger the new values for each processor
    void triggerWriteSPI(int iProc);                    //Trigger the new values for one processor

    void resetPosZeroSPI(int iProc, int iClock, int iWatchPtr);
    //--------------------------------------------------------------------------------------------------------------------
};

#endif // DATA_H

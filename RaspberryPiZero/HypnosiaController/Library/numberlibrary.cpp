#include "numberlibrary.h"

//---------------------------------------------------------------------------------------------------
//------------------------------------------FRONT VIEW-----------------------------------------------
//---------------------------------------------------------------------------------------------------
//USED FOR 3x2 & 3x8 MATRIX
//  0    1
//  1
//  2
//---------------------------------------------------------------------------------------------------
//USED FOR 6x14 MATRIX
//  0    1   2
//  1
//  2
//  3
//  4
//  5
//---------------------------------------------------------------------------------------------------

//Initiliaze tridimensional array
NumberLibrary::NumberLibrary()
{
    positionArray = new int**[NBR_ROWS_NBR_MAX];

    for(int a=0; a<NBR_ROWS_NBR_MAX; a++)
    {
        positionArray[a] = new int*[NBR_COLUMN_NBR_MAX];

        for(int b=0; b<NBR_COLUMN_NBR_MAX; b++)
        {
            positionArray[a][b] = new int[NBR_WATCHPOINTER];
        }
    }
}

//Delete tridimensional array
NumberLibrary::~NumberLibrary()
{
    for(int a=0; a<NBR_ROWS_NBR_MAX; a++)
    {
        for(int b=0; b<NBR_COLUMN_NBR_MAX; b++)
        {
            delete [] positionArray[a][b];
        }
        delete [] positionArray[a];
    }

    delete [] positionArray;
}
//---------------------------------------------------------------------------------------------------
//NUMBERS LIBRARY
int*** NumberLibrary::set_0(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;
        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;
        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = RIGHT;
        positionArray[0][1][1] = LEFT;
        positionArray[0][2][0] = DOWN;
        positionArray[0][2][1] = LEFT;
        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;
        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;
        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;
        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = UP;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;
        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = RIGHT;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_1(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = DOWN_LEFT;
        positionArray[0][0][1] = DOWN_LEFT;
        positionArray[0][1][0] = DOWN_LEFT;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = UP_RIGHT;
        positionArray[1][0][1] = UP_RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = UP;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = DOWN_LEFT;
        positionArray[0][0][1] = DOWN_LEFT;
        positionArray[0][1][0] = RIGHT;
        positionArray[0][1][1] = DOWN_LEFT;
        positionArray[0][2][0] = DOWN;
        positionArray[0][2][1] = LEFT;

        positionArray[1][0][0] = UP_RIGHT;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = DOWN_LEFT;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = UP_RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = DOWN_LEFT;
        positionArray[3][0][1] = DOWN_LEFT;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = DOWN_LEFT;
        positionArray[4][0][1] = DOWN_LEFT;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = DOWN_LEFT;
        positionArray[5][0][1] = DOWN_LEFT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_2(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = RIGHT;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = RIGHT;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = LEFT;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = LEFT;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = RIGHT;
        positionArray[0][1][1] = LEFT;
        positionArray[0][2][0] = DOWN;
        positionArray[0][2][1] = LEFT;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = LEFT;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = RIGHT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = LEFT;

        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = RIGHT;
        positionArray[4][2][0] = DOWN;
        positionArray[4][2][1] = LEFT;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = RIGHT;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_3(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = RIGHT;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = RIGHT;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = RIGHT;
        positionArray[0][1][1] = LEFT;
        positionArray[0][2][0] = DOWN;
        positionArray[0][2][1] = LEFT;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = LEFT;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = RIGHT;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = RIGHT;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = LEFT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = RIGHT;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_4(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = DOWN;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = DOWN;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = LEFT;

        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = UP;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;
        positionArray[0][2][0] = DOWN_LEFT;
        positionArray[0][2][1] = DOWN_LEFT;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = DOWN_LEFT;
        positionArray[1][2][1] = DOWN_LEFT;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = LEFT;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = RIGHT;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = DOWN_LEFT;
        positionArray[4][0][1] = DOWN_LEFT;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = DOWN_LEFT;
        positionArray[5][0][1] = DOWN_LEFT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_5(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = LEFT;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = LEFT;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = LEFT;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = LEFT;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = RIGHT;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = RIGHT;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = LEFT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_6(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = LEFT;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = LEFT;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = LEFT;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = LEFT;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = DOWN;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = UP;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_7(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = RIGHT;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = LEFT;

        positionArray[1][0][0] = DOWN_LEFT;
        positionArray[1][0][1] = DOWN_LEFT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = UP;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = LEFT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = DOWN_LEFT;
        positionArray[3][0][1] = DOWN_LEFT;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = DOWN_LEFT;
        positionArray[4][0][1] = DOWN_LEFT;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = DOWN_LEFT;
        positionArray[5][0][1] = DOWN_LEFT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_8(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = LEFT;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN_RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = UP;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN_LEFT;

        positionArray[3][0][0] = UP_RIGHT;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = DOWN;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP_LEFT;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = UP;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_9(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;

        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = RIGHT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = LEFT;
        break;

    case 2: //6x14 MATRIX
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = DOWN;

        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = DOWN;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;

        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = UP;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;

        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = RIGHT;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;

        positionArray[4][0][0] = RIGHT;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = LEFT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;

        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** NumberLibrary::set_betweenTime(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        positionArray[0][0][0] = DOWN_LEFT;
        positionArray[0][0][1] = DOWN_RIGHT;

        positionArray[1][0][0] = DOWN_LEFT;
        positionArray[1][0][1] = DOWN_RIGHT;

        positionArray[2][0][0] = UP_LEFT;
        positionArray[2][0][1] = UP_RIGHT;
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN_RIGHT;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN_LEFT;
        //Line 2
        positionArray[1][0][0] = RIGHT;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = LEFT;
        positionArray[1][1][1] = DOWN;
        //Line 3
        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = UP;
        positionArray[2][1][0] = LEFT;
        positionArray[2][1][1] = UP;
        //Line 4
        positionArray[3][0][0] = RIGHT;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = DOWN;
        //Line 5
        positionArray[4][0][0] = RIGHT;
        positionArray[4][0][1] = UP;
        positionArray[4][1][0] = LEFT;
        positionArray[4][1][1] = UP;
        //Line 6
        positionArray[5][0][0] = RIGHT;
        positionArray[5][0][1] = UP_RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = UP_LEFT;
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------

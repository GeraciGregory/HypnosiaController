#include "letterlibrary.h"

//---------------------------------------------------------------------------------------------------
//------------------------------------------FRONT VIEW-----------------------------------------------
//---------------------------------------------------------------------------------------------------
//USED FOR 6x14 MATRIX
//  0    1   2   3
//  1
//  2
//  3
//  4
//  5
//---------------------------------------------------------------------------------------------------

//Initiliaze tridimensional array
LetterLibrary::LetterLibrary()
{
    positionArray = new int**[NBR_ROWS_LETTER_MAX];

    for(int a=0; a<NBR_ROWS_LETTER_MAX; a++)
    {
        positionArray[a] = new int*[NBR_COLUMN_LETTER_MAX];

        for(int b=0; b<NBR_COLUMN_LETTER_MAX; b++)
        {
            positionArray[a][b] = new int[NBR_WATCHPOINTER];
        }
    }
}
//Delete tridimensional array
LetterLibrary::~LetterLibrary()
{
    for(int a=0; a<NBR_ROWS_LETTER_MAX; a++)
    {
        for(int b=0; b<NBR_COLUMN_LETTER_MAX; b++)
        {
            delete [] positionArray[a][b];
        }
        delete [] positionArray[a];
    }

    delete [] positionArray;
}

//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_A(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_B(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_C(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_D(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_E(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = LEFT;
        positionArray[1][2][1] = RIGHT;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = LEFT;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = LEFT;
        positionArray[2][2][1] = RIGHT;
        positionArray[2][3][0] = LEFT;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = RIGHT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = LEFT;
        positionArray[3][2][1] = RIGHT;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = LEFT;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = RIGHT;
        positionArray[4][2][0] = LEFT;
        positionArray[4][2][1] = RIGHT;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = LEFT;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = LEFT;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_F(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_G(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = LEFT;
        positionArray[1][2][1] = RIGHT;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = LEFT;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = DOWN_LEFT;
        positionArray[2][2][1] = RIGHT;
        positionArray[2][3][0] = LEFT;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP_LEFT;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = RIGHT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = LEFT;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = LEFT;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_H(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;
        positionArray[0][2][0] = RIGHT;
        positionArray[0][2][1] = DOWN;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = DOWN;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = LEFT;
        positionArray[2][3][0] = UP;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = RIGHT;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = LEFT;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_i(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = LEFT;

        //Line 3
        positionArray[2][0][0] = RIGHT;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = LEFT;
        positionArray[2][1][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_I(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN_RIGHT;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN_LEFT;

        //Line 2
        positionArray[1][0][0] = DOWN_LEFT;
        positionArray[1][0][1] = DOWN_LEFT;
        positionArray[1][1][0] = UP_LEFT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = UP_RIGHT;
        positionArray[1][2][1] = DOWN;
        positionArray[1][3][0] = DOWN_LEFT;
        positionArray[1][3][1] = DOWN_LEFT;

        //Line 3
        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;
        positionArray[2][3][0] = DOWN_LEFT;
        positionArray[2][3][1] = DOWN_LEFT;

        //Line 4
        positionArray[3][0][0] = DOWN_LEFT;
        positionArray[3][0][1] = DOWN_LEFT;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = DOWN_LEFT;
        positionArray[3][3][1] = DOWN_LEFT;

        //Line 5
        positionArray[4][0][0] = DOWN_LEFT;
        positionArray[4][0][1] = DOWN_LEFT;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN_LEFT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN_RIGHT;
        positionArray[4][3][0] = DOWN_LEFT;
        positionArray[4][3][1] = DOWN_LEFT;

        //Line 6
        positionArray[5][0][0] = UP_RIGHT;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = LEFT;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP_LEFT;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_J(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_K(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_L(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_M(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;
        positionArray[0][2][0] = RIGHT;
        positionArray[0][2][1] = DOWN;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN_RIGHT;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN_LEFT;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = DOWN;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = DOWN_RIGHT;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = DOWN_LEFT;
        positionArray[2][2][1] = DOWN;
        positionArray[2][3][0] = UP;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_N(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = DOWN;
        positionArray[0][2][0] = RIGHT;
        positionArray[0][2][1] = DOWN;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = UP;
        positionArray[1][1][1] = DOWN_RIGHT;
        positionArray[1][2][0] = UP;
        positionArray[1][2][1] = DOWN;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = DOWN;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = DOWN_RIGHT;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = UP_LEFT;
        positionArray[2][3][0] = UP;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP_LEFT;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = LEFT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_O(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = LEFT;
        positionArray[1][2][1] = DOWN;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = DOWN;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;
        positionArray[2][3][0] = UP;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = DOWN;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = UP;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = RIGHT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = LEFT;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = LEFT;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_P(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_Q(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_R(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_S(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = DOWN;
        positionArray[1][1][0] = RIGHT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = LEFT;
        positionArray[1][2][1] = RIGHT;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = LEFT;

        //Line 3
        positionArray[2][0][0] = UP;
        positionArray[2][0][1] = DOWN;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = RIGHT;
        positionArray[2][2][0] = LEFT;
        positionArray[2][2][1] = RIGHT;
        positionArray[2][3][0] = LEFT;
        positionArray[2][3][1] = DOWN;

        //Line 4
        positionArray[3][0][0] = UP;
        positionArray[3][0][1] = RIGHT;
        positionArray[3][1][0] = LEFT;
        positionArray[3][1][1] = RIGHT;
        positionArray[3][2][0] = LEFT;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = UP;
        positionArray[3][3][1] = DOWN;

        //Line 5
        positionArray[4][0][0] = RIGHT;
        positionArray[4][0][1] = DOWN;
        positionArray[4][1][0] = LEFT;
        positionArray[4][1][1] = RIGHT;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = LEFT;
        positionArray[4][3][0] = UP;
        positionArray[4][3][1] = DOWN;

        //Line 6
        positionArray[5][0][0] = UP;
        positionArray[5][0][1] = RIGHT;
        positionArray[5][1][0] = LEFT;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = LEFT;
        positionArray[5][2][1] = RIGHT;
        positionArray[5][3][0] = UP;
        positionArray[5][3][1] = LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_T(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
    case 1: //3x8 MATRIX
        break;

    case 2: //6x14 MATRIX
        //Line 1
        positionArray[0][0][0] = RIGHT;
        positionArray[0][0][1] = DOWN;
        positionArray[0][1][0] = LEFT;
        positionArray[0][1][1] = RIGHT;
        positionArray[0][2][0] = LEFT;
        positionArray[0][2][1] = RIGHT;
        positionArray[0][3][0] = LEFT;
        positionArray[0][3][1] = DOWN;

        //Line 2
        positionArray[1][0][0] = UP;
        positionArray[1][0][1] = RIGHT;
        positionArray[1][1][0] = LEFT;
        positionArray[1][1][1] = DOWN;
        positionArray[1][2][0] = RIGHT;
        positionArray[1][2][1] = DOWN;
        positionArray[1][3][0] = UP;
        positionArray[1][3][1] = LEFT;

        //Line 3
        positionArray[2][0][0] = DOWN_LEFT;
        positionArray[2][0][1] = DOWN_LEFT;
        positionArray[2][1][0] = UP;
        positionArray[2][1][1] = DOWN;
        positionArray[2][2][0] = UP;
        positionArray[2][2][1] = DOWN;
        positionArray[2][3][0] = DOWN_LEFT;
        positionArray[2][3][1] = DOWN_LEFT;

        //Line 4
        positionArray[3][0][0] = DOWN_LEFT;
        positionArray[3][0][1] = DOWN_LEFT;
        positionArray[3][1][0] = UP;
        positionArray[3][1][1] = DOWN;
        positionArray[3][2][0] = UP;
        positionArray[3][2][1] = DOWN;
        positionArray[3][3][0] = DOWN_LEFT;
        positionArray[3][3][1] = DOWN_LEFT;

        //Line 5
        positionArray[4][0][0] = DOWN_LEFT;
        positionArray[4][0][1] = DOWN_LEFT;
        positionArray[4][1][0] = UP;
        positionArray[4][1][1] = DOWN;
        positionArray[4][2][0] = UP;
        positionArray[4][2][1] = DOWN;
        positionArray[4][3][0] = DOWN_LEFT;
        positionArray[4][3][1] = DOWN_LEFT;

        //Line 6
        positionArray[5][0][0] = DOWN_LEFT;
        positionArray[5][0][1] = DOWN_LEFT;
        positionArray[5][1][0] = UP;
        positionArray[5][1][1] = RIGHT;
        positionArray[5][2][0] = UP;
        positionArray[5][2][1] = LEFT;
        positionArray[5][3][0] = DOWN_LEFT;
        positionArray[5][3][1] = DOWN_LEFT;

        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_U(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_V(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_W(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_X(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_Y(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------
int*** LetterLibrary::set_Z(int matrix)
{
    switch (matrix)
    {
    case 0: //3X2 MATRIX
        break;
    case 1: //3x8 MATRIX
        break;
    case 2: //6x14 MATRIX
        break;
    }
    return positionArray;
}
//---------------------------------------------------------------------------------------------------

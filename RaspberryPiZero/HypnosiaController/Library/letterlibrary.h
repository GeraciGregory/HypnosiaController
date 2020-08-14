#ifndef LETTERLIBRARY_H
#define LETTERLIBRARY_H

#include "numberlibrary.h"

#define NBR_ROWS_LETTER_MAX   6
#define NBR_COLUMN_LETTER_MAX 4
#define NBR_WATCHPOINTER      2

class LetterLibrary
{
public:
    LetterLibrary();
    ~LetterLibrary();

    int*** positionArray;

//NUMBERS
public:
    int*** set_A(int matrix);
    int*** set_B(int matrix);
    int*** set_C(int matrix);
    int*** set_D(int matrix);
    int*** set_E(int matrix);
    int*** set_F(int matrix);
    int*** set_G(int matrix);
    int*** set_H(int matrix);
    int*** set_i(int matrix);
    int*** set_I(int matrix);
    int*** set_J(int matrix);
    int*** set_K(int matrix);
    int*** set_L(int matrix);
    int*** set_M(int matrix);
    int*** set_N(int matrix);
    int*** set_O(int matrix);
    int*** set_P(int matrix);
    int*** set_Q(int matrix);
    int*** set_R(int matrix);
    int*** set_S(int matrix);
    int*** set_T(int matrix);
    int*** set_U(int matrix);
    int*** set_V(int matrix);
    int*** set_W(int matrix);
    int*** set_X(int matrix);
    int*** set_Y(int matrix);
    int*** set_Z(int matrix);
};

#endif // LETTERLIBRARY_H

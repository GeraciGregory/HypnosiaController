#ifndef NUMBERLIBRARY_H
#define NUMBERLIBRARY_H

//-------------------------------------------------
//Fixed positions
#define UP          0
#define RIGHT       270
#define DOWN        180
#define LEFT        90
#define UP_RIGHT    318
#define UP_LEFT     42
#define DOWN_RIGHT  222
#define DOWN_LEFT   138
//-------------------------------------------------
#define NBR_ROWS_NBR_MAX    6
#define NBR_COLUMN_NBR_MAX  3
#define NBR_WATCHPOINTER    2
//-------------------------------------------------

class NumberLibrary
{
public:
    NumberLibrary();
    ~NumberLibrary();

    int*** positionArray;

//NUMBERS
public:
    int*** set_TEST_1();
    int*** set_TEST_2();
    int*** set_TEST_3();
    int*** set_TEST_4();

    int*** set_0(int matrix);
    int*** set_1(int matrix);
    int*** set_2(int matrix);
    int*** set_3(int matrix);
    int*** set_4(int matrix);
    int*** set_5(int matrix);
    int*** set_6(int matrix);
    int*** set_7(int matrix);
    int*** set_8(int matrix);
    int*** set_9(int matrix);

    int*** set_betweenTime(int matrix);
};

#endif // NUMBERLIBRARY_H

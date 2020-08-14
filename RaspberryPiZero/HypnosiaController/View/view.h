#ifndef VIEW_H
#define VIEW_H

#include <QString>
#include <QWidget>
#include "Controller/controller.h"
#include "observer.h"
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QObject>

class Button;
class ComboBox;
class Label;
class Controller;

class View: public QWidget, public Observer
{    
    Q_OBJECT  //Used for signals and slots

public:
    View(int x,int y,int width,int height,QString title, QWidget* parent=0);    //Constructor, used to initialize size of the GUI application
    ~View();                                                                    //Destructor
    void initializeRelation(Controller* controller);                            //Initialize relation
    void setupUI();                                                             //Setup User Interface
    void changed();                                                             //Interface method
    void stop();                                                                //Interface method

    //---------------------------------
    QPushButton* anim1;
    QPushButton* plusBtn;
    QPushButton* minusBtn;
    QPushButton* resetPosition;
    QPushButton* btnPlusProc;
    QPushButton* btnMinusProc;
    QPushButton* btnPlusClock;
    QPushButton* btnMinusClock;
    QPushButton* btnPlusWatchPtr;
    QPushButton* btnMinusWatchPtr;
    //---------------------------------
    QLabel* lbProcessor;
    QLabel* lbClock;
    QLabel* lbWatchPointer;
    //---------------------------------

private:
    Controller* pController;

    //window parameters
    int x;
    int y;
    int width;
    int height;
    QString title;
};

#endif // VIEW_H

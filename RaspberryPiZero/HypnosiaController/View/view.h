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
    View(int x,int y,int width,int height,QString title, QWidget* parent=0);
    //View();
    ~View();
    void initializeRelation(Controller* controller);
    void setupUI(); //Setup User Interface
    void changed();
    void stop();

    QPushButton* countDown;
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


    QLabel* lbProcessor;
    QLabel* lbClock;
    QLabel* lbWatchPointer;

public slots:
    void onBoxChanged();

private:
    Controller* pController;

    //window
    int x;
    int y;
    int width;
    int height;
    QString title;
};

#endif // VIEW_H

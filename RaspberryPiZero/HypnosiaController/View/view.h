#ifndef VIEW_H
#define VIEW_H

#include <QString>
#include <QWidget>
#include "Controller/controller.h"
#include "Button/button.h"
#include "Button/combobox.h"
#include "Button/label.h"
#include "observer.h"


class Button;
class ComboBox;
class Label;
class Controller;

class View: public QWidget, public Observer
{    
public:
    View(int x,int y,int width,int height,QString title);
    //View();
    ~View();
    void initializeRelation(Controller* controller);
    void setupUI(); //Setup User Interface
    void changed();
    void stop();

    Button* countDown;
    Button* anim1;
    Button* plusBtn;
    Button* minusBtn;
    ComboBox* cbProcessor;
    Label* lbProcessor;
    ComboBox* cbClock;
    Label* lbClock;
    ComboBox* cbWatchPointer;
    Label* lbWatchPointer;

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

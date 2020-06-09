#ifndef VIEW_H
#define VIEW_H

#include <QString>
#include <QWidget>
#include "Controller/controller.h"
#include "Button/button.h"
#include "observer.h"


class Button;

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

private:
    Controller* pController;
    Button* countDown;
    Button* anim1;

    //window
    int x;
    int y;
    int width;
    int height;
    QString title;
};

#endif // VIEW_H

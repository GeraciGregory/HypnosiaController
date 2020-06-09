#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button: public QPushButton
{
    //Q_OBJECT

public:
    Button(QWidget* parent);
    ~Button();

    /*
private slots:
    void buttonClicked();

signals:
    void close();
    */
};

#endif // BUTTON_H

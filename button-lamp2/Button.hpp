#ifndef BUTTON_H
#define BUTTON_H

class ButtonClient;

class Button {
private:
    ButtonClient* itsClient;

public:
    Button(ButtonClient*);
    void Detect();
    virtual bool getState() = 0;
};

#endif

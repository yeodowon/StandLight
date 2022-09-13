#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include <iostream>
#include "Led.h"

enum {LIGHT_OFF, LIGHT_ON};


class Controller
{
private:
    int lightState;
    Led *light;

public:
    Controller(Led *Led);
    virtual ~Controller(); //virtual 다형성할때 필요
    void updateEvent(std::string strBtn);

};

#endif
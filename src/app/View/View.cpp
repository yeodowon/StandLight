#include "View.h"
#include <wiringPi.h>

View::View(Led *Led)
{
    light = Led;
    lightState = LIGHT_OFF;
}

View::~View()
{
}

void View::updateState(std::string strState)
{
    switch (lightState)
    {
    case LIGHT_OFF:
        lightOff();
        if (strState == "StateOn")
        {
            lightState = LIGHT_ON;
        }
        break;

    case LIGHT_ON:
        lightOn();
        if (strState == "StateOff")
        {
            lightState = LIGHT_OFF;
        }
        break;
    }
}

void View::lightView()
{
    switch (lightState)
    {
    case LIGHT_OFF:
        lightOff();

        break;

    case LIGHT_ON:
        lightOn();

        break;
    }
}

void View::lightOn()
{
    static int prevtime = 0;
    if(millis() - prevtime < 300) return;
    prevtime = millis();
    light->Toggle();
}

void View::lightOff()
{
    light->Off();
}
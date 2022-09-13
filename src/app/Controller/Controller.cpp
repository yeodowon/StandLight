#include "Controller.h"

Controller::Controller(Led *Led)
{
    light = Led;            //이름을 light로 하겠다.
    lightState = LIGHT_OFF; //초기화
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    switch (lightState)
    {
    case LIGHT_OFF:
        if (strBtn == "powerButton")
        {
            lightState = LIGHT_ON;
            light->On();
        }
        break;
    case LIGHT_ON:
        if (strBtn == "powerButton")
        {
            lightState = LIGHT_OFF;
            light->Off();
        }
        break;
    }
}
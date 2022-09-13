#include <iostream>
#include <wiringPi.h>
#include "Listener.h"
#include "Led.h"
#include "View.h"
#include "Button.h"
#include "Controller.h"




int main()
{
    std::cout << "Hello World!" << std::endl;
    
    Button button1(27); //의미부여(추상화)
    Led led1(25);// Led인데 light라는 이름을 주었다(의미부여)
    View view(&led1);
    Controller conrtol(&view);
    Listener listener(&button1, &conrtol); 
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(50); //50ms 간격으로 버튼 감시
    }
    
    return 0;
}
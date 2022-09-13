#include <iostream>
#include <wiringPi.h>
#include "Listener.h"
#include "Button.h"
#include "Led.h"





int main()
{
    std::cout << "Hello World!" << std::endl;
    
    Button button1(27); //의미부여(추상화)
    Led led1(25);// Led인데 light라는 이름을 주었다(의미부여)
    Listener listener(&button1, &led1); 
    while (1)
    {
        listener.checkEvent();
        delay(50); //50ms 간격으로 버튼 감시
    }
    
    return 0;
}
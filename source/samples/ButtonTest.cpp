#include "MicroBit.h"
#include "Tests.h"



void
onButtonA(MicroBitEvent)
{
    uBit.display.print("Aa");
}

void
onButtonB(MicroBitEvent)
{
    uBit.display.print("Bb");
}

void
onButtonAB(MicroBitEvent)
{
    uBit.display.print("Cc");
}

void listenerRemoved(MicroBitListener *)
{
    DMESG("Listener deleted");
}

void
button_test1()//最原始的读写io口的方式
{
    while(1)
    {
        if (uBit.io.P5.getDigitalValue())//P5是左键
            uBit.display.image.setPixelValue(0,0,0);
        else
            uBit.display.image.setPixelValue(0,0,255);

        if (uBit.io.P11.getDigitalValue())//P11是右键
            uBit.display.image.setPixelValue(4,0,0);
        else
            uBit.display.image.setPixelValue(4,0,255);

        uBit.sleep(100);
    }
}

void
button_test2()//包装成按钮类的模式
{
    while(1)
    {
        if (uBit.buttonA.isPressed())
            uBit.display.image.setPixelValue(0,0,255);
        else
            uBit.display.image.setPixelValue(0,0,0);

        if (uBit.buttonB.isPressed())
            uBit.display.image.setPixelValue(4,0,255);
        else
            uBit.display.image.setPixelValue(4,0,0);

        uBit.sleep(100);
    }
}

void
button_test3()//事件监听的方式
{
    uBit.messageBus.listen(DEVICE_ID_BUTTON_A, DEVICE_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_B, DEVICE_BUTTON_EVT_CLICK, onButtonB);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, onButtonAB);

    while(1)
        uBit.sleep(1000);
}

void
button_test4()//增加一个删除监听触发回调的例子
{
    uBit.messageBus.setListenerDeletionCallback(listenerRemoved);
    
    uBit.messageBus.listen(DEVICE_ID_BUTTON_A, DEVICE_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_B, DEVICE_BUTTON_EVT_CLICK, onButtonB);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, onButtonAB);

    uBit.sleep(10000);

    uBit.messageBus.ignore(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, onButtonAB);

    while(1)
        uBit.sleep(1000);
}



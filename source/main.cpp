#include "MicroBit.h"
#include "samples/Tests.h"
#include "samples/CMicroBit.h"
using namespace std;


MicroBit uBit;
// MicroBit 主板;

int 主函数()
{
    uBit.init();
    // 主板.init();

    // blinky();
    主板.点阵显示屏.滚动显示("go!");
    while (1)
    {
        // uBit.display.scroll("ding!");
        
    }
}
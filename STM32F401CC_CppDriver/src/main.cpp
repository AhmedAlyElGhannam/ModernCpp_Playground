#include "std_types.h"
#include "RCC.h"
#include "LED.hpp"

#define DELAY()     for (volatile uint32_t i = 0; i < 1000000; i++)

int main() 
{
    MRCC_enuSetPeripheralClkState(MRCC_AHB1_GPIOA | MRCC_AHB1_GPIOB | MRCC_AHB1_GPIOC, MRCC_PERIPHERAL_CLK_ENABLE);

    LED ledAqua(GPIOA, PIN00, ACTIVE_LOW);
    LED ledPink(GPIOA, PIN01, ACTIVE_HIGH);
    LED ledGreen(GPIOA, PIN02, ACTIVE_HIGH);
    LED ledRed(GPIOA, PIN03, ACTIVE_HIGH);
    LED ledYellow(GPIOA, PIN04, ACTIVE_HIGH);

    while (1) 
    {
        ledAqua.HLED_voidTurnOn();
        ledPink.HLED_voidTurnOn();
        ledGreen.HLED_voidTurnOn();
        ledRed.HLED_voidTurnOn();
        ledYellow.HLED_voidTurnOn();

        DELAY();

        ledAqua.HLED_voidTurnOff();
        ledPink.HLED_voidTurnOff();
        ledGreen.HLED_voidTurnOff();
        ledRed.HLED_voidTurnOff();
        ledYellow.HLED_voidTurnOff();

        DELAY();
    }

    return 0;
}
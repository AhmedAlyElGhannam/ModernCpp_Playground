#include "std_types.h"
#include "error_status.h"
#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "SYSTICK.h"
#include "scheduler.h"
#include "LCD.h"


int main(void)
{

    MRCC_enuSetPeripheralClkState(MRCC_AHB1_GPIOA | MRCC_AHB1_GPIOB | MRCC_AHB1_GPIOC, MRCC_PERIPHERAL_CLK_ENABLE);

    MGPIO_enuSetPinMode(GPIOA, PIN01, GPOUT);
    MGPIO_enuOutputSpeed(GPIOA, PIN01, VHIGH_SPEED);

    MGPIO_enuSetPinMode(GPIOA, PIN01, GPOUT);
    MGPIO_enuOutputSpeed(GPIOA, PIN01, VHIGH_SPEED);


    while (true)
    {
        MGPIO_enuSetPinVal(GPIOA, PIN01, PIN_HIGH);
        for (volatile uint32_t i = 0; i < 800000; i++);
        MGPIO_enuSetPinVal(GPIOA, PIN01, PIN_LOW);
        for (volatile uint32_t i = 0; i < 800000; i++);
    }
    return 0;
}


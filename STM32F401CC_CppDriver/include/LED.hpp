#ifndef LED_HPP
#define LED_HPP

#include <GPIO.hpp>

typedef enum 
{
    LED_ON = 1U,
    LED_OFF = !LED_ON,
} HLED_enuLEDState_t;

typedef enum 
{
    ACTIVE_HIGH = 0U,
    ACTIVE_LOW = !ACTIVE_HIGH,
} HLED_enuLEDConnection_t;

class LED : protected GPIO
{
    public:
        LED();
        LED(MGPIO_enuPortDesignator_t _port, MGPIO_enuPinDesignator_t _pin, HLED_enuLEDConnection_t _connection);

        void HLED_voidTurnOn();
        void HLED_voidTurnOff();

    protected:
        HLED_enuLEDConnection_t connection;
};

#endif
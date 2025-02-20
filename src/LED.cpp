#include <LED.hpp>

LED::LED() : GPIO(INV_PORT, INV_PIN)
{
    this->connection = ACTIVE_HIGH;
}

LED::LED(MGPIO_enuPortDesignator_t _port, MGPIO_enuPinDesignator_t _pin, HLED_enuLEDConnection_t _connection) : GPIO(_port, _pin)
{
    this->connection = _connection;

    this->MGPIO_enuSetPinMode(GPOUT);
    this->MGPIO_enuOutputSpeed(VHIGH_SPEED);
}

void LED::HLED_voidTurnOn()
{
    this->MGPIO_enuSetPinVal(this->connection ^ LED_ON == 1 ? PIN_HIGH : PIN_LOW);
}
void LED::HLED_voidTurnOff()
{
    this->MGPIO_enuSetPinVal(this->connection ^ LED_ON == 1 ? PIN_LOW : PIN_HIGH);
}
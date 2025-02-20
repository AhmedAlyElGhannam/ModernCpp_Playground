#include <GPIO.hpp>

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIOx_Registers_t;

#define GPIO_BASE_ADDRESS   ((uint32_t)0x40020000UL)
#define GPIO_GET_PORT_ADDRESS(GPIOx)    \
    ((GPIOx_Registers_t*)(((GPIO_BASE_ADDRESS) + (((uint32_t)(GPIOx)) * (0x400UL)))))

#define IS_INVALID_PTR(PTR)     (NULL == PTR)
#define IS_INVALID_MODE(MODE)   (MODE > ANALOG)
#define IS_INVALID_ALT_FUNC(AF) (AF > ALT_FUNC15)
#define IS_INVALID_OUT_TYPE(OUT)    (OUT > ODR)
#define IS_INVALID_OUT_SPEED(SPD)   (SPD > VHIGH_SPEED)
#define IS_INVALID_RES_CONFIG(RES)  (RES > PD_RES)
#define IS_INVALID_PIN_VAL(VAL)     ((VAL != PIN_HIGH) && (VAL != PIN_LOW))

GPIO::GPIO()
{
    this->pin = INV_PIN;
    this->port = INV_PORT;
}

GPIO::GPIO(MGPIO_enuPortDesignator_t _port, MGPIO_enuPinDesignator_t _pin)
{
    this->pin = _pin;
    this->port = _port;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuSetPinMode(MGPIO_enuPinMode_t copy_enuPinMode)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_MODE(copy_enuPinMode))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        ptr_structGPIOPortBaseAdd->MODER &= ~(0x03UL << (2 * this->pin));
        ptr_structGPIOPortBaseAdd->MODER |= (copy_enuPinMode << (2 * this->pin));
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuAltFuncSel(MGPIO_enuPinAltFunc_t copy_enuPinAltFunc)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_ALT_FUNC(copy_enuPinAltFunc))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        if (this->pin < PIN08)
        {
            ptr_structGPIOPortBaseAdd->AFRL = (ptr_structGPIOPortBaseAdd->AFRL & ~(0xFFUL << (4 * this->pin))) | (copy_enuPinAltFunc << (4 * this->pin));
        }
        else if (this->pin >= PIN08)
        {
            ptr_structGPIOPortBaseAdd->AFRH = (ptr_structGPIOPortBaseAdd->AFRH & ~(0xFFUL << (4 * (this->pin - PIN08)))) | (copy_enuPinAltFunc << (4 * (this->pin - PIN08)));
        }
        else {}
        
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuOutputType(MGPIO_enuPinOutType_t copy_enuPinOutType)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_OUT_TYPE(copy_enuPinOutType))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        ptr_structGPIOPortBaseAdd->OTYPER = (ptr_structGPIOPortBaseAdd->OTYPER & ~(0x01UL << this->pin)) | (copy_enuPinOutType << this->pin);
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuOutputSpeed(MGPIO_enuPinOutSpeed_t copy_enuPinOutSpeed)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_OUT_SPEED(copy_enuPinOutSpeed))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        ptr_structGPIOPortBaseAdd->OSPEEDR = (ptr_structGPIOPortBaseAdd->OSPEEDR & ~(0x03UL << (2 * this->pin))) | (copy_enuPinOutSpeed << (2 * this->pin));
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuPinResConfig(MGPIO_enuPinResConfig_t copy_enuPinResConfig)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_RES_CONFIG(copy_enuPinResConfig))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        ptr_structGPIOPortBaseAdd->PUPDR = (ptr_structGPIOPortBaseAdd->PUPDR & ~(0x03UL << (2 * this->pin))) | (copy_enuPinResConfig << (2 * this->pin));
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuSetPinVal(MGPIO_enuPinVal_t copy_enuPinVal)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_PIN_VAL(copy_enuPinVal))
    {
        ret_enuErrorStatus = INV_ARG;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        ptr_structGPIOPortBaseAdd->BSRR = (ptr_structGPIOPortBaseAdd->BSRR & ~(copy_enuPinVal << this->pin)) | (copy_enuPinVal << this->pin);
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuGetPinVal(uint32_t* ptr_uint32PinVal)
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;

    if (IS_INVALID_PTR(ptr_uint32PinVal))
    {
        ret_enuErrorStatus = NULL_PTR;
    }
    else
    {
        GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

        (*ptr_uint32PinVal) = ((ptr_structGPIOPortBaseAdd->IDR >> this->pin) & 0x01UL);
    }

    return ret_enuErrorStatus;
}

SRV_enuErrorStatus_t GPIO::MGPIO_enuPinLockEnable()
{
    SRV_enuErrorStatus_t ret_enuErrorStatus = ALL_OK;
    GPIOx_Registers_t* ptr_structGPIOPortBaseAdd = GPIO_GET_PORT_ADDRESS(this->port);

    /* set bit corresponding to pin */
    ptr_structGPIOPortBaseAdd->LCKR = (ptr_structGPIOPortBaseAdd->LCKR & ~(0x01UL << this->pin)) | (0x01UL << this->pin);

    /* set LCKK */
    ptr_structGPIOPortBaseAdd->LCKR |= 0x10000UL;

    /* clr LCKK */
    ptr_structGPIOPortBaseAdd->LCKR &= ~(0x10000UL);

    /* set LCKK */
    ptr_structGPIOPortBaseAdd->LCKR |= 0x10000UL;

    /* if LCKK is not set -> return NOK */
    if (!((ptr_structGPIOPortBaseAdd->LCKR >> 16) & 0x01UL))
    {
        ret_enuErrorStatus = NOK;
    }
    else {} /* lock was set successfully */

    return ret_enuErrorStatus;
}

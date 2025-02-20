#ifndef GPIO_HPP
#define GPIO_HPP

#include "error_status.h"
#include "std_types.h"

/**
 * @enum MGPIO_enuPortDesignator_t
 * @brief Enumeration for GPIO port designators.
 */
typedef enum
{
    GPIOA = 0x00UL, /**< GPIO Port A */
    GPIOB,          /**< GPIO Port B */
    GPIOC,          /**< GPIO Port C */
    GPIOD,          /**< GPIO Port D */
    GPIOE,          /**< GPIO Port E */
    GPIOF,          /**< GPIO Port F (unsupported) */
    GPIOG,          /**< GPIO Port G (unsupported) */
    GPIOH,          /**< GPIO Port H */
    INV_PORT,
} MGPIO_enuPortDesignator_t;

/**
 * @enum MGPIO_enuPinDesignator_t
 * @brief Enumeration for GPIO pin designators.
 */
typedef enum
{
    PIN00 = 0x00UL, /**< GPIO Pin 0 */
    PIN01,          /**< GPIO Pin 1 */
    PIN02,          /**< GPIO Pin 2 */
    PIN03,          /**< GPIO Pin 3 */
    PIN04,          /**< GPIO Pin 4 */
    PIN05,          /**< GPIO Pin 5 */
    PIN06,          /**< GPIO Pin 6 */
    PIN07,          /**< GPIO Pin 7 */
    PIN08,          /**< GPIO Pin 8 */
    PIN09,          /**< GPIO Pin 9 */
    PIN10,          /**< GPIO Pin 10 */
    PIN11,          /**< GPIO Pin 11 */
    PIN12,          /**< GPIO Pin 12 */
    PIN13,          /**< GPIO Pin 13 */
    PIN14,          /**< GPIO Pin 14 */
    PIN15 = 0x0FUL, /**< GPIO Pin 15 */
    INV_PIN,
} MGPIO_enuPinDesignator_t;

/**
 * @enum MGPIO_enuPinMode_t
 * @brief Enumeration for GPIO pin modes.
 */
typedef enum
{
    INPUT  = 0b00UL, /**< Input mode */
    GPOUT  = 0b01UL, /**< General-purpose output mode */
    ALTFNC = 0b10UL, /**< Alternate function mode */
    ANALOG = 0b11UL, /**< Analog mode */
} MGPIO_enuPinMode_t;

/**
 * @enum MGPIO_enuPinAltFunc_t
 * @brief Enumeration for GPIO alternate functions.
 */
typedef enum
{
    ALT_FUNC00 = 0x00UL, /**< Alternate Function 0 */
    ALT_FUNC01 = 0x01UL, /**< Alternate Function 1 */
    ALT_FUNC02 = 0x02UL, /**< Alternate Function 2 */
    ALT_FUNC03 = 0x03UL, /**< Alternate Function 3 */
    ALT_FUNC04 = 0x04UL, /**< Alternate Function 4 */
    ALT_FUNC05 = 0x05UL, /**< Alternate Function 5 */
    ALT_FUNC06 = 0x06UL, /**< Alternate Function 6 */
    ALT_FUNC07 = 0x07UL, /**< Alternate Function 7 */
    ALT_FUNC08 = 0x08UL, /**< Alternate Function 8 */
    ALT_FUNC09 = 0x09UL, /**< Alternate Function 9 */
    ALT_FUNC10 = 0x0AUL, /**< Alternate Function 10 */
    ALT_FUNC11 = 0x0BUL, /**< Alternate Function 11 */
    ALT_FUNC12 = 0x0CUL, /**< Alternate Function 12 */
    ALT_FUNC13 = 0x0DUL, /**< Alternate Function 13 */
    ALT_FUNC14 = 0x0EUL, /**< Alternate Function 14 */
    ALT_FUNC15 = 0x0FUL, /**< Alternate Function 15 */
    ALT_FUNC_NONE = 0xF0UL
} MGPIO_enuPinAltFunc_t;

/**
 * @enum MGPIO_enuPinOutType_t
 * @brief Enumeration for GPIO pin output types.
 */
typedef enum
{
    PUSH_PULL = 0, /**< Push-pull output */
    ODR       = 1, /**< Open-drain output */
} MGPIO_enuPinOutType_t;

/**
 * @enum MGPIO_enuPinOutSpeed_t
 * @brief Enumeration for GPIO pin output speeds.
 */
typedef enum
{
    LOW_SPEED   = 0b00UL, /**< Low speed */
    MED_SPEED   = 0b01UL, /**< Medium speed */
    HIGH_SPEED  = 0b10UL, /**< High speed */
    VHIGH_SPEED = 0b11UL, /**< Very high speed */
} MGPIO_enuPinOutSpeed_t;

/**
 * @enum MGPIO_enuPinResConfig_t
 * @brief Enumeration for GPIO pin resistor configurations.
 */
typedef enum
{
    NO_RES = 0b00UL, /**< No resistor */
    PU_RES = 0b01UL, /**< Pull-up resistor */
    PD_RES = 0b10UL, /**< Pull-down resistor */
} MGPIO_enuPinResConfig_t;

/**
 * @enum MGPIO_enuPinVal_t
 * @brief Enumeration for GPIO pin values.
 */
typedef enum
{
    PIN_HIGH = 0x00000001UL, /**< Pin High value */
    PIN_LOW  = 0x00010000UL, /**< Pin Low value */
} MGPIO_enuPinVal_t;


class GPIO 
{
    protected:
        MGPIO_enuPortDesignator_t port;
        MGPIO_enuPinDesignator_t pin;

    public:
        GPIO();
        GPIO(MGPIO_enuPortDesignator_t _port, MGPIO_enuPinDesignator_t _pin);
        SRV_enuErrorStatus_t MGPIO_enuSetPinMode(MGPIO_enuPinMode_t copy_enuPinMode);
        SRV_enuErrorStatus_t MGPIO_enuAltFuncSel(MGPIO_enuPinAltFunc_t copy_enuPinAltFunc);
        SRV_enuErrorStatus_t MGPIO_enuOutputType(MGPIO_enuPinOutType_t copy_enuPinOutType);
        SRV_enuErrorStatus_t MGPIO_enuOutputSpeed(MGPIO_enuPinOutSpeed_t copy_enuPinOutSpeed);
        SRV_enuErrorStatus_t MGPIO_enuPinResConfig(MGPIO_enuPinResConfig_t copy_enuPinResConfig);
        SRV_enuErrorStatus_t MGPIO_enuSetPinVal(MGPIO_enuPinVal_t copy_enuPinVal);
        SRV_enuErrorStatus_t MGPIO_enuGetPinVal(uint32_t* ptr_uint32PinVal);
        SRV_enuErrorStatus_t MGPIO_enuPinLockEnable();

};


#endif
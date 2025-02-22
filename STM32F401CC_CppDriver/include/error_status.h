#ifndef ERROR_STATUS_H
#define ERROR_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    ALL_OK = 0x00,
    NOK,
    NULL_PTR,
    INV_ARG,
    RCC_TIMEOUT,
    RCC_INV_CLK,
    RCC_INV_CFG,
    RCC_INV_CLK_SRC,
    RCC_PLL_CFG_WHILE_EN,
    RCC_PLL_INV_M,
    RCC_PLL_INV_N,
    RCC_PLL_INV_P,
    RCC_PLL_INV_Q,
    RCC_PLL_INV_R,
    RCC_INV_PLL_SRC,
    RCC_INV_AHB_CLK_PRE,
    RCC_INV_APB_LS_CLK_PRE,
    RCC_INV_APB_HS_CLK_PRE,
    RCC_INV_INT_RDY_STATE,
    RCC_INV_MCO_PRE,
    GPIO_INV_PORT,
    GPIO_INV_PIN,
    NVIC_INV_IRQ_NUM,
    NVIC_INV_IRQ_PRI,
    LCD_BUSY,
    LCD_BUF_OVF,
} SRV_enuErrorStatus_t;


#ifdef __cplusplus
}
#endif


#endif
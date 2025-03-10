/**
 * @file stm32f401xx.h
 * @brief STM32F401 microcontroller register definitions.
 *
 * This file contains the memory addresses and structures for the GPIO and RCC
 * registers to enable low-level hardware control on the STM32F401 MCU.
 *
 * @author Ahmed Mostafa
 * @date February 15, 2025
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

/**
 * @brief Base address of GPIOA peripheral.
 */
#define GPIOA_BASEADDR 0x40020000

/**
 * @brief Base address of GPIOB peripheral.
 */
#define GPIOB_BASEADDR 0x40020400

/**
 * @brief Base address of GPIOC peripheral.
 */
#define GPIOC_BASEADDR 0x40020800

/**
 * @brief Base address of RCC (Reset and Clock Control) peripheral.
 */
#define RCC_BASEADDR 0x40023800

#define ADC_BASEADDR 0x40012000

/**
 * @brief GPIO register definition structure.
 *
 * This structure represents the registers of a General-Purpose Input/Output (GPIO) port.
 */
typedef struct {
    volatile int MODER;    /**< GPIO port mode register (offset 0x00) */
    volatile int OTYPER;   /**< GPIO port output type register (offset 0x04) */
    volatile int OSPEEDR;  /**< GPIO port output speed register (offset 0x08) */
    volatile int PUPDR;    /**< GPIO port pull-up/pull-down register (offset 0x0C) */
    volatile int IDR;      /**< GPIO port input data register (offset 0x10) */
    volatile int ODR;      /**< GPIO port output data register (offset 0x14) */
    volatile int BSRR;     /**< GPIO port bit set/reset register (offset 0x18) */
    volatile int LCKR;     /**< GPIO port configuration lock register (offset 0x1C) */
    volatile int AFR[2];   /**< GPIO alternate function registers (offset 0x20-0x24) */
} GPIO_RegDef_t;

/**
 * @brief Macro to access GPIOA registers.
 */
#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)

/**
 * @brief Macro to access GPIOB registers.
 */
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)

/**
 * @brief Macro to access GPIOC registers.
 */
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)

/**
 * @brief RCC register definition structure.
 *
 * This structure represents the registers of the Reset and Clock Control (RCC) peripheral.
 */
typedef struct {
    volatile int CR;         /**< Clock control register (offset 0x00) */
    volatile int PLLCFGR;    /**< PLL configuration register (offset 0x04) */
    volatile int CFGR;       /**< Clock configuration register (offset 0x08) */
    volatile int CIR;        /**< Clock interrupt register (offset 0x0C) */
    volatile int AHB1RSTR;   /**< AHB1 peripheral reset register (offset 0x10) */
    volatile int AHB2RSTR;   /**< AHB2 peripheral reset register (offset 0x14) */
    volatile int RESERVED0[2]; /**< Reserved (offset 0x18-0x1C) */
    volatile int APB1RSTR;   /**< APB1 peripheral reset register (offset 0x20) */
    volatile int APB2RSTR;   /**< APB2 peripheral reset register (offset 0x24) */
    volatile int RESERVED1[2]; /**< Reserved (offset 0x28-0x2C) */
    volatile int AHB1ENR;    /**< AHB1 peripheral clock enable register (offset 0x30) */
    volatile int AHB2ENR;    /**< AHB2 peripheral clock enable register (offset 0x34) */
    volatile int RESERVED2[2]; /**< Reserved (offset 0x38-0x3C) */
    volatile int APB1ENR;    /**< APB1 peripheral clock enable register (offset 0x40) */
    volatile int APB2ENR;    /**< APB2 peripheral clock enable register (offset 0x44) */
} RCC_RegDef_t;

/**
 * @brief Macro to access RCC registers.
 */
#define RCC ((RCC_RegDef_t*) RCC_BASEADDR)

typedef struct{
	volatile int SR;
	volatile int CR1;
	volatile int CR2;
	volatile int SMPR1;
	volatile int SMPR2;
	volatile int JOFR1;
	volatile int JOFR2;
	volatile int JOFR3;
	volatile int JOFR4;
	volatile int HTR;
	volatile int LTR;
	volatile int SQR1;
	volatile int SQR2;
	volatile int SQR3;
	volatile int JSQR;
	volatile int JDR1;
	volatile int JDR2;
	volatile int JDR3;
	volatile int JDR4;
	volatile int DR;
	volatile int CCR;
}ADC_RegDef_t;

#define ADC1 ((ADC_RegDef_t*) ADC_BASEADDR)

#endif /* INC_STM32F401XX_H_ */

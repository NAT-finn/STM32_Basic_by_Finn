/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stm32f103xx_gpio.h>
#include <SEGGER_RTT.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(void)
{
	for(uint32_t i = 0; i < 200000; i++);
}

int main(void)
{
	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = 13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_MODE_10MHZ;
	GpioLed.GPIO_PinConfig.GPIO_PinMode_CNF = OUTPUT_OPEN_DRAIN_CNF;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioLed);

	SEGGER_RTT_printf(0, "Hello world \n");
    /* Loop forever */
	for(;;)
	{
		GPIO_ToggleOutputPin(GPIOC, 13);
		delay();
	}
	return 0;
}

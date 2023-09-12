/*
 * stm32f103xx_gpio.h
 *
 *  Created on: Aug 29, 2023
 *      Author: ADMIN
 */

#ifndef SRC_STM32F103XX_GPIO_H_
#define SRC_STM32F103XX_GPIO_H_

#include "stm32f103xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinMode_CNF;
}GPIO_PinConfig_t;


/*
 * This is a Handle structure for GPIO pin
 */
typedef struct
{
	GPIO_Reg_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/*
 * Define các chế độ của GPIO
 */
#define INPUT_MODE                      0       // Mấy cái này trong Datasheet
#define OUTPUT_MODE_10MHZ               1
#define OUTPUT_MODE_2MHZ                2
#define OUTPUT_MODE_50MHZ               3

#define ANALOG_MODE_CNF                 0
#define FLOATING_INPUT_CNF              1
#define INPUT_PULL_UP_DOWN_CNF          2

#define OUTPUT_PUSH_PULL_CNF            0
#define OUTPUT_OPEN_DRAIN_CNF           1
#define AFIO_PUSH_PULL_CNF              2
#define AFIO_OPEN_DRAIN_CNF             3






/***************************************************
 *  APIs supported by this driver
 *( Nói chung là chỗ khai báo hàm )
 ***************************************************/

// Init and DeInit
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Reg_t *pGPIOx);
// Clock setup
#if MY_CODE
// Hàm tự chế, chắc là đúng =))
#define GPIO_PeriClockControl(X, Y)           GPIO##X##_PERI_CLOCK_##Y##ABLE()
#else
void GPIO_PeriClockControl(GPIO_Reg_t *pGPIOx, uint8_t EnorDi);  /* EnorDi: Enable or Disable */
#endif
// Read and Write
uint16_t GPIO_ReadFromInputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_Reg_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_Reg_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber);
// IRQ Configuration and ISR handling
void GPIO_IRQHandling(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQCOnfig(uint8_t PinNumber);


#endif /* SRC_STM32F103XX_GPIO_H_ */

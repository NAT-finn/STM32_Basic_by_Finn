/*
 * stm32f103xx_gpio.c
 *
 *  Created on: Aug 29, 2023
 *      Author: ADMIN
 */
#include "stm32f103xx_gpio.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	uint8_t getmode = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinMode_CNF << 2 ) + ( pGPIOHandle->GPIO_PinConfig.GPIO_PinMode );
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber < 8)
	{
		temp = getmode << ( 4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber );
		pGPIOHandle->pGPIOx->CRL &= ~( 0xF << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber * 4));
		pGPIOHandle->pGPIOx->CRL |= temp;
	}else
	{
		temp = getmode << ( 4 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber-8) );
		pGPIOHandle->pGPIOx->CRH &= ~( 0xF << ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber-8) * 4));
		pGPIOHandle->pGPIOx->CRH |= temp;
	}
	temp = 0;
}

void GPIO_DeInit(GPIO_Reg_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
}

void GPIO_WriteToOutputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value != GPIO_OFF)
	{
		//Write 1 to the output data register at the bit field corresponding to the pin
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		//Write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_Reg_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

uint16_t GPIO_ReadFromInputPin(GPIO_Reg_t *pGPIOx, uint8_t PinNumber)
{
	uint16_t value;
	value = (uint16_t)((pGPIOx->IDR >> PinNumber) & 0x0000000000000001);
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_Reg_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

#if MY_CODE != 1            /* Dùng hàm GPIO_PeriClockControl theo hướng dẫn */
void GPIO_PeriClockControl(GPIO_Reg_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi != DISABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PERI_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PERI_CLOCK_ENABLE();
		}
	}else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PERI_CLOCK_DISABLE();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PERI_CLOCK_DISABLE();
		}
	}
}
#endif





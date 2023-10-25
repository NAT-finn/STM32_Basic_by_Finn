/*
 * stm32f103c8tx.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ADMIN
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include<stdint.h>

#define __vo volatile

/*
 * Định nghĩa bộ nhớ Flash và Ram
 */
#define FLASH_BASEADDR          0x08000000U
#define SRAM_BASEADDR           0x20000000U


/*
 * Định nghĩa Peripheral và các bus bên trong
 * "unsigned int" (hoặc viết tắt là "unsigned") thường được sử dụng khi
 *  chỉ muốn biểu thị các giá trị không âm để tối ưu hóa việc sử dụng bộ nhớ
 *  hoặc để mô phỏng các giá trị không thể âm như chỉ số của mảng.
 */
#define PERIPH_BASE             0x40000000U // U = unsigned int
#define APB1PERIPH_BASE         PERIPH_BASE // giống địa chỉ của PERIPH_BASE
#define APB2PERIPH_BASE         0x40010000U
#define AHBPERIPH_BASE          0x40018000U


/*
 * Định nghĩa các thanh ghi do APB2 quản lý
 */
#define GPIOA_BASEADDR          0x40010800U  //(APB2PERIPH_BASE + 0x800)
#define GPIOB_BASEADDR          0x40010C00U
#define GPIOC_BASEADDR          0x40011000U
#define GPIOD_BASEADDR          0x40011400U
#define GPIOE_BASEADDR          0x40011800U
#define GPIOF_BASEADDR          0x40011C00U
#define GPIOG_BASEADDR          0x40012000U
#define SPI1_BASEADDR           0x40013000U
#define USART1_BASEADDR         0x40013800U
#define EXTI_BASEADDR           0x40010400U


/*
 * Định nghĩa các thanh ghi do APB1 quản lý
 */
#define I2C1_BASEADDR           0x40005400U  //(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR           0x40005800U
#define USART2_BASEADDR         0x40004400U
#define USART3_BASEADDR         0x40004800U
#define UART4_BASEADDR          0x40004C00U
#define UART5_BASEADDR          0x40005000U
#define SPI2_BASEADDR           0x40003800U
#define SPI3_BASEADDR           0x40003C00U


/*
 * Định nghĩa các thanh ghi do AHB quản lý
 */
#define RCC_BASEADDR            0x40021000U


/*
 * Structuring peripheral register
 * Trong ngôn ngữ lập trình C, từ khóa "volatile" được sử dụng để chỉ ra rằng một biến có thể
 * thay đổi bất kỳ lúc nào bên ngoài quá trình thực thi chương trình. Điều này có nghĩa là trạng thái
 * của biến có thể thay đổi bất kỳ lúc nào mà không cần thông báo trước cho trình biên dịch hoặc
 * trình biên dịch tối ưu hóa.
 *
 * Thanh ghi nào không public vẫn phải phải khai báo
 */
typedef struct
{
	__vo uint32_t CRL;
	__vo uint32_t CRH;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t BRR;
	__vo uint32_t CLKR;
	// uint32_t VD;      /* Reserved */
}GPIO_Reg_t;

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_Reg_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
}RCC_Reg_t;


/*
 * Tạo các con trỏ kiểu GPIO_Reg_t trỏ đến các địa chỉ của thanh ghi GPIO Port
 */
#define GPIOA                 ((GPIO_Reg_t*)GPIOA_BASEADDR)
#define GPIOB                 ((GPIO_Reg_t*)GPIOB_BASEADDR)
#define GPIOC                 ((GPIO_Reg_t*)GPIOC_BASEADDR)
#define GPIOD                 ((GPIO_Reg_t*)GPIOD_BASEADDR)
#define GPIOE                 ((GPIO_Reg_t*)GPIOE_BASEADDR)
#define GPIOF                 ((GPIO_Reg_t*)GPIOF_BASEADDR)
#define GPIOG                 ((GPIO_Reg_t*)GPIOG_BASEADDR)

#define RCC                   ((RCC_Reg_t*)RCC_BASEADDR)

#define EXTI                  ((EXTI_Reg_t*)EXTI_BASEADDR)

/*
 * Clock Enable Marcos for GPIOx peripherals
 */
#define GPIOA_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 2))
#define GPIOB_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 3))
#define GPIOC_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 4))
#define GPIOD_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 5))
#define GPIOE_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 6))
#define GPIOF_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 7))
#define GPIOG_PERI_CLOCK_ENABLE()      (RCC->APB2ENR |= (1 << 8))

#define AFIO_PERI_CLOCK_ENABLE()       (RCC->APB2ENR |= (1 << 1))

/*
 * Clock Disable Marcos for GPIOx peripherals
 */
#define GPIOA_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 2))
#define GPIOB_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 3))
#define GPIOC_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 4))
#define GPIOD_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 5))
#define GPIOE_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 6))
#define GPIOF_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 7))
#define GPIOG_PERI_CLOCK_DISABLE()      (RCC->APB2ENR &= ~(1 << 8))

/*
 * Marcos to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 2)); (RCC->APB2RSTR &= ~(1 <<2)); } while(0)
#define GPIOB_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 3)); (RCC->APB2RSTR &= ~(1 <<3)); } while(0)
#define GPIOC_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 <<4)); } while(0)
#define GPIOD_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 <<5)); } while(0)
#define GPIOE_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 6)); (RCC->APB2RSTR &= ~(1 <<6)); } while(0)
#define GPIOF_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 7)); (RCC->APB2RSTR &= ~(1 <<7)); } while(0)
#define GPIOG_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 8)); (RCC->APB2RSTR &= ~(1 <<8)); } while(0)

/*
 * Some generic marcos
 */
#define MY_CODE             0
#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_OFF            DISABLE



#endif /* INC_STM32F103XX_H_ */

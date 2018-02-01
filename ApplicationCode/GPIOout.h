/*
 * GPIOout.h
 *
 *  Created on: 27.01.2018
 *      Author: dave
 */
#ifndef GPIOOUT_H_
#define GPIOOUT_H_

#include <cstdint>

extern "C"
{
	#include "stm32f1xx_hal.h"
	#include "stm32f1xx_hal_gpio.h"
}

 //Port numbers: 0=A, 1=B, 2=C, 3=D, 4=E
class GPIOout {
public:
	  __attribute__((always_inline)) GPIOout(const std::uint8_t portNr, const std::uint8_t pinNr) : portNumber(portNr),pinNumber(pinNr)
	  {
		  switch(portNr){
		  case 0: port = GPIOA;   __HAL_RCC_GPIOA_CLK_ENABLE();		break;
		  case 1: port = GPIOB;   __HAL_RCC_GPIOB_CLK_ENABLE();		break;
		  case 2: port = GPIOC;	  __HAL_RCC_GPIOC_CLK_ENABLE();	  	break;
		  case 3: port = GPIOD;   __HAL_RCC_GPIOD_CLK_ENABLE();		break;
		  case 4: port = GPIOE;   __HAL_RCC_GPIOE_CLK_ENABLE();		break;}

		  switch(pinNr){
		  case 0: pin = GPIO_PIN_0;  break;
		  case 1: pin = GPIO_PIN_1;  break;
		  case 2: pin = GPIO_PIN_2;  break;
		  case 3: pin = GPIO_PIN_3;  break;
		  case 4: pin = GPIO_PIN_4;  break;
		  case 5: pin = GPIO_PIN_5;  break;
		  case 6: pin = GPIO_PIN_6;  break;
		  case 7: pin = GPIO_PIN_7;  break;
		  case 8: pin = GPIO_PIN_8;  break;
		  case 9: pin = GPIO_PIN_9;  break;
		  case 10: pin = GPIO_PIN_10;  break;
		  case 11: pin = GPIO_PIN_11;  break;
		  case 12: pin = GPIO_PIN_12;  break;
		  case 13: pin = GPIO_PIN_13;  break;
		  case 14: pin = GPIO_PIN_14;  break;
		  case 15: pin = GPIO_PIN_15;  break;
		  }

		  GPIO_InitTypeDef initGPIO;
		  initGPIO.Mode = GPIO_MODE_OUTPUT_PP;
		  initGPIO.Pull = GPIO_NOPULL;			//PULL Up/Down resistor
		  initGPIO.Speed = GPIO_SPEED_FREQ_HIGH;
		  initGPIO.Pin = pin;

		  HAL_GPIO_Init(port, &initGPIO);

		  low();
	  }

	  inline void __attribute__((always_inline)) high()
	  {
		  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
	  }

	  inline void __attribute__((always_inline)) low()
	  {
		  HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	  }

	  inline void __attribute__((always_inline)) toggle()
	  {
		  HAL_GPIO_TogglePin(port, pin);
	  }

private:
	  const std::uint8_t portNumber;
	  const std::uint8_t pinNumber;

	  GPIO_TypeDef *port;
	  std::uint16_t pin;
};

#endif /* GPIOOUT_H_ */

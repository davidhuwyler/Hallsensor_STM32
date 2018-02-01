/*
 * AnalogIN.h
 *
 *  Created on: 01.02.2018
 *      Author: dave
 */

#ifndef ANALOGIN_B1_H_
#define ANALOGIN_B1_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	#include "stm32f1xx_hal.h"
#ifdef __cplusplus
}

#include <cstdint>
#include <string>

class AnalogIN_B1 {
public:
	static ADC_HandleTypeDef* adcHandler;
	static constexpr uint32_t AdcTimeout_MS = 1000;

	  AnalogIN_B1() = default;

	  static inline uint32_t __attribute__((always_inline)) getValue()
	  {
		  HAL_ADC_Start(AnalogIN_B1::adcHandler);
		  HAL_ADC_PollForConversion(AnalogIN_B1::adcHandler, AdcTimeout_MS);
		  return HAL_ADC_GetValue(AnalogIN_B1::adcHandler);
	  }

	  static std::string executeShellCMD(std::string cmd);

};


extern "C" {
#endif // __cplusplus

void setADChandler(ADC_HandleTypeDef* handler);

#ifdef __cplusplus
}
#endif


#endif /* ANALOGIN_B1_H_ */

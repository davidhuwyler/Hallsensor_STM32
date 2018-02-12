/*
 * PWMcontroller.h
 *
 *  Created on: 02.02.2018
 *      Author: dave
 */

#ifndef PWMCONTROLLER_H_
#define PWMCONTROLLER_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	#include "stm32f1xx_hal.h"
#ifdef __cplusplus
}

#include <cstdint>
#include <string>

class PWMcontroller
{
public:
	static TIM_HandleTypeDef* timerHandler;

	PWMcontroller() = default;

	static void setPWM_A0(uint8_t dutycycle);
	static void setPWM_A1(uint8_t dutycycle);

	static std::string executeShellCMD(std::string cmd);
private:
	static void initChannel(uint8_t dutycycle, uint32_t Channel);
};

extern "C" {
#endif // __cplusplus

void setTmrHandler(TIM_HandleTypeDef* handler);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif /* PWMCONTROLLER_H_ */

/*
 * PWMcontroller.cpp
 *
 *  Created on: 02.02.2018
 *      Author: dave
 */

#include <PWMcontroller.h>

TIM_HandleTypeDef* PWMcontroller::timerHandler;

void setTmrHandler(TIM_HandleTypeDef* handler)
{
	PWMcontroller::timerHandler = handler;
}


void PWMcontroller::setPWM_A0(uint8_t dutycycle)
{
	PWMcontroller::initChannel(dutycycle,TIM_CHANNEL_1);
}

void PWMcontroller::setPWM_A1(uint8_t dutycycle)
{
	PWMcontroller::initChannel(dutycycle,TIM_CHANNEL_2);
}


/*
 * pulselength 0..4096 = dutycycle 0..100%
 * Channnel TIM_CHANNEL_1 = A0, TIM_CHANNEL_2 = A1
 */
void PWMcontroller::initChannel(uint8_t dutycycle, uint32_t Channel)
{
	  TIM_ClockConfigTypeDef sClockSourceConfig;
	  TIM_MasterConfigTypeDef sMasterConfig;
	  TIM_OC_InitTypeDef sConfigOC;

	  PWMcontroller::timerHandler->Instance = TIM2;
	  PWMcontroller::timerHandler->Init.Prescaler = 0xFF;  //Frequency ~1khz
	  PWMcontroller::timerHandler->Init.CounterMode = TIM_COUNTERMODE_UP;
	  PWMcontroller::timerHandler->Init.Period = 256;
	  PWMcontroller::timerHandler->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  PWMcontroller::timerHandler->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	  HAL_TIM_Base_Init(PWMcontroller::timerHandler);

	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  HAL_TIM_ConfigClockSource(PWMcontroller::timerHandler, &sClockSourceConfig);
	  HAL_TIM_PWM_Init(PWMcontroller::timerHandler);

	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  HAL_TIMEx_MasterConfigSynchronization(PWMcontroller::timerHandler, &sMasterConfig);

	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = dutycycle;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  HAL_TIM_PWM_ConfigChannel(PWMcontroller::timerHandler, &sConfigOC, Channel);
	  HAL_TIM_PWM_Start(PWMcontroller::timerHandler, Channel);
}


std::string PWMcontroller::executeShellCMD(std::string cmd)
{
	std::string A0dutyCMD = "A0duty";
	std::string A1dutyCMD = "A1duty";

	if(cmd.substr(0,A0dutyCMD.size()).compare(A0dutyCMD) == 0)
	{
		std::string dutyString = cmd.substr(A0dutyCMD.size()+1);
		uint8_t duty = std::stoi(dutyString,nullptr);
		PWMcontroller::setPWM_A0(duty);
		std::string returnString = " --> A0 dutycycle set to ";
		returnString.operator +=(std::to_string(duty));
		return returnString;
	}
	else if(cmd.substr(0,A1dutyCMD.size()).compare(A1dutyCMD) == 0)
	{
		std::string dutyString = cmd.substr(A1dutyCMD.size()+1);
		uint8_t duty = std::stoi(dutyString,nullptr);
		PWMcontroller::setPWM_A1(duty);
		std::string returnString = " --> A1 dutycycle set to ";
		returnString.operator +=(std::to_string(duty));
		return returnString;
	}
	else
	{
		return " No valid parameter. Try <A0duty %value%> or <A1duty %value%> . value = 0..256\nex: A0duty 127";
	}

}

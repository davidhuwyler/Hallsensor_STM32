/*
 * AnalogIN.cpp
 *
 *  Created on: 01.02.2018
 *      Author: dave
 */

#include <AnalogIN_B1.h>

ADC_HandleTypeDef* AnalogIN_B1::adcHandler;

void setADChandler(ADC_HandleTypeDef* handler)
{
		AnalogIN_B1::adcHandler = handler;
}

std::string AnalogIN_B1::executeShellCMD(std::string cmd)
{
	std::string getValueCMD = "getValue";


	if(cmd.compare(getValueCMD) == 0)
	{
		std::string returnString = " --> Value of ADC-Pin B1 = ";
		returnString.operator +=(std::to_string(AnalogIN_B1::getValue()));
		return returnString;
	}
	else
	{
		return " No valid parameter. Try <getValue>";
	}

}

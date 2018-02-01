/*
 * LED.cpp
 *
 *  Created on: 27.01.2018
 *      Author: dave
 */

#include <LED.h>
GPIOout LED::pinC13 = GPIOout(2,13);

std::string LED::executeShellCMD(std::string cmd)
{
	std::string onCMD = "on";
	std::string offCMD = "off";
	std::string toggleCMD = "toggle";

	if(cmd.compare(onCMD) == 0)
	{
		LED::turnOn();
		return " --> Led Turned on";
	}
	else if(cmd.compare(offCMD) == 0)
	{
		LED::turnOff();
		return " --> Led Turned off";
	}
	else if(cmd.compare(toggleCMD) == 0)
	{
		LED::toggle();
		return " --> Led toggled";
	}
	else
	{
		return " No valid parameter. Try <on> , <off> or <toggle>";
	}

}



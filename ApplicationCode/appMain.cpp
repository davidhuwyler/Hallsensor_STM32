/*
 * appMain.cpp
 *
 *  Created on: 26.01.2018
 *      Author: dave
 */

#include "appMain.h"
#include "USBserial.h"
#include "LED.h"
#include "PWMcontroller.h"
#include "MagnetController.h"


void	appMain()
{
	MagnetController::CalcOutput();
}

void sendRun()
{
	//USBserial::sendLine("Run...\n");
}

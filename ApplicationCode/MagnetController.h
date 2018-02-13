/*
 * MagnetController.h
 *
 *  Created on: 12.02.2018
 *      Author: dave
 */

#ifndef MAGNETCONTROLLER_H_
#define MAGNETCONTROLLER_H_

#include <cstdint>
#include <string>
#include "MiniPID.h"
#include "AnalogIN_B1.h"
#include "PWMcontroller.h"

class MagnetController {
public:
	MagnetController() = default;

	static void CalcOutput();
	static std::string executeShellCMD(std::string cmd);

private:
	static uint32_t setPoint;
	static double p;
	static double i;
	static double d;
	static MiniPID pid;
};

#endif /* MAGNETCONTROLLER_H_ */

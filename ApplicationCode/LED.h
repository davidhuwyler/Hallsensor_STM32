/*
 * LED.h
 *
 *  Created on: 27.01.2018
 *      Author: dave
 */

#ifndef LED_H_
#define LED_H_

#include <string>
#include "GPIOout.h"

class LED {
public:
	static GPIOout pinC13;

	inline static void __attribute__((always_inline)) turnOn() { LED::pinC13.low(); }
	inline static void __attribute__((always_inline)) turnOff(void) { LED::pinC13.high(); }
	inline static void __attribute__((always_inline)) toggle(void) { LED::pinC13.toggle(); }

	static std::string executeShellCMD(std::string cmd);

};

#endif /* LED_H_ */

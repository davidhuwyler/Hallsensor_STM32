/*
 * USBserial.h
 *
 *  Created on: 26.01.2018
 *      Author: dave
 */

#ifndef USBSERIAL_H_
#define USBSERIAL_H_

#ifdef __cplusplus

#include <vector>
#include <cstdint>
#include <string>

class USBserial {
public:
	USBserial();

	static void sendLine(std::string line);

private:
	constexpr static std::uint16_t BUFFER_SIZE = 200;
	//static std::vector<std::uint8_t> data = std::vector(BUFFER_SIZE);

	virtual ~USBserial();
};

extern "C" {
#endif //__cplusplus
	void USBserial_receivedData(uint8_t* Buf, uint32_t Len);

#ifdef __cplusplus
}
#endif//__cplusplus



#endif /* USBSERIAL_H_ */

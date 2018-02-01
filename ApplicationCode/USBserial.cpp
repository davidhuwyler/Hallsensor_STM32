/*
 * USBserial.cpp
 *
 *  Created on: 26.01.2018
 *      Author: dave
 */

#include <USBserial.h>
#include "CMDshell.h"

extern "C"
{
	#include "usbd_cdc_if.h"
}


USBserial::USBserial() {
	// TODO Auto-generated constructor stub
}



void USBserial::sendLine(std::string line)
{
	char buf[USBserial::BUFFER_SIZE] = "";
	strcpy(buf, line.c_str());

	CDC_Transmit_FS((unsigned char*)buf, line.size());

}



USBserial::~USBserial() {
	// TODO Auto-generated destructor stub
}



//Function gets called from USB_CDC
void USBserial_receivedData(uint8_t* Buf, uint32_t Len)
{
	std::string str((char*)Buf,Len);
	CMDshell::parseCommand(str);
	//USBserial::sendLine(str);
}

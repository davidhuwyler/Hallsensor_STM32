/*
 * CMDshell.cpp
 *
 *  Created on: 26.01.2018
 *      Author: dave
 */
#include <cstdint>
#include "CMDshell.h"
#include "USBserial.h"
#include "LED.h"

constexpr std::uint8_t CMDshell::CMD_LIST[CMDshell::NUMBER_OF_COMMANDS][CMDshell::MAX_NUMBER_OF_CHARS_PER_COMMAND];


CMDshell::CMDshell() {
	// TODO Auto-generated constructor stub

}

void CMDshell::parseCommand(std::string command)
{
	command = command.substr(0,command.size()-1);
	std::uint8_t cmdIndex = 0xFF;
	std::uint8_t answerBuf[CMDshell::LINE_BUFFER_SIZE];
	std::string answerString = std::string((char*)answerBuf,CMDshell::LINE_BUFFER_SIZE);

	for(std::uint16_t i = 0 ; i<CMDshell::NUMBER_OF_COMMANDS ; i++)
	{
		std::string commandInList = std::string((char*)CMDshell::CMD_LIST[i]);
		//if(command.compare()==0)
		if(commandInList.compare(command.substr(0,commandInList.size()))==0)
		{
			cmdIndex = i;
		}
	}

	if(cmdIndex != 0xFF)
	{
		std::string commandInList = std::string((char*)CMDshell::CMD_LIST[cmdIndex]);
		switch(cmdIndex)
		{
		case 0: //help
			executeCMD_help();
			break;

		case 1: //led
			answerString = "--------------------------------";
			answerString.operator +=("\n LED gets executed. Param: ");
			answerString.operator +=(command.substr(commandInList.size()));
			answerString.operator +=("\n");
			if(command.size()==commandInList.size())
				answerString.operator+=(LED::executeShellCMD(" "));
			else
				answerString.operator+=(LED::executeShellCMD(command.substr(commandInList.size()+1)));
			answerString.operator +=("\n");
			break;

		default:
			answerString ="\nCommand not implemented...";
		}
	}
	else
	{
		answerString = "\n";
		answerString.operator +=(command);
		answerString.operator +=(" is not a valid command... Try <help>\n");
	}

	USBserial::sendLine(answerString);

}

void CMDshell::executeCMD_help()
{
	std::uint8_t answerBuf[CMDshell::LINE_BUFFER_SIZE];
	std::string answerString = std::string((char*)answerBuf,CMDshell::LINE_BUFFER_SIZE);
	answerString = "--------------------------------";
	answerString.operator +=("\n List of commands:");
	for(std::uint16_t i = 0 ; i<CMDshell::NUMBER_OF_COMMANDS ; i++)
	{
		answerString.operator +=("\n  ");
		answerString.operator +=((char*)CMDshell::CMD_LIST[i]);
		//TODO Print out subCommands (Like LED on / LED off)
	}
	answerString.operator +=("\n--------------------------------");
	USBserial::sendLine(answerString);
}

CMDshell::~CMDshell() {
	// TODO Auto-generated destructor stub
}


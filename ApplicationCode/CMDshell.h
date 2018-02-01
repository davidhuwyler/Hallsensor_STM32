/*
 * CMDshell.h
 *
 *  Created on: 26.01.2018
 *      Author: dave
 */

#ifndef CMDSHELL_H_
#define CMDSHELL_H_

#include <string>
#include <vector>

class CMDshell {
public:
	CMDshell();

	static void parseCommand(std::string command);
	virtual ~CMDshell();

private:
	constexpr static std::uint16_t LINE_BUFFER_SIZE = 200;

	constexpr static std::uint8_t NUMBER_OF_COMMANDS = 2;
	constexpr static std::uint8_t MAX_NUMBER_OF_CHARS_PER_COMMAND = 15;
	constexpr static std::uint8_t CMD_LIST[NUMBER_OF_COMMANDS][MAX_NUMBER_OF_CHARS_PER_COMMAND] = {
			"help",
			"led"
	};
	static void executeCMD_help();
};

#endif /* CMDSHELL_H_ */

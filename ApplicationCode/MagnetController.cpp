/*
 * MagnetController.cpp
 *
 *  Created on: 12.02.2018
 *      Author: dave
 */

#include <MagnetController.h>

//init
uint32_t MagnetController::setPoint = 3050;
double MagnetController::p = 0.1;
double MagnetController::i = 0.01;
double MagnetController::d = 0.0;
MiniPID MagnetController::pid = MiniPID(MagnetController::p,MagnetController::i,MagnetController::d);

void MagnetController::CalcOutput()
{
	pid.setOutputLimits(0,255);
	pid.setOutputRampRate(10);
	PWMcontroller::setPWM_A0((uint8_t)pid.getOutput((double)AnalogIN_B1::getValue(),(double)MagnetController::setPoint));
}

std::string MagnetController::executeShellCMD(std::string cmd)
{
	std::string getParamsCMD = std::string("getParams");
	std::string setSetPointCMD = std::string("setPoint");
	std::string setPCMD = std::string("setP");
	std::string setICMD = std::string("setI");
	std::string setDCMD = std::string("setD");

	if(cmd.substr(0,getParamsCMD.size()).compare(getParamsCMD) == 0)
	{
		std::string returnString = " --> PID Params: \n ";
		returnString.operator +=("    Setpoint: " + std::to_string(MagnetController::setPoint));
		returnString.operator +=("\n     P: " + std::to_string(MagnetController::p));
		returnString.operator +=("\n     I: " + std::to_string(MagnetController::i));
		returnString.operator +=("\n     D: " + std::to_string(MagnetController::d));
		return returnString;
	}
	else if(cmd.substr(0,setSetPointCMD.size()).compare(setSetPointCMD) == 0)
	{
		if(cmd.size()==setSetPointCMD.size()) // no setPoint given...
		{
			return " --> Please provide an integer Setpoint ";
		}
		else
		{
			std::string setPointString = cmd.substr(setSetPointCMD.size()+1);
			uint32_t setPoint = std::stoi(setPointString,nullptr);
			MagnetController::pid.setSetpoint(setPoint);
			MagnetController::setPoint = setPoint;
			return " --> PID Setpoint changed to " + std::to_string(setPoint);
		}
	}
	else if(cmd.substr(0,setPCMD.size()).compare(setPCMD) == 0)
	{
		if(cmd.size()==setPCMD.size()) // no P value given...
		{
			return " --> Please provide an double P Value (ex 0.11) ";
		}
		else
		{
		std::string pString = cmd.substr(setPCMD.size()+1);
		double p = std::stod(pString,nullptr);
		MagnetController::pid.setP((double)p);
		MagnetController::p = p;
		return " --> PID, P-Value changed to " +std::to_string(p);
		}
	}
	else if(cmd.substr(0,setICMD.size()).compare(setICMD) == 0)
	{
		if(cmd.size()==setICMD.size()) // no I value given...
		{
			return " --> Please provide an double I Value (ex 0.011) ";
		}
		else
		{
		std::string iString = cmd.substr(setICMD.size()+1);
		double i = std::stod(iString,nullptr);
		MagnetController::pid.setI((double)i);
		MagnetController::i = i;
		return " --> PID, I-Value changed to " + std::to_string(i);
		}
	}
	else if(cmd.substr(0,setDCMD.size()).compare(setDCMD) == 0)
	{
		if(cmd.size()==setDCMD.size()) // no D value given...
		{
			return " --> Please provide an double D Value (ex 0.0) ";
		}
		else
		{
		std::string dString = cmd.substr(setDCMD.size()+1);
		double d = std::stod(dString,nullptr);
		MagnetController::pid.setD((double)d);
		MagnetController::d = d;
		return " --> PID, D-Value changed to " + std::to_string(d);
		}
	}
	else
	{
		std::string returnString = " No valid parameter. Try <getParams> \n";
		returnString.operator +=("<setpoint %value%> . value = 2800..3100\n");
		returnString.operator +=("<setP %p%> . p = 0.0 .. 100.0\n");
		returnString.operator +=("<setI %i%>\n");
		returnString.operator +=("<setD %d%>");
		return returnString;
	}

}


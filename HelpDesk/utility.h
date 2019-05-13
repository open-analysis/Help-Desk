#pragma once

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <Windows.h>


struct Util 
{
private:
	std::fstream f;
	std::string destName_m = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\";
	//bool incstatus(std::string name);
public:
	std::string mkfile(std::string name);
	bool rdfile(std::string name, int);
	bool updatefile(std::string name, int);
	bool updatestatus(std::string, int);
	std::string rmSpaces(std::string text);
	std::string addSpaces(std::string text);
};

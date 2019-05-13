#include "utility.h"

std::string Util::mkfile(std::string name)
{
	std::string text = "";
	std::string file = "NEW.txt";
	std::string destDir = destName_m + name;
	std::string destName = destDir + "\\" + file;
	f.open(file, std::ios::out);
	if (f.is_open())
	{
		printf("Enter text:\n>");
		do {
			if (text != "") // why tf does it go thro the loop twice before stopping for input?
				break;
		} while (std::getline(std::cin, text));
		f << text;
		f.close();
		printf("\n");
		if (CreateDirectory(destDir.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
			if (rename(file.c_str(), destName.c_str()) != -1)
				return destName;
			else
				printf("Couldn't move files\n");
		else
		{
			printf("Failed to create directory\n");
			std::cout << GetLastError() << "\n";
			return "fuck";
		}
		return "";
	}
	else
	{
		printf("Unable to open file\n");
		return "failed";
	
	}
}

bool Util::rdfile(std::string name, int stat)
{
	std::string status;
	switch (stat)
	{
	case 1: status = "INPROG";
		break;
	case 2: status = "RETURN";
		break;
	case 3: status = "CLOSED";
		break;
	default: status = "NEW";
		break;
	}

	std::string text = "";
	std::string content = "";
	std::string file = status + ".txt";
	std::string destDir = destName_m + name;
	std::string destName = destDir + "\\" + file;
	f.open(destName, std::ios::in | std::ios::beg);
	if (f.is_open())
	{
		std::cout << f.rdbuf() << "\n";
		f.clear();
		f.close();
		/*
		while (std::getline(f, content))
		{
			text += content;
		}
		//f >> content;
		f.close();
		std::cout << text << "\n";*/
		return 1;
	} 
	else
	{
		//printf("Unable to read file");
		return 0;
	}
}

bool Util::updatefile(std::string name, int stat)
{
	std::string status;
	switch (stat)
	{
		case 1: status = "INPROG";
			break;
		case 2: status = "RETURN";
			break;
		case 3: status = "CLOSED";
			break;
		default: status = "NEW";
			break;
	}
	std::string content = "";
	std::string destName = destName_m + name + "\\" + status + ".txt";
	f.open(destName, std::ios::out | std::ios::ate | std::ios::app);
	if (f.is_open())
	{
		printf("What do you want to add?\n>");
		do {
			if (content != "") 
				break;
		} while (std::getline(std::cin, content));
		printf("\n");
		f << "\n\tUPDATE:";		// add time stamp feature
		f << "\n---------------------------\n";
		f << content;
		f.close();
		return 1;
	}
	else
	{
		//printf("Unable to update file");
		return 0;
	}
}

bool Util::updatestatus(std::string name, int stat)
{
	//std::string destName = destName_m + name + ".txt";
	std::string status;
	switch (stat)
	{
	case 1: status = "INPROG";
		break;
	case 2: status = "RETURN";
		break;
	case 3: status = "CLOSED";
		break;
	default: status = "NEW";
		break;
	}
	std::string content = "";
	std::string destName = destName_m + name + "\\" + status + ".txt";
	f.open(destName, std::ios::out);
	if (f.is_open())
	{
		/*
		std::string s;
		int c = 0;
		do
		{
			f >> s;
			if (s[c] == 0x0a)
				break;
			else if (c > 7)
				break;
			c++;
		} while (true);
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = 0x00;
		}
		f.seekp(0, std::ios::beg);
		f << s;
		f.seekp(0, std::ios::beg);
		f << stat;
		//f << "\n";
		*/
		printf("File details: ");
		do {
			if (content != "")
				break;
		} while (std::getline(std::cin, content));
		f << content;
		f.close();
		return 1;
	}
	else
	{
		printf("Failed to update status [UTILS]\n");
		return 0;
	}
}

std::string Util::rmSpaces(std::string text)
{
	int len = text.length();
	for (int i = 0; i < len - 1; i++)
	{
		if (text[i] == 0x20) //space
		{
			text[i] = 0x7E; // tilde ~
		}
	}
	return text;
}

std::string Util::addSpaces(std::string text)
{
	int len = text.length();
	for (int i = 0; i < len - 1; i++)
	{
		if (text[i] == 0x7E) // tilde ~
		{
			text[i] = 0x20; //space
		}
	}
	return text;
}
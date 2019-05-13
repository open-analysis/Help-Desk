#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"
#include "llist.h"

// TODO:
// add ticket number
// Create a log system

int main(int argc, char *argv)
{
	LList list;
	Util utils;
	list.importFiles();
	std::string menu = 
		"\n"
		"0: Exit\n"
		"1: Add\n"
		"2: Read\n"
		"3: Update\n"
		"4: Remove\n"
		"5: Print\n";

	//bool running = true;
	std::string name = "";
	printf("What do you want to do?");
	std::cout << menu;
	std::string in = "";
	while (true)
	{
		printf(">");
		std::cin >> in;
		printf("\n");
		if (in == "1") // add person
		{
			printf("What is the name?\n>");
			std::cin >> name;
			printf("\n");
			std::string file;
			if ((file = utils.mkfile(name)) != "")
				list.add(name, file);
			else
				printf("Failure to add to list\n");
		}
		else if (in == "2") // read file
		{
			printf("Which file?\n>");
			std::cin >> name;
			printf("\n");
			Node* node = list.search(name);
			if (utils.rdfile(name, node->status) == 1);
			else
				printf("Failed to read\n");
		}
		else if (in == "3") // update file
		{
			printf("Which file?\n>");
			std::cin >> name;
			printf("\n");
			printf("What would you like to update?\n");
			printf("1: Text\n");
			printf("2: Status\n");
			printf(">");
			std::cin >> in;
			Node* node = list.search(name);
			if (in == "1")
			{
				if (utils.updatefile(name, node->status) == 1)
					printf("\n\nUpdated\n");
				else
					printf("Failed to update file\n");
			}
			else if (in == "2")
			{
				printf("1. Increment the status\n");
				printf("2. Alter the status\n");
				printf(">");
				std::cin >> in;
				if (in == "1")
				{
					if (utils.updatestatus(name, node->status++) == 1)
					{
						list.update(name, node->status++);
						printf("\n\nUpdated\n");
					}
					else
						printf("Failed to update file\n");
				}
				else if (in == "2")
				{
					printf("Change the status to what?\n 1. NEW\n 2.INPROG\n 3.RETURN\n 4.CLOSED\n");
					printf(">");
					std::cin >> in;
					if (in == "1")
					{
						if (utils.updatestatus(name, 1) == 1)
						{
							list.update(name, 1);
							printf("\n\nUpdated\n");
						}
						else
							printf("Failed to update file\n");
					}
					else if (in == "2")
					{
						if (utils.updatestatus(name, 2) == 1)
						{
							list.update(name, 2);
							printf("\n\nUpdated\n");
						}
						else
							printf("Failed to update file\n");
					}
					else if (in == "3")
					{
						if (utils.updatestatus(name, 3) == 1)
						{
							list.update(name, 3);
							printf("\n\nUpdated\n");
						}
						else
							printf("Failed to update file\n");
					}
					else if (in == "4")
					{
						if (utils.updatestatus(name, 4) == 1)
						{
							list.update(name, 4);
							printf("\n\nUpdated\n");
						}
						else
							printf("Failed to update file\n");
					}
					else 
					{
						printf("Unsure on status update\n");
					}
				}
				else 
				{
					printf("Unsure on way to update file\n");
				}
			}
			else
			{
				printf("\nUnsure on input\n");
			}
		}
		else if (in == "4") // remove file
		{
			printf("What do you wish to remove?\n>");
			std::cin >> name;
			printf("\n");
			list.removeNode(name);
		}
		else if (in == "5") // print file
		{
			printf("Printing...\n");
			list.printNodes();
		}
		else if (in == "0") // exit
		{
			//running = false;
			printf("Exiting...\n");
			break;
		}
		else // prints the cmds again
		{
			std::cout << menu;
			printf(">");
		}
	}
	printf("Good-bye\n");
	return 0;
}
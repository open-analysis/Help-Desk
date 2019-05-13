#pragma once
#include <iostream>;
#include <fstream>;
#include <string>;
#include "utility.h"


struct Node {
	std::string id;
	unsigned int num;
	//std::string stDate;
	int status = 0; // 0 = NEW; 1 = IN PROGRESS; 2 = REPAIRED, NOT RETURNED; 3 = RETURNED
	std::string file;
	std::string dir = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\" + file + "\\";
	Node* next;
};

class LList {
private:
	Util utils;
	Node* head;
	int numClients = 0;

public:
	LList();

	void printNodes();

	void importFiles();
	void exportFiles();

	void update(std::string, int);

	void add(std::string id, std::string file);
	void removeNode(std::string id);
	
	Node* search(std::string);

private:
	void sort();
	Node* minimumString(Node* start);
	void swap(Node* orig, Node* replace);
	void addImports(std::string id, int, std::string file);
};

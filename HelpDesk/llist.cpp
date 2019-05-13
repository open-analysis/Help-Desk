#include "llist.h"

void LList::printNodes() {
	Node* node = head;
	do {
		std::cout << node->id << " ";
		std::cout << node->status << " ";
		std::cout << node->num << " ";
		std::cout << utils.addSpaces(node->file) << " ";
		printf("\n");
		//std::cout << node->num << std::endl;
		node = node->next;
	} while (node != NULL);
	printf("\n");
}

LList::LList() {
	head = NULL;
	numClients = 0;
}

void LList::importFiles() {
	std::string listN = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\list.txt";
	std::ifstream f(listN);
	std::string tempid;
	int tempStatus;
	//unsigned long tempNum;
	std::string tempFile;
	int numPeople = 0;
	if (f.is_open()) {
		f >> numPeople;
		numClients = numPeople;
		for (int i = 0; i < numPeople; i++) {
			f >> tempid;
			f >> tempStatus;
			//f >> tempNum;
			f >> tempFile;
			addImports(tempid, tempStatus, tempFile);
		}
		f.close();
	}
	else {
		std::cout << "Couldn't find import file" << std::endl;
	}

}

void LList::exportFiles() {
	std::string listN = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\list.txt";
	std::ofstream f(listN, std::ios::trunc);
	Node* node = head;
	f << numClients << std::endl;
	while (node != NULL) {
		f << node->id << " " << node->status << " " << node->num << " " << node->file << std::endl;
		node = node->next;
	}
}

void LList::add(std::string id, std::string file) {
	if (head == NULL) {
		head = new Node;
		head->id = id;
		//head->status = status;
		head->num = numClients;
		head->file = utils.rmSpaces(file);
		head->next = NULL;
		numClients++;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new Node;
		temp->next->id = id;
		temp->next->file = utils.rmSpaces(file);
		temp->next->num = numClients;
		temp->next->next = NULL;
		numClients++;
		sort();
	}
	exportFiles();
}

void LList::addImports(std::string id, int status, std::string file)
{
	if (head == NULL) {
		head = new Node;
		head->id = id;
		head->status = status;
		//head->num = 0;
		head->file = utils.rmSpaces(file);
		head->next = NULL;
		//numClients++;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new Node;
		temp->next->id = id;
		temp->next->status = status;
		temp->next->file = utils.rmSpaces(file);
		//temp->next->num = temp->num++;
		temp->next->next = NULL;
		//numClients++;
		sort();
	}
}

void LList::removeNode(std::string id) {
	// don't remove the first added node
	std::string file = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\" +/* id + "\\" +*/ id + ".txt";
	Node* temp = head;
	Node* temp2 = NULL;

	while (temp->id != id) {
		temp2 = temp;
		temp = temp->next;
	}

	temp2->next = temp2->next->next;
	delete temp;
	numClients--;
	exportFiles();
	// DELETE THE FILE
	// PROBABLY WON'T WORK
	if (remove(temp->dir.c_str()) != 0) // should probably perror() this but whatever :/
		printf("Failed to delete the file proper.\n");
	else
		printf("File Delted\n");
}

void LList::update(std::string id, int stat)
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
	std::string file = "C:\\Users\\Josh Chica\\Documents\\HelpDesk\\" +/* id + "\\" +*/ id + "\\" + status + ".txt";
	
	Node* temp = head;
	while (temp->id != id)
		temp = temp->next;
	temp->status = stat;
	
	exportFiles();
}

void LList::sort() {
	Node* counter = head;
	Node* change = NULL;
	while (counter != NULL) {
		change = minimumString(counter);
		swap(counter, change);
		counter = counter->next;
	}
}

Node* LList::minimumString(Node* start) {
	Node* tmp = start->next;
	while (tmp != NULL) {
		if (start->id[0] > tmp->id[0]) {
			start = tmp;
		}
		else if (start->id[0] == tmp->id[0]) {
			if (start->id[1] == tmp->id[1]) {
				start = tmp;
			}
			else {
				int i = 2;
				while (start->id[i] == tmp->id[i]) {
					i++;
				}

				if (start->id[i] > tmp->id[i]) {
					start = tmp;
				}
			}
		}
		tmp = tmp->next;
	}
	return start;
}

void LList::swap(Node* orig, Node* replace) {
	std::string tmpid = orig->id;
	int tmpStatus = orig->status;
	std::string tmpFile = orig->file;
//	unsigned long tmpNum = orig->num;

	orig->id = replace->id;
	orig->status = replace->status;
	orig->file = replace->file;
//	orig->num = replace->num;

	replace->id = tmpid;
	replace->status = tmpStatus;
	replace->file = tmpFile;
	//replace->num = tmpNum;
}

Node* LList::search(std::string name)
{
	 Node* node = head;
	 while (node->id != name)
		 node = node->next;
	 return node;
}
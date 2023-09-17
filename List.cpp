#pragma once
#include "List.h"
#include <iostream>
#include <iomanip>

using namespace std;

List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Node* temp;

	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = nullptr;
}

void List::Display() {												//************ FIX FORMATTING OF DISPLAY() OUTPUT*******************

	if (head == nullptr) {														// - done.
		cout << "Empty list\n";
	}
	else {
		Node* temp = head;
		cout << "Game Name\t\t Year\t Price\n";
		cout << "-----------------------------------------\n";
		while (temp != nullptr) {
			cout << left << setw(25) << temp->gameName << setw(8) << temp->yearReleased << temp->gamePrice << " $" << endl;
			temp = temp->next;
		}
		cout.copyfmt(ios(nullptr));
	}
}																	//******************************************************************

int List::Length() { 
	if (head == nullptr) {
		return 0;
	}
	else {
		Node* temp = head;
		unsigned int i = 0;

		while (temp != nullptr) {
			i++;
			temp = temp->next;
		}
		return i;
	}
}

void List::Delete() {
	Node* temp;

	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = nullptr;
}

void List::PushFront(std::string name, unsigned short int year, float price) {
	Node* newNode = new Node(name, year, price);									//not sure if this will use defaults for last two 
																					//arguments in the call -- CHECK
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}

Node List::PopFront() { 
	Node emptyNode;

	if (head == nullptr) {
		cout << "The list is empty." << endl << endl;								//Not sure I need this line - check requirements / output
		return emptyNode;
	}
	else {
		emptyNode.gameName = head->gameName;
		emptyNode.gamePrice = head->gamePrice;
		emptyNode.yearReleased = head->yearReleased;

		head->next->previous = nullptr;
		Node* temp = head;
		head = head->next;
		delete temp;
		return emptyNode;
	}
}

Node List::PeekFront() {

	if (head == nullptr) {
		Node emptyNode("NA");
		return emptyNode;
	}
	else {
		return *head;	
	}
}

void List::PushBack(std::string name, unsigned short int year, float price){
	Node* newNode = new Node(name, year, price);									//not sure if this will use defaults for last two 
																					//arguments in the call -- CHECK -- IT DOES! :D
	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->previous = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

Node List::PopBack() { 
	Node emptyNode;

	if (tail == nullptr) {
		cout << "The list is empty." << endl << endl;								//Not sure I need this line - check requirements / output
		return emptyNode;
	}
	else {
		emptyNode.gameName = tail->gameName;
		emptyNode.gamePrice = tail->gamePrice;
		emptyNode.yearReleased = tail->yearReleased;

		tail->previous->next = nullptr;
		Node* temp = tail;
		tail = tail->previous;
		delete temp;
		return emptyNode;
	}
}

Node List::PeekBack() {

	if (tail == nullptr) {
		Node emptyNode("NA");
		return emptyNode;
	}
	else {
		return *tail;
	}
}

void List::Sort() {

	if ((head == nullptr) || (head->next == nullptr)) {
		cout << "Sort failed to initialize. List is empty or has only 1 element. Code LC156." << endl;
		return;
	}

	Node* index = head;									//sort-variable setup
	Node* txfr;
	unsigned int i = 0, j = 0, listLength = Length();
	listLength--;

	while (i < listLength) {						//BEGIN: Insertion sort algorithm
		i++;
		j++;
		index = index->next;
		if (index->yearReleased <= index->previous->yearReleased) {			//Check if node out of order
			txfr = index;													//Remove identified node from list
			index->previous->next = index->next;
			if (index != tail) {
				index->next->previous = index->previous;
			}
			else {
				tail = index->previous;
			}

			j--;															//Adjust index location back 1 step
			index = index->previous;

			while (txfr->yearReleased < index->yearReleased) {				//Find where node should be inserted
				if (index->previous == nullptr) {							//INSERTION: BEFORE (TO HEAD of list)
					txfr->next = index;
					txfr->previous = index->previous;
					index->previous = txfr;
					head = txfr;
					j++;													//adjust current position (index) to reflect insertion.
					break;
				}
				j--;
				index = index->previous;
			}

			if (txfr->yearReleased > index->yearReleased) {					//INSERTION: AFTER current index
				txfr->previous = index;
				txfr->next = index->next;
				index->next->previous = txfr;
				index->next = txfr;
			}

			else if (txfr->yearReleased == index->yearReleased) {			//nested alphabetical sort
				unsigned short int
					indxLength = index->gameName.length(),					//this is just saving overhead on repeated .length() method calls
					txfrLength = txfr->gameName.length(),
					maxLength;

				if (txfrLength >= indxLength) {		//setting for loop iteration length
					maxLength = indxLength;
				}
				else {
					maxLength = txfrLength;
				}

				for (unsigned short int k = 0; k < maxLength; k++) {				//BEGIN: Alphabetical sort algorithm

					static unsigned short int ignLoc = k, tgnLoc = k;					//teaching alphabetical sort to ignore spaces
					if (k != 0) {														//and otherwise non-letter characters
						ignLoc++;
						tgnLoc++;
					}																						//NOTE:
					while ((index->gameName[ignLoc] == ' ') ||													//worth noting here is that we could 
						((int)index->gameName[ignLoc] < 65) ||													//include numeric characters into 
						(((int)index->gameName[ignLoc] > 90) && ((int)index->gameName[ignLoc] < 97)) ||			//alphabetic sort, through multiple 
						((int)index->gameName[ignLoc] > 122)) {													//different methods -> the commonly 
																												//accepted method being to treat numbers
						ignLoc++;																				//as coming before all letters and 
					}																							//ordered 0-9 (ascending).
					while ((txfr->gameName[tgnLoc] == ' ') ||													//THIS HAS NOT BEEN IMPLEMENTED HERE
						((int)txfr->gameName[tgnLoc] < 65) ||													//this bit of code to the left ignores 
						(((int)txfr->gameName[tgnLoc] > 90) && ((int)txfr->gameName[tgnLoc] < 97)) ||			//ALL non-letter characters (including
						((int)txfr->gameName[tgnLoc] > 122)) {													//numbers).

						tgnLoc++;
					}

					if ((indxLength - (ignLoc + 1)) >= (txfrLength - (tgnLoc + 1))) {			//adjusting loop iterations to compensate for skipped
						k = maxLength - (txfrLength - tgnLoc);									//character values
					}
					else {
						k = maxLength - (indxLength - ignLoc);
					}

					char ign, tgn;													//ensuring capitals are compared to capitals to determine
					if (((int)index->gameName[ignLoc] > 96) && ((int)index->gameName[ignLoc] < 123)) {		//alphabetical order
						ign = (char)((int)index->gameName[ignLoc] - 32);									//(apples to apples)
					}
					else {
						ign = index->gameName[ignLoc];
					}
					if (((int)txfr->gameName[tgnLoc] > 96) && ((int)txfr->gameName[tgnLoc] < 123)) {
						tgn = (char)((int)txfr->gameName[tgnLoc] - 32);
					}
					else {
						tgn = txfr->gameName[tgnLoc];
					}

					if (ign == tgn) {											//CASE: character IDENTICAL
						if (k == maxLength - 1) {										//check to determine if last character to be compared
							txfr->previous = index;										//if YES --> insert AFTER
							txfr->next = index->next;
							if (index != tail) {
								index->next->previous = txfr;
							}
							else {														//if (index == tail)
								tail = txfr;
							}
							index->next = txfr;
						}
					}

					else if ((int)ign > (int)tgn) {									//CASE: txfr char comes BEFORE index char
						txfr->next = index;														//INSERTION: BEFORE
						txfr->previous = index->previous;
						if (index->previous != nullptr) {										//if (index != head)
							index->previous->next = txfr;
						}
						else {																	//if (index == head)
							head = txfr;
						}
						index->previous = txfr;
						j++;														//adjust current position (index) to reflect insertion.
						break;
					}

					else {															//CASE: txfr char come AFTER index char
						txfr->previous = index;										//INSERTION: AFTER
						txfr->next = index->next;
						if (index->next != nullptr) {								//if (index != tail)
							index->next->previous = txfr;
						}
						else {														//if (index == tail)
							tail = txfr;
						}
						index->next = txfr;
						break;
					}
				}
			}

			while (j < i) {													//moving index back to previous position in linked list prior
				j++;														//to continuing sort
				index = index->next;
			}
		}
	}
}
 
Node List::Search(std::string target, signed short int* index) { 
	Node returnNode("NA");

	if (head == nullptr) {
		*index = -1;
		return returnNode;
	}
	else {
		Node* temp = head;
		*index = 0;

		while (target != temp->gameName) {
			if (temp->next == nullptr) {
				*index = -1;
				return returnNode;
			}
			temp = temp->next;
			(*index)++;
		}
		returnNode.gameName = temp->gameName;
		returnNode.gamePrice = temp->gamePrice;
		returnNode.yearReleased = temp->yearReleased;

		return returnNode;
	}
}

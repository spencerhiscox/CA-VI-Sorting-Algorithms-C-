©Carleton University, 2023

/****************************************/
/************* Don't Modify *************/
/****************************************/

#pragma once
#include "Node.h"
class List
{
	Node* head;
	Node* tail;

public:
	List();
	~List();
	void Display();
	int Length();
	void Delete();

	void PushFront(std::string, unsigned short int, float);
	Node PopFront();
	Node PeekFront();

	void PushBack(std::string, unsigned short int, float);
	Node PopBack();
	Node PeekBack();
	void Sort();
	Node Search(std::string target, signed short int* index);
};


©Carleton University, 2023

/****************************************/
/************* Don't Modify *************/
/****************************************/
#pragma once
#include <string>

class Node
{
public:
	Node* next;
	Node* previous; 
	std::string gameName;
	unsigned short int yearReleased;
	float gamePrice;
	Node(std::string name = "", unsigned short int year = 0, float price = 0, Node* nextIn = nullptr, Node* prevIn = nullptr);
};


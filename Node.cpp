#pragma once
#include "Node.h"

/*
Node::Node() {
	next = nullptr;
	previous = nullptr;
	gameName = "";
	yearReleased = 0;
	gamePrice = 0.0f;
}
*/

Node::Node(std::string name, unsigned short int year, float price, Node* nextIn, Node* prevIn) {
	next = nextIn;
	previous = prevIn;
	gameName = name;
	yearReleased = year;
	gamePrice = price;
}

/*
Node::~Node() {
	next = nullptr;
	previous = nullptr;
	gameName = "";
	yearReleased = 0;
	gamePrice = 0.0f;
}
*/

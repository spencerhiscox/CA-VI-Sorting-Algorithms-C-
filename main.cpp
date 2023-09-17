/****************************************/
/************* Don't Modify *************/
/****************************************/

#include <string>
#include "List.h"
#include <iostream>

using namespace std;

int main() {
	List list1;
	cout << "-----------------------------------------\n";
	cout << "-----------Test 1 - Empty List-----------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Empty list\n";
	cout << "\nLength: 0 \n";
	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	list1.Display();
	cout << "\nLength: " << list1.Length() << endl;
	cout << "\n*****************************************\n";

	cout << "\n-----------------------------------------\n";
	cout << "--------Test 2 - PushBack function-------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Resident Evil\t\t 1996\t 31.53 $\n";
	cout << "Sonic the Hedgehog\t 1991\t 25.25 $\n";
	cout << "Super Mario 2\t\t 1993\t 21.23 $\n";
	cout << "Super Mario 64\t\t 1996\t 41.43 $\n";
	cout << "Final Fantasy VII\t 1997\t 35.99 $\n";
	cout << "Donky Kong Country\t 1994\t 40.99 $\n";
	cout << "\nLength: 6\n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	list1.PushBack("Resident Evil", 1996, 31.53f);
	list1.PushBack("Sonic the Hedgehog", 1991, 25.25f);
	list1.PushBack("Super Mario 2", 1993, 21.23f);
	list1.PushBack("Super Mario 64", 1996, 41.43f);
	list1.PushBack("Final Fantasy VII", 1997, 35.99f);
	list1.PushBack("Donky Kong Country", 1994, 40.99f);

	list1.Display();
	cout << "\nLength: " << list1.Length() << endl;

	cout << "\n*****************************************\n";

	cout << "\n-----------------------------------------\n";
	cout << "-------Test 3 - PushFront function-------\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Left 4 Dead\t\t 2008\t 33.53 $\n";
	cout << "Halo: Combat Evolved\t 2001\t 27.25 $\n";
	cout << "World of Warcraft\t 2004\t 55.43 $\n";
	cout << "Grand Theft Auto IV\t 2008\t 45.99 $\n";
	cout << "Red Alert 2\t\t 2000\t 30.99 $\n";
	cout << "\nLength: 5\n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	List list2;

	list2.PushFront("Red Alert 2", 2000, 30.99f);
	list2.PushFront("Grand Theft Auto IV", 2008, 45.99f);
	list2.PushFront("World of Warcraft", 2004, 55.43f);
	list2.PushFront("Halo: Combat Evolved", 2001, 27.25f);
	list2.PushFront("Left 4 Dead", 2008, 33.53f);

	list2.Display();
	cout << "\nLength: " << list2.Length() << endl;

	cout << "\n*****************************************\n";

	cout << "\n-----------------------------------------\n";
	cout << "--------Test 4 - PopFront function-------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "First game in the list is:\n";
	cout << "-----------------------------------------\n";

	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Resident Evil\t\t 1996\t 31.53 $\n";
	cout << "\nLength: 5 \n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "First game in the list is:\n";
	cout << "-----------------------------------------\n";

	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	Node temp = list1.PopFront();
	cout << temp.gameName << "\t\t " << temp.yearReleased << "\t " << temp.gamePrice << " $\n";
	cout << "\nLength: " << list1.Length() << endl;

	cout << "\n*****************************************\n";

	cout << "\n-----------------------------------------\n";
	cout << "--------Test 5 - PopBack function--------\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Last game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Red Alert 2\t\t2000\t 30.99 $\n";
	cout << "\nLength: 4 \n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "Last game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	temp = list2.PopBack();
	cout << temp.gameName << "\t\t " << temp.yearReleased << "\t " << temp.gamePrice << " $\n";
	cout << "\nLength: " << list2.Length() << endl;

	cout << "\n*****************************************\n";


	cout << "\n-----------------------------------------\n";
	cout << "--------Test 6 - PeekFront function------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "First game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Sonic the Hedgehog\t 1991\t 25.25 $\n";
	cout << "\nLength: 5 \n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "First game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	temp = list1.PeekFront();
	cout << temp.gameName << "\t " << temp.yearReleased << "\t " << temp.gamePrice << " $\n";
	cout << "\nLength: " << list1.Length() << endl;

	cout << "\n*****************************************\n";

	cout << "\n----------------------------------------\n";
	cout << "--------Test 7 - PeekBack function-------\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Last game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Grand Theft Auto IV\t 2008\t 45.99 $\n";
	cout << "\nLength: 4 \n\n";

	cout << "-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "Last game in the list is:\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	temp = list2.PeekBack();
	cout << temp.gameName << "\t " << temp.yearReleased << "\t " << temp.gamePrice << " $\n";
	cout << "\nLength: " << list2.Length() << endl;

	cout << "\n*****************************************\n";


	cout << "\n-----------------------------------------\n";
	cout << "------Test 8 - Sort by year function-----\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "-----------------------------------------\n";
	cout << "------------ List before sort -----------\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	list2.Display();
	cout << "-----------------------------------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Halo: Combat Evolved\t 2001\t 27.25 $\n";
	cout << "World of Warcraft\t 2004\t 55.43 $\n";
	cout << "Grand Theft Auto IV\t 2008\t 45.99 $\n";
	cout << "Left 4 Dead\t\t 2008\t 33.53 $\n";
	cout << "\nLength: 4 \n\n";

	cout << "-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	list2.Sort();
	list2.Display();
	cout << "\nLength: " << list2.Length() << endl;

	cout << "\n*****************************************\n";


	cout << "\n-----------------------------------------\n";
	cout << "----Test 9.1 - Search by name function---\n";
	cout << "------------ Expected Output ------------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "-----------------------------------------\n";
	cout << "Super Mario 64 is located at index: 2\n";
	cout << "-----------------------------------------\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << "Super Mario 64\t\t 1996\t 41.43 $\n";
	cout << "-----------------------------------------\n";

	signed short int index = 0;
	Node searchResult;
	searchResult = list1.Search("Super Mario 64", &index);
	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << searchResult.gameName << " is located at index: " << index << "\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << searchResult.gameName << "\t " << searchResult.yearReleased << "\t " << searchResult.gamePrice << " $\n";
	cout << "\n\n-----------------------------------------\n";
	cout << "----Test 9.2 - Search by name function---\n";
	cout << "------------ Expected Output ------------\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "-----------------------------------------\n";
	cout << "Red Alert 2 is located at index: -1\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n";
	cout << " NA\t\t 0\t 0 $\n";

	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	index = 0;
	searchResult = list2.Search("Red Alert 2", &index);
	cout << "Red Alert 2 is located at index: " << index << "\n";
	cout << "Game Name\t\t Year\t Price\n";
	cout << "-----------------------------------------\n ";
	cout << searchResult.gameName << "\t\t " << searchResult.yearReleased << "\t " << searchResult.gamePrice << " $\n";

	cout << "\n*****************************************\n";


	cout << "\n-----------------------------------------\n";
	cout << "----------Test 10.1 - Delete Lists-------\n";
	cout << "----------------- List 1 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "List 1:\n";
	cout << "Empty list\n";
	cout << "\nLength: 0 \n";
	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "List 1:\n";
	list1.Delete();
	list1.Display();
	cout << "\nLength: " << list1.Length() << endl;

	cout << "\n-----------------------------------------\n";
	cout << "----------Test 10.2 - Delete Lists-------\n";
	cout << "----------------- List 2 ----------------\n";
	cout << "------------ Expected Output ------------\n";
	cout << "-----------------------------------------\n";
	cout << "List 2:\n";
	cout << "Empty list\n";
	cout << "\nLength: 0 \n";
	cout << "\n-----------------------------------------\n";
	cout << "-------------- Your Output --------------\n";
	cout << "-----------------------------------------\n";
	cout << "List 2:\n";
	list2.Delete();
	list2.Display();
	cout << "\nLength: " << list2.Length();
}

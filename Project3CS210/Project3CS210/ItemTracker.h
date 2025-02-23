#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;
//creating an item tracker class with the private map
class ItemTracker {
private:
	map<string, int> itemTracker;

//setting up all the function we will need to complete the program
public:
	ItemTracker();

	void readAndWriteData();
	void findWord();
	void displayQuantity();
	void displayHistogram();
	void menuOptions();
	


};
#endif
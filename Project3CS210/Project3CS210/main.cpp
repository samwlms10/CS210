/*
Samuel Williams
2/20/2025
Project 3
*/
#include "ItemTracker.h"

int main() {
	ItemTracker tracker;
	//calling the function to make a backup and then the menu
	tracker.readAndWriteData();
	tracker.menuOptions();
	
	return 0;
}
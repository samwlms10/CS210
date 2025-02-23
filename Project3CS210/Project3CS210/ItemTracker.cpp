#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "ItemTracker.h"

using namespace std;

ItemTracker::ItemTracker() {
}
//setting up to read and write the data to another file
void ItemTracker::readAndWriteData() {
    ifstream itemFS;
    string item;
    ofstream frequencyFS;
    //opening the file of information and also making a new file called frequencyFS for backup
    itemFS.open("CS210_Project_Three_Input_File.txt");
    frequencyFS.open("frequency.dat", ios::out);
    //if the file could not open it will display a message
    if (!itemFS.is_open()) {
        cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
    }
    //if the file did open, while there is information on the line then the file will write to frequencyFS and also add the item to the map
    else {
        while (itemFS>> item) {
            frequencyFS << item << endl;
            itemTracker[item]++;
        }
    }
    //closing both files
    itemFS.close();
    frequencyFS.close();
}
//setting up to find the users word
void ItemTracker::findWord() {
    string userItem;
    char anotherMenuOption = 'Y';
    //getting the item that the customer wants to look for
    while (anotherMenuOption == 'Y' || anotherMenuOption == 'y') {
        cout << "What item would you want to find?" << endl;
        cin >> userItem;
        bool wordFound = false;
        //comparing the user item to the map of items and if the word is there then the wordfound bool goes to true
        for (auto it : itemTracker) {
            if (userItem == it.first) {
                cout << it.first << " " << it.second << endl;
                wordFound = true;
                break;
            }
        }
        //if the word is not found then it prints out a message with the item the user typed in and displays 0
        if (!wordFound) {
            cout << "Sorry, that item is not here." << endl;
            cout << userItem << " 0" << endl;
        }
        //gives the user a chance to look for another word
        cout << "Would you like to search for another item? Please enter Y for yes or N for no" << endl;
        while (!(cin >> anotherMenuOption) || (anotherMenuOption != 'Y' && anotherMenuOption != 'y' && anotherMenuOption != 'N' && anotherMenuOption != 'n')) {
            cout << "Error invalid input! Please only enter Y or N for your answer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
}
//setting up the display for each items quantity
void ItemTracker::displayQuantity() {
    //looping through the map and displaying all the information in it
    for (auto it : itemTracker) {
        cout << it.first << " " << it.second << endl;
    }

}
//setting up the histogram
void ItemTracker::displayHistogram() {
    //looping through the map and displaying the first item
    for (auto it : itemTracker) {
        cout << it.first << " ";
        //using a for loop to loop through as many times as the second item in the map and printing out a *
        for (int i = 0; i < it.second; i++) {
            cout << "*";
        }
        cout << endl;
    }  
}
//setting up the menu options for the customer to choose
void ItemTracker::menuOptions() {
    int choice;
    char anotherMenuOption = 'Y';
    // Displaying the menu
    while (anotherMenuOption == 'Y' || anotherMenuOption == 'y') {
        cout << "Hello please enter 1-4 for your choice." << endl;
        cout << "Option 1 print out how many times a word appears." << endl;
        cout << "Option 2 print out the entire list." << endl;
        cout << "Option 3 print out a histogram of the entire list." << endl;
        cout << "Option 4 exit." << endl;

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input! Please enter a valid number!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // calling the findWord function
        if (choice == 1) {
            findWord();
        }
        // calling the displayQuantity function
        else if (choice == 2) {
            displayQuantity();
        }
        // calling the displayHistogram function
        else if (choice == 3) {
            displayHistogram();
        }
        // exiting if the user wants
        else if (choice == 4) {
            cout << "Thank you for using our item tracker!" << endl;
            break;
        }
        // giving them an option to choose another menu item
        cout << "Would you like to see another option? Y for yes or N for no." << endl;
        while (!(cin >> anotherMenuOption) || (anotherMenuOption != 'Y' && anotherMenuOption != 'y' && anotherMenuOption != 'N' && anotherMenuOption != 'n')) {
            cout << "Error invalid input! Please only enter Y or N for your answer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
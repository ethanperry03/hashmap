#include <iostream>
#include <string>
#include "menu.h"
using namespace std;

/** displayMenu()
 * This function prints a formatted menu with options for inserting new keys, loading entries
 * from an input file, removing entries by key, finding and displaying entries by key, displaying
 * all entries, getting table information, and quitting the program.
 * @void
 */
void displayMenu() {
    cout << endl << "-----------MENU------------------------" << endl;
    cout << "i - Insert new key" << endl;
    cout << "l - Load entries from an input file" << endl;
    cout << "r - Remove entry by key" << endl;
    cout << "f - Find and display entry by key" << endl;
    cout << "a - Display all entries in the table" << endl;
    cout << "t - Get table information" << endl;
    cout << "p - Change probing exponent" << endl;
    cout << "q - quit" << endl;
    cout << "---------------------------------------" << endl;
}

/** getInputStr()
 * This function prompts the user to enter the first and last name of a key, reads the input
 * from the console, and returns it as a string. This is useful for obtaining key values
 * that can be used in hash table operations.
 *
 * @return string The key entered by the user.
 */
string getInputStr() {
    string inputName;
    cout << "Input first and last name of key: ";
    getline(cin, inputName);
    return inputName;
}

/** optionHub()
 * This function provides a hub for user options to interact with the hash table. Depending
 * on the input character, it calls various methods to insert entries, load entries from a
 * file, remove entries, find and display entries, display all entries, or display table
 * information. If the input is invalid, it displays an error message.
 *
 * @param table Reference to the HashTable object.
 * @param input Character representing the user's choice of action.
 * @return void This function does not return a value.
 */
void optionHub(HashTable& table, char input) {
    if (input == 'i') {
        table.insertOneKey();
    }
    else if (input == 'l') {
        string inputFileName;
        cout << "Input .csv file:";
        getline(cin, inputFileName);
        table.loadEntries(inputFileName);
    }
    else if (input == 'r') {
        string inputName = getInputStr();
        table.remove(inputName);
    }
    else if (input == 'f') {
        string inputName = getInputStr();
        int index = table.find(inputName);
        if(index != -1) {
            table.display(index);
        }
    }
    else if (input == 'd') {
        table.display();
    }
    else if (input == 't') {
        table.getInfo();
    }
    else if (input == 'p') {
        table.changeProbe();
    }
    else {
        cout << "Invalid input, please try again." << endl;
    }
}
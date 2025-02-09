#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

void displayMenu() {
    cout << endl << "-----------MENU------------------------" << endl;
    cout << "i - Insert new key" << endl;
    cout << "l - Load entries from an input file" << endl;
    cout << "r - Remove entry by key" << endl;
    cout << "f - Find and display entry by key" << endl;
    cout << "a - Display all entries in the table" << endl;
    cout << "c - Number of collisions so far" << endl;
    cout << "q - quit" << endl;
    cout << "---------------------------------------" << endl;
}

string getInputStr() {
    string inputName;
    cout << "Input first and last name of key: ";
    getline(cin, inputName);
    return inputName;
}

void optionHub(HashTable& table, const char input) {
    if (input == 'i') {
        table.insert();
    }
    else if (input == 'l') {
        cout << "load" << endl;
        table.loadEntries("load entries");
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
    else if (input == 'c') {
        cout << "Collisions: " << table.getCollisions() << endl;
    }
    else {
        cout << "Invalid input, please try again." << endl;
    }
}


int main() {

    int tableSize = 6;
//    cout << "Enter desired table size: ";
//    cin >> tableSize;

    // table init
    HashTable table(tableSize);

    char input;
    do {
        displayMenu();
        cout << "-> ";
        cin >> input;
        cin.get();
        if (input != 'q') {
            optionHub(table, input);
        }
    } while (input != 'q');

    cout << "Thank you for using this hash table!" << endl;

    // DTOR?????
    return 0;
}

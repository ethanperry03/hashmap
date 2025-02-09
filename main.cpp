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
    cout << "t - Get table information" << endl;
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
        table.insertOneKey();
    }
    else if (input == 'l') {
        string inputFileName;
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
    else {
        cout << "Invalid input, please try again." << endl;
    }
}


int main() {

    int tableSize = 3;
    cout << "Enter desired table size: ";
    cin >> tableSize;

    // table init
    HashTable table(tableSize);

    // do while input loop
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

#include <iostream>
//#include <vector>
#include "hash.h"
using namespace std;

void displayMenu() {
    cout << endl << "-----------MENU------------------------" << endl;
    cout << "i - Insert new key" << endl;
    cout << "l - Load entries from an input file" << endl;
    cout << "f - Find entry by key" << endl;
    cout << "r - Remove entry by key" << endl;
    cout << "d - Display entry by key" << endl;
    cout << "a - Display all entries in the table" << endl;
    cout << "q - quit" << endl;
    cout << "---------------------------------------" << endl;
}

void optionHub(HashTable& table, const char input) {
    if (input == 'i') {
        cout << "Input" << endl;
//        table.insert("test");
    }
    else if (input == 'l') {
        cout << "load" << endl;
        table.loadEntries("load entries");
    }
    else if (input == 'f') {
        cout << "find" << endl;
        table.find("testing");
    }
    else if (input == 'r') {
        cout << "remove" << endl;
        table.remove("remove");
    }
    else if (input == 'd') {
        cout << "display" << endl;
        table.display("string");
    }
    else if (input == 'a') {
        cout << "all" << endl;
        table.display();
    }
    else {
        cout << "Invalid input, please try again." << endl;
    }
}


int main() {

    // table init
    HashTable table(10);

    char input;
    do {
        displayMenu();
        cout << "-> ";
        cin >> input;
        if (input != 'q') {
            optionHub(table, input);
        }
    } while (input != 'q');

    cout << "Thank you for using this hash table!" << endl;

    // DTOR?????
    return 0;
}

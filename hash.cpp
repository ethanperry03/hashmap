#include <iostream>
#include <vector>
#include "hash.h"
using namespace std;

// hash function using Knuth's constant
int HashTable::hashFunction(string key) {
    cout << "hash function" << endl;
    return 0;
}

// linear probing method
int HashTable::probe(string key, int i) {
    cout << "probing" << endl;
    return 0;
}

// parameterized constructor
HashTable::HashTable(int tableSize) {
    count = 0;
    cout << "Table created";
}


// insertion by key
void HashTable::insert(Entry entry) {

}
// find entry by its key value
Entry HashTable::find(string key) {
    cout << "find entry: " << key << endl;
    Entry l;
    return l;
}
// remove entry by its key
void HashTable::remove(string key) {
    cout << "remove entry: " << key << endl;
}

// display one entry by key
void HashTable::display(string key) {
    cout << "display entry: " << key << endl;
}

// display all entries
void HashTable::display() {
    cout << "display aaaallllllllll" << endl;
}

// load in entries from a table
void HashTable::loadEntries(string key) {
    cout << "load entries: " << key << endl;
}

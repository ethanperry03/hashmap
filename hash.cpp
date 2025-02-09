#include <iostream>
#include <cmath>
#include "hash.h"
#include "helper.h"
using namespace std;

// parameterized constructor
HashTable::HashTable(int tableSize) {
    count = 0;
    collisions = 0;
    size = findNextPrime(tableSize);
    table.resize(size);

    cout << "Table created with size of: " << size << endl;
}

// hash function using Knuth's constant
int HashTable::hashFunction(string key) {
    int sum = 0;
    int charCast;
    // sum together the ascii values of all characters in the string
    for (int i = 0; i < key.length(); i++){
        charCast = key[i];
        sum += charCast;
    }

    // use knuths constant (A) for multiplicative hashing method to find the slot it belongs in
    // index = floor ( size * ( key * Amod1 ) )
    double KNUTHS = (sqrt(5) - 1) / 2.0;
    // grab the fractional part ([0,1])
    double fraction = (sum * KNUTHS) - floor(sum * KNUTHS);
    // get the index
    int index = floor(this->size * fraction);

    return index;
}

// linear probing method
int HashTable::probe(Entry inputEntry, int index) {
    if(this->isFull()) {
        cout << "Error: table is full, no where to insert" << endl;
        return -1;
    }
    // else, linear probe
    int counter = 0;
    cout << "probing" << endl;
    while(counter < this->size) {
        index = index % this->size;
        // if this slot is not occupied
        if(!this->table[index].dirtyBit) {
            insertEntry(inputEntry, index);
            return index;
        }
        counter++;
        index++;
        this->collisions++;
    }
    return index;
}

// return the load factor if another element were to be inserted
double HashTable::getLoadFactor() const {
    return (1.0 + count) / size;
}

// create and return an Entry node from user input
Entry HashTable::createEntry() {
    Entry inputEntry;

    cout << "Input first and last name: ";
    getline(cin, inputEntry.name);
//
//    cout << "Enter phone number: ";
//    getline(cin, inputEntry.phoneNum);
//
//    cout << "Enter Address: ";
//    getline(cin, inputEntry.address);

//    inputEntry.name = "Ethan Perry";
    inputEntry.phoneNum = "123-456-7890";
    inputEntry.address = "21 Norton Street";

    return inputEntry;
}

void HashTable::resizeTable() {
    // double the size of the table, and find the next largest prime
    this->size = findNextPrime(this->size * 2);

}

// insert and entry to the table
void HashTable::insertEntry(Entry& input, int index) {
    table[index].name = input.name;
    table[index].phoneNum = input.phoneNum;
    table[index].address = input.address;
    table[index].dirtyBit = true;
    this->count++;
    cout << input.name << " has been entered in the table at index " << index << endl;
}

// insertion by key
void HashTable::insert() {
    // create a new entry and find where it should go
    Entry input = createEntry();
    int result = hashFunction(input.name);

    // if the load factor is large, resize the table, then proceed
    if(getLoadFactor() > 0.70) {
        resizeTable();
    }

    // if the index is valid to insert at that slot
    if (!table[result].dirtyBit) {
        insertEntry(input, result);
    }
    // else implies there is a collision
    // if the collision is NOT a duplicate key
    else if (table[result].name != input.name) {
        probe(input, result);
    }
    // else there was a collision and the key is not unqiue
    // count collision ??????????????????????????//
    else {
        cout << "Error in insertion: " << input.name << " already exists as a key" << endl;
    }
}

// find entry by its key value
int HashTable::find(string key) {
    int index = hashFunction(key);
    int counter = 0;
    // else, linear probe
    while(counter < this->size) {
        index = index % this->size;
        // if this slot is not occupied
        if(this->table[index].name == key && table[index].dirtyBit) {
            return index;
        }
        counter++;
        index++;
    }
    cout << "Error: " << key << " not found" << endl;
    return -1;
}

// remove entry by its key
void HashTable::remove(string key) {
    int index = this->find(key);
    if(index != -1 && this->table[index].name == key) {
        // say that it is unoccupied
        this->table[index].dirtyBit = false;
        this->size--;
        this->count--;
        cout << "Successfully removed " << key << " at index " << index << endl;
    }

}

// display one entry by key
void HashTable::display(int index) {
    cout << "------------ " << index << " --------------" << endl;
    cout << "Name: " << this->table[index].name << endl;
    cout << "Phone Number: " << this->table[index].phoneNum << endl;
    cout << "Address: " << this->table[index].address << endl << endl;
}

// display all entries
void HashTable::display() {
    for (int i = 0; i < table.size(); i++) {
        if(table[i].dirtyBit) {
            display(i);
        }
    }
}

// load in entries from a table
void HashTable::loadEntries(string key) {
    cout << "load entries: " << key << endl;
}

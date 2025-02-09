//
// Created by Ethan Perry on 2/7/2025.
//

#ifndef P1_HASH_H
#define P1_HASH_H

#include <iostream>
#include <vector>
using namespace std;

// struct for each value entry
struct Entry {
    string name;
    string phoneNum;
    string address;
    bool dirtyBit;
};

class HashTable {
private:
    // vector storing key/val pairs
    vector<Entry> table;
    // size of the table
    int size;
    // number of entries currently in the table
    int count;
    // number of collisions while inserting
    int collisions;

    // hash function using Knuth's constant
    int hashFunction(string);
    // linear probing method
    int probe(Entry, int);
    // calculate the load factor
    double getLoadFactor() const;
    // get information to create an Entry node
    Entry createEntry();
    // insert a specific entry given the struct and index
    void insertEntry(Entry&, int);
    // resize the array and rehash entries
    void resizeTable();
public:
    // parameterized constructor
    HashTable(int);
    // insertion by key
    void insert();
    // find entry by its key value
    int find(string);
    // remove entry by its key
    void remove(string);
    // display one entry by key
    void display(int);
    // display all entries
    void display();
    // load in entries from a table
    void loadEntries(string);
    // return number of collisions
    int getCollisions() {return collisions;}
    // is full and is empty in line defintion
    bool isEmpty () {return count == 0;}
    bool isFull () {return count == size;}
};



#endif //P1_HASH_H

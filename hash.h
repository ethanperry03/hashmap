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
    int probe(string, int);
    // calculate the load factor
    int getLoadFactor() {return (count / size);}
public:
    // parameterized constructor
    HashTable(int);
    // insertion by key
    void insert(Entry);
    // find entry by its key value
    Entry find(string);
    // remove entry by its key
    void remove(string);
    // display one entry by key
    void display(string);
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

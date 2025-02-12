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
    bool validBit;
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
    // exponent for probing method
    int probeExpo;

    // hash function using Knuth's constant
    int hashFunction(const string&) const;
    // linear probing method
    int probe(Entry, int);
    // calculate the load factor
    double getLoadFactor() const;
    // get information to create an Entry node
    static Entry createEntry();
    // insert a given entry
    int insert(Entry&);
    // insert a specific entry given the struct and index
    void insertStruct(Entry&, int);
    // resize the array and rehash entries
    void resizeTable();
public:
    // parameterized constructor
    explicit HashTable(int);
    // insertion by key
    void insertOneKey();
    // find entry by its key value
    int find(const string&) const;
    // remove entry by its key
    void remove(const string&);
    // display one entry by key
    void display(const int&) const;
    // display all entries
    void display() const;
    // load in entries from a table
    void loadEntries(const string&);
    // display information about the table
    void getInfo() const;
    // change the probing method
    void changeProbe();
    // is full in line defintion
    bool isFull () const {return count == size;}
};



#endif //P1_HASH_H

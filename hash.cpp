#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
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

/** hashFunction()
 * This function computes the hash index for a given string key using Knuth's multiplicative
 * hashing method. The function first calculates the sum of the ASCII values of all characters
 * in the key. It then uses Knuth's constant (A) to determine the fractional part of the product
 * of the sum and the constant. Finally, the function maps this fractional value to an index
 * within the bounds of the hash table size.
 *
 * @param key The string key for which the hash index is to be computed.
 * @return int The computed hash index, which is an integer within the range [0, size - 1].
 */
int HashTable::hashFunction(string key) {
    int sum = 0;
    // sum together the ascii values of all characters in the string
    for (int i = 0; i < key.length(); i++){
        sum += key[i];
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

/** probe() - HashTable class
 * Linear probing method to insert an entry into the hash table.
 *
 * This function attempts to insert the provided entry (`inputEntry`) into the hash table
 * starting from the given index. If the table is full, an error message is displayed,
 * and the function returns -1. Otherwise, linear probing is used to find an available slot
 * for the entry. The function handles collisions by incrementing the index and continues
 * probing until an empty slot is found or the entire table has been checked. If a suitable
 * slot is found, the entry is inserted, and the index of the slot is returned.
 *
 * Key components:
 * - Checks if the hash table is full and returns an error if true.
 * - Uses a linear probing technique to handle collisions and find an available slot.
 * - Inserts the entry into the first available slot found and increments the entry count.
 *
 * @param inputEntry The entry to be inserted into the hash table.
 * @param index The starting index for the probing process.
 * @return int The index of the slot where the entry was inserted, or -1 if the table is full.
 */
int HashTable::probe(Entry inputEntry, int index) {
    if(this->isFull()) {
        cout << "Error: table is full, no where to insert" << endl;
        return -1;
    }
    // else, linear probe
    int counter = 0;
    while(counter < this->size) {
        index = index % this->size;
        // if this slot is not occupied
        if(!this->table[index].validBit) {
            insertStruct(inputEntry, index);
            this->count++;
            return index;
        }
        counter++;
        index++;
        this->collisions++;
    }
    return index;
}

/** getLoadFactor() - HashTable class
 * Returns the load factor if another element were to be inserted.
 * @return double The load factor of the hash table after the next insertion.
 */
double HashTable::getLoadFactor() const {
    return (1.0 + count) / size;
}

/** createEntry() - HashTable class
 * This function prompts the user to input the first and last name, phone number,
 * and address, and stores these values in a new Entry structure. The Entry node is
 * then returned to be inserted into the hash table. This allows for dynamic creation
 * of entries based on user-provided information.
 *
 * @return Entry A structure containing the user's input data for name, phone number, and address.
 */
Entry HashTable::createEntry() {
    // declare Entry struct and grab input from user
    Entry inputEntry;

    cout << "Input first and last name: ";
    getline(cin, inputEntry.name);

    cout << "Enter phone number: ";
    getline(cin, inputEntry.phoneNum);

    cout << "Enter Address: ";
    getline(cin, inputEntry.address);

    return inputEntry;
}

/** resizeTable() - HashTable class
 * This function resizes the hash table by doubling its current size and finding the next
 * largest prime number. It then rehashes all existing entries into the new table. This
 * ensures efficient storage and reduces the likelihood of collisions as the table grows.
 *
 * @return void This function does not return a value.
 */
void HashTable::resizeTable() {
    // declare a new vector that will be the old table after swapping
    vector<Entry> oldTable(this->size);
    // swap the vectors
    table.swap(oldTable);
    // double the size of the table, and find the next largest prime
    this->size = findNextPrime(this->size * 2);
    // resize table
    table.resize(this->size);

    int newIndex;
    // loop through the old table and hash all existing entries into new table
    for(int i = 0; i < oldTable.size(); i++) {
        // if the given index has a value pair
        if(oldTable[i].validBit) {
            // get the new index (since this->size has been updated)
            newIndex = hashFunction(oldTable[i].name);
            // insert the new entry into the new table
            insertStruct(oldTable[i], newIndex);
        }
    }
    cout << "Table has been resized to " << this->size << endl;
}

/** insert() - HashTable class
 * This function first checks if the load factor exceeds a threshold (0.70). If it does,
 * the table is resized before proceeding. The hash function is then used to determine
 * the index for insertion. The function handles collisions and ensures that duplicate
 * keys are not inserted. If a collision occurs with a unique key, linear probing is used
 * to find an available slot.
 *
 * @param input The entry structure to be inserted into the hash table.
 * @return void This function does not return a value.
 */
bool HashTable::insert(Entry& input) {
    // if the load factor is large, resize the table, then proceed
    if(getLoadFactor() > 0.70) {
        resizeTable();
    }

    // get hash function result
    int result = hashFunction(input.name);
    int index;
    // if the index is valid to insert at that slot
    if (!table[result].validBit) {
        insertStruct(input, result);
        this->count++;
        index = result;
    }
    // else implies there is a collision
    // if the collision is NOT a duplicate key
    else if (table[result].name != input.name) {
        index = probe(input, result);
    }
    // else there was a collision and the key is not unqiue
    // count collision ??????????????????????????//
    else {
        index = -1;
    }
    return index;
}

/** insertStruct() - HashTable class
 * This function takes an entry structure and inserts it into the hash table at the given index.
 * It copies the name, phone number, and address from the input entry to the corresponding
 * index in the table and sets the valid bit to true, indicating that the slot is occupied.
 *
 * @param input The entry structure to be inserted into the hash table.
 * @param index The index at which the entry should be inserted.
 * @return void This function does not return a value.
 */
void HashTable::insertStruct(Entry& input, int index) {
    table[index].name = input.name;
    table[index].phoneNum = input.phoneNum;
    table[index].address = input.address;
    table[index].validBit = true;
}

/** insertOneKey() - HashTable class
 * This function creates a new entry based on user input and inserts it into the hash table
 * using the appropriate insertion method. It allows for dynamic addition of entries to the
 * hash table based on keys provided by the user.
 *
 * @return void This function does not return a value.
 */
void HashTable::insertOneKey() {
    // create a new entry and find where it should go
    Entry input = createEntry();
    int index = insert(input);
    if(index != -1) {
        cout << input.name << " has been entered in the table at index " << index << endl;
    }
    else {
        cout << "Error in insertion: " << input.name << " already exists as a key" << endl;
    }
}

/** find() - HashTable class
 * This function uses linear probing to search for an entry with the specified key in the
 * hash table. It starts from the index determined by the hash function and continues
 * probing until it finds the entry or has checked the entire table. If the entry is found,
 * the index of the entry is returned. If the entry is not found, an error message is displayed,
 * and the function returns -1.
 *
 * @param key The key value to search for in the hash table.
 * @return int The index of the entry if found, or -1 if the entry is not found.
 */
int HashTable::find(string key) {
    int index = hashFunction(key);
    int counter = 0;
    // else, linear probe
    while(counter < this->size) {
        index = index % this->size;
        // if this slot is not occupied
        if(this->table[index].name == key && table[index].validBit) {
            return index;
        }
        counter++;
        index++;
    }
    cout << "Error: " << key << " not found" << endl;
    return -1;
}

/** remove() - HashTable class
 * This function finds the entry with the specified key in the hash table using the find
 * function. If the entry is found, it marks the slot as unoccupied by setting the valid bit
 * to false, decreases the table size and count, and displays a success message with the index.
 * If the entry is not found, no action is taken.
 *
 * @param key The key value of the entry to be removed from the hash table.
 * @return void This function does not return a value.
 */
void HashTable::remove(string key) {
    int index = this->find(key);
    if(index != -1 && this->table[index].name == key) {
        // say that it is unoccupied
        this->table[index].validBit = false;
        this->size--;
        this->count--;
        cout << "Successfully removed " << key << " at index " << index << endl;
    }
}

/** display() - HashTable class
 * This function prints the details of an entry at the given index in the hash table.
 * It includes the entry's name, phone number, and address, formatted for readability.
 *
 * @param index The index of the entry to be displayed.
 * @return void This function does not return a value.
 */
void HashTable::display(int index) {
    cout << "------------ " << index << " --------------" << endl;
    cout << "Name: " << this->table[index].name << endl;
    cout << "Phone Number: " << this->table[index].phoneNum << endl;
    cout << "Address: " << this->table[index].address << endl << endl;
}

/** display() - HashTable class
 * This function iterates through the entire hash table and displays the details of
 * all entries that are marked as valid. It uses the display function to print the
 * details of each valid entry.
 *
 * @return void This function does not return a value.
 */
void HashTable::display() {
    for (int i = 0; i < table.size(); i++) {
        if(table[i].validBit) {
            display(i);
        }
    }
}

/** loadEntries() - HashTable class
 * This function reads entries from the provided input file and inserts them into the hash table.
 * It first checks if the file exists and is open. If the file is invalid or empty, an error message
 * is displayed, and the function returns. Otherwise, it reads each line from the file, parses the
 * entry data, and inserts the entries into the hash table.
 *
 * @param inputFileName The name of the input file containing entries to be loaded.
 * @return void This function does not return a value.
 */
void HashTable::loadEntries(string inputFileName) {
    // check if file exists
    ifstream file(inputFileName);
    if(!file.is_open()) {
        cout << "Error: '" << inputFileName << "' is an invalid file input" << endl;
        return;
    }
    // check if file is empty
    string inputLine;
    if(!getline(file, inputLine)) {
        cout << "Error: provided input file, '" << inputFileName << "' is empty" << endl;
        return;
    }

    // file is valid and non empty
    Entry inputEntry;
    inputEntry.validBit = true;

    int countBeforeFile = this->count;
    // while you are still reading valid lines from input file
    while(getline(file, inputLine)) {
        stringstream line(inputLine);

        // get each struct data member
        getline(line, inputEntry.name, ',');
        getline(line, inputEntry.phoneNum, ',');
        getline(line, inputEntry.address, ',');

        // insert into the table
        insert(inputEntry);
    }
    cout << "Inserted " << this->count - countBeforeFile << " entries from '" << inputFileName << "'" << endl;
}

/** getInfo() - HashTable class
 * This function prints detailed information about the current state of the hash table.
 * It includes the number of elements, table size, load factor (with precision), and the
 * number of collisions that have occurred. This information helps in understanding the
 * performance and efficiency of the hash table.
 *
 * @return void This function does not return a value.
 */
void HashTable::getInfo() const {
    cout << "------------ info ------------" << endl;
    cout << "Num of elements: " << this->count << endl;
    cout << "Table size: " << this->size << endl;
    cout << "Load Factor: " << setprecision(3) << getLoadFactor() << endl;
    cout << "Num of Collisions: " << this->collisions << endl;
}
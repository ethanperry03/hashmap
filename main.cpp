/** Assignment 1: Hashmap
 * Ethan Perry
 * Sun. Feb 16th, 2025
 * Hashtable implementation using open addressing in c++
 * I have abided by the Wheaton College Honor code in this work. -Ethan Perry
 */

#include <iostream>
#include "menu.h"
#include "hash.h"
#include "helper.h"
using namespace std;

/** main()
 * This function initializes the hash table with a user-defined size, displays a menu of
 * options, and processes user inputs in a loop until the user chooses to quit. It allows
 * for dynamic interaction with the hash table, including inserting keys, loading entries
 * from a file, removing entries, finding and displaying entries, displaying all entries,
 * and getting table information.
 *
 * @return int Returns 0 upon successful completion.
 */
int main() {

    int tableSize;
    cout << "Enter desired table size: ";
    tableSize = getIntInput();

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

    return 0;
}

## To do 
- linear probing change(?)
- dependencies of functions
- const
- header comment in main?

# Hash Table Implementation using Open Addressing in C++

## Authors
- Ethan Perry

## Description
This project involves implementing a hash table using open addressing with linear probing in C++. The goal is to achieve 
constant-time complexity O(1) for insert, find, and delete operations. The hash table supports the following operations
via the user-facing menu:
- Insert an entry into the hash table while handling collisions through linear probing.
- Load a batch of entries from a .csv file
- Remove an entry from the hash table.
- Find an entry based on the key.
- Display all entries stored in the hash table.
- Get data about the current table.
- Dynamic resizing to maintain efficiency.


## How to Run
1. **Compile the code**: Use a C++ compiler to compile the code.
2. **Run the executable**: Run the compiled executable.
3. **Interact with the menu**: Follow the menu options to insert, find, or remove entries.

## Input
The program will first prompt you to enter your desired table size. An algorithm is then run to find the closest prime
number to the input size. After entering the table size, the following menu will appear continuously until you quit.

-----------MENU------------------------\
i - Insert new key\
l - Load entries from an input file\
r - Remove entry by key\
f - Find and display entry by key\
a - Display all entries in the table\
t - Get table information\
q - quit\
---------------------------------------\

## Time Complexity Analysis
The hash table is designed to achieve O(1) time complexity for insert, find, and delete operations. The use of open 
addressing with linear probing helps in resolving collisions efficiently. The hash function ensures uniform distribution
of keys, minimizing the chances of collisions.

- **Insert**: O(1) on average, O(n) in the worst-case scenario due to collisions.
- **Find**: O(1) on average, O(n) in the worst-case scenario due to collisions.
- **Remove**: O(1) on average, O(n) in the worst-case scenario due to collisions.

## Help
### Common Issues
- **Collision Handling**: Ensure that the hash function distributes keys uniformly.
- **Full Table**: Implement dynamic resizing to handle the scenario where the table is full.
- **Duplicate Keys**: Properly handle duplicate keys by updating the existing entry.

### Advice
- First try inserting and deleting on a small table.
- Test the hash table with a large dataset to ensure efficiency.

## Version History

## Honor Pledge
I hereby declare that the work presented in this project is my own and adheres to the honor code. Ethan Perry

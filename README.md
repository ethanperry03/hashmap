# Hash Table Implementation using Open Addressing in C++

## Author 
Ethan Perry

## Description
This project involves implementing a hash table using open addressing with linear probing in C++. The goal is to achieve 
constant-time complexity O(1) for insert, find, and delete operations. The program has a continuous input stream that
runs as you interact with the hash table. Each entry contains someones first and last name, phone number, and address.
The hash function works by summing the ascii values of the first and last name as the key input. By using a prime number
table size, the elements get distributed more evenly across the table. I also used Knuth's constant to aid at this
distribution across the table. There are several other menu options that are detailed below to gain insights and metrics
for the table.

## How to Run
1. **Compile the code:** Generate an executable to use the program
2. **Pre-input:** Select a table size and the program will find the next smallest prime number to initialize the table.
3. **Input Loop:** An input loop will constantly run as you choose options from the table. You can stop the program
by entering 'q'. **See below for explanation on each input**
4. **End Program:** After entering the character 'q', the program will end.
>-----------MENU------------------------\
  i - Insert new key by entering name, number, address. It will then be stored in the hash table.\
  l - Load a batch of entries from an input file csv file. CSV header should be Name, Phone Number, Address.\
  r - Remove an entry by entering the Name associated with that contact.\
  f - Find entry by contact name and then display entry information and index.\
  a - Display all entries in the table from the entire hash table. (Be cautious of large tables)\
  t - Get table information such as # of entries, collisions, table size, load factor, avg collisions per insertion \
  p - Change probing exponent (default is expo = 1 which is linear probing)\
  q - quit
>

## Sample input and output

```
Enter desired table size:10
 Table created with size of: 11

-----------MENU------------------------
i - Insert new key
l - Load entries from an input file
r - Remove entry by key
f - Find and display entry by key
a - Display all entries in the table
t - Get table information
p - Change probing exponent
q - quit
---------------------------------------
->l
 Input .csv file:contacts-1.csv
Table has been resized to 23
Table has been resized to 47
Table has been resized to 97
Table has been resized to 197
Table has been resized to 397
Table has been resized to 797
Table has been resized to 1597
Table has been resized to 3203
Table has been resized to 6421
Table has been resized to 12853
Table has been resized to 25717
Inserted 9897 entries from 'contacts-1.csv'


menu would print
->i
 Input first and last name:Christopher Thomas
 Enter phone number:e
 Enter Address:e
 Error in insertion: Christopher Thomas already exists as a key


menu would print
->f
 Input first and last name of key:Christopher Thomas
 ------------ 18816 --------------
Name: Christopher Thomas
Phone Number: 613-36-8870
Address: "661 Craig Extensions Apt. 750


menu would print
->t
 ------------ info ------------
Num of Elements: 9897
Table Size: 25717
Load Factor: 0.385
Num of Collisions: 35495
Average Collisions Before Insert: 3.6


menu would print
->r
 Input first and last name of key:Christopher Thomas
 Successfully removed Christopher Thomas at index 18816


menu would print
->i
 Input first and last name:Christopher Thomas
 Enter phone number:e
 Enter Address:e
 Christopher Thomas has been entered in the table at index 18816
 

menu would print
->q
 Thank you for using this hash table!
```

## Time Complexity Analysis
The hash table is designed to achieve O(1) time complexity for insert, find, and delete operations. The use of open 
addressing with linear probing helps in resolving collisions efficiently. The hash function ensures uniform distribution
of keys, minimizing the chances of collisions.

- **Insert**: O(1) on average, O(n) in the worst-case scenario due to collisions.
- **Find**: O(1) on average, O(n) in the worst-case scenario due to collisions.
- **Remove**: O(1) on average, O(n) in the worst-case scenario due to collisions.

## Help
- Ensure you enter input files correctly by name
- Ensure you spell first/last names correctly when trying to find given entry
- Testing different probing methods should yield slightly different output


## Version History
```
commit b37753dbd78bcf6b36d46fb096e21b4c92bca524 (HEAD -> main, origin/main)
Author: Ethan Perry <ethan.perry03@gmail.com>
Date:   Wed Feb 12 16:42:07 2025 -0500

    Created seperate menu helper file to unload main.cpp

commit fdffc5c34d1d12827496dda66f4f1c797ad96b12
Merge: 6283774 4c557f0
Author: Ethan Perry <ethan.perry03@gmail.com>
Date:   Wed Feb 12 13:20:02 2025 -0500

    Merged branches, tested more inputs

commit 4c557f0bea5cb3f2ee7c66637f650abfea83e17a
Author: Ethan Perry <ethan.perry03@gmail.com>
Date:   Wed Feb 12 13:11:16 2025 -0500

    Implemented probing change

commit 6283774df0f09de2c8af5bb8b13179677dc6e4c1
Author: Ethan Perry <ethan.perry03@gmail.com>
Date:   Wed Feb 12 12:50:43 2025 -0500

    Commiting before branching to work on probe

```

## Honor Pledge
I hereby declare that the work presented in this project is my own and adheres to the honor code. Ethan Perry
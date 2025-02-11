#include "helper.h"
using namespace std;

/** isPrime()
 * This function checks if the input number `n` is a prime number. It uses a series of
 * conditional checks and an optimized loop to eliminate non-prime numbers efficiently.
 * The function returns true if `n` is prime and false otherwise.
 *
 * @param n The number to be checked for primality.
 * @return bool True if the number is prime, false otherwise.
 */
bool isPrime(int n) {
    // Check for numbers less than or equal to 1
    if (n <= 1) {
        return false;
    }
    // Direct check for numbers 2 and 3
    if (n <= 3) {
        return true;
    }
    // Eliminate multiples of 2 and 3 to set up algorithm
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    // begin loop at 5 and check chunks of 6 long
    // ex: [5, 6, 7, 8, 9, 10]
    // the only elements that are not multiples of 2 or 3 are i = 0 and i = 2
    // since multiples of 2 and 3 were already weeded out, you just need to check
    // elements i = 0 and i = 2 every 6 integer chunk
    // you check this up until the sqrt(i) factor
    for (int i = 5; i * i <= n; i += 6) {
        // Check for factors
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    // If no factors found, n is prime
    return true;
}

/** findNextPrime()
 * This function checks if the input value is less than 2 and returns 2 as the next prime.
 * If the input is greater than 1, it increments the value until a prime number is found.
 * The function returns the next largest prime number greater than or equal to the input value.
 *
 * @param input The starting value to find the next prime number.
 * @return int The next prime number greater than or equal to the input value.
 */
int findNextPrime(int input) {
    // if input is less than 2, just return 2
    if (input <= 1) {
        return 2;
    }

    // increment
    int i = 0;
    // create a loop that runs until a prime is found
    // while input + i is not prime
    while (!isPrime(input + i)) {
        i++;
    }
    // return the next biggest prime
    return input + i;
}
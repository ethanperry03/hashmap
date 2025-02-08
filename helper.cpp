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



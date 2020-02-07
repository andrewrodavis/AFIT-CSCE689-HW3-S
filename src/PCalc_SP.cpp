#include <PCalc_SP.h>
#include <PCalc.h>
#include <iostream>
#include <math.h>

PCalc_SP::PCalc_SP(unsigned int arraySize) : PCalc(arraySize){}

/**
 * markNonPrimes: algorithm for finding primes up to the argument countTo
 *      Uses Sieve of Eratsthonesseses
 *
 * PCalc class has array size,
 */
void PCalc_SP::markNonPrimes() {
    // Square root for fast
    int squareRoot = sqrt(this->array_size());
    // Used for fast --> run with this in loop and "this->array_size()" to compare performance maybe
    int arraySize = this->array_size();

    // run through square root of arraySize
    for(int i = 0; i < squareRoot; i++){
        // Check value at i for true or false
        // If true, begin crossing out its multiples
        if(this->at(i)) {
            // Iterate through the list from i -> the size of the array
            //      i2, i2+i, i2+2i, i2+3i == just add i to each one
            // This is the current prime found that will be checked
            int checkValue = i * i;
            for (int j = i; j < this->array_size(); j++) {
                // Switch flag
                this->at(checkValue) = false;

                // add i to the check value
                checkValue = checkValue + i;
            }
        }
        // If false, it is not a prime, continue
        else{
            continue;
        }
    }

}

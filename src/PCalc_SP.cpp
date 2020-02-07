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

    // Mark 0 and 1 as false to not include in list
    this->at(0) = this->at(1) = false;

    // Need array of bool values --> this->at(i). Assume the first element here is 2?
    // Iterate over the list until square root of array_size
    for(int i = 2; i < squareRoot; i++){
        // if the current value is true,
        if(this->at(i)){
            // It is a prime, begin marking its multiples as false
            // Iterate from the i^2 to the end of the array list
            // Get i * i as value
            int currentPrime = i * i;
            while(currentPrime < arraySize){
                this->at(currentPrime) = false;
                currentPrime = currentPrime + i;
            }
        }
    }
}

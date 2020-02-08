#include <PCalc_SP.h>
#include <PCalc.h>
#include <PCalc_T.h>
#include <math.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

PCalc_T::PCalc_T(unsigned int arraySize, unsigned int num_threads) : PCalc(arraySize){
    this->numThreads = num_threads;
}


/**
 * markNonPrimes: This is the entry point into the multi-threaded version of PCalc_SP
 *      Uses Sieve of Eratsthonesseses
 *
 */
void PCalc_T::markNonPrimes() {
    // Mark 0 and 1 as false to not include in list
    this->at(0) = this->at(1) = false;

    std::vector<std::thread> threads;

    for(int i = 0; i < this->numThreads; i++){
//        threads.push_back( std::thread(&PCalc_T::sieveOfErat, this));
        threads.push_back( std::thread(&PCalc_T::sieveOfErat, this, this->firstMPrimes[i] ));
    }

    for(auto &t : threads){
        t.join();
    }
}

/**
 * siveOfErat: The actual algorithm to run
 *
 * @param number
 * @return
 */
int PCalc_T::sieveOfErat(int start) {
    // For faster access
    long int arraySize = this->array_size();
    long int squareRoot = sqrt(this->array_size());
    bool * primeNumber = &at(0);

    for(long int i = start; i < squareRoot; i++){
        // If the current value is true...
        if(primeNumber[i]){
//        if(this->at(i)){
            // ...then it is a prime. Begin
            long int currentPrime = i * i;

            // Mark all its multiples
            while(currentPrime < arraySize){
                primeNumber[i] = false;
//                this->at(currentPrime) = false;
                currentPrime = currentPrime + i;
            }
        }
    }
}
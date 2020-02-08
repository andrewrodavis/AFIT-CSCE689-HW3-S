#ifndef PCALC_T_H
#define PCALC_T_H

#include "PCalc.h"
#include <vector>

// Your implementation of PCalc_T class should go here. 
// Make sure your constructor takes in two parameters:

// PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads);

// Call the parent constructor when initializing your constructor and pass in array_size. Then
// use num_threads to cap off how many threads you use to calculate all prime numbers
class PCalc_T : public PCalc{
public:
    PCalc_T(unsigned int array_size, unsigned int num_threads);

    // Sieve Algorithm
    void markNonPrimes();
    int sieveOfErat(int start);

private:
    int numThreads;
    std::vector<long int> firstMPrimes = {2,3,5,7,11,
                                     13,17,19,23,29,
                                     31,37,41,43,47,
                                     53,59,61,67,71,
                                     73,79,83,89,97,
                                     101,103,107,109,113,
                                     127,131,137,139,149,
                                     151,157,163,167,173,
                                     179,181,191,193,197,
                                     199,211,223,227,229};
};

#endif

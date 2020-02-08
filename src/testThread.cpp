//
// Created by daviandr on 2/7/20.
//

#include "testThread.h"
#include <thread>
#include <vector>
#include <iostream>
#include "testThread.h"

int testThread::sieve(int id){
    std::cout << "Launched by thread " << id << "\n";
}

void testThread::manage(int numT) {
    for(int i = 0; i < numT; i++){
        this->th.push_back( std::thread(this->sieve, i) );
    }
}
//
// Created by daviandr on 2/7/20.
//

#ifndef AFIT_CSCE689_HW3_S_TESTTHREAD_H
#define AFIT_CSCE689_HW3_S_TESTTHREAD_H

#include <thread>
#include <vector>

class testThread {
public:
    std::vector<std::thread> th;

    int sieve(int id);
    void manage(int numT);
};


#endif //AFIT_CSCE689_HW3_S_TESTTHREAD_H

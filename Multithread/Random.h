#ifndef MULTITHREAD_RANDOM_H
#define MULTITHREAD_RANDOM_H

#include <cstdlib>

int Random() {
    return rand() % 100 + 1;
}

#endif //MULTITHREAD_RANDOM_H

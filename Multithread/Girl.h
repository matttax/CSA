#ifndef MULTITHREAD_GIRL_H
#define MULTITHREAD_GIRL_H


#include <pthread.h>
#include "Guy.h"

class Girl {
public:
    explicit Girl(int n);
    ~Girl();
    void selectGuy();

private:
    Guy *guys; // Динамический массив поклонников.
    Guy *selected_guy; // Выбранный поклонник.
    int N; // Количество поклонников.
};


#endif //MULTITHREAD_GIRL_H

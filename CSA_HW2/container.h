#include "shape.h"

#ifndef CSA_HW2_CONTAINER_H
#define CSA_HW2_CONTAINER_H


class container {
private:
    void clear();
    int len;
    shape *storage[10000];
public:
    container();
    ~container();

    void in(ifstream &ifst);
    void in_rand(int size);
    void out(ofstream &ofst);
    void straightsel_sort();
};

#endif //CSA_HW2_CONTAINER_H

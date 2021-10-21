#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef CSA_HW2_REGTET_H
#define CSA_HW2_REGTET_H


class regtet : public shape {
private:
    int edge;
public:
    virtual ~regtet() {}
    virtual void in(ifstream &ifdt);
    virtual void in_rand();
    virtual void out(ofstream &ofst);
    virtual double sq_surf();
};

#endif //CSA_HW2_REGTET_H

#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef CSA_HW2_PARALLELEPIPED_H
#define CSA_HW2_PARALLELEPIPED_H


class parallelepiped : public shape {
private:
    int a, b, c;
public:
    virtual ~parallelepiped() {}
    virtual void in(ifstream &ifdt);
    virtual void in_rand();
    virtual void out(ofstream &ofst);
    virtual double sq_surf();
};

#endif //CSA_HW2_PARALLELEPIPED_H

#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef CSA_HW2_SPHERE_H
#define CSA_HW2_SPHERE_H


class sphere : public shape {
private:
    int r;
public:
    virtual ~sphere() {}
    virtual void in(ifstream &ifdt);
    virtual void in_rand();
    virtual void out(ofstream &ofst);
    virtual double sq_surf();
};


#endif //CSA_HW2_SPHERE_H

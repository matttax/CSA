#include <fstream>

using namespace  std;

#ifndef CSA_HW2_SHAPE_H
#define CSA_HW2_SHAPE_H

class shape {
public:
    virtual ~shape() {};
    static shape *static_in(ifstream &ifst);
    static shape *static_in_rand();
    virtual void in(ifstream &ifst) = 0;
    virtual void in_rand() = 0;
    virtual void out(ofstream &ofst) = 0;
    virtual double sq_surf() = 0;
};

#endif //CSA_HW2_SHAPE_H

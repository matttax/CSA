#include "parallelepiped.h"

void parallelepiped::in(ifstream &ifdt) {
    ifdt >> a >> b >> c;
}

void parallelepiped::in_rand() {
    a = random20();
    b = random20();
    c = random20();
}

double parallelepiped::sq_surf() {
    return double(2 * (a * b + b * c + c * a));
}

void parallelepiped::out(ofstream &ofst) {
    ofst << "It is Parallelepiped: a = " << a
    << ", b = " << b
    << ", c = " << c
    << ". Surface square = " << parallelepiped::sq_surf() << endl;
}
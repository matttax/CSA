#include "sphere.h"
#include "math.h"

void sphere::in(ifstream &ifdt) {
    ifdt >> r;
}

void sphere::in_rand() {
    r = random20();
}

double sphere::sq_surf() {
    return double(4 * M_PI * r * r);
}

void sphere::out(ofstream &ofst) {
    ofst << "It is Sphere: r = " << r
    << ". Surface square = " << sphere::sq_surf() << endl;
}
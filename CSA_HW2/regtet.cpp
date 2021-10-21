#include "regtet.h"
#include "math.h"

void regtet::in(ifstream &ifdt) {
    ifdt >> edge;
}

void regtet::in_rand() {
    edge = random20();
}

double regtet::sq_surf() {
    return double(edge * edge * sqrt(3));
}

void regtet::out(ofstream &ofst) {
    ofst << "It is Regular Tetrahedron: edge = " << edge
    << ". Surface square = " << regtet::sq_surf() << endl;
}
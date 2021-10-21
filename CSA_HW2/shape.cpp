#include "shape.h"
#include "regtet.h"
#include "parallelepiped.h"
#include "sphere.h"
#include "rand.h"

shape *shape::static_in(ifstream &ifst) {
    shape* sh;
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            sh = new sphere;
            break;
        case 2:
            sh = new parallelepiped;
            break;
        case 3:
            sh = new regtet;
            break;
    }
    sh->in(ifst);
    return sh;
}

shape *shape::static_in_rand() {
    int k = random20();
    shape* sh;
    switch (k) {
        case 1:
            sh = new sphere;
            break;
        case 2:
            sh = new parallelepiped;
            break;
        case 3:
            sh = new regtet;
            break;
    }
    sh->in_rand();
    return sh;
}
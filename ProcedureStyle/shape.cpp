// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры и создания произвольной фигуры

#include "shape.h"
#include "parallelepiped.h"
#include "regtet.h"
#include "sphere.h"

// Ввод параметров обобщенной фигуры из файла
shape* in(ifstream& ifst) {
    shape* sh;
    int k;
    ifst >> k;
    switch (k) {
    case 1:
        sh = new shape;
        sh->k = shape::SPHERE;
        in(sh->sph, ifst);
        if (sh->sph.r <= 0) {
            return 0;
        }
        return sh;
    case 2:
        sh = new shape;
        sh->k = shape::PARALLELEPIPED;
        in(sh->p, ifst);
        if (sh->p.a <= 0 || sh->p.b <= 0 || sh->p.c <= 0) {
            return 0;
        }
        return sh;
    case 3:
        sh = new shape;
        sh->k = shape::REGTET;
        in(sh->rt, ifst);
        if (sh->rt.edge <= 0) {
            return 0;
        }
        return sh;
    default:
        return 0;
    }
}

// Случайный ввод обобщенной фигуры
shape* in_rand() {
    shape* sh;
    auto k = rand() % 3 + 1;
    switch (k) {
    case 1:
        sh = new shape;
        sh->k = shape::SPHERE;
        in_rand(sh->sph);
        return sh;
    case 2:
        sh = new shape;
        sh->k = shape::PARALLELEPIPED;
        in_rand(sh->p);
        return sh;
    case 3:
        sh = new shape;
        sh->k = shape::REGTET;
        in_rand(sh->rt);
        return sh;
    default:
        return 0;
    }
}

// Вывод параметров текущей фигуры в поток
void out(shape& sh, ofstream& ofst) {
    switch (sh.k) {
    case shape::SPHERE:
        out(sh.sph, ofst);
        break;
    case shape::PARALLELEPIPED:
        out(sh.p, ofst);
        break;
    case shape::REGTET:
        out(sh.rt, ofst);
        break;
    default:
        ofst << "Incorrect figure!" << endl;
    }
}

// Вычисление площади поверхности фигуры
double surf_sq(shape& sh) {
    switch (sh.k) {
    case shape::SPHERE:
        return surf_sq(sh.sph);
        break;
    case shape::PARALLELEPIPED:
        return surf_sq(sh.p);
        break;
    case shape::REGTET:
        return surf_sq(sh.rt);
        break;
    default:
        return 0.0;
    }
}

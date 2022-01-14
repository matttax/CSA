// sphere.cpp - содержит методы параллелепипеда

#include "sphere.h"
#include "math.h"

// Ввод параметров сферы из файла
void sphere::in(ifstream &ifdt) {
    ifdt >> r;
}

// Случайная генерация параметров сферы
void sphere::in_rand() {
    r = random20();
}

// Вычисление площади поверхности сферы
double sphere::sq_surf() {
    return double(4 * M_PI * r * r);
}

// Вывод параметров сферы в поток
void sphere::out(ofstream &ofst) {
    ofst << "It is Sphere: r = " << r
    << ". Surface square = " << sphere::sq_surf() << endl;
}

// parallelepiped.cpp - содержит методы параллелепипеда

#include "parallelepiped.h"

// Ввод параметров параллелепипеда из файла
void parallelepiped::in(ifstream &ifdt) {
    ifdt >> a >> b >> c;
}

// Случайная генерация параметров параллелепипеда
void parallelepiped::in_rand() {
    a = random20();
    b = random20();
    c = random20();
}

// Вычисление площади поверхности параллелепипеда
double parallelepiped::sq_surf() {
    return double(2 * (a * b + b * c + c * a));
}

// Вывод параметров параллелепипеда в поток
void parallelepiped::out(ofstream &ofst) {
    ofst << "It is Parallelepiped: a = " << a
    << ", b = " << b
    << ", c = " << c
    << ". Surface square = " << parallelepiped::sq_surf() << endl;
}

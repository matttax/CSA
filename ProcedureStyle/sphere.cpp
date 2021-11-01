// sphere.cpp - содержит функции обработки шара

#include "sphere.h"

#define PI 3.14159

// Ввод параметров шара из потока
void in(sphere& sph, ifstream& ifst) {
    ifst >> sph.r;
}

// Случайный ввод параметров шара
void in_rand(sphere& sph) {
    sph.r = Random();
}

// Вывод параметров шара в поток
void out(sphere& sph, ofstream& ofst) {
    ofst << "It is Sphere: r = " << sph.r << ". Surface square = " << surf_sq(sph) << endl;
}

// Вычисление площади поверхности шара
double surf_sq(sphere& sph) {
    return double(4 * PI * sph.r * sph.r);
}

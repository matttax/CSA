#ifndef __sphere__
#define __sphere__

// sphere.h - содержит описание шара

#include <fstream>
using namespace std;

#include "rand.h"

// Шар
struct sphere {
    int r; // радиус
};

// Ввод параметров шара из файла
void in(sphere& sph, ifstream& ifst);

// Случайный ввод параметров шара
void in_rand(sphere& sph);

// Вывод параметров шара в форматируемый поток
void out(sphere& sph, ofstream& ofst);

// Вычисление площади поверхности шара
double surf_sq(sphere& sph);

#endif //__sphere__

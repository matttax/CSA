#ifndef __parallelepiped__
#define __parallelepiped__

// parallelepiped.h - содержит описание параллелепипеда

#include <fstream>
using namespace std;

#include "rand.h"

// Параллелепипед
struct parallelepiped {
    int a, b, c; // рёбра
};

// Ввод параметров параллелепипеда из файла
void in(parallelepiped& p, ifstream& ifst);

// Случайный ввод параметров параллелепипеда
void in_rand(parallelepiped& p);

// Вывод параметров параллелепипеда в форматируемый поток
void out(parallelepiped& p, ofstream& ofst);

// Вычисление площади поверхности параллелепипеда
double surf_sq(parallelepiped& p);

#endif //__parallelepiped__

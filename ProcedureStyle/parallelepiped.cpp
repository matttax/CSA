// parallelepiped.cpp - содержит функции обработки параллелепипеда

#include "parallelepiped.h"

// Ввод параметров параллелепипеда из потока
void in(parallelepiped& t, ifstream& ifst) {
    ifst >> t.a >> t.b >> t.c;
}

// Случайный ввод параметров параллелепипеда
void in_rand(parallelepiped& t) {
    t.a = Random();
    t.b = Random();
    t.c = Random();
}

// Вывод параметров параллелепипеда в поток
void out(parallelepiped& t, ofstream& ofst) {
    ofst << "It is Parallelepiped: a = " << t.a << ", b = " << t.b << ", c = " << t.c << ". Surface square = " << surf_sq(t) << endl;
}

// Вычисление площади поверхности параллелепипеда
double surf_sq(parallelepiped& t) {
    return double(2 * (t.a * t.b + t.b * t.c + t.c * t.a));
}

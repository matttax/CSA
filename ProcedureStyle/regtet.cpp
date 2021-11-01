// triangle.cpp - содержит функции обработки правильного тэтраэдра

#include "regtet.h"
#define SQRT3 1.73205081

// Ввод параметров правильного тэтраэдра из потока
void in(regtet& rt, ifstream& ifst) {
    ifst >> rt.edge;
}

// Случайный ввод параметров правильного тэтраэдра
void in_rand(regtet& rt) {
    rt.edge = Random();
}

// Вывод параметров правильного тэтраэдра в поток
void out(regtet& rt, ofstream& ofst) {
    ofst << "It is Regular Tetrahedron: edge = " << rt.edge << ". Surface square = " << surf_sq(rt) << endl;
}

// Вычисление площади поверхности правильного тэтраэдра
double surf_sq(regtet& rt) {
    return double(rt.edge * rt.edge * SQRT3);
}

// rectangle.cpp - содержит методы правильного тетраэдра

#include "regtet.h"
#include "math.h"

// Ввод параметров правильного тетраэдра из файла
void regtet::in(ifstream &ifdt) {
    ifdt >> edge;
}

// Случайная генерация параметров правильного тетраэдра
void regtet::in_rand() {
    edge = random20();
}

// Вычисление площади поверхности правильного тетраэдра
double regtet::sq_surf() {
    return double(edge * edge * sqrt(3));
}

// Вывод параметров правильного тетраэдра в поток
void regtet::out(ofstream &ofst) {
    ofst << "It is Regular Tetrahedron: edge = " << edge
    << ". Surface square = " << regtet::sq_surf() << endl;
}

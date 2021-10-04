#ifndef __regtet__
#define __regtet__

// regtet.h - содержит описание шара

#include <fstream>
using namespace std;

#include "rand.h"

// Праильный тетраэдр
struct regtet {
    int edge; // ребро
};

// Ввод параметров праильного тетраэдра из файла
void in(regtet& rt, ifstream& ifst);

// Случайный ввод параметров праильного тетраэдра
void in_rand(regtet& rt);

// Вывод параметров праильного тетраэдра в форматируемый поток
void out(regtet& rt, ofstream& ofst);

// Вычисление площади поверхности праильного тетраэдра
double surf_sq(regtet& rt);

#endif //__regtet__

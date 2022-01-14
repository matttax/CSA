// parallelepiped.h - содержит описание параллелепипеда и его интерфейса

#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef __parallelepiped__
#define __parallelepiped__


class parallelepiped : public shape {
private:
    int a, b, c; // Длина, ширина, высота
public:
    virtual ~parallelepiped() {}

    // Ввод параметров параллелепипеда из файла
    virtual void in(ifstream &ifdt);

    // Случайная генерация параметров параллелепипеда
    virtual void in_rand();

    // Вывод параметров параллелепипеда в поток
    virtual void out(ofstream &ofst);

    // Вычисление площади поверхности параллелепипеда
    virtual double sq_surf();
};

#endif //__parallelepiped__

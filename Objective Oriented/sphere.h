// sphere.h - содержит описание сферы и её интерфейса

#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef __sphere__
#define __sphere__


class sphere : public shape {
private:
    int r; // Радиус
public:
    virtual ~sphere() {}

    // Ввод параметров сферы из файла
    virtual void in(ifstream &ifdt);

    // Случайная генерация параметров сферы
    virtual void in_rand();

    // Вывод параметров сферы в поток
    virtual void out(ofstream &ofst);

    // Вычисление площади поверхности сферы
    virtual double sq_surf();
};

#endif //__sphere__

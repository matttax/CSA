// shape.h - содержит описание обобщающей трёхмерной фигуры

#include <fstream>

using namespace  std;

#ifndef __shape__
#define __shape__

// Класс shape обобщает все имеющиеся фигуры
class shape {
public:
    virtual ~shape() {};

    // Ввод обобщенной фигуры
    static shape *static_in(ifstream &ifst);

    // Случайный ввод обобщенной фигуры
    static shape *static_in_rand();

    // Виртуальный метод ввода обобщенной фигуры
    virtual void in(ifstream &ifst) = 0;

    // Виртуальный метод ввода случайной фигуры
    virtual void in_rand() = 0;

    // Виртуальный метод вывода обобщенной фигуры
    virtual void out(ofstream &ofst) = 0;

    // Вычисление площади поверхности обобщенной фигуры
    virtual double sq_surf() = 0;
};

#endif //__shape__

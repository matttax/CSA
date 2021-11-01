#ifndef __shape__
#define __shape__

// shape.h - содержит описание обобщающей геометрической фигуры

#include "parallelepiped.h"
#include "regtet.h"
#include "sphere.h"

// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {
        SPHERE,
        PARALLELEPIPED,
        REGTET
    };
    key k; // ключ
    double density; // используемая альтернатива
    union { // используем простейшую реализацию
        sphere sph;
        parallelepiped p;
        regtet rt;
    };
};

// Ввод обобщенной фигуры
shape* in(ifstream& ifdt);

// Случайный ввод обобщенной фигуры
shape* in_rand();

// Вывод обобщенной фигуры
void out(shape& sh, ofstream& ofst);

// Вычисление площади поверхности обобщенной фигуры
double surf_sq(shape& sh);

#endif //__shape__

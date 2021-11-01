#ifndef __container__
#define __container__

// container.h - содержит тип данных, представляющий простейший контейнер

#include "shape.h"

// Простейший контейнер на основе одномерного массива
struct container {
    enum { 
        max_len = 10000 
    }; // максимальная длина
    int len; // текущая длина
    shape* cont[max_len];
};

// Инициализация контейнера
void init(container& c);

// Очистка контейнера от элементов (освобождение памяти)
void clear(container& c);

// Ввод содержимого контейнера из указанного потока
void in(container& c, ifstream& ifst);

// Случайный ввод содержимого контейнера
void in_rand(container& c, int size);

// Вывод содержимого контейнера в указанный поток
void out(container& c, ofstream& ofst);

// Сортировка фигур в контейнере по убыванию
void straightsel_sort(container& c);

#endif //__container__

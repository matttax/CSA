// container.cpp - содержит функции обработки контейнера

#include "container.h"
#include "shape.h"

// Инициализация контейнера
void init(container& c) {
    c.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void clear(container& c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

// Ввод содержимого контейнера из указанного потока
void in(container &c, ifstream &ifst) {
    while(!ifst.eof()) {
        c.cont[c.len] = in(ifst);
        if(c.cont[c.len] != 0) {
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void in_rand(container& c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = in_rand()) != nullptr) {
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void out(container& c, ofstream& ofst) {
    ofst << "Container contains " << c.len << " elements. " << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        out(*(c.cont[i]), ofst);
    }
}

// Сортировка фигур в контейнере по убыванию
void straightsel_sort(container& c) {
    int min;
    shape temp;
    for (int i = 0; i < c.len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < c.len; j++)
        {
            if (surf_sq(*c.cont[j]) < surf_sq(*c.cont[min]))
                min = j;
        }
        temp = *c.cont[i];
        *c.cont[i] = *c.cont[min];
        *c.cont[min] = temp;
    }
}

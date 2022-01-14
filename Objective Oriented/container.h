// container.h содержит тип данных, представляющий контейнер

#include "shape.h"

#ifndef __container__
#define __container__

// Контейнер на основе одномерного массива
class container {
private:
    int len;
    shape *storage[10000];
public:
    container();
    ~container();

    // Ввод содержимого контейнера из указанного потока
    void in(ifstream &ifst);

    // Случайный ввод содержимого контейнера
    void in_rand(int size);

    // Вывод содержимого контейнера в указанный поток
    void out(ofstream &ofst);

    // Сортировка контейнера прямым выбором
    void straightsel_sort();
};

#endif //__container__

// regtet.h - содержит описание правильного тетраэдра и его интерфейса

#include "rand.h"
#include "shape.h"

using namespace std;

#ifndef __regtet__
#define __regtet__


class regtet : public shape {
private:
    int edge; // Сторона
public:
    virtual ~regtet() {}

    // Ввод параметров правильного тетраэдра из файла
    virtual void in(ifstream &ifdt);

    // Случайная генерация параметров правильного тетраэдра
    virtual void in_rand();

    // Вывод параметров правильного тетраэдра в поток
    virtual void out(ofstream &ofst);

    // Вычисление площади поверхности правильного тетраэдра
    virtual double sq_surf();
};

#endif //__regtet__

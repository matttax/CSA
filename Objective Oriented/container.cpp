// container.cpp - содержит функции обработки контейнера

#include "container.h"
#include "shape.h"

// Конструктор
container::container(): len(0) {}

// Деструктор контейнера: очищает его от всех элементов
container::~container() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

// Ввод содержимого контейнера из указанного потока
void container::in(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = shape::static_in(ifst)) != 0) {
            len++;
        }
    }
    len -= 1;
}


// Случайная генерация содержимого контейнера
void container::in_rand(int size) {
    while(len < size) {
        if((storage[len] = shape::static_in_rand()) != nullptr) {
            len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void container::out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->out(ofst);
    }
}

// Сортировка контейнера прямым выбором
void container::straightsel_sort() {
    int min;
    for (int i = 0; i < len - 1; i++) {
        min = i;
        for (int j = i + 1; j < len; j++) {
            if (storage[j]->sq_surf() < storage[min]->sq_surf())
                min = j;
        }
        std::swap(storage[i], storage[min]);
    }
}

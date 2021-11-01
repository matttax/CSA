// main.cpp - содержит главную функцию, обеспечивающую простое тестирование

#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1() {
    printf("Incorrect command line!\n");
    printf("Waited: command -f infile outfile01 outfile02\n");
    printf("    or: command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("Incorrect qualifier value!\n");
    printf("Waited: command -f infile outfile01 outfile02\n");
    printf("    or: command -n number outfile01 outfile02\n");
}

int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start");
    container c;
    init(c);


    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        in(c, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            printf("Incorrect numer of figures. Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        in_rand(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container: " << endl;
    out(c, ofst1);

    // Сортировка
    straightsel_sort(c);
    ofstream ofst2(argv[4]);
    ofst2 << "Sorted container: " << endl;
    out(c, ofst2);

    clear(c);
    printf("Stop");
    return 0;
}

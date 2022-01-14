#include <iostream>
#include "container.h"
#include "string.h"

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
        std::cout << argc;
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;

    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c.in(ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("Incorrect number of figures. Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.in_rand(size);
    }
    else {
        errMessage2();
        return 2;
    }

    ofstream ofst1(argv[3]);
    ofst1 << "Filled container: " << endl;
    c.out(ofst1);

    // Сортировка
    c.straightsel_sort();
    ofstream ofst2(argv[4]);
    ofst2 << "Sorted container: " << endl;
    c.out(ofst2);

    printf("Stop\n");
    return 0;
}

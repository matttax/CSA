#include <iostream>
#include "Girl.h"

int main(int argc, char *argv[]) {
    int n;
    // Пользователь может как указать количество поклонников в аргументах командной строки,
    // так и ввести вручную.
    if (argc != 2) {
        std::cout << "Number of guys:\n";
        std::cin >> n;
    } else {
        n = std::stoi(argv[1]);
    }
    if (n < 0 || n > 10000) {
        std::cout << "Invalid N! Should be from 0 to 10000";
        return 0;
    }
    Girl g(n);
    g.selectGuy();
    return 0;
}

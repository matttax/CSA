#include <iostream>
#include <unistd.h>
#include "Girl.h"

Girl::Girl(int n) {
    guys = new Guy[n];
    selected_guy = nullptr;
    N = n;
}

Girl::~Girl() {
    delete[] guys;
}

void Girl::selectGuy() {
    // Происходит активация всех потоков, каждый поклонник отправляет своё сообщение.
    for (int i = 0; i < N; i++) {
        guys[i].number = i + 1;
        guys[i].start();
    }
    int index = -1;
    // Девушка выбирает подходящего (им окажется первый рандомно попавшийся, с сообщением длиннее, чем 50 знаков)
    do {
        index = rand() % N;
        Guy maybe = guys[index];
        selected_guy = (maybe.message.length() > 50) ? &maybe : nullptr;
    } while (!selected_guy);
    selected_guy->is_chosen = true;
    sleep(1);
    std:: cout << "She picked guy number " << selected_guy->number << "\n";
}
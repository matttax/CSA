#include <iostream>
#include "Guy.h"
#include "Random.h"

Guy::Guy() {
    smartness = Random();
    is_chosen = false;
}

Guy::~Guy() = default;

// Запуск потока.
int Guy::start () {
    return pthread_create(&thread_id, nullptr, Guy::thread_func, this );
}

// Ожидание.
int Guy::wait () const {
    return pthread_join(thread_id, nullptr );
}

// Генерация и вывод сообщения защищены двоичным семафором.
void Guy::run () {
    pthread_mutex_lock(&mutex);
    message = create_message();
    std::string str = "Guy number " + std::to_string(number) + " wrote: \"" + message + "\"\n";
    std::cout << str;
    pthread_mutex_unlock(&mutex);
    wait();
}

// Создаётся сообщение исходя из умственных способностей поклонника.
std::string Guy::create_message() const {
    std::string symbols = "qwertyuiopasdfghjklzxcvbnm1234567890!?";
    std::string msg;
    for (int i = 0; i < smartness; i++) {
        msg += symbols[Random() % symbols.length()];
    }
    return msg;
}
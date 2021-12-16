#ifndef MULTITHREAD_GUY_H
#define MULTITHREAD_GUY_H

#include <pthread.h>
#include <string>

class Guy {
public:
    Guy();
    ~Guy();
    std::string message; // Сообщение на валентинке.
    int start(); // Запуск потока.
    int wait() const; // Ожидание.
    void run();
    bool is_chosen; // Был ли он выбран.
    int number; // Порядковый номер.

private:
    int smartness; // Умственные способности.
    std::string create_message() const;
    pthread_t thread_id{};
    static void* thread_func(void* d) { // Функция потока.
        (static_cast <Guy*>(d))->run();
        return nullptr;
    }
    pthread_mutex_t mutex; // Мьютекс, двоичный семафор.
};


#endif //MULTITHREAD_GUY_H

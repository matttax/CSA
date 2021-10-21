#ifndef __rand__
#define __rand__

#include <cstdlib>

// rand.h - содержит генератор случайных чисел в диапазоне от 1 до 20

inline auto random20() {
    return rand() % 20 + 1;
}

#endif //__rand__

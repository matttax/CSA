#include "container.h"
#include "shape.h"

container::container(): len(0) {}

container::~container() {
    clear();
}

void container::clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

void container::in(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = shape::static_in(ifst)) != 0) {
            len++;
        }
    }
    len -= 1;
}

void container::in_rand(int size) {
    while(len < size) {
        if((storage[len] = shape::static_in_rand()) != nullptr) {
            len++;
        }
    }
}

void container::out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->out(ofst);
    }
}

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
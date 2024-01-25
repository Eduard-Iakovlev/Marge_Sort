#include "Windows.h"
#include "Array.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (true) {
        Array* array = new Array;
        array->print_begin();
        array->print();
        array->sort_arr();
        array->print_end();
        array->print();
        if (array->menu() == 1) break;
        delete array;
    }
}
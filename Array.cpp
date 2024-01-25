#include "Array.h"
#include "Data.h"
#include <iostream>


Array::Array(){
    Length length;
    _length = length.length();

    for (int i = 0; i < _length; i++)
        _arr.push_back(rand() % (_end - _start + 1) + _start);
}

Array::~Array(){
    _arr.clear();
}

void Array::print(){
    for (int i = 0; i < _arr.size(); i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

void Array::print_begin(){
    std::cout << "\n Исходный массив: \n";
}

void Array::print_end(){
    std::cout << " Отсортированный массив: \n";
}

void Array::sort_arr(){
    MSort sort;
    sort.merge_sort(&_arr, 0, _arr.size() - 1);
}

int Array::menu(){
    Data<int> data('1', '2');
    while (true) {
        std::cout << "\n Выберите действие:\n";
        std::cout << " 1 - Выход\n";
        std::cout << " 2 - Выбрать другую длину массива\n -> ";
        _menu = data.input();
        if (_menu > 2) {
            system("cls");
            data.clear();
            std::cout << " Не верный ввод\n Введите номер номер соответствующий действию:\n";
            continue;
        }
        else break;
    }
    return _menu;
}

#include "MSort.h"
#include <thread>
#include <future>

MSort::MSort() {}

MSort::~MSort(){}

void MSort::merge(std::vector<int>* arr, int l, int m, int r) {
    int nl = m - l + 1;
    int nr = r - m;

    // создаем временные массивы
    int* left = new int[nl];
    int* right = new int[nr];

    // копируем данные во временные массивы
     tmp_arr(*arr, left, nl, l);
     tmp_arr(*arr, right, nr, m + 1);

    int i = 0, j = 0;
    int k = l;  // начало левой части

    while (i < nl && j < nr) {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j]) {
            arr->at(k) = left[i];
            i++;
        }
        else {
            arr->at(k) = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl) {
        arr->at(k) = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr) {
        arr->at(k) = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;

}

void MSort::merge_sort(std::vector<int>* arr, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2; 
        std::thread left(std::bind(&MSort::merge_sort, this, std::ref(arr), l, m));
        std::thread right(std::bind(&MSort::merge_sort, this, std::ref(arr), m + 1, r));
        left.join();
        right.join();

        merge(arr, l, m, r);

    }
}

void MSort::tmp_arr(std::vector<int>& arrv ,int* arr_tmp, int length, int begin){
    for (int i = 0; i < length; i++)
        arr_tmp[i] = arrv[begin + i];
}

void MSort::tmp_arr_parallel(std::vector<int>* arr, int* arr_tmp, int length, int begin, std::promise<void>&& promise){
    tmp_arr(*arr, arr_tmp, length, begin);
    promise.set_value();
}



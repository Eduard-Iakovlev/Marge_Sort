#pragma once
#include <vector>


class MSort{
public:
	MSort();
	~MSort();
	void merge(std::vector<int>* arr, int l, int m, int r);
	void merge_sort(std::vector<int>* arr, int l, int r);
	void tmp_arr(std::vector<int>* arrv, int* arr_tmp[], int length, int begin);
private:

};


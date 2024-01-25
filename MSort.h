#pragma once
#include <vector>


class MSort{
public:
	MSort();
	~MSort();
	void merge(std::vector<int>* arr, int l, int m, int r);
	void merge_sort(std::vector<int>* arr, int l, int r);
};


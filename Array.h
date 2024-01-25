#pragma once
#include "MSort.h"
#include "Length.h"


class Array{
public:
	Array();
	~Array();
	void print();
	void print_begin();
	void print_end();
	void sort_arr();
	int menu();
private:
	std::vector<int> _arr;
	int _length = 0;
	int _start = -99;
	int _end = 99;
	int _menu = 0;
};


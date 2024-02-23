#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class SmartSearchLab {
private:
	vector<T> arr;
	vector<T> generateIntArray(int size);
	int binarySearch(int low, int high, T target);
public:
	SmartSearchLab();
	SmartSearchLab(int size);
	SmartSearchLab(vector<T> arr);
	void sort();
	void shuffle();
	int binarySearch(T target);
	void print();
	int linearSearch(T target);
};

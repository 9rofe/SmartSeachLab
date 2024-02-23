#include "SmartSearchLab.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

template<typename T>
SmartSearchLab<T>::SmartSearchLab() {
	generateIntArray(10);
}

template<typename T>
SmartSearchLab<T>::SmartSearchLab(int size) {
	try {
		if (size < 5) {
			throw invalid_argument("Size must be at least 5");
		}
		// Initialize array with randomized values
		arr = generateIntArray(size);
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
}

template<typename T>
SmartSearchLab<T>::SmartSearchLab(vector<T> arr) : arr(arr) {
}

template<typename T>
vector<T> SmartSearchLab<T>::generateIntArray(int size) {
	vector<T> tempArr;
	for (int i = 0; i < size - 1; i++)
	{
		tempArr.push_back(i);
	}
	return tempArr;
}

template<typename T>
void SmartSearchLab<T>::sort() {
	sort(arr.begin(), arr.end());
}

template<typename T>
void SmartSearchLab<T>::shuffle() {
	random_shuffle(arr.begin(), arr.end());
}

template<typename T>
int SmartSearchLab<T>::binarySearch(T target) {
	return binarySearch(0, arr.size(), target);
}

template<typename T>
int SmartSearchLab<T>::binarySearch(int low, int high, T target) {
	if (high < low) {
		cout << "ITEM NOT FOUND" << endl;
		return 1;
	}
	int mid = low + (high - low) / 2;
	if (arr[mid] == target) {
		cout << "FOUND at index " << mid << endl;
		return 1;
	}
	else if (arr[mid] > target) {
		cout << "NOT FOUND at index " << mid << endl;
		return binarySearch(low, mid - 1, target) + 1;
	}
	else {
		cout << "NOT FOUND at index " << mid << endl;
		return binarySearch(mid + 1, high, target) + 1;
	}
}

template<typename T>
void SmartSearchLab<T>::print() {
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

template<typename T>
int SmartSearchLab<T>::linearSearch(T target) {
	int checks = 0;
	for (int i = 0; i < arr.size(); i++) {
		checks++;
		if (arr[i] == target) {
			cout << "FOUND at index " << i << endl;
			return checks;
		}
		cout << "NOT FOUND at index " << i << endl;
	}
	cout << "ITEM NOT FOUND" << endl;
	return checks;
}

#include "SmartSearchLab.h"
#include <iostream>
#include <time.h>
#include <random>

using namespace std;

int main() {
	SmartSearchLab<int> unsorted(100);
	unsorted.shuffle();
	SmartSearchLab<int> sorted(100);
	sorted.sort();

	cout << "Unsorted list: ";
	unsorted.print();
	cout << "\nSorted list: ";
	sorted.print();

	int linearChecks = unsorted.linearSearch(3);
	cout << "Linear search on array of size 100 checks " << linearChecks << " values" << endl;
	int binaryChecks = sorted.binarySearch(3);
	cout << "Binary search on array of size 100 checks " << binaryChecks << " values" << endl;

	return 0;
}

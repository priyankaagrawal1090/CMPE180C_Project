#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "sort.h"
#include "main.h"
#include "test.h"

using namespace std;

int main() {
	// Supply seed to random function
	srand(time(0));

	// test single threaded merge sort for vector of integers
	vector<int> vec = generate_vec<int>(SIZE);
	string algo = "MERGESORT";
	test_single_thread<int>(ref(vec),ref(algo),THRESHOLD);

	return 0;
}


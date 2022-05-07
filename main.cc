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

	// test single and multi threaded merge sort for vector of integers
	vector<int> vec = generate_vec<int>(SIZE);
	vector<int> vec_single = vec;
	vector<int> vec_multi = vec;
	string algo = "MERGESORT";
	test_single_thread<int>(ref(vec_single),ref(algo),THRESHOLD);
	test_multi_thread<int>(ref(vec_multi),ref(algo),THRESHOLD);
	return 0;
}


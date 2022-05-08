#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "sort.h"
#include "main.h"
#include "test.h"

#define THRESHOLD   100
#define SIZE        10000

using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

int main() {
	// Supply seed to random function
	srand(time(0));
	vector<int> vec;
	for(int i=0; i<SIZE; i++){
        	vec.push_back(rand());
    	}

	// test single and multi threaded merge sort for vector of integers
	vector<int> vec_single_merge = vec;
	vector<int> vec_multi_merge = vec;
	vector<int> vec_single_quick = vec;
	vector<int> vec_multi_quick = vec;
	string algo[2] = {"MERGESORT","QUIICKSORT"};
	Result result_single_merge, result_multi_merge, result_single_quick, result_multi_quick;

	result_single_merge = test_single_thread<int>(ref(vec_single_merge),ref(algo[0]),THRESHOLD,SIZE,&compare);
	result_multi_merge = test_multi_thread<int>(ref(vec_multi_merge),ref(algo[0]),THRESHOLD,SIZE,&compare);
	cout << "Execution time for single thread: " << result_single_merge.time << " us\n";
	cout << "Execution time for multi thread: " << result_multi_merge.time << " us\n";
	cout << "Speedup: " <<  result_single_merge.time - result_multi_merge.time << " us\n";

	result_single_quick = test_single_thread<int>(ref(vec_single_quick),ref(algo[1]),THRESHOLD,SIZE,&compare);
	result_multi_quick = test_multi_thread<int>(ref(vec_multi_quick),ref(algo[1]),THRESHOLD,SIZE,&compare);
	cout << "Execution time for single thread: " << result_single_quick.time << " us\n";
	cout << "Execution time for multi thread: " << result_multi_quick.time << " us\n";
	cout << "Speedup: " <<  result_single_quick.time - result_multi_quick.time << " us\n\n";
	
	return 0;
}

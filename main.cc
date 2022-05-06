#include <iostream>
#include <ctime>
#include <algorithm>
#include <getopt.h>
#include <sstream>
#include "sort.h"

using namespace std;

#define THRESHOLD   100
#define SIZE        10
#define MAX_VALUE   1000
#define MIN_VALUE   0

template <typename T> void print_vec(vector<T> &);
template <typename T> vector<T> generate_vec(int);

int main(int argc, char *argv[]) {
	vector<float> vec;
    int size = SIZE;
    int max_value = MAX_VALUE;
    int min_value = MIN_VALUE;
	string algo = "MERGSORT";
    int Threshold = THRESHOLD;
    vec = generate_vec<float>(size);
	cout << "Unsorted vector: ";
	print_vec(vec);
	Sort(vec.begin(),vec.end(),algo, Threshold);
	cout << "Sorted vector: ";
	print_vec(vec);
	if(is_sorted(vec.begin(),vec.end())){
        cout << "Is sorted: TRUE \n";
		return 0;
    } else {
        cout << "Is sorted: FALSE \n";
		return -1;
    }
}

template <typename T>
void print_vec(vector<T> &v1) {
	std::cout << "{";
	for (auto itr = v1.begin(); itr != v1.end(); itr++) {
		if(std::distance(itr,v1.end()) > 1)
			std::cout << *itr << ",";
		else
			std::cout << *itr << "}\n";
	}
}

template <typename T>
vector<T> generate_vec(int size){
    vector<T> vec;
    for(int i=0; i<size; i++){
        vec.push_back(rand());
    }
    return vec;
}

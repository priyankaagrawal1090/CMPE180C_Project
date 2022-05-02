/*******************************************************************************

********************************************************************************
// Name: 			Priyanka Agrawal
// File type:		.cc
// Description:		This file contains the implementation of the function
//                  which merges two sorted vectors in an ascending order. 
//                   
*********************************************************************************/

#include <iostream>
#include <algorithm>
#include "sort.h"

using std::vector;
using std::string;

void merge(const vector<int>::iterator begin, const vector<int>::iterator end, const vector<int>::iterator mid) {
	vector<int> left(begin,mid);
	vector<int> right(mid,end);
	auto itr_in1 = begin;
	auto itr_left = left.begin();
	auto itr_right = right.begin();
	while( (itr_left < left.end()) && (itr_right < right.end()) ) {
		if(*itr_left < *itr_right) {
			*itr_in1++ = *itr_left++;
		} else {
			*itr_in1++ = *itr_right++;
		}
	}
	while(itr_left < left.end()) {
		*itr_in1++ = *itr_left++;
	}
	while(itr_right < right.end()) {
		*itr_in1++ = *itr_right++;
	}
}

void sortMerge(const vector<int>::iterator begin, const vector<int>::iterator end) {
	auto size = distance(begin,end);
	auto mid = begin+(size/2);
	if(size < THRESHOLD) {
		sortInsertion(begin,end);
		return;
	}
	sortMerge(begin,mid);
	sortMerge(mid,end);
	merge(begin,end,mid);
}

void swap(vector<int>::iterator itr1, vector<int>::iterator itr2) {
	int temp = *itr1;
	*itr1 = *itr2;
	*itr2 = temp; 
}

vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	// select rightmost element as pivot
	auto itr_pivot = prev(end,1);

	// pointer for greater element
	auto itr_greater = begin;

	// traverse each element of the array
	// compare them with the pivot
	for(auto itr = begin; itr != itr_pivot; itr++) {
		if(*itr < *itr_pivot) {
			// if element smaller than pivot is found
			// swap it with the greater element pointed by itr_greater
			swap(itr_greater++,itr);	
		}
	}
	// swap pivot with the greater element at itr_greater
	swap(itr_greater,itr_pivot);
	return (itr_greater);
}

void sortQuick(const vector<int>::iterator begin, const vector<int>::iterator end) {
	auto size = distance(begin,end);
	if(size < THRESHOLD || size < 2) {
		sortInsertion(begin,end);
		return;
	}
	// find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
	auto itr_pivot = partition(begin,end);
	// recursive call on the left and right of pivot
	sortQuick(begin,itr_pivot);
	sortQuick(itr_pivot+1,end);
}

void sortInsertion(vector<int>::iterator begin,vector<int>::iterator end) {
	for(auto itr = begin; itr != end; itr++) {
		// search
		auto const itr_insertion_pt = upper_bound(begin,itr,*itr);
		// insert
		rotate(itr_insertion_pt,itr,itr+1);
	}
}

void Sort(vector<int> &in1, const string &algo) {
	if(algo=="MERGESORT") {
		sortMerge(in1.begin(),in1.end());
	} else if(algo=="QUICKSORT") {
		sortQuick(in1.begin(),in1.end());
	} else {
		sortInsertion(in1.begin(), in1.end());
	}
}

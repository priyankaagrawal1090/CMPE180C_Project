/*******************************************************************************

********************************************************************************
// Name: 			Priyanka Agrawal
// File type:		.h
// Description:		This file contains the declaration of the function
//                  which merges two sorted vectors in an ascending order. 
//                   
*********************************************************************************/

#ifndef __SORT_H__
#define __SORT_H__

#include <vector>
#include <string>
using std::vector;
using std::string;

#define THRESHOLD 100

template <typename RandomIt> void sortMerge(RandomIt, RandomIt, const int);
template <typename RandomIt> void merge(RandomIt, RandomIt, RandomIt);
template <typename RandomIt> void Sort(RandomIt, RandomIt, const std::string &, const int);
template <typename RandomIt> void sortQuick(RandomIt, RandomIt, const int);
template <typename RandomIt> auto partition(RandomIt, RandomIt);
template <typename RandomIt> void Swap(RandomIt, RandomIt);
template <typename RandomIt> void sortInsertion(RandomIt, RandomIt);

template <typename RandomIt>
void merge(RandomIt begin, RandomIt end, RandomIt mid) {
	typedef typename std::iterator_traits<RandomIt>::value_type value_type;
	vector<value_type> left(begin,mid);
	vector<value_type> right(mid,end);
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

template <typename RandomIt>
void sortMerge(RandomIt begin, RandomIt end, const int Threshold) {
	auto size = distance(begin,end);
	auto mid = begin+(size/2);
	if(size < Threshold) {
		sortInsertion(begin,end);
		return;
	}
	sortMerge(begin,mid,Threshold);
	sortMerge(mid,end,Threshold);
	merge(begin,end,mid);
}

template <typename RandomIt>
void Swap(RandomIt itr1, RandomIt itr2) {
	typedef typename std::iterator_traits<RandomIt>::value_type value_type;
	value_type temp = *itr1;
	*itr1 = *itr2;
	*itr2 = temp; 
}

template <typename RandomIt>
auto partition(RandomIt begin, RandomIt end) {
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
			Swap(itr_greater++,itr);	
		}
	}
	// swap pivot with the greater element at itr_greater
	Swap(itr_greater,itr_pivot);
	return (itr_greater);
}

template <typename RandomIt>
void sortQuick(RandomIt begin, RandomIt end, const int Threshold) {
	auto size = distance(begin,end);
	if(size < Threshold || size < 2) {
		sortInsertion(begin,end);
		return;
	}
	// find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
	auto itr_pivot = partition(begin,end);
	// recursive call on the left and right of pivot
	sortQuick(begin,itr_pivot,Threshold);
	sortQuick(itr_pivot+1,end,Threshold);
}

template <typename RandomIt>
void sortInsertion(RandomIt begin, RandomIt end) {
	for(auto itr = begin; itr != end; itr++) {
		// search
		auto const itr_insertion_pt = upper_bound(begin,itr,*itr);
		// insert
		rotate(itr_insertion_pt,itr,itr+1);
	}
}

template <typename RandomIt>
void Sort(RandomIt begin, RandomIt end, const string &algo, const int Threshold) {
	if(algo=="MERGESORT") {
		sortMerge(begin,end,Threshold);
	} else if(algo=="QUICKSORT") {
		sortQuick(begin,end,Threshold);
	} else {
		sortInsertion(begin,end);
	}
}

#endif // __SORT_H__
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

#define THRESHOLD 2

void Sort(std::vector<int> &, const std::string &);
void sortMerge(std::vector<int>::iterator, std::vector<int>::iterator);
void sortQuick(std::vector<int>::iterator, std::vector<int>::iterator);
std::vector<int>::iterator partition(std::vector<int>::iterator, std::vector<int>::iterator);
void swap(std::vector<int>::iterator, std::vector<int>::iterator);
void merge(std::vector<int>::iterator, std::vector<int>::iterator, std::vector<int>::iterator);
void sortInsertion(std::vector<int>::iterator,std::vector<int>::iterator);

#endif // __SORT_H__
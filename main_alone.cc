#include<iostream>
#include<vector>
#include<chrono>
#include<thread>
#include<string>
#include<algorithm>
#include "sort.h"

#define THRESHOLD 2

bool compare(int elem1,int elem2){
	return elem1>elem2;
}

int main(){
	
	srand(time(0));																							//seed for the Random number generator
	int size = 10;																							
	std::cout<<"Size: "<<size<<'\n';
	std::vector<int> a,b,c,d;
	
	std::cout<<"\nUnsorted Array: \n";
	for(int i=0;i<size;i++){
		int temp = rand()%100;
		a.push_back(temp);	
		b.push_back(temp);
		c.push_back(temp);
		d.push_back(temp);
		std::cout<<a[i]<<'\t';																											//randomly generate the array elements
	}

	auto a_begin = a.begin();
	auto a_end = a.end();

	auto start = std::chrono::high_resolution_clock::now();	//start time of the sorting function(using Single thread)

	std::thread singlethreadMerge(Sort<int>,std::ref(a_begin),std::ref(a_end),"MERGESORT",THRESHOLD,compare);

	singlethreadMerge.join();

	auto stop = std::chrono::high_resolution_clock::now();													//stop time of thesorting function(using Single thread)

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);					//Execution time of the sorting Algorithm(using Single thread)

	std::cout<<"\nSorted Array:Merge Sort function(Using Single thread)) \n";
	for(int i=0;i<size;i++){
		std::cout<<a[i]<<'\t';
	}

	auto b_begin = b.begin();
	auto b_end = b.end();
	auto b_mid = b.begin()+size/2;

	auto start1 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Multithreading)

	std::thread firstMerge (Sort<int>,std::ref(b_begin),std::ref(b_mid),"MERGESORT",THRESHOLD,compare);									//creating thread 1
	std::thread secondMerge (Sort<int>,std::ref(b_mid),std::ref(b_end),"MERGESORT",THRESHOLD,compare);									//creating thread 2

	firstMerge.join();																						//wait for the thread1 to complete	
	secondMerge.join();																						//wait for the thread2 to complete
	
	std::thread thirdMerge (merge<int>,std::ref(b_begin),std::ref(b_end),std::ref(b_mid),compare);										//creating the third merging thread
	
	thirdMerge.join();																						//wait for the 3rd thread to complete

	auto stop1 = std::chrono::high_resolution_clock::now();													//stop time of the sorting function(using Multithreading)
	
	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);					//Execution time of the sorting Algorithm(using Multithreading)
	
	std::cout<<"\nSorted Array:(Merge Sort function(Using Two threads)) \n";
	for(int i=0;i<size;i++){
		std::cout<<b[i]<<'\t';
	}

	auto c_begin = c.begin();
	auto c_end = c.end();

	auto start2 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Single thread)

	std::thread singlethreadQuick(Sort<int>,std::ref(c_begin),std::ref(c_end),"QUICKSORT",THRESHOLD,compare);

	singlethreadQuick.join();

	auto stop2 = std::chrono::high_resolution_clock::now();													//stop time of thesorting function(using Single thread)

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);					//Execution time of the sorting Algorithm(using Single thread)

	std::cout<<"\nSorted Array:(Quick Sort function(Using Single thread)) \n";
	for(int i=0;i<size;i++){
		std::cout<<c[i]<<'\t';
	}
	
	auto d_begin = d.begin();
	auto d_end = d.end();
	auto d_mid = d.begin()+size/2;
	
	auto start3 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Multithreading)

	std::thread firstQuick (Sort<int>,std::ref(d_begin),std::ref(d_mid),"QUICKSORT",THRESHOLD,compare);									//creating thread 1
	std::thread secondQuick (Sort<int>,std::ref(d_mid),std::ref(d_end),"QUICKSORT",THRESHOLD,compare);									//creating thread 2

	firstQuick.join();																						//wait for the thread1 to complete	
	secondQuick.join();																						//wait for the thread2 to complete
	
	std::thread thirdQuick (merge<int>,std::ref(d_begin),std::ref(d_end),std::ref(d_mid),compare);										//creating the third merging thread
	
	thirdQuick.join();																						//wait for the 3rd thread to complete

	auto stop3 = std::chrono::high_resolution_clock::now();													//stop time of the sorting function(using Multithreading)
	
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);					//Execution time of the sorting Algorithm(using Multithreading)
	
	std::cout<<"\nSorted Array:(Quick Sorting function(Using Two threads)) \n";
	for(int i=0;i<size;i++){
		std::cout<<d[i]<<'\t';
	}

	std::cout<<"\nExecution Time for Merge Sort function(Using Single thread): "<<duration.count()<<" ms"<<'\n';
	std::cout<<"Execution Time for Merge Sort function(Using Two threads): "<<duration1.count()<<" ms"<<'\n';
	std::cout<<"Multithreading is "<<duration.count()-duration1.count()<<" ms faster(for Merge Sort).";
	std::cout<<"\nExecution Time for Quick Sort function(Using Single thread): "<<duration2.count()<<" ms"<<'\n';
	std::cout<<"Execution Time for Quick Sorting function(Using Two threads): "<<duration3.count()<<" ms"<<'\n';
	std::cout<<"Multithreading is "<<duration2.count()-duration3.count()<<" ms faster(for Quick Sort).";
}

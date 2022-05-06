#include<iostream>
#include<vector>
#include<chrono>
#include<thread>
#include<string>
#include<algorithm>

#define THRESHOLD 2

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

	auto start = std::chrono::high_resolution_clock::now();	
																											//start time of the sorting function(using Single thread)

	std::thread singlethreadMerge(Sort<int>,a.begin(),a.end(),"MERGESORT");

	singlethreadMerge.join();

	auto stop = std::chrono::high_resolution_clock::now();													//stop time of thesorting function(using Single thread)

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);					//Execution time of the sorting Algorithm(using Single thread)

	std::cout<<"\nSorted Array:Merge Sort function(Using Single thread)) \n";
	for(int i=0;i<size;i++){
		std::cout<<a[i]<<'\t';
	}

	auto start1 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Multithreading)

	std::thread firstMerge (Sort<int>,b.begin(),b.begin()+size/2,"MERGESORT");									//creating thread 1
	std::thread secondMerge (Sort<int>,b.begin()+size/2,b.end(),"MERGESORT");									//creating thread 2

	firstMerge.join();																						//wait for the thread1 to complete	
	secondMerge.join();																						//wait for the thread2 to complete
	
	std::thread thirdMerge (merge<int>,b.begin(),b.end(),b.begin()+size/2);										//creating the third merging thread
	
	thirdMerge.join();																						//wait for the 3rd thread to complete

	auto stop1 = std::chrono::high_resolution_clock::now();													//stop time of the sorting function(using Multithreading)
	
	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);					//Execution time of the sorting Algorithm(using Multithreading)
	
	std::cout<<"\nSorted Array:(Merge Sort function(Using Two threads)) \n";
	for(int i=0;i<size;i++){
		std::cout<<b[i]<<'\t';
	}

	auto start2 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Single thread)

	std::thread singlethreadQuick(Sort<int>,c.begin(),c.end(),"QUICKSORT");

	singlethreadQuick.join();

	auto stop2 = std::chrono::high_resolution_clock::now();													//stop time of thesorting function(using Single thread)

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);					//Execution time of the sorting Algorithm(using Single thread)

	std::cout<<"\nSorted Array:(Quick Sort function(Using Single thread)) \n";
	for(int i=0;i<size;i++){
		std::cout<<c[i]<<'\t';
	}

	auto start3 = std::chrono::high_resolution_clock::now();												//start time of the sorting function(using Multithreading)

	std::thread firstQuick (Sort<int>,d.begin(),d.begin()+size/2,"QUICKSORT");									//creating thread 1
	std::thread secondQuick (Sort<int>,d.begin()+size/2,d.end(),"QUICKSORT");									//creating thread 2

	firstQuick.join();																						//wait for the thread1 to complete	
	secondQuick.join();																						//wait for the thread2 to complete
	
	std::thread thirdQuick (merge<int>,d.begin(),d.end(),d.begin()+size/2);										//creating the third merging thread
	
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
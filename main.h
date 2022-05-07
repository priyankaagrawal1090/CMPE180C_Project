#ifndef __MAIN_H_
#define __MAIN_H_

#define THRESHOLD   100
#define SIZE        10

template <typename T> void print_vec(vector<T> &);
template <typename T> vector<T> generate_vec(int);
template <typename T> void test_single_thread(vector<T> &,const string &, const int);

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

template <typename T>
void test_single_thread(vector<T> & vec,const string & algo, const int Threshold) {
    auto itr_beg = vec.begin();
    auto itr_end = vec.end();
    //start time of the sorting function(using Single thread)
    auto start = std::chrono::high_resolution_clock::now();
    // Create a single thread using lamda function
    std::thread t0( [&itr_beg,&itr_end,&algo,&Threshold] () {Sort(itr_beg,itr_end,algo,Threshold);} );
    t0.join();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout << "\n###################################\n";
    std::cout << "# Testing single thread sort\n";
    std::cout << "###################################\n";
    std::cout << "\tData Type: " << typeid(T).name() << "\n";
    std::cout << "\tAlgorithm: " << algo << "\n";
    std::cout << "\tThreshold: " << Threshold << "\n";
    std::cout << "\tSorting result: " << is_sorted(vec.begin(),vec.end()) << "\n";
    std::cout << "\tDuration: " << duration.count() << "ms\n";
    std::cout << "\n\n";
}

#endif //__MAIN_H_
#ifndef __MAIN_H_
#define __MAIN_H_

#define THRESHOLD   100
#define SIZE        10000000

struct Result{
    bool    pass;
    int     time;
};

template <typename T> void print_vec(vector<T> &);
template <typename T> vector<T> generate_vec(int);
template <typename T> bool Less(const T &, const T &);
template <typename T> Result test_single_thread(vector<T> &,const string &, const int);
template <typename T> Result test_multi_thread(vector<T> &,const string &, const int);

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
bool Less(const T & a, const T & b)
{
	if(a == b)
		return a > b;

	return a < b;
}

template <typename T>
Result test_single_thread(vector<T> & vec,const string & algo, const int Threshold) {
    auto itr_beg = vec.begin();
    auto itr_end = vec.end();
    //start time of the sorting function(using Single thread)
    auto start = std::chrono::high_resolution_clock::now();
    // Create a single thread using lamda function
    std::thread t0( [&itr_beg,&itr_end,&algo,&Threshold] () {Sort(itr_beg,itr_end,algo,Threshold,Less<T>);} );
    t0.join();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    Result result;
    result.pass = is_sorted(vec.begin(),vec.end());
    result.time = duration.count();

    std::cout << "\n###################################\n";
    std::cout << "# Testing single thread sort\n";
    std::cout << "###################################\n";
    std::cout << "\tData Type: " << typeid(T).name() << "\n";
    std::cout << "\tAlgorithm: " << algo << "\n";
    std::cout << "\tThreshold: " << Threshold << "\n";
    std::cout << "\tSorting result: " << is_sorted(vec.begin(),vec.end()) << "\n";
    std::cout << "\tDuration: " << duration.count() << "us\n";
    std::cout << "\n\n";

    return result;
}

template <typename T>
Result test_multi_thread(vector<T> & vec,const string & algo, const int Threshold) {
    auto itr_beg = vec.begin();
    auto itr_mid = vec.begin()+(vec.size()/2);
    auto itr_end = vec.end();
    //start time of the sorting function(using Single thread)
    auto start = std::chrono::high_resolution_clock::now();
    // Create two parallel single threads using lamda function
    std::thread t0( [&itr_beg,&itr_mid,&algo,&Threshold] () {Sort(itr_beg,itr_mid,algo,Threshold,Less<T>);} );
    std::thread t1( [&itr_mid,&itr_end,&algo,&Threshold] () {Sort(itr_mid,itr_end,algo,Threshold,Less<T>);} );
    // Join both threads
    t0.join();
    t1.join();
    // Spawn a third thread for merge
    std::thread t2( [&itr_beg,&itr_end,&itr_mid] () {merge(itr_beg,itr_end,itr_mid,Less<T>);} );
    t2.join();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    Result result;
    result.pass = is_sorted(vec.begin(),vec.end());
    result.time = duration.count();

    std::cout << "\n###################################\n";
    std::cout << "# Testing Multi thread sort\n";
    std::cout << "###################################\n";
    std::cout << "\tData Type: " << typeid(T).name() << "\n";
    std::cout << "\tAlgorithm: " << algo << "\n";
    std::cout << "\tThreshold: " << Threshold << "\n";
    std::cout << "\tSorting result: " << is_sorted(vec.begin(),vec.end()) << "\n";
    std::cout << "\tDuration: " << duration.count() << "us\n";
    std::cout << "\n\n";

    return result;
}

#endif //__MAIN_H_
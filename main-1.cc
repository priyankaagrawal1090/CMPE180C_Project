#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <getopt.h>
#include <sstream>
#include "sort.h"

using namespace std;

bool argparse(int &argc, char* argv[], string &algo, vector<int> &vec);
void print_vec(std::vector<int> &v1);
vector<int> take_int(const string &str);

int main(int argc, char *argv[]) {
	vector<int> vec;
	string algo;
	argparse(argc, argv, algo, vec);
	cout << "Unsorted vector: ";
	print_vec(vec);
	Sort(vec,algo);
	cout << "Sorted vector: ";
	print_vec(vec);
	if(is_sorted(vec.begin(),vec.end()))
		return 0;
	else
		return -1;
}

// Returns True if the arguments were legal else false
bool argparse(int &argc, char* argv[], string &algo, vector<int> &vec){
	string arr = "";
	algo.clear();
    vec.clear();
    int c;
    int option_index;
    
    static struct option long_options[] = {
        {"algo", required_argument, 0, 'a'},
        {"vec", required_argument, 0, 'v'}
    };

    while((c = getopt_long(argc, argv, "a:v:", long_options,&option_index)) != -1) {
        switch(c) {
            case 'a':{
                algo = optarg;
                break;
            }
            case 'v':{
                arr = optarg;
                break;
            }
            case '?':{
                cerr << "Got unknown option. \n"; 
                return 0;
            }
            default:{
                cerr << "got unknown parse returns " << c << "\n";
                return 0;
            }
        }
    }
	if(algo.size()==0) {
		cerr << "Specify exactly one algorithm using option -a <algorithm>.\n";
		return 0;
	}
	if(arr.size()==0) {
		cerr << "Specify exactly one vector using -v <vector>.\n";
        return 0;
	}
	vec = take_int(arr);
	return 1;
}

void print_vec(std::vector<int> &v1) {
	std::cout << "{";
	for (auto itr = v1.begin(); itr != v1.end(); itr++) {
		if(std::distance(itr,v1.end()) > 1)
			std::cout << *itr << ",";
		else
			std::cout << *itr << "}\n";
	}
}

vector<int> take_int(const string &str) {
    stringstream ss(str);
    vector<int> result;
    char ch;
    int tmp;
    while(ss >> tmp) {
        result.push_back(tmp);
        ss >> ch;
    }
    return result;
}
/*
 * test.cc
 *
 * @description: unit tests and integration tests for the sort.cc file
 *
 * @author: Mansi Thaker
 */

#include "sort.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>

#define THRESHOLD 100

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

// Unit Tests
void test_swap() {
    // Inplace swap
    vector<int> vec{1, 2, 3, 4, 5};
    auto itr1 = vec.begin();
    auto itr2 = prev(vec.end(), 1);
    Swap<vector<int>::iterator>(itr1, itr2);
    assert(*itr1 == 5);
    assert(*itr2 == 1);

    // O utplace swap
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 3, 2, 4, 5};
    Swap<vector<int>::iterator>(a.begin() + 1, a.begin() + 2);
    for (size_t i = 0; i < b.size(); i++) {
        assert(b[i] == a[i]);
    }

    // Passed
    cout << "Swap() passed" << endl;
}

void test_partition() {
    // partition case 1
    vector<int> vec{1, 2, 3, 4, 5};
    auto itr_pivot = Partition<vector<int>::iterator>(vec.begin(), vec.end(), compare);
    assert(*itr_pivot == 5);

    // partition case 2
    // pivot at the beginning
    vector<int> a{1, 1, 1, 1, 1};
    auto itr_pivot2 = Partition<vector<int>::iterator>(a.begin(), a.end(), compare);
    assert(*itr_pivot2 == 1);
    // pivot at the end
    vector<int> b{1, 0, -1, 1, 3};
    auto itr_pivot3 = Partition<vector<int>::iterator>(b.begin(), b.end(), compare);
    assert(*itr_pivot3 == 3);
    // pivot at the middle
    vector<int> c{-4, -3, -2, -1};
    auto itr_pivot4 = Partition<vector<int>::iterator>(c.begin(), c.end(), compare);
    assert(*itr_pivot4 == -1);

    // Passed
    cout << "Partition() passed" << endl;
}

void test_sortInsertion() {
    // sortInsertion case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    sortInsertion<vector<int>::iterator>(vec.begin(), vec.end(), compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortInsertion case 2
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sortInsertion<vector<int>::iterator>(b.begin(), b.end(), compare);
    for (size_t i = 0; i < b.size(); i++) {
        assert(b[i] == a[i]);
    }

    // sortInsertion case 3
    vector<int> c{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    vector<int> d{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    sortInsertion<vector<int>::iterator>(c.begin(), c.end(), compare);
    for (size_t i = 0; i < c.size(); i++) {
        assert(c[i] == d[i]);
    }

    // sortInsertion case 4
    vector<int> e{-4, -3, -2, -1};
    vector<int> f{-4, -3, -2, -1};
    sortInsertion<vector<int>::iterator>(e.begin(), e.end(), compare);
    for (size_t i = 0; i < e.size(); i++) {
        assert(e[i] == f[i]);
    }

    // sortInsertion case 5
    vector<int> g{-11, 3, 2};
    vector<int> h{-11, 2, 3};
    sortInsertion<vector<int>::iterator>(g.begin(), g.end(), compare);
    for (size_t i = 0; i < g.size(); i++) {
        assert(g[i] == h[i]);
    }

    // sortInsertion case 6
    vector<int> k{-4, -4, 3, -4};
    vector<int> l{-4, -4, -4, 3};
    sortInsertion<vector<int>::iterator>(k.begin(), k.end(), compare);
    for (size_t i = 0; i < k.size(); i++) {
        assert(k[i] == l[i]);
    }

    // Passed
    cout << "sortInsertion() passed" << endl;
}

void test_sortMerge() {
    // sortMerge case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    sortMerge<vector<int>::iterator>(vec.begin(), vec.end(), THRESHOLD, compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortMerge case 2
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sortMerge<vector<int>::iterator>(b.begin(), b.end(), THRESHOLD, compare);
    for (size_t i = 0; i < b.size(); i++) {
        assert(b[i] == a[i]);
    }

    // sortMerge case 3
    vector<int> c{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    vector<int> d{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    sortMerge<vector<int>::iterator>(c.begin(), c.end(), THRESHOLD, compare);
    for (size_t i = 0; i < c.size(); i++) {
        assert(c[i] == d[i]);
    }

    // sortMerge case 4
    vector<int> e{-4, -3, -2, -1};
    vector<int> f{-4, -3, -2, -1};
    sortMerge<vector<int>::iterator>(e.begin(), e.end(), THRESHOLD, compare);
    for (size_t i = 0; i < e.size(); i++) {
        assert(e[i] == f[i]);
    }

    // sortMerge case 5
    vector<int> g{-11, 3, 2};
    vector<int> h{-11, 2, 3};
    sortMerge<vector<int>::iterator>(g.begin(), g.end(), THRESHOLD, compare);
    for (size_t i = 0; i < g.size(); i++) {
        assert(g[i] == h[i]);
    }

    // sortMerge case 6
    vector<int> k{-4, -4, 3, -4};
    vector<int> l{-4, -4, -4, 3};
    sortMerge<vector<int>::iterator>(k.begin(), k.end(),THRESHOLD, compare);
    for (size_t i = 0; i < k.size(); i++) {
        assert(k[i] == l[i]);
    }

    // Passed
    cout << "sortMerge() passed" << endl;
}

void test_sortQuick() {
    // sortQuick case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    sortQuick<vector<int>::iterator>(vec.begin(), vec.end(), THRESHOLD, compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortQuick case 2
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sortQuick<vector<int>::iterator>(b.begin(), b.end(), THRESHOLD, compare);
    for (size_t i = 0; i < b.size(); i++) {
        assert(b[i] == a[i]);
    }

    // sortQuick case 3
    vector<int> c{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    vector<int> d{1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    sortQuick<vector<int>::iterator>(c.begin(), c.end(), THRESHOLD, compare);
    for (size_t i = 0; i < c.size(); i++) {
        assert(c[i] == d[i]);
    }

    // sortQuick case 4
    vector<int> e{-4, -3, -2, -1};
    vector<int> f{-4, -3, -2, -1};
    sortQuick<vector<int>::iterator>(e.begin(), e.end(), THRESHOLD, compare);
    for (size_t i = 0; i < e.size(); i++) {
        assert(e[i] == f[i]);
    }

    // sortQuick case 5
    vector<int> g{-11, 3, 2};
    vector<int> h{-11, 2, 3};
    sortQuick<vector<int>::iterator>(g.begin(), g.end(), THRESHOLD, compare);
    for (size_t i = 0; i < g.size(); i++) {
        assert(g[i] == h[i]);
    }

    // sortQuick case 6
    vector<int> k{-4, -4, 3, -4};
    vector<int> l{-4, -4, -4, 3};
    sortQuick<vector<int>::iterator>(k.begin(), k.end(), THRESHOLD, compare);
    for (size_t i = 0; i < k.size(); i++) {
        assert(k[i] == l[i]);
    }

    // Passed
    cout << "sortQuick() passed" << endl;
}

// Integration Tests
void test_sortMerge_Integration() {
    // sortMerge case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    Sort<vector<int>::iterator>(vec.begin(), vec.end(), "MERGESORT", THRESHOLD, compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortMerge case 2
    vector<int> a{4, -3, 2, -1};
    vector<int> b{-3, -1, 2, 4};
    Sort<vector<int>::iterator>(a.begin(), a.end(), "MERGESORT", THRESHOLD, compare);
    for (size_t i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }

    // Passed
    cout << "Sort(MERGESORT) passed" << endl;
}

void test_sortQuick_Integration() {
    // sortQuick case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    Sort<vector<int>::iterator>(vec.begin(), vec.end(), "QUICKSORT", THRESHOLD, compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortQuick case 2
    vector<int> a{4, -3, 2, -1};
    vector<int> b{-3, -1, 2, 4};
    Sort<vector<int>::iterator>(a.begin(), a.end(), "QUICKSORT", THRESHOLD, compare);
    for (size_t i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }

    // Passed
    cout << "Sort(QUICKSORT) passed" << endl;
}

void test_sortInsertion_Integration() {
    // sortInsertion case 1
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> vec2{1, 2, 3, 4, 5};
    Sort<vector<int>::iterator>(vec.begin(), vec.end(), "INSERTIONSORT", THRESHOLD, compare);
    for (size_t i = 0; i < vec2.size(); i++) {
        assert(vec2[i] == vec[i]);
    }

    // sortInsertion case 2
    vector<int> a{4, -3, 2, -1};
    vector<int> b{-3, -1, 2, 4};
    Sort<vector<int>::iterator>(a.begin(), a.end(), "INSERTIONSORT", THRESHOLD, compare);
    for (size_t i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }

    // Passed
    cout << "Sort(INSERTIONSORT) passed" << endl;
}

int main() {
    test_swap();
    test_partition();
    test_sortInsertion();
    test_sortMerge();
    test_sortQuick();
    test_sortMerge_Integration();
    test_sortQuick_Integration();
    test_sortInsertion_Integration();
    cout << "All tests passed" << endl;
}
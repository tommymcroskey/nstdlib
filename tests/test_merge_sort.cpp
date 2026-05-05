#include "garden/merge_sort.hpp"

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

void test_lt_sort_trivial() {
	std::vector<int> v = {5, 4, 2, 3, 7};
	gdn::merge_sort_in_place_lt(v);
	int t = -1;
	for (int n : v) {
		assert(t < n);
		t = n;
	}
}

void test_lt_sort_has_freqs() {
	std::vector<int> v = {16, 22, 58, 37, 21, 22, 33};
	std::unordered_map<int, int> freqs;
	for (int n : v) {
		freqs[n]++;
	}
	gdn::merge_sort_in_place_lt(v);
	for (int n : v) {
		freqs[n]--;
	}
	for (auto [key, value] : freqs) {
		assert(value == 0);
	}
}

void run_tests() {
	test_lt_sort_trivial();
	test_lt_sort_has_freqs();
}

int main() {
	run_tests();
	return 0;
}

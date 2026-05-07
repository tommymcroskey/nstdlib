#include "garden/find.hpp"
#include "garden/merge_sort.hpp"

#include <cassert>
#include <vector>

void test_linear_find_trivial() {
	std::vector<int> v = {1, 5, 8, 3, 6, 0};
	std::vector<int> cpy(v);
	auto ptr = std::find(v.begin(), v.end(), 5);
	assert(*ptr == 5);
	assert(ptr != v.end());
	assert(v == cpy);
}

void test_sorted_find_trivial() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> cpy(v);
	auto ptr = gdn::find(v.begin(), v.end(), 6, true);
	assert(*ptr == 5);
	assert(ptr != v.end());
	assert(v == cpy);
}

void test_find_empty_vector() {
	std::vector<int> v(0);
	assert(gdn::find(v.begin(), v.end(), 6) == v.end());
	assert(v.size() == 0);
}

void test_find_empty_sorted_vector() {
	std::vector<int> v(0);
	assert(gdn::find(v.begin(), v.end(), 6, true) == v.end());
	assert(v.size() == 0);
}

void test_sorted_false_find() {
	std::vector<int> v = {4, 5, 6, 1, 2, 0, 9};
	std::vector<int> cpy(v);
	auto ptr = gdn::find(v.begin(), v.end(), 2, false);
	assert(*ptr == 2);
	assert(ptr != v.end());
	assert(v == cpy);
}

void run_tests() {
	test_linear_find_trivial();
	test_sorted_find_trivial();
	test_find_empty_vector();
	test_sorted_false_find();
}

int main() {
	run_tests();
	return 0;
}

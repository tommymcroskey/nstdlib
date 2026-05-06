#include "garden/vector.hpp"

#include <cassert>

void test_constructor_sanity() {
	gdn::Vector<int> v;
}

void test_push_back_trivial() {
	gdn::Vector<int> v;
	v.push_back(4);
	assert(v[0] == 4);
	assert(v.size() == 1);
}

void test_trivial_back() {
	gdn::Vector<int> v;
	v.push_back(5);
	assert(v.back() == 5);
	assert(v.size() == 1);
}

void test_trivial_front() {
	gdn::Vector<int> v;
	v.push_back(4);
	v.push_back(10);
	assert(v.front() == 4);
	assert(v.size() == 2);
}

void test_trivial_bracket_reassignment() {
	gdn::Vector<int> v;
	v.push_back(7);
	v.push_back(5);
	v.push_back(167);
	v[2] = 3;
	for (int i = 0, val = 7; i < 3; i++) {
		assert(v[i] = val);
		val -= 2;
	}
}

class MyType {
public:
	int data_;
	MyType(int data) : data_(data) {}
	bool operator==(const MyType& mt) const { return data_ == mt.data_; }
};

void test_ud_default_constructor() {
	gdn::Vector<MyType> v;
}

void test_ud_capacity_constructor() {
	gdn::Vector<MyType> v(10);
}

void test_ud_fill_constructor() {
	MyType mt(26);
	gdn::Vector<MyType> v(10, mt);
}

void test_ud_push_back() {
	gdn::Vector<MyType> v;
	MyType mt(26);
	v.push_back(mt);
	assert(v.front() == mt);
	assert(v.size() == 1);
}

void run_tests() {
	test_constructor_sanity();
	test_push_back_trivial();
	test_trivial_back();
	test_trivial_front();
	test_trivial_bracket_reassignment();
	test_ud_default_constructor();
	test_ud_capacity_constructor();
	test_ud_fill_constructor();
	test_ud_push_back();
}

int main() {
	run_tests();
	return 0;
}

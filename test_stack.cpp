#include "stack.hpp"

#include <cassert>

void test_constructor_trivial() {
	/*
	* Test default constructor
	*/
	Stack<int, 10> st;
}

void test_push_trivial() {
	/*
	* Push trivial valuesk
	*/
	Stack<int, 10> st;
	int value = 10;
	st.push(value);
	assert(st.size() == 1);
}

void test_push_nullptr() {
	/*
	* Push nullptr object
	*/
}

void run_tests() {
	test_push_trivial();
	test_push_nullptr();
}

int main(int argc, char** argv) {
	run_tests();
	return 0;
}

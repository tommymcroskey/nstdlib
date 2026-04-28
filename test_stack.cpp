#include "stack.hpp"

#include <cassert>
#include <vector>

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

void test_push_to_limit() {
	/*
	* Push values N + 1 times
	*/
	Stack<int, 10> st;
	try {
		for (int i = 0; i < 11; i++) {
			st.push(i);
		}
		assert(false);
	} catch (std::overflow_error&) {}
}

void test_pop_empty() {
	/*
	* Pop from empty stack
	*/
	Stack<bool, 5> st;
	try {
		st.pop();
		assert(false);
	} catch (std::underflow_error&) {}
}

void test_pop_trivial() {
	/*
	* Test standard pop behavior
	*/
	Stack<float, 3> st;
	float value = 1.0f;
	st.push(value);
	st.pop();
	assert(st.size() == 0);
}

void test_top_empty() {
	/*
	* Test top from empty
	*/
	Stack<int, 200> st;
	try {
		st.top();
		assert(false);
	} catch (std::logic_error&) {}
}

void run_tests() {
	test_constructor_trivial();
	test_push_trivial();
	test_push_to_limit();
	test_pop_empty();
	test_pop_trivial();
	test_top_empty();
}

int main(int argc, char** argv) {
	run_tests();
	return 0;
}

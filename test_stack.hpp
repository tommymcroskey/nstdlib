#include "stack.hpp"

#include <cassert>

void test_push_trivial() {
	/*
	* Push trivial valuesk
	*/
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

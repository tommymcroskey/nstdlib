#include "garden/circular_buffer.hpp"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

void test_constructor_sanity() {
	std::cout << "Testing constructor sanity\n";
	gdn::CircularBuffer<int, 10> cb;
}

void test_enqueue_trivial() {
	std::cout << "Testing enqueue on single rvalue\n";
	gdn::CircularBuffer<int, 15> cb;
	cb.enqueue(5);
	assert(cb.size() == 1);
}

void test_enqueue_moved_value() {
	std::cout << "Testing enqueue on single rvalue reference\n";
	gdn::CircularBuffer<int, 4> cb;
	int value = 1600;
	cb.enqueue(std::move(value));
	assert(cb.size() == 1);
}

void test_enqueue_lvalue() {
	std::cout << "Testing enqueue on single lvalue\n";
	gdn::CircularBuffer<int, 600> cb;
	int value = 1600;
	assert(cb.size() == 0);
	cb.enqueue(value);
	assert(cb.size() == 1);
}

void test_dequeue_trivial() {
	std::cout << "Testing dequeue on 10 values\n";
	gdn::CircularBuffer<int, 13> cb;
	for (int i = 0; i < 10; i++) {
		cb.enqueue(i);
	}
	for (int i = 0; i < 10; i++) {
		int res = cb.dequeue();
		assert(res == i);
	}
	assert(cb.size() == 0);
}

void run_tests() {
	test_constructor_sanity();
	test_enqueue_trivial();
	test_enqueue_moved_value();
	test_enqueue_lvalue();
	test_dequeue_trivial();
}

int main() {
	run_tests();
	return 0;
}

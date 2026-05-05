#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>
#include <stdexcept>

namespace gdn {
inline namespace _stack_0_1_0 {

template <typename T, size_t N>
class Stack {

public:

Stack() : top_(0) {} 
~Stack() = default;

void push(T& e) {
	if (full()) {
		throw std::overflow_error("stack is full");
	}
	data[top_++] = e;
}

void pop() {
	if (empty()) {
		throw std::underflow_error("stack is empty");
	}
	top_--;
}

T top() const {
	if (empty()) {
		throw std::logic_error("stack is empty");
	}
	return data[top_];
}

bool empty() const { return top_ == 0; }
bool full() const { return top_ == N; }
size_t size() const { return top_; }

private:

size_t top_;
T data[N];

};

};

};

#endif // STACK_HPP

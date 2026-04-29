#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

#include <cstddef>
#include <cstdlib>
#include <memory>

template <typename T, size_t N>
class CircularBuffer {

public:

CircularBuffer() :
	capacity_(N),
	size_(0),
	front_(0),
	back_(0)
{}
~CircularBuffer() = default;

void enqueue(T e) {
	if (full()) {
		throw std::overflow_error("circular buffer is full");
	}
	data[front_] = std::move(e);
	front_ = (front_ + 1) % capacity_;
	size_++;
}

T dequeue() {
	if (empty()) {
		throw std::underflow_error("circular buffer is empty");
	}
	size_t to_pop = back_;
	back_ = (back_ + 1) % capacity_;
	size_--;
	return std::move(data[to_pop]);
}

size_t capacity() const { return capacity_; }
size_t size() const { return size_; }
bool empty() const { return size_ == 0; }
bool full() const { return size_ == capacity_; }

private:

size_t capacity_;
size_t size_;
size_t front_;
size_t back_;

T data[N];

};

#endif // CIRCULAR_BUFFER_HPP 

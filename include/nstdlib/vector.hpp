#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <memory>

namespace nstd {

template <typename T>
class Vector {

public:

	Vector();
	Vector(size_t capacity);
	Vector(size_t capacity, const T& fill);
	Vector(const Vector& o); // copy constructor
	Vector(Vector&& o) noexcept; // move constructor

	~Vector();

	Vector& operator=(const Vector& o); // copy assignment operator
	Vector& operator=(Vector&& o); // move assignment operator
	T& operator[](size_t idx);

	T& front() const;
	T& back() const;
	size_t size();

private:

	unique_ptr<T> data;
	size_t capacity;
	size_t size;

};

};

#endif // VECTOR_HPP

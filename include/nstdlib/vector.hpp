#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <memory>

namespace nstd {

template <typename T>
class Vector {

public:

	Vector()
		: data_(static_cast<T*>(::operator new(DEFAULT_CAPACITY * sizeof(T))))
		, capacity_(DEFAULT_CAPACITY)
		, size_(0)
	{}

	Vector(size_t capacity)
		: data_(static_cast<T*>(::operator new(capacity * sizeof(T))))
		, capacity_(capacity)
		, size_(0)
	{}

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
	void push_back();

private:

	unique_ptr<T> data_;
	size_t capacity_;
	size_t size_;

inline namespace _version_0_1_0 {

	void _expand_exponential();
};

};

};

#endif // VECTOR_HPP

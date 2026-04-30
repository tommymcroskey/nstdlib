#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <memory>

namespace nstd {
inline namespace _vector_version_0_1_0 {

template <typename T>
class Vector {

public:

	Vector()
		: data_(static_cast<T*>(::operator new(default_capacity * sizeof(T))))
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

	static constexpr default_capacity = 8;

	unique_ptr<T> data_;
	size_t capacity_;
	size_t size_;

	void _expand_exponential();
};

};

};

#endif // VECTOR_HPP

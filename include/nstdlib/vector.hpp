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
	Vector(const Vector& o);
	Vector(Vector&& o) noexcept;

	~Vector();

	Vector& operator=(const Vector& o);
	Vector& operator=(Vector&& o);

	/**
	* @brief operator[] override for const vectors
	* @throws out_of_range on access index > size
	*/
	const T& operator[](size_t idx) const {
		if (_out_of_bounds(idx)) {
			throw std::out_of_range("index not in range");
		}
		return data_.get()[idx];
	}

	/**
	* @brief operator[] override for non const vectors
	* @throws out_of_range on access index > size
	*/
	T& operator[](size_t idx) {
		return const_cast<T&>(static_cast<const Vector&>(*this)[idx]);
	}

	/**
	* @brief returns the front of the vector
	*/
	T& front() const {
		if (_empty()) {
			throw std::out_of_range("cannot get front of empty vector");
		}
		return *this[0];
	}

	/**
	* @brief returns the back of the vector
	*/
	T& back() const {
		if (_empty()) {
			throw std::out_of_range("cannot get back of empty vector");
		}
		return *this[size_ - 1]
	}
	size_t size() const { return size_; }
	void push_back(const T& e);

private:

	static constexpr default_capacity = 8;

	unique_ptr<T> data_;
	size_t capacity_;
	size_t size_;

	bool _empty() const { return size_ == 0; }
	bool _out_of_bounds(size_t idx) const { return idx >= size_; }
	void _expand_exponential();
};

};

};

#endif // VECTOR_HPP

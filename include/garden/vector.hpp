/**
* @file garden/vector
* @brief This file is a template vector implementation
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <cstdlib>
#include <memory>

namespace gdn {
inline namespace _vector_0_1_0 {

template <typename T>
class Vector {

public:

	Vector()
		: data_(static_cast<T*>(::operator new(default_capacity * sizeof(T))))
		, capacity_(default_capacity)
		, size_(0)
	{}

	Vector(size_t capacity)
		: data_(static_cast<T*>(::operator new(capacity * sizeof(T))))
		, capacity_(capacity)
		, size_(0)
	{}

	Vector(size_t capacity, const T& fill) : Vector(capacity) {
		for (; size_ < capacity_; size_++) {
			data_[size_] = fill;
		}
	}

	~Vector() {
		for (size_t i = 0; i < size_; i++) {
			data_[i].~T();
		}
		::operator delete(data_);
	}

	Vector(const Vector& o): Vector(o.capacity_) {
		for (; size_ < o.size_; size_++) {
			data_[size_] = o.data_[size_];
		}
	}

	Vector(Vector&& o)
		: data_(std::move(o.data_))
		, capacity_(o.capacity_)
		, size_(o.size_)
	{
		o.data_ = nullptr;
		o.capacity_ = 0;
		o.size_ = 0;
	}

	Vector& operator=(const Vector& o) {
		if (this == &o) {
			return *this;
		}
		Vector tmp(o);
		std::swap(data_, tmp.data_);
		std::swap(capacity_, tmp.capacity_);
		std::swap(size_, tmp.size_);
		return *this;
	}

	Vector& operator=(Vector&& o) {
		if (this == &o) {
			return *this;
		}
		for (size_t i = 0; i < size_; i++) {
			data_[i].~T();
		}
		::operator delete(data_);
		data_ = std::move(o.data_);
		capacity_ = o.capacity_;
		size_ = o.size_;
		o.data_ = nullptr;
		o.capacity_ = 0;
		o.size_ = 0;
		return *this;
	}
	
	const T& operator[](size_t idx) const {
		if (idx >= size_) {
			throw std::out_of_range("cannot access index greater than vector size");
		}
		return data_[idx];
	}

	T& operator[](size_t idx) {
		return const_cast<T&>(static_cast<const Vector&>(*this)[idx]);
	}

	const T& front() const {
		if (_empty()) {
			throw std::out_of_range("cannot get front of empty vector");
		}
		return data_[0];
	}

	const T& back() const {
		if (_empty()) {
			throw std::out_of_range("cannot get back of empty vector");
		}
		return data_[size_ - 1];
	}

	T& front() {
		return const_cast<T&>(static_cast<const Vector&>(*this).front());
	}

	T& back() {
		return const_cast<T&>(static_cast<const Vector&>(*this).back());
	}

	size_t size() const { return size_; }

	/**
	* @brief add T element to end of container
	*/
	void push_back(const T& e) {
		if (_full()) {
			_expand();
		}
		data_[size_++] = e;
	}

private:

	static constexpr size_t default_capacity = 8;

	T* data_;
	size_t capacity_;
	size_t size_;

	bool _empty() const { return size_ == 0; }
	bool _full() const { return size_ == capacity_; }

	void _expand() {
		if (capacity_ * 2 < capacity_) {
			throw std::bad_alloc();
		}
		capacity_ *= 2;
		if (std::is_trivially_copyable<T>::value) {
			_tc_expand_exponential();
		} else {
			_ud_expand_exponential();
		}
	}

	/**
	* @brief expand vector of user-defined type, no optimization
	*/
	void _ud_expand_exponential() {
		T* ptr = static_cast<T*>(::operator new(capacity_ * sizeof(T)));
		for (size_t i = 0; i < size_; i++) {
			ptr[i] = std::move(data_[i]);
			data_[i].~T();
		}
		::operator delete(data_);
		data_ = ptr;
	}

	/**
	* @brief expand vector of trivially copyable type, using realloc optimization
	*/
	void _tc_expand_exponential() {
		T* ptr = static_cast<T*>(realloc(data_, capacity_ * sizeof(T)));
		if (ptr == nullptr) {
			throw std::bad_alloc();
		}
		data_ = ptr;
	}

};

};

};

#endif // VECTOR_HPP

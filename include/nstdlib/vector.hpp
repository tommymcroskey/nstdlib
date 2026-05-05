#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib>
#include <cstddef>
#include <memory>

namespace nstd {
inline namespace _vector_version_0_1_0 {

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
		
	Vector(const Vector& o) : Vector(o.capacity_) {
		for (; size_ < capacity_; size_++) {
			data_[size_] = o[size_];
		}
	}

	Vector(Vector&& o) noexcept
		: data_(o.data_)
		, capacity_(o.capacity_)
		, size_(o.size_)
	{ o.data_ = nullptr; }

	~Vector() {
		for (size_t i = 0; i < size_; i++) {
			data_[i].~T();
		}
		::operator delete(data_);
	}

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
		return data_[idx];
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
	const T& front() const {
		if (_empty()) {
			throw std::out_of_range("cannot get front of empty vector");
		}
		return (*this)[0];
	}

	T& front() {
		return const_cast<T&>(static_cast<const Vector&>((*this)).front());
	}

	/**
	* @brief returns the back of the vector
	*/
	const T& back() const {
		if (_empty()) {
			throw std::out_of_range("cannot get back of empty vector");
		}
		return (*this)[size_ - 1];
	}
		
	T& back() {
		return const_cast<T&>(static_cast<const Vector&>(*this).back());
	}

	size_t size() const noexcept { return size_; }
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
	bool _out_of_bounds(size_t idx) const { return idx >= size_; }
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
	* @brief user defined expand 2^n capacity for n usages
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
	* @brief trivially copyable expand 2^n capacity for n usage, using realloc optimization
	*/
	void _tc_expand_exponential() {
		T* ptr = static_cast<T*>(realloc((void*)data_, capacity_ * sizeof(T)));
		if (ptr == nullptr) {
			throw std::bad_alloc();
		}
		data_ = ptr;
	}
		
};

};

};

#endif // VECTOR_HPP

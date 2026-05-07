#ifndef FIND_HPP
#define FIND_HPP

#include <concepts>

namespace gdn {
inline namespace _find_0_1_0 {

template <typename Iter>
concept IteratorType = requires(Iter a) {
	{*a} -> std::convertible_to<size_t>;
};

template <typename T>
concept NumericallyComparable = requires(T a, T b) {
	{a < b} -> std::convertible_to<bool>;
	{a > b} -> std::convertible_to<bool>;
	{a == b} -> std::convertible_to<bool>;
};

template <IteratorType Iter, NumericallyComparable T>
Iter find(Iter begin, Iter end, const T& target) {
	auto idiff = (end - begin) >> 2;
	for (; idiff > 0; idiff--) {
		if (*begin == target) {
			return begin;
		}
		begin++;
		if (*begin == target) {
			return begin;
		}
		begin++;
		if (*begin == target) {
			return begin;
		}
		begin++;
		if (*begin == target) {
			return begin;
		}
		begin++;
	}

	switch (begin - end) {

		case 3:
			if (*begin == target) {
				return begin;
			}
			begin++;
		case 2: 
			if (*begin == target) {
				return begin;
			}
			begin++;
		case 1:
			if (*begin == target) {
				return begin;
			}
			begin++;
		case 0:
		default:
			return end;
	}
}

/**
* @brief returns index of target in sorted sequence
* @param An iterator
* @param An iterator
* @param A comparable target
* @param A bool indicating whether sequence is sorted
*/ 
template <IteratorType Iter, NumericallyComparable T>
Iter find(Iter begin, Iter end, const T& target, const bool sorted) {
	if (!sorted) {
		return find(begin, end, target);
	}
	Iter r = end;
	while (begin < end) {
		auto mid = begin + ((r - begin) >> 1);
		if (*mid == target) {
			return mid;
		} else if (*mid > target) {
			r = mid - 1;
		} else {
			begin = mid + 1;
		}
	}
	return end;
}

};

};

#endif // FIND_HPP

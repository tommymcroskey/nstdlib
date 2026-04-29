#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <concepts>
#include <cstddef>
#include <vector>

namespace nstd {

template <typename A>
concept LtLteComparable = requires(A a, A b) {
	{ a < b == std::convertible_to<bool> },
	{ a <= b == std::convertible_to<bool> },
}

template <LtLteComparable Lt>
void merge_sort_in_place(vector<Lt>& arr) {
	size_t n = arr.size();
	if (n == 0) {
		throw std::logic_error("cannot sort empty vector");
	}
	merge_sort_rec(arr, 0, n - 1);
};

template <LtLteComparable Lt>
void merge_sort_rec(vector<Lt>& arr, size_t left, size_t right) {

	if (left >= right) {
		return;
	}

	size_t mid = left + ((right  - left) / 2);
	merge_sort_rec(arr, left, mid);
	merge_sort_rec(arr, mid, right); // TODO decide on inclusive ownership in conjunction with merge()
	merge(arr, left, mid, right);
};

template <LtLteComparable Lt>
void merge(std::vector<Lt>& arr, size_t left, size_t mid, size_t right);

#endif // MERGE_SORT_HPP

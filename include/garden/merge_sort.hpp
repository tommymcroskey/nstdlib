#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <concepts>
#include <cstddef>
#include <vector>

namespace gdn {
inline namespace _merge_sort_0_1_0 {

template <typename T>
concept LtComparable = requires(T a, T b) {
	{a < b} -> std::convertible_to<bool>;
};

template <LtComparable Lt>
void merge_lt(std::vector<Lt>& arr, size_t left, size_t mid, size_t right) {

	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	std::vector<Lt> v1, v2;
	v1.reserve(n1);
	v2.reserve(n2);

	for (size_t i = 0; i < n1; i++) {
		v1.push_back(arr[i + left]);
	}
	for (size_t j = 0; j < n2; j++) {
		v2.push_back(arr[j + mid + 1]);
	}

	size_t i = 0, j = 0, wptr = left;
	while (i < n1 && j < n2) {
		if (v1[i] <= v2[j]) {
			arr[wptr++] = v1[i++];
		} else {
			arr[wptr++] = v2[j++];
		}
	}

	while (i < n1) {
		arr[wptr++] = v1[i++];
	}
	while (j < n2) {
		arr[wptr++] = v2[j++];
	}
}

template <LtComparable Lt>
void merge_sort_rec_lt(std::vector<Lt>& arr, size_t left, size_t right) {

	if (left >= right) {
		return;
	}

	size_t mid = left + ((right  - left) / 2);
	merge_sort_rec_lt(arr, left, mid);
	merge_sort_rec_lt(arr, mid + 1, right);
	merge_lt(arr, left, mid, right);
}

template <LtComparable Lt>
void merge_sort_in_place_lt(std::vector<Lt>& arr) {
	size_t n = arr.size();
	if (n < 2) {
		return;
	}
	merge_sort_rec_lt(arr, 0, n - 1);
}

};

};

#endif // MERGE_SORT_HPP

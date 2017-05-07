#include <iostream>

int *merge(const int array_first[], const int size_first, const int array_second[], const size_t size_second, const size_t size_third) {
	int *array_third = new int[size_third];

	auto first1 = array_first;
	auto last1 = array_first + size_first;
	auto first2 = array_second;
	auto last2 = array_second + size_second;
	size_t count_first = 0;
	size_t count_second = 0;
	size_t count_third = 0;

	for (; first1 != last1; ++array_third, count_third++) {
		if (first2 == last2) {
			while (first1 != last1) {
				*array_third++ = *first1++;
				count_first++;
				count_third++;
			}
			for (size_t i = 0; i < count_first; ++i)
				array_first--;
			for (size_t i = 0; i < count_third; ++i)
				array_third--;
			return array_third;
		}
		if (*first2 < *first1) {
			*array_third = *first2;
			++first2;
			count_second++;
		}
		else {
			*array_third = *first1;
			++first1;
			count_first++;
		}
	}

	while (first2 != last2) {
		*array_third++ = *first2++;
		count_third++;
	}

	for (size_t i = 0; i < count_first; ++i)
		array_first--;
	for (size_t i = 0; i < count_second; ++i)
		array_second--;
	for (size_t i = 0; i < count_third; ++i)
		array_third--;

	return array_third;
}

int main() {
	std::cout << "First array (size): ";
	size_t size_first;
	std::cin >> size_first;
	std::cout << "Second array (size): ";
	size_t size_second;
	std::cin >> size_second;

	while (std::cin.get() != '\n')
		continue;

	int *array_first = new int[size_first];
	int *array_second = new int[size_second];

	for (size_t i = 0; i < size_first; ++i)
		array_first[i] = i + 100;

	for (size_t i = 0; i < size_second; ++i)
		array_second[i] = i;

	size_t size_third = size_first + size_second;
	int *array_third = merge(array_first, size_first, array_second, size_second, size_third);

	std::cout << "Merged array:\n";
	for (size_t i = 0; i < size_third; ++i)
		std::cout << array_third[i] << " ";

	delete[] array_first;
	delete[] array_second;
	delete[] array_third;

	std::cin.get();
}

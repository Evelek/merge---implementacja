#include <stdio.h>
#include <stdlib.h>

int *merge(const int array_first[], const int size_first, const int array_second[], const size_t size_second, const size_t size_third) {
	int *array_third = (int *)malloc(size_third * sizeof(int));

	const int *first1 = array_first;
	const int *last1 = array_first + size_first;
	const int *first2 = array_second;
	const int *last2 = array_second + size_second;
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
	puts("First array (size): ");
	size_t size_first;
	scanf_s("%u", &size_first);
	puts("Second array (size): ");
	size_t size_second;
	scanf_s("%u", &size_second);

	while (getchar() != '\n')
		continue;

	int *array_first = (int *)malloc(size_first * sizeof(int));
	int *array_second = (int *)malloc(size_second * sizeof(int));

	for (size_t i = 0; i < size_first; ++i)
		array_first[i] = i + 100;

	for (size_t i = 0; i < size_second; ++i)
		array_second[i] = i;

	size_t size_third = size_first + size_second;
	int *array_third = merge(array_first, size_first, array_second, size_second, size_third);

	puts("Merged array:\n");
	for (size_t i = 0; i < size_third; ++i)
		printf("%d ", array_third[i]);

	free(array_first);
	free(array_second);
	free(array_third);

	getchar();
}

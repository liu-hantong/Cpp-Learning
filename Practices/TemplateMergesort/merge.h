#pragma once
template <typename T>
T* merge(T* array_1, size_t size_1, T* array_2, size_t size_2) {
	//merge sort
	T *final = new T[size_1 + size_2];
	int array1 = 0;
	int array2 = 0;
	int final_index = 0;
	while (array1 < size_1 && array2 < size_2) {
		if (array_1[array1] <= array_2[array2])
			final[final_index++] = array_1[array1++];
		if (array_1[array1] > array_2[array2])
			final[final_index++] = array_2[array2++];
	}
	if (array1 == size_1)
		for (; array2 < size_2; array2++)
			final[final_index++] = array_2[array2];
	if (array2 == size_2)
		for (; array1 < size_1; array1++)
			final[final_index++] = array_1[array1];
	return final;
}
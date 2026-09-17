#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int insertion_sort(int* A, int length) {
	if (A == NULL) return 0; 

	for (int i = 1; i < length; ++i) {
		int tmp = A[i];
		int j = i;

		while (tmp < A[j-1] && j > 0) {
			A[j] = A[j-1];
			--j;
		}
		A[j] = tmp;
	}
	return 0;
}

int create_array(int* array, int length) {
	srand(time(NULL));

	for(int i = 0; i < length; ++i) {
		int signal = rand() % 2;

		array[i] = rand() % 100;

		if (signal == 1) {
			array[i] *= -1;
		}
	}

	return 0;
}

int display_array(int* array, int length) {
	printf("[");
	for (int i = 0; i < length; ++i) {
		printf("%d, ", array[i]);
	}
	printf("\b\b]");
	
	return 0;
}
int main() {
	int length = 100;
	int* array = malloc(length * sizeof(*array));
	create_array(array, length);
	display_array(array, length);
	insertion_sort(array, length);
	display_array(array, length);
}

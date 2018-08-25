#include "sort.h"

void Algorithm_selector(double *arr, int size){
	printf("Choose an algorithm: (I)nsersion sort, (S)election sort, (B)ubblesort, (M)ergesort, (Q)uicksort.\n>_");
	char algo;
	scanf("%c", &algo);
	getchar();

	switch(algo){
		case 'I':
			isort_g2s(arr, size);
			break;
		case 'i':
			isort_s2g(arr, size);
			break;
		case 'S':
			sSort_g2s(arr, size);
			break;
		case 's':
			sSort_s2g(arr, size);
			break;
		case 'B':
		case 'b':
			bubbleSort(arr, size);
		case 'M':
		case 'm':
			split(arr, 0, size-1);
			break;
		case 'Q':
		case 'q':
			quicksort(arr, 0, size-1);
			break;
		default:
			puts("Algorithm not found. Try again, later.");
			exit(1);
	}
}

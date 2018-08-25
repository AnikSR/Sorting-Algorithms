#include "sort.h"

/* Selection sort is an alter ego of insertion sort. They are basically same algorithm,
 * seen from different point of views. In the selection sort point of view:
 * 1. The array is scanned from the beginning to the end for the smallest value.
 * 2. Once found, it is swapped with the first(i=0) element of the array. Thus the first
 * element becomes sorted.
 * 3. The scanning restarts from the next element as the outter for loop advances to i = 1.
 * Once the smallest of the remaining elements is found, its swapped with with second element
 * of the array.
 * 4. This process continues till the last element, sorting the array from smallest element to
 * the largest. */
void sSort_s2g(double *Arr, int n){
	int i, j, k;
       	double tmp;

	for(i = 0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			k = i;
			tmp = Arr[i];

			if(Arr[k] > Arr[j])
				k = j;
			Arr[i] = Arr[k];
			Arr[k] = tmp;		
		}
	}
}

/* To sort the elements in the other direction, the algorithm just have to scan for the highest
 * element instead of the smallest element in each cycle of scanningand pluck it to the beginning
 * of the array till the last element. */
void sSort_g2s(double *Arr, int n){
	int i, j, k;
	double tmp;

	for(i = 0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			k = i;
			tmp = Arr[i];

			if(Arr[k] < Arr[j])
				k = j;
			Arr[i] = Arr[k];
			Arr[k] = tmp;		
		}
	}
}

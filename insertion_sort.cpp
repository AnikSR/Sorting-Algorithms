#include "sort.h"

/* The main theme of insertion sort is to take each element from one side of the array  *
 * and insert it to its rightful position. Here is how it is done here:                 *
 ****************************************************************************************/ 
void isort_s2g(double *array, int n){
	/* 1. Sorting starts from the beginning of the array. The first position(index i = 0)
	 * is taken as sorted and the next element(i=1) is taken as the key.
	 * 
	 * 2. If the key is smaller than the first element, they swap their locations. This places
	 * the smaller element in the beginning of the array and the larger element is after it.
	 * 
	 * 3. Now first two array elements being sorted, the for loop advances to i = 2, the
	 * 3rd array element now becomes the key.
	 *
	 * 4. the while loop compares the key with the first two sorted elements, swapping it with
	 * earlier elements if necessary.
	 *
	 * 5. This process continues until the for loop reaches the final element(i = size -1). Now
	 * the final element becomes the key and the while loop compares it with all the previous
	 * sorted elements, "inserting" it in the proper location. With all the element now placed
	 * to its rightful location, sorting is now complete. */
	int i, j, key;
	for(i=1; i<n; i++)
	{
		key = array[i];
		j = i-1;

		while(j>=0 && key<array[j])
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

void isort_g2s(double *array, int n){
	/* Sorting the array greater to smaller direction works just the same way. Only this time
	 * the while loop swaps the key with previous elements if it is greater than the previous
	 * elements. As a result the largest element end up in the beginning of the array with the
	 * smallest element at the end. */
	int i, j, key;
	for(i=1; i<n; i++)
	{
		key = array[i];
		j = i-1;

		while(j>=0 && key>array[j])
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

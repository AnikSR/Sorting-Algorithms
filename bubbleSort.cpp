#include "sort.h"

/* Bubble sort is also called sinksort. Because arry elements with higher values
 * progressively sinks to the bottom as the sorting progresses. Just as heavier
 * elements sinks in the bottom of a ferness with the progess of smelting. This
 * algorithm in step by step manner looks like this:
 *
 * 1. Sorting start from the first(j=0) element of the array. This first element
 * is compared to the next element, if the next element is smaller, it is swapped
 * with this next element.
 * 2. As the inner for loop progresses to j=1, the next element is compared to
 * its next element with swapping if necessary.
 * 3. This is repeated till the last two array elements(arr[size-2] and arr[size-1]
 * are compared and if necessary swapped.
 * 4. The outter loop restarts the process from i=1 and repeats the whole thing in
 * total of size-1 times, sinking all "size" number of elements according to their
 * density(value). */
void bubbleSort(double *arr, int size){
	
	for(int i = 0; i< size-1; i++)
		for(int j = 0; j< size-1; j++)
			if(arr[j] > arr[j+1]){
				double temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}

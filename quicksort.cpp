#include "sort.h"

void quicksort(double *arr, int low, int high){ 
	if(low < high){
		int i = low, j = high;
		double pivot = arr[low];

		/* Start screening the array from left for a value greater than pivot.
		 * Then screen from the right for a value smaller than pivot.
		 * Then swap them if the larger value is upstream to the smaller value.
		 * Continue screening and swapping until the whole array is screened.
		 * Then place the pivot where search for a smaller value stopped.
		 * The older value therein must be first transfered to the old location of pivot. */
		while(i< j){
			while(arr[i] <= pivot && i<= high)
				i++;
			while(arr[j] > pivot && j >= low)
				j--;

			if(i< j){
				double temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}	

		arr[low] = arr[j];
		arr[j] = pivot;

		// Now once they are divided, conquer them.
		quicksort(arr, low, j-1);
		quicksort(arr, j+1, high);
	}
}

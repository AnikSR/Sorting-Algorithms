#include "sort.h"

/* split():
 * This function will take the input array and recursively
 * divide the array until its down to single element. Then
 * call will return to previous call to split() which will
 * transfer single element array to merge() which will sort
 * by merging. Then split() will return to even earlier call
 * mergin now sorted array from previous call until the whole
 * array is sorted. */
void split(double *inputArray, int low, int high){
	int mid = 0;

	if(low < high){
		mid = (low+high)/2;
		// Devide.
		split(inputArray, low, mid);
		split(inputArray, mid+1, high);
		// And Conquer(sort by merging).
		merge(inputArray, low, mid, high);
	}
}


/* Merge(): 
 * This function takes the split array, compares, sorts and
 * merges it into bigger sorted array. This function performs
 * the conquer step of mergesort algorithm. */
void merge(double *inputArray, int low, int mid, int high){
	int n1, n2;	// Variable to hold array size.
	int i, j, k;	// Index variable.
	
	n1 = mid - low + 1;
	n2 = high - mid;

	double arr1[n1+1], arr2[n2+1];

	for(i = 0; i< n1; i++)
		arr1[i] = inputArray[low+i];
	for(j = 0; j< n2; j++)
		arr2[j] = inputArray[mid+1+j];

	// Marks the end of array, just as '\0' indicated end of string in C.
	arr1[i] = 994967296;
	arr2[j] = 994967296;

	i = 0; j = 0;
	for(k = low; k<= high; k++){
		if(arr1[i] <= arr2[j]){
			inputArray[k] = arr1[i];
			i++;
		}
		else{
			inputArray[k] = arr2[j];
			j++;
		}
	}
}

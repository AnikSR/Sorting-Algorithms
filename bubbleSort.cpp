#include "sort.h"


void bubbleSort(double *arr, int size){

	for(int i = 0; i< size; i++)
		for(int j = 0; j<size; j++)
			if(arr[j] > arr[j+1]){
				double temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}

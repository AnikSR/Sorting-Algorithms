#include "sort.h"

void isort_g2s(double *array, int n){
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

 
void isort_s2g(double *array, int n){
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

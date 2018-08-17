#include "sort.h"

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

#ifndef SORT_H
#define SORT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

// Input functions.
void FinputCollector();
void KinputCollector();

// Algorithm selector.
void Algorithm_selector(double *, int);

// Sorting algorithms.
void isort_g2s(double *, int);
void isort_s2g(double *, int);
void sSort_g2s(double *, int);
void sSort_s2g(double *, int);
void split(double * , int, int);
void merge(double * , int, int, int);
void quicksort(double * , int, int);

// Output function.
void printArray(double *, int);

#endif

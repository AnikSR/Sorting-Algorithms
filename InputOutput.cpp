/* This file contains the functions to read the input array for sorting and function that outputs the sorted array. 	*
 * Note: The input functions transfer the input array directly to the sorter function and then to the output function.	*
 * This is because, the goal here was to get the array size from input, so that array of any size can be processed. The *
 * array must either be a global or declared inside main() if further processing of the array is to be done by main().  *
 * In those cases, the size have to be declared before knowing the input array size, limiting possible input size.	*/
#include "sort.h"

void FinputCollector(){
	FILE *fp;
	char filename[80];
	double buffer;
			
	// Collect the input filename and chip off the tailing "newline" kept by fgets() .
	printf("Filename: ");
	fgets(filename, 80, stdin);
	int n = strlen(filename);
	filename[n-1] = '\0';

	// Open the input file to read the input array. Or, abort the program.
	if((fp = fopen(filename, "r")) == NULL){
		perror("Can not open file");
		exit(1);
	}

	// In this scan, the function will count how many numbers to be sorted.
	int length = 0;
	while((fscanf(fp, "%lf\n", &buffer))!= EOF)
		length++;

	/* The input scan:
	 * The frepoen() resets the file position indicator to the beginning of the file.
	 * Then fscanf() scans the input number to the input array. */
	freopen(filename, "r", fp);
	double input[length];
	for(int i = 0; i< length; i++){
		fscanf(fp, "%lf\n", &input[i]);
	}

	// Finally, sort and print.
	Algorithm_selector(input, length);
	printArray(input, length);

	fclose(fp);
	fp = NULL;
}


void KinputCollector(){
	int n;

	printf("How many numbers to be sorted?\n>_");
	scanf("%d", &n);

	double input[n];

	for(int i = 0; i< n; i++){
		printf("Num%d: ", i+1);
		scanf("%lf", &input[i]);
	}
	getchar();

	Algorithm_selector(input, n);
	printArray(input, n);
}


void printArray(double *inputArray, int length){
	/* This function outputs the sorted array. Based on what option is selected
	 * it can output the array to console or to a file. If the selected file
	 * already exists, then based on option given, it can overwrite or append
	 * to the existing file.*/
	char opt;

	puts("Press \'f\' to redirect sorted array to a file");
	scanf("%c", &opt);
	getchar();
	if(opt == 'f' || opt == 'F'){
		char filename[80], overwrite;
		FILE *fp;

		// Collect the output filename and chip off the trailing "newline" kept by fgets().
		printf("Filename: ");
		fgets(filename, 80, stdin);
		int len = strlen(filename);
		filename[len-1] = '\0';

		/* access(), defined in unistd.h detects whether a file of <filename> already exist in the file. 
		  It does so by checking if the file path specified by <filename> is accessable. If such a file
		  is found access() returns 0. If no such file exists in current directory, it returns -1. */
		int n = access(filename, F_OK);
		if(n != -1){
			puts("File already exists, overwrite or append? (o)verwrite, (a)ppend, output to (c)onsole.");
			scanf("%c", &overwrite);
			getchar();
		}
			
		/* If its a new filename(n==-1) or if the operator wants to overwrite or append the result to the old file:
		 * Try to open the file. If it opens, write the output to it. If it doesn't, print output to the console. */
		int indicator = 0;
		if(n == -1 || (n != -1 && (overwrite == 'o' || overwrite == 'O'))){
			if((fp = fopen(filename, "w")) != NULL)
				indicator = 1;
		}
		else if(n == -1 || (n != -1 && (overwrite == 'a' || overwrite == 'A'))){
			if((fp = fopen(filename, "a")) != NULL){
				fputs("\n", fp);
				indicator = 1;
			}
		}
		else if(n!= -1 &&(overwrite != 'y' || overwrite != 'Y' || overwrite != 'a' || overwrite != 'A'))
			puts("Printing output to the console.");
		else{
			perror("Can't open file");
			puts("Printing output to the console.");
		}

		/* The indicator variable seperates file opening and writting. As a result single writing sequence can be used to both 
		 * overwrite or append to the file. Output is written to file only if file is successfully openned(indicator ==1). */
		if(indicator == 1){
			for(int i = 0; i< length; i++)
				fprintf(fp, "%lf\n", inputArray[i]);
			fclose(fp);
			fp = NULL;
			return;
		}
	}

	printf("length = %d\n", length);
	for(int i = 0; i< length; i++)
		printf("%d: %lf\n", i+1, inputArray[i]);
}

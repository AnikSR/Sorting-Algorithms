#include "sort.h"

int main(int argc, char *argv[]){
	/* Collection of input data. */
	// If command line arguments are given, input is taken from command line.
	if(argc > 1){
		int size = argc - 1;
		double inputArray[size];

		for(int i = 0; i< size; i++)
			inputArray[i] = atof(argv[i+1]);

		Algorithm_selector(inputArray, size);
		printArray(inputArray, size);
	}
	// Else if arguments are typed in or comes from a file.
	else{
		char opt;
		puts("Input numbers from? Keyboard(k), File(f), Quit(q)");
		scanf("%c", &opt);
		getchar(); //To clear stdin.

		if(opt == 'f' || opt == 'F')
			FinputCollector();
		else if(opt == 'k' || opt == 'K')
			KinputCollector();
		else if(opt == 'q' || opt == 'Q')
			puts("See you again, have a good day.");
		else{
			puts("Unauthorized input source. Try again later.");
			return 1;
		}
	}

	return 0;
}

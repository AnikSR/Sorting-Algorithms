CPPFLAGS = -Wall -g

objects =  sort.o InputOutput.o Algorithm_selector.o insertion_sort.o selection_sort.o bubbleSort.o mergesort.o quicksort.o

sort:	$(objects)
	cc -o sort $(objects) -lstdc++

clean:
	rm -f sort $(objects)

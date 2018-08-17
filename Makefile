CPPFLAGS = -Wall -g

objects =  sort.o InputOutput.o insertion_sort.o selection_sort.o mergesort.o quicksort.o Algorithm_selector.o

sort:	$(objects)
	cc -o sort $(objects) -lstdc++

clean:
	rm -f sort $(objects)

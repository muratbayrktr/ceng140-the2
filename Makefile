main:
	gcc main.c functions.c -ansi -Wall -pedantic-errors -o main
	
clean:
	rm main

selection_sort:
	gcc selection_sort.c -ansi -Wall -pedantic-errors -o main
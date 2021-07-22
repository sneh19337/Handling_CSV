#please see the ouput by typing ./q1 after running the makefile
q1: q1.o
	gcc q1.o -o q1
	
q1.o: q1.s
	gcc -c q1.s -o q1.o
	
q1.s: q1.i
	gcc -S q1.i -o q1.s

q1.i: q1.c
	gcc -E q1.c -o q1.i
clean:
	rm q1.i q1.s q1.o q1
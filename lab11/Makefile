all: labSD

labSD: graph.o main.c
	gcc main.c graph.o list.o stack.o queue.o heap.o -o labSD -g

graph.o: list.o stack.o queue.o heap.o graph.h graph.c
	gcc -c graph.c -g

list.o: list.c list.h
	gcc -c list.c -g

stack.o: stack.c stack.h
	gcc -c stack.c -g

queue.o: queue.c queue.h
	gcc -c queue.c -g

heap.o: heap.c heap.h
	gcc -c heap.c -g

clean:
	rm -f *.o *~ labSD rm *.dot *.png


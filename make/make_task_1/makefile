
main.o : main.c
	gcc -c main.c

add.o : add.o
	gcc -c add.c

a.out : main.o add.o
	gcc main.o add.o
.PHONY:clean
clean:
	rm add.o main.o a.out



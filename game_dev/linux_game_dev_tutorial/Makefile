test:
	make build;
	./demo.out;

build:
	gcc -Wall -c demo.c -I "/usr/include/SDL";
	gcc demo.o -lSDL -o demo.out;

clean:
	-rm demo.o;
	-rm demo.out;

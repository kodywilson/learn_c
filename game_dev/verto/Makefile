test:
	make build;
	./game.out;

build:
	gcc -Wall -c game.c -I "/usr/include/SDL2";
	gcc game.o -lSDL -o game.out;

clean:
	-rm game.o;
	-rm game.out;

test:
	make build;
	./game.out;

build:
	gcc -o game.out game.c `sdl2-config --cflags --libs`
	#gcc -Wall -g game.c -I "/usr/include/SDL2";
	#gcc game.o -lSDL -o game.out;
	#gcc -g game.c -o game.out -I "/usr/include/SDL2" $(pkg-config --cflags --libs sdl2)

clean:
	-rm game.o;
	-rm game.out;

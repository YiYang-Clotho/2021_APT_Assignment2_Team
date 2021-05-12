objects = test_main.o TestPlayer.o ../src/Tile.o\
 ../src/Node.o ../src/LinkedList.o ../src/Player.o 



unit_test: $(objects)
	g++ -Wall -std=c++14 -g -O -o unit_test $(objects) 




clean:
	rm -rf qwirkle *.o *.dSYM
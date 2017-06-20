CPPFLAGS= -c -g -Iinc -fpermissive -std=c++11 -Wall -pedantic

__START__: tablica
	./tablica

tablica: obj/main.o obj/BinaryTree.o obj/stoper.o
	g++ -o tablica obj/main.o obj/BinaryTree.o obj/stoper.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o	src/stoper.cpp

obj/BinaryTree.o: src/BinaryTree.cpp inc/BinaryTree.hh
	g++ ${CPPFLAGS} -o obj/BinaryTree.o src/BinaryTree.cpp

clean:
	rm -f obj/*.o tablica

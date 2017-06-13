CPPFLAGS= -c -g -Iinc -fpermissive -std=c++11 -Wall -pedantic

__START__: drzewoAvl
	./drzewoAvl

drzewoAvl: obj/main.o obj/avlTree.o obj/stoper.o
	g++ -o drzewoAvl obj/main.o obj/avlTree.o obj/stoper.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o	src/stoper.cpp

obj/avlTree.o: src/avlTree.cpp inc/avlTree.hh
	g++ ${CPPFLAGS} -o obj/avlTree.o src/avlTree.cpp

clean:
	rm -f obj/*.o drzewoAvl

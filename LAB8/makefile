CPPFLAGS= -c -g -Iinc -fpermissive -std=c++11 -Wall -pedantic

<<<<<<< HEAD
__START__: tablica
	./tablica

tablica: obj/main.o obj/BinaryTree.o obj/stoper.o
	g++ -o tablica obj/main.o obj/BinaryTree.o obj/stoper.o
=======
__START__: drzewoAvl
	./drzewoAvl

drzewoAvl: obj/main.o obj/avlTree.o obj/stoper.o
	g++ -o drzewoAvl obj/main.o obj/avlTree.o obj/stoper.o
>>>>>>> 6c3980df66229e94b01ad4e7bb63e150874bf6bc
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o	src/stoper.cpp

<<<<<<< HEAD
obj/BinaryTree.o: src/BinaryTree.cpp inc/BinaryTree.hh
	g++ ${CPPFLAGS} -o obj/BinaryTree.o src/BinaryTree.cpp

clean:
	rm -f obj/*.o tablica
=======
obj/avlTree.o: src/avlTree.cpp inc/avlTree.hh
	g++ ${CPPFLAGS} -o obj/avlTree.o src/avlTree.cpp

clean:
	rm -f obj/*.o drzewoAvl
>>>>>>> 6c3980df66229e94b01ad4e7bb63e150874bf6bc

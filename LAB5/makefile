CPPFLAGS= -c -g -Iinc -fpermissive -std=c++11 -Wall -pedantic

__START__: tablica
	./tablica

tablica: obj/main.o obj/tablica.o obj/stoper.o obj/Stack.o obj/Queue.o obj/List.o
	g++ -o tablica obj/main.o obj/tablica.o obj/stoper.o obj/Stack.o obj/Queue.o obj/List.o

obj/main.o: src/main.cpp inc/tablica.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh
	g++ ${CPPFLAGS} -o obj/tablica.o src/tablica.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o	src/stoper.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/Queue.o src/Queue.cpp

obj/List.o: src/List.cpp inc/List.hh
	g++ ${CPPFLAGS} -o obj/List.o src/List.cpp


clean:
	rm -f obj/*.o tablica

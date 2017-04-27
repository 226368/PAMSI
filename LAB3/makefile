CPPFLAGS= -c -g -Iinc -fpermissive

__START__: tablica
	./tablica

tablica: obj/main.o obj/tablica.o obj/stoper.o obj/zbior_danych.o obj/Stack.o obj/Queue.o
	g++ -o tablica obj/main.o obj/tablica.o obj/stoper.o obj/zbior_danych.o obj/Stack.o obj/Queue.o

obj/main.o: src/main.cpp inc/tablica.hh inc/zbior_danych.hh inc/Stack.hh inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh
	g++ ${CPPFLAGS} -o obj/tablica.o src/tablica.cpp

obj/stoper.o: src/stoper.cpp inc/stoper.hh
	g++ ${CPPFLAGS} -o obj/stoper.o	src/stoper.cpp

obj/zbior_danych.o: src/zbior_danych.cpp inc/zbior_danych.hh
	g++ ${CPPFLAGS} -o obj/zbior_danych.o src/zbior_danych.cpp

obj/List.o: inc/List.hh
	g++ ${CPPFLAGS} -o List.o

obj/iList.o: inc/iList.hh
	g++ ${CPPFLAGS} -o iList.o

obj/Stack.o: src/Stack.cpp inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/Queue.o src/Queue.cpp


clean:
	rm -f obj/*.o tablica

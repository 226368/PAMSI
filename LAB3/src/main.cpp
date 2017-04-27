#include <iostream>

#include "tablica.hh"
#include "Stack.hh"
#include "Queue.hh"
using namespace std;



int main() {

/*		Tablica tab;
		tab.dziala();

// program do testowania czasu działania

		tab.wyswietl();
		tab.zmien_rozmiar();
		tab.wyswietl();

//program właściwy

*/

//MeasureAble *wsk = new Tablica;

//wsk -> zmien_rozmiar();
//wsk -> wyswietl();
//wsk -> measureTime();

/*iStack *stos = new Stack;
 for(int i=0;i<10;i++)
 {
	 stos->push(rand()%10);
 }

while(!stos->isEmpty())
{
	cout << stos->top() << endl;
	stos->pop();
}*/

iQueue *stos = new Queue;
 for(int i=0;i<10;i++)
 {
	 stos->enqueue(i);
 }

while(!stos->isEmpty())
{
	cout << stos->front() << endl;
	stos->dequeue();
}

	return 0;

}

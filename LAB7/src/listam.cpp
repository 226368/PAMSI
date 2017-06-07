
#include "listam.hh"
#include <iostream>

using namespace std;

Lista::Lista(){
	head = 0;      // ustawiam wartosc na NULL
}
Lista::Lista(int i,Lista *in = 0){
	element = i;
	next = in;
}

int Lista::getElement(int number){
	Lista *temp = head; // wskazuje na pierwszy element listy
	//int i=1;
	if(number == 1) {
		return temp->element;
	}
	if(number > sum()){
		cout << "BLAD !!!!!! przekroczono liste" << endl;
		return number;
	}
	for(int i=1;i<number;i++){
		temp=temp->next;
		//cout << "wykonuje sie petla" << endl;
	}
	return temp->element;
}

void Lista::pushFront(int nowyEl){
	count++;                        // zliczanie elementow listy
	head = new Lista(nowyEl,head);  // miejsce na nowy element listy

}

int Lista::deleteFront(){
	int el = head->element;
	Lista *tmp = head;
	head =head->next;
	delete tmp;
	return el;
}

int Lista::deleteElement(int number){
	if(number == 1){
		deleteFront();
	}
	else{
		int j =1;
		// aby usunac element na pozycji 'number' potrzebuje wskaznik na poprzedni element czli number-1
		Lista *temp = head; // wsjaznik bezie po wykoniau petli wskaznikiem na poprzedni element listy

		while(temp){
			// warunek konczacy petle , znalezienie number-1
			if((j+1)==number) break;
			temp = temp->next;
			j++;
		}

		if(temp->next->next == 0){
			temp->next = 0; // czy element number+1 jest ostatni ?
		}
		else{
			temp->next = temp->next->next;
		}
	}
return number;
}

void Lista::printAll(){
	Lista *temp = head;
	if(count == 0) cout << "Lista jest pusta ! " << endl;
	else{
			while(temp){
				cout << temp->element << " ";
				temp=temp->next; // przejscie do nastepnego elementu
			}

	cout << endl;
	}
}

int Lista::sum(){\
	return count;
}

void Lista::deleteAll(){  // funkcja dziala na podstawie petli wykorzystujacecej juz wczesniej napisana metode usuwajaca element z listy na przodzie
		for(int i=0;i<sum();i++){
		deleteFront();
	}
	count = 0;    // wyzerowna zmienna przechowujaca ilosc elementow listy

}

Lista::~Lista() {
	// TODO Auto-generated destructor stub
}

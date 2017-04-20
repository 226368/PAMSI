// Autor Przemyslaw Jordanek - PAMSI quicksort
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <math.h>
#include <fstream>
#include <ctime>

using namespace std;

//============================= Pivot == MEDIANA ==================================
void QuickSort(int tab[], int left, int right) { //jako element do por�wnania wybierana jest mediana

      int i = left, j = right;                     // elem najbardzie po lewej / prawej
      int tmp;                                      // zmienna pomocnicza
      int pivot = tab[(left + right) / 2]; //pivot jest elementem srodkowym

      while (i <= j) {                      // dop�ki i < j
            while (tab[i] < pivot)          // p�tla trwa do czasu gdy pivot b�dzie mniejszy od elem tab[i]
                  i++;
            while (tab[j] > pivot)          // w druga strone
                  j--;
            if (i <= j) {                       // kiedy dojdzie do miejsca w ktorym i > pivot i j < pivot
                  tmp = tab[i];
                  tab[i] = tab[j];
                  tab[j] = tmp;
                  i++;
                  j--;
            }
      }
      if (left < j)                                 // dziel i zwyciezaj ( po przejsciu petli j jest lo lewej od pivota
            QuickSort(tab, left, j);
      if (i < right)
            QuickSort(tab, i, right);
}

//================= PIVOT == elem najbardziej z lewej ==============================
void QuickSort_lewa(int t[], int l, int p) //jako element por�wnania wybiera pierwszy od lewej
{
	if ( l < p )
    {

         int m=l;
         for ( int i=l+1; i <= p; i++ )
         {
              if ( t[i] < t[l] )                // jesli elem po pivocie jest < od niego to zamien
              {
                   int temp = t[++m];
                   t[m]=t[i];
                   t[i]=temp;                   // elem uporzadkowane wzgl pivota
              }
         }
          int temp=t[l];
          t[l]=t[m];
          t[m]=temp;

              QuickSort_lewa(t,l,m-1);
              QuickSort_lewa(t,m+1,p);
    }

}

// =============================== FUNKCJE DO OBSLUGI ALGORYTMU =========
void wypelnij_tab_rand(int tab[],int size)      // wypelnienie randomowe
{
	for (int i=0;i<size;i++)
	{
		tab[i]=rand() % 100;
	}
}

void wypelnij_tab_malejaco(int tab[],int size)
{
	for (int i=0;i<size;i++)
	{
	 tab[i] = size*3 - 2*i;
	}
}

void wypelnij_tab_rosnaco(int tab[],int size)
{
	for (int i=0;i<size;i++)
	{
		tab[i] = i * 2 + 2 ;
	}
}

void wyswietl_tab(int tab[],int size)
{
	for (int i=0;i<size;i++)
	{
	cout<<tab[i]<<" , ";
	if(!(i%10))                 // co 10 cyfr przechodzi do nast linii
        cout << endl;
	}
}

void sprawdz_sort(int tab[],unsigned int size)
{
	for(unsigned int i=0;i<(size-1);i++)
	{
		if (tab[i+1]<tab[i])
		{
			cout<<"\n\nTablica nie jest posortowana rosnaco!!!\n\n";
			break;
		}
	}
}

int *pom;

void scal(int tablica[], int lewy, int srodek, int prawy)
{
  //int *pom = new int[]

  int i = lewy, j = srodek + 1;

  //kopiujemy lewą i prawą część tablicy do tablicy pomocniczej
  for(int i = lewy;i<=prawy; i++)
    *(pom+i) = *(tablica+i);

  //scalenie dwóch podtablic pomocniczych i zapisanie ich
  //we własciwej tablicy
  for(int k=lewy;k<=prawy;k++)
  if(i<=srodek)
    if(j <= prawy)
         if(pom[j]<pom[i])
             *(tablica+k) = *(pom+(j++));
         else
             *(tablica+k) = *(pom+(i++));
    else
        *(tablica+k) = *(pom+(i++));
  else
      *(tablica+k) = *(pom+(j++));
}

void sortowanie_przez_scalanie(int tablica[],int lewy, int prawy)
{
  //gdy mamy jeden element, to jest on już posortowany
  if(prawy<=lewy) return;

  //znajdujemy srodek podtablicy
  int srodek = (prawy+lewy)/2;

  //dzielimy tablice na częsć lewą i prawa
  sortowanie_przez_scalanie(tablica, lewy, srodek);
  sortowanie_przez_scalanie(tablica, srodek+1, prawy);

  //scalamy dwie już posortowane tablice
  scal(tablica, lewy, srodek, prawy);
}

// ===================== FUNKCJA DO OBSLUGI ALGORYTMOW +pomiar czasu =====
void sortuj(int tablica[], unsigned int n, int wyb, int lp)
{
	ofstream plik;
	clock_t StartTime, StopTime;        // do pomiaru czasu
	double zegar;                                   // do przechowywania czasu

	switch (wyb)
	{
	case 1:
        plik.open("QickSort.txt",ios::out);         // tworze nowy plik

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_rand(tablica,n);
			//wyswietl_tab(tablica,n);
			cout << endl << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort(tablica,0,n-1);
            cout << endl << endl;
			sprawdz_sort(tablica,n);
            StopTime=clock();
            //wyswietl_tab(tablica,n);
        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << endl << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla randomowej."<<endl;
		}
		plik.close();
		break;

	case 2:
		plik.open("QickSort.txt",ios::out);         // tworze nowy plik

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_malejaco(tablica,n);
			//wyswietl_tab(tablica,n);
			cout << endl << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort(tablica,0,n-1);
            cout << endl << endl;
			sprawdz_sort(tablica,n);
            StopTime=clock();
            //wyswietl_tab(tablica,n);
        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << endl << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla malejacej."<<endl;
		}
		plik.close();
		break;

	case 3:
        plik.open("QickSort.txt",ios::out);         // tworze nowy plik

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_rosnaco(tablica,n);
			//wyswietl_tab(tablica,n);
			cout << endl << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort(tablica,0,n-1);
            cout << endl << endl;
			sprawdz_sort(tablica,n);
            StopTime=clock();
            //wyswietl_tab(tablica,n);
        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla rosnacej."<<endl;
		}
		plik.close();
		break;

	case 4:
		plik.open("QickSort_left.txt",ios::out);

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_rand(tablica,n);
            //wyswietl_tab(tablica,n);
            cout << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort_lewa(tablica,0,n-1);
			sprawdz_sort(tablica,n);
			cout << endl << endl;
			StopTime=clock();
			//wyswietl_tab(tablica,n);

        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << endl << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla randomowej."<<endl;
		}
		plik.close();
		break;

    case 5:
		plik.open("QickSort_left.txt",ios::out);

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_rand(tablica,n);
            //wyswietl_tab(tablica,n);
            cout << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort_lewa(tablica,0,n-1);
			sprawdz_sort(tablica,n);
			cout << endl << endl;
			StopTime=clock();
			//wyswietl_tab(tablica,n);

        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << endl << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla malejacej."<<endl;
		}
		plik.close();
		break;

    case 6:
		plik.open("QickSort_left.txt",ios::out);

		for (int li=0; li<lp;li++)
		{
			wypelnij_tab_rand(tablica,n);
            //wyswietl_tab(tablica,n);
            cout << endl;
			cout << "Rozpoczynam pomiar czasu\n";
			StartTime= clock();
			QuickSort_lewa(tablica,0,n-1);
			sprawdz_sort(tablica,n);
			cout << endl << endl;
			StopTime=clock();
			//wyswietl_tab(tablica,n);


        zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
		cout << endl << "Czas wynosi: " << zegar;
        plik<<dec<<zegar<<" <- czas dla rosnacej."<<endl;
		}
		plik.close();
		break;

    case 7:
    plik.open("Merge_Sort.txt",ios::out);

    for(int li = 0; li<lp;li++)
    {
      pom = new int[n];
      wypelnij_tab_rand(tablica,n);
      wyswietl_tab(tablica,n);
      cout << endl;
      StartTime = clock();
      sortowanie_przez_scalanie(tablica,0,n-1);
      //sprawdz_sort(tablica,n);
      std::cout << "\n" << '\n';
      StopTime=clock();
      wyswietl_tab(tablica,n);

      zegar =(double)(StopTime-StartTime)/CLOCKS_PER_SEC;
      cout << endl << "Czas wynosi: " << zegar;
      plik<<dec<<zegar<<" <- czas dla rosnacej."<<endl;
    }

    plik.close();
    break;

		default:;
		break;
	}
}

//==============================================================================
// PROGRAM GLOWNY
//==============================================================================

int main()
{
	unsigned int n=0;       //rozmiar tablicy
	int ch;                         //wybor algorytmu
	int lp;                          // liczba sortowan
	int *tablica;
	ofstream plik;

	do
	{
		cout << "Witam w prorgamie!\n"
		    <<"Wybierz rodzaj algorytmu sortowania - QUICK SORT;\n"
			<<"1. Quick Sort(pivot = mediana )- tablica randomowa\n"
			<<"2. Quick Sort(pivot = mediana )- tablica malejaca\n"
            <<"3. Quick Sort(pivot = mediana )- tablica rosnaca\n"
			<<"4. Quick Sort(pivot z lewej)- tablica randomowa\n"
			<<"5. Quick Sort(pivot z lewej)- tablica malejaca\n"
			<<"6. Quick Sort(pivot z lewej)- tablica rosnaca\n"
      <<"7. Merge Sort\n"
			<<"0. exit\n";
		cin>>ch;

		if(ch!=0){
			cout<<"\n\nPodaj rozmiar tablicy i w kolejnej linni liczbe sortowan dla kazdej opcji.\n";
			cout<<"Wynik zapisany zostanie do pliku.\n\n";
			cin>>n;
			cin>>lp;

			tablica=new int[n];
			sortuj(tablica,n,ch,lp); //wysylam adres pierwszego elem tablicy/ rozmiar/ wybor algor/ liczbe sortowac
			delete [] tablica;
			cout<<"\nPlik zostal utworzony :)\n";
		}
	}while(ch!=0);

	return 0;
}

#include "tablica.hh"

void Tablica::zmniejsz_tab(unsigned int n_rozm)
{
	int *ptr = new int[n_rozm];

	for(unsigned int i=0;i<n_rozm;i++)
	{
		*(ptr+i) = *(tablica+i);
	}

	delete [] tablica;

	tablica = ptr;
}

void Tablica::powieksz_tab(unsigned int n_rozm)
{
	int *ptr = new int[n_rozm];

	//memcpy(ptr,tablica,sizeof(int)*rozmiar);

	for(unsigned int i=0;i<n_rozm;++i)
	{
		*(ptr+i) = rand() % 100;
	}

	delete [] tablica;

	tablica = ptr;

	//delete  ptr;

}

void Tablica::powieksz_operacja_pom(unsigned int nowy_rozmiar, unsigned int &temp_rozm)
{
	for(temp_rozm;temp_rozm<nowy_rozmiar;)
		{
			++temp_rozm;
			powieksz_tab(temp_rozm);
			//cout<<endl << "funkcja została użyta!!" << endl << endl;
		}
}

void Tablica::zmniejsz_operacja_pom(unsigned int nowy_rozmiar,unsigned int &temp_rozm)
{
	for(temp_rozm;temp_rozm>nowy_rozmiar;)
		{
			--temp_rozm;
			zmniejsz_tab(temp_rozm);
			//cout << "zmniejszenie tablicy wywołane"  << endl;
		}
}

void Tablica::wyswietl()
{
	cout << "\n\n\nWyświetlenie tablicy:" << endl << endl;
	for(unsigned int i=0;i<rozmiar;i++)
	{
		cout << *(tablica+i) << " ";
	}
	cout << endl << endl<<"aktualny rozmiar to: "<<rozmiar  << endl << endl << endl;
}

void Tablica::zwiekszanie_tablicy(unsigned int nowy_rozmiar,int wybrana_metoda)

{

	if(wybrana_metoda==1)
	{
		//stoper mierz_czas;
		//mierz_czas.startPomiar();
		unsigned int temp_rozm = rozmiar;

		powieksz_operacja_pom(nowy_rozmiar,temp_rozm);

		//mierz_czas.koniecPomiar();
	}

	else if(wybrana_metoda==2)
	{
		//stoper mierz_czas;

		unsigned	int temp_rozm = rozmiar;

		if(temp_rozm*2 > nowy_rozmiar)
		{
			powieksz_operacja_pom(nowy_rozmiar,temp_rozm);
		}
		else
		{
			for(temp_rozm;temp_rozm<nowy_rozmiar;)
			{
				temp_rozm*=2;
				powieksz_tab(temp_rozm);

				if(temp_rozm*2 > nowy_rozmiar)
				{
					powieksz_operacja_pom(nowy_rozmiar,temp_rozm);
				}
			}
		}
	}
	else	{ cout << "zła metoda" << endl; }
}

void Tablica::zmniejszanie_tablicy(unsigned int nowy_rozmiar)
{
	int wybrana_metoda;

	cout << "w jaki spsób chcesz zmniejszać tablice ?" << endl;
	cout << "1. - zmniejszenie  rozmiaru o jeden element" << endl;
	cout << "2. - dwu krotne zmniejszenie rozmiaru tablicy" << endl;
	cin  >> wybrana_metoda;

	if(wybrana_metoda==1)
	{
		//stoper mierz_czas;

		unsigned int temp_rozm = rozmiar;

		zmniejsz_operacja_pom(nowy_rozmiar,temp_rozm);

		cout << "aktualny rozmiar to:" << temp_rozm << endl;
	}

	else if(wybrana_metoda==2)
	{
		//stoper mierz_czas;

		unsigned int temp_rozm = rozmiar;

		if(temp_rozm/2 < nowy_rozmiar)
		{
			zmniejsz_operacja_pom(nowy_rozmiar,temp_rozm);
		}

		else
		{
			for(temp_rozm;temp_rozm>nowy_rozmiar;)
			{
				temp_rozm/=2;
				zmniejsz_tab(temp_rozm);

				if(temp_rozm/2 < nowy_rozmiar)
				{
					zmniejsz_operacja_pom(nowy_rozmiar,temp_rozm);
				}
			}
		}
	}
}

void Tablica::zmien_rozmiar()
{
	unsigned int nowy_rozmiar;

	cout << "podaj nową wielkość tablicy: ";
	cin >> nowy_rozmiar;
	if(nowy_rozmiar <= 0)
	{
		cerr << "fail" << endl;
	}
	else
	{

	cout << endl;
	cout << "zadany rozmiar tablicy to: " << nowy_rozmiar << endl;

	int wybrana_metoda;

		cout << "w jaki spsób chcesz powiększać tablice ?" << endl;
		cout << "1. - powiększanie rozmiaru o jeden element" << endl;
		cout << "2. - dwu krotne zwiększanie rozmiaru tablicy" << endl;
		cin  >> wybrana_metoda;


	if(nowy_rozmiar>rozmiar)
	{
		zwiekszanie_tablicy(nowy_rozmiar,wybrana_metoda);
	}

	else if((nowy_rozmiar<rozmiar)&&(nowy_rozmiar>0))
	{
		zmniejszanie_tablicy(nowy_rozmiar);
	}


	else if(nowy_rozmiar<0)
	{
		cerr << "tablice z liczbą elementów mniejszą bądź równą zero Ci nie stworze... :/" << endl;
	}
		rozmiar = nowy_rozmiar;
	}

}

void Tablica::resetTablicy()
{
		if(rozmiar!=2)
		{
			rozmiar = 2;
			delete [] tablica;
			tablica = new int[rozmiar];
			for(unsigned int i=0;i<rozmiar;i++)
			{
				*(tablica+i) = rand() % 10;
			}
		}
}

void Tablica::measureTime()
{
	unsigned int size,way,quantity;
	stoper pomiar;
	cout << "dla jakiego rozmiaru chcesz wykonać serie pomiaru ? " << endl;
	cin >> size;
	cout << "\nile chcesz wykonać pomiarów? " << endl;
	cin >> quantity;
	cout << "\nw jaki sposób chcesz powiększać tablice ? \n  inkrementacja rozmiaru - przycisk 1, \n podwajanie rozmiaru - przycisk 2\n ";
	cin >> way;

	for(unsigned int i=0;i<quantity;i++)
	{
		resetTablicy();
		pomiar.startPomiar();
		zwiekszanie_tablicy(size,way);
		pomiar.koniecPomiar();
		rozmiar = size;
		//wyswietl();
		resetTablicy();
		//wyswietl();
	}
}

int Tablica::sizeTab()
{
	//cout <<"\nwywołana funkcja sizeTab\nrozmiar to: " << rozmiar << endl;
	return rozmiar;
}


void Tablica::quickSort(int lewy,int prawy)
{
	int v = tablica[(lewy+prawy)/2];          //element srodkowy jako pivot
	//int v = tablica[lewy];										//początek tablicy jako pivot
	//int v = tablica[rand() % prawy];						//losowy element tablicy jako pivot
	int i,j,x;
	i=lewy;
	j=prawy;
		do{
			while (tablica[i]<v) i++;
			while (tablica[j]>v) j--;
			if(i<=j)
			{
				x = tablica[i];
				tablica[i]=tablica[j];
				tablica[j] = x;
				i++;
				j--;
			}
		}while (i<=j);
		if(j>lewy) quickSort(lewy,j);
		if(i<prawy) quickSort(i,prawy);
}




void Tablica::measureQuickSort()
{
	unsigned int quantity;
	unsigned long int sizeOfTab[] = {16,128,1024,16384,131072,1048576,2097152,16777216};
	cout << "\nIle razy chcesz dokonać pomiaru szybkości sortowania ? : ";
	cin >> quantity;
	cout <<"\nTablice jakiego rozmiaru chcesz sortować ?\n";
	//cout <<"Zalecane rozmiary: 16, 128, 1024, 16384, 131072, 524288,1048576 \n";
	//cin >> sizeOfTab;

	for(unsigned long int j = 0;j<8;++j)
	{
		stoper pomiar;

		for(unsigned int i=0;i<quantity;i++)
		{
			resetTablicy();
			zwiekszanie_tablicy(sizeOfTab[j],2);
			rozmiar = sizeOfTab[j];
			pomiar.startPomiar();
			quickSort(0,sizeTab()-1);
			pomiar.koniecPomiar();
			//resetTablicy();
		}
		cout << "pomiar dla rozmiaru: " << sizeTab() << endl;
	}
}

#include "stoper.hh"


void stoper::startPomiar()
{
	size++;

	double *temp = new double[size];

	memcpy(temp,ptr,sizeof(double)*size);

	delete [] ptr;

	ptr = temp;

	start = clock();
}


void stoper::koniecPomiar()
{
	koniec = clock();

	*(ptr+size-1) = (koniec-start)/(double)CLOCKS_PER_SEC;
}


stoper::stoper()
{
	ptr = new double[size];
}


stoper::~stoper()
{
	cout.setf(ios::fixed);
	cout.precision(5);

	double temp = 0;

	for(int i=0;i<size;i++)
	{
		temp += *(ptr+i);
		cout << "wartość pomiaru " << i <<" to " << *(ptr+i) << endl;
	}

	cout << "średnia wartość pomiaru szybkości programu to: " << temp/size << "sek" << endl;
}

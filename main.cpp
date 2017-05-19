//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fib(int n)
{
	int prevFib = 0;
	int currFib = 1;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
		for (int i = 2; i <= n; i++)
	{
		int newFib
		= prevFib + currFib ;
		prevFib = currFib ; //Hier wurde die Reihenfolge der Zuweisung vertauscht
		currFib = newFib ; //Somit wurden currFib und prevFib der gleiche Wert zugewiesen
	}
	return currFib;
}


int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 12 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
	return 0;
}

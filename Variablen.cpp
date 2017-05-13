//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	int iErste, iZweite, iSumme, iQuotient; //Die benötigten Variablen werden als integer initialisiert

	double dSumme, dQuotient; 								//Die späteren Ergebnisse werden als double initialisiert

	std::cout << "Geben Sie 2 Zahlen ein" << std::endl; 	//Der Benutzer wird aufgefordert 2 Zahlen einzugeben
	std::cin >> iErste;										// Hier wird die erste Zahl eingegeben
	std::cin >> iZweite; 									// Hier wird die zweite Zahl eingegeben

	iSumme= iErste+iZweite; 								//iSumme wird definiert als Summe der eingegenen Zahlen
	iQuotient =iErste/iZweite;								//iQuotient wird definiert als Division der eingegenen Zahlen

	dSumme =iErste+iZweite; 								//Hier wird die Summe als double abgespeichert, trotz Addition zweier Integer
	dQuotient = iErste / iZweite; 							//Hier das selbe für die Division

	std::cout << "Die Summe der eingegebenen Zahlen beträgt " << iSumme << std::endl; // Die Summe wird ausgegeben
	std::cout << "Das Ergebnis der Division der eingegebenen Zahlen beträgt " << iQuotient << std::endl; // Das Ergebnis der Division wird ausgegeben

	std::cout << "Die Summe der eingegebenen Zahlen beträgt " << dSumme << std::endl; // Die Summe wird ausgegeben
	std::cout << "Das Ergebnis der Division der eingegebenen Zahlen beträgt " << dQuotient << std::endl; // Das Ergebnis der Division wird ausgegeben

	double dSummeCast = (double) (iErste+iZweite); 					//Hier werden die Variablen zu einem double umgewandelt
	double dQuotientCast = ((double) iErste) / ((double) iZweite);

	std::cout << "Die Summe der eingegebenen Zahlen beträgt " << dSummeCast << std::endl; // Die Summe wird ausgegeben
	std::cout << "Das Ergebnis der Division der eingegebenen Zahlen beträgt " << dQuotientCast << std::endl; // Das Ergebnis der Division wird ausgegeben

	// Versuch01Teil1.4

	std::string sVorname, sNachname, sVornameName, sNameVorname;
	std::cout << "Geben Sie Ihren Vornamen ein" << std::endl;
	std::cin >> sVorname;
	std::cout << "Geben Sie Ihren Nachnamen ein" << std::endl;
	std::cin >> sNachname;

	sVornameName = sVorname + " " + sNachname;
	sNameVorname = sNachname + ", " + sVorname;

	std::cout << "Name, Vorname: " << sNameVorname << std::endl;
	std::cout << "Vorname, Name: " << sVornameName << std::endl;

// Versuch01Teil1.5

	{
		int	iFeld [2] = {1, 2};
		//iFeld [0] = 1;
		//iFeld [1] = 2;
		std::cout << "Feld1, Feld2: " << iFeld[0] << ", " << iFeld [1] << std::endl;
		int spielfeld [2][3] = {{1, 2, 3},{4, 5, 6}};

		// Nun werden alle 6 Felder nacheinander im Format 2x3 ausgegeben
		std::cout << "Felder 1 - 6:\n" << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld [0][2] <<"\n" << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;

		const int iZweite = 1; // iZweite wird als Integer-Konstante initialisiert und den Wert 1 zugewiesen.
		std::cout << "Die Konstante im Block lautet: " << iZweite << std::endl;
	}
		std::cout << "Die Konstante außerhalb des Blocks lautet: " << iZweite << std::endl;

		int iName1, iName2;
		iName1=sVorname [0];
		iName2=sVorname [1];

		std::cout<< "1. Buchstabe laut ASCII-Tabelle: " << iName1 << std::endl;

		std::cout<< "2. Buchstabe laut ASCII-Tabelle: " << iName2 << std::endl;


    int Buchstabe1, Buchstabe2;
    if (iName1<97)
     Buchstabe1 = (iName1+1)%65; //+1 da Modulo bei Rest =0 beginnt, aber der erste Buchstabe = 1 ist
     else
    	 Buchstabe1 = (iName1+1)%97;

    if (iName2<97)
         Buchstabe2 = (iName2+1)%65;
         else
        	 Buchstabe2 = (iName2+1)%97;

	std::cout<< "Stelle im Alphabetdes 1. Buchstaben: " << Buchstabe1 << std::endl;

	std::cout<< "Stelle im Alphabet des 2. Buchstaben: " << Buchstabe2 << std::endl;


	return 0;
	
}

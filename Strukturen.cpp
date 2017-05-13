/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{

	struct Person {
		std::string sNachname, sVorname;
		int iGeburtsjahr, iAlter;
	};

	Person nBenutzer;

	std::cout << "Geben Sie Ihren Nachnamen ein" << std::endl;
		std::cin >> nBenutzer.sNachname;
		std::cout << "Geben Sie Ihren Vornamen ein" << std::endl;
		std::cin >> nBenutzer.sVorname;
		std::cout << "Geben Sie Ihr Geburtsjahr ein" << std::endl;
		std::cin >> nBenutzer.iGeburtsjahr;
		std::cout << "Geben Sie Ihr Alter ein" << std::endl;
		std::cin >> nBenutzer.iAlter;

		std::cout << "nBenutzer: " << nBenutzer.sNachname << ", " << nBenutzer.sVorname << std::endl;
		std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
		std::cout << "Alter: " << nBenutzer.iAlter << " \n " << std::endl;

		Person nKopieEinzeln;  									// Hier wird nun jedes Element einzeln kopiert
			nKopieEinzeln.sNachname = nBenutzer.sNachname;
			nKopieEinzeln.sVorname = nBenutzer.sVorname;
			nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
			nKopieEinzeln.iAlter = nBenutzer.iAlter;

		Person nKopieGesamt; 									// Hier wird die gesamte Struktur kopiert
			nKopieGesamt = nBenutzer;

	std::cout << "nKopieEinzeln: " << nKopieEinzeln.sNachname << ", " << nKopieEinzeln.sVorname << std::endl;
			std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
			std::cout << "Alter: " << nKopieEinzeln.iAlter << " \n" << std::endl;

	std::cout << "nKopieGesamt: " << nKopieGesamt.sNachname << ", " << nKopieGesamt.sVorname << std::endl;
			std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
			std::cout << "Alter: " << nKopieGesamt.iAlter << std::endl;


	return 0;
	
}

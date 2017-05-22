//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einfuehrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vektor.h"

	/**
	 * @brief Berechnet die Sichtweite eines Menschen auf der Erde
	 *
	 * Die Funktion prueft zunaechst ob die Funktionen aus Vektor.cpp aus der Klasse Vektor richtig funktionieren.
	 * Dann kann der Benutzer die eigene Hoehe auf der Erde eingeben. Da sich der Mensch auf der Erde befindet, muss
	 * auf die Hoehe noch der Radius der Erde addiert werden. Der Erdvektor wird ebenfalls auf der y-Achse initialisiert.
	 * Ein dritter Vektor wird durch die Differenz vom Erd- und Menschvektor bestimmt.
	 * <br> Eine while-Schleife prueft wann der Erdvektor orthogonal zum eben genannten Differenzvektor ist. Bis dies der Fall ist,
	 * wird der Erdvektor mit der rotateAroundZ () Funktion gedreht und die benoetigten Schleifen durchlaeufe gezaehlt.
	 * Sobald die Bedingung der while-Schleife nicht mehr stimmt wird der Winkel zwischen Erd- und Menschvektor und
	 * die Laenge des Differenzvektors, also der Sichtweite, berechnet.
	 * <br> Die Sichtweite, die Hoehe des Menschen, der Winkel in Grad und die Anzahl der Schleifendurchlauefe werden ausgegeben.
	 *
	 * @return 0, Rueckgabewert ist unwichtig, da die Funktion nicht mehr benoetigt wird.
	 */

int main()
{ 
	std::cout << "Funktionen werden getestet:\n" << std::endl;

	Vektor vektor1(1,2,3);
	Vektor vektor2(4,5,6);

	Vektor resultvektor1(5,7,9);
	Vektor testresult = vektor1.add(vektor2);
	if(testresult.getX()==resultvektor1.getX()&&testresult.getY()==resultvektor1.getY()&&testresult.getZ()==resultvektor1.getZ())
	std::cout << "Addition korrekt" << std::endl;
	else
	std::cout << "Addition inkorrekt" << std::endl;

	Vektor resultvektor2(-3,-3,-3);
	Vektor testresult2 = vektor1.sub(vektor2);
	if(testresult2.getX()==resultvektor2.getX()&&testresult2.getY()==resultvektor2.getY()&&testresult2.getZ()==resultvektor2.getZ())
	std::cout << "Subtraktion korrekt" << std::endl;
	else
	std::cout << "Subtraktion inkorrekt" << std::endl;

	double resultlength1 = sqrt(14);
	double resultlength2 = sqrt(77);
	double testresult3 = vektor1.length();
	double testresult32 = vektor2.length();
	if(testresult3==resultlength1 && testresult32==resultlength2)
	std::cout << "Laenge korrekt" << std::endl;
	else
	std::cout << "Laenge inkorrekt" << std::endl;

	Vektor vektor3 (-3,2,-1);
	Vektor vektor4 (2,2,-2);
	bool testresult4 = vektor1.ortho(vektor2);
	bool testresult42 = vektor3.ortho(vektor4);
	if(testresult4!=true && testresult42==true)
	std::cout << "Orthogonalitätstest korrekt" << std::endl;
	else
	std::cout << "Orthogonalitätstest inkorrekt" << std::endl;

	double skprod1 = vektor1.scalarProd(vektor2);
	double skprod2 = vektor3.scalarProd(vektor4);
	if(skprod1!=0 && skprod2==0)
	std::cout << "Skalarprodukt korrekt" << std::endl;
	else
	std::cout << "Skalarprodukt inkorrekt" << std::endl;

	double winkeltest = acos(32/(sqrt(14)*sqrt(77)));
	double winkeltest2 = vektor1.angle(vektor2);
	if (winkeltest== winkeltest2)
	std::cout << "Winkel korrekt" << std::endl;
	else
	std::cout << "Winkel inkorrekt" << std::endl;

	double person = 0;

	std::cout << "\nWie hoch stehen Sie?" << std::endl;
	std::cin >> person;

	double hoehe = (person/1000)+6371.0;  	// !! Wichtig in Kilometer Schritten !!
	int steps = 0;
	Vektor mensch (0,hoehe,0); 				//Koordinaten Mensch auf Erde
	Vektor erde (0,6371,0); 				//Koordinaten Erde
	Vektor sichtweite = erde.sub(mensch);	//radius zwischen Mensch und Erdvektor
	double sicht = 0;
	double winkel = 0;


	while (sichtweite.ortho(erde)==false)	// Bis der Erdvektor orthogonal zum Radius ist
	{
		erde.rotateAroundZ(-0.00000001);
		sichtweite = erde.sub(mensch);
		steps++;
	}

	winkel = mensch.angle(erde)*180/3.14159265359;
	sicht = sichtweite.length();

	std::cout << std::fixed;
	std::cout << "Sie können " << std::setprecision (3) << sicht  << " Km weit sehen" << std::endl;
	std::cout << std::fixed;
	std::cout << "Sie sind " << std::setprecision (2) << (mensch.getY()-6371)*1000 << " Meter hoch" << std::endl;
	std::cout << std::fixed;
	std::cout << "Der Winkel beträgt " << std::setprecision(4) << winkel << " Grad" << std::endl;
	std::cout << "Anzahl der Schritte: " << steps << std::endl;

   return 0;
}

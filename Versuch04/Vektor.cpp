//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

/**
 *@brief Destruktor loescht ein Objekt
 */

Vektor::~Vektor()
{

}

/**
 * @brief Greift auf x-Wert des Vektors aus der Klasse zu
 *
 * @return gibt den x-Wert zurueck
 */
double Vektor::getX() const
{
return this->x;
}

/**
 * @brief Greift auf y-Wert des Vektors aus der Klasse zu
 *
 * @return gibt den y-Wert zurueck
 */

double Vektor::getY() const
{
return this->y;
}

/**
 * @brief Greift auf z-Wert des Vektors aus der Klasse zu
 *
 * @return gibt den z-Wert zurueck
 */

double Vektor::getZ() const
{
return this->z;
}

/**
 *@brief Differenz von Vektoren
 *
 *Berechnet deine Differenz von Vektoren. Sinnvoll für den Radius zwischen Mensch und dem Erdvektor.
 *Die Funktion bekommt einen Vektor als Parameter (input) uebergeben und subtrahiert ihn von dem per
 *this-Zeiger uebergebenen Vektor der Klasse Vektor.
 *
 *@return vneu Gibt den neu gespannten Vektor aus
 *@param input Vektor der eingegeben wird
 */

Vektor Vektor::sub(const Vektor& input) const //subtrahiert 2 Vektoren
{
	double xneu = (this->getX()-input.getX());
	double yneu = (this->getY()-input.getY());
	double zneu = (this->getZ()-input.getZ());
	Vektor vneu (xneu,yneu,zneu);
return vneu;
}

/**
 * @brief Addition von zwei Vektoren
 *
 * Hier werden 2 Vektoren addiert (x, y, z- Koordinaten einzeln), wird verwendet
 * um den Mensch auf den Erdradius zu stellen (Koordinaten Ursprung = Erdmitte)
 *
 * @return vneu Neuer Vektor
 * @param input Vektor der uebergeben wird
 */

Vektor Vektor::add(const Vektor& input) const
{
	double xneu = (this->getX()+input.getX());
	double yneu = (this->getY()+input.getY());
	double zneu = (this->getZ()+input.getZ());
	Vektor vneu (xneu,yneu,zneu);
return vneu;
}

/**
 *@brief Berechnet die Laenge eines Vektors
 *
 *@return Gibt die berechnete Laenge eines Vektor zurueck
 */
double Vektor::length() const
{
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));
}

/**
 *@brief Entnimmt das Skalarprodukt aus der Funktion scalarProd() und prueft, wann es (fast) = 0 wird.
 *
 *@return true Gibt true zurueck, wenn die Vektoren orthogonal sind
 *@param input Eingegebener Vektor
 */
bool Vektor::ortho (const Vektor& input) const
{
	double skprodukt = this->scalarProd(input);
	if (skprodukt >= 0.001 || skprodukt <= -0.001) //Messsystem zu ungenau für Skalarprodukt = 0
		return false;
	else
		return true;
}

/**
 *Berechnet das Skalarprodukt
 *
 *@return gibt das Skalarprodukt als double zurueck
 *@param input uebergebener Vektor
 */

double Vektor::scalarProd(const Vektor& input) const
{
	return ((this->getX()*input.getX())+(this->getY()*input.getY())+(this->getZ()*input.getZ()));
}

/**
 *@brief Berechnet den Winkel zwischen 2 Vektoren (in rad)
 *
 *@return winkel Gibt den Wnkel zurueck
 *@param input uebergebener Vektor
 */
double Vektor::angle(const Vektor& input) const //Skalarprodukt/Länge
{
	double winkel = acos(this->scalarProd(input)/(this->length()*input.length()));
return winkel;
}

/**
 *@brief Laesst Vektor um z-Achse rotieren
 *
 *Dazu wird ein Winkel in radiant übergeben. Um die korrekte Rotation zu erreichen muss die
 *gegebene Matrix (S. 83 im Skript) mit den x- und y-Koordinaten multipliziert werden.
 *
 *@param rad Der Winkel um den rotiert werden soll
 */

void Vektor::rotateAroundZ(const double rad) //Vektor rotiert um z-Achse mit Winkel in radiant, hier wird Matrix (2x2) benötigt
{
	double a = 0, b = 0;

	a = ((cos(rad)* this->getX()) - (sin(rad) * this->getY()));
	b = ((sin(rad)* this->getX()) + (cos(rad) * this->getY()));

	this->x = a;
	this->y = b;
}

/**
 *@brief Gibt die Werte der aktuellen Vektoren aus
 */

void Vektor::ausgabe() const
{
	std::cout << "die Werte des Vektors sind:" << std::endl;
	std::cout << this->getX() << std::endl;
	std::cout << this->getY() << std::endl;
	std::cout << this->getZ() << std::endl;
}

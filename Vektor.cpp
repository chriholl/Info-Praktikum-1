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

Vektor::~Vektor()
{

}

double Vektor::getX() const
{
return this->x;
}

double Vektor::getY() const
{
return this->y;
}

double Vektor::getZ() const
{
return this->z;
}

Vektor Vektor::sub(const Vektor& input) const //subtrahiert 2 Vektoren
{
	double xneu = (this->getX()-input.getX());
	double yneu = (this->getY()-input.getY());
	double zneu = (this->getZ()-input.getZ());
	Vektor vneu (xneu,yneu,zneu);
return vneu;
}

Vektor Vektor::add(const Vektor& input) const
{
	double xneu = (this->getX()+input.getX());
	double yneu = (this->getY()+input.getY());
	double zneu = (this->getZ()+input.getZ());
	Vektor vneu (xneu,yneu,zneu);
return vneu;
}

double Vektor::length() const
{
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));
}

bool Vektor::ortho (const Vektor& input) const
{
	double skprodukt = this->scalarProd(input);
	if (skprodukt >= 2.5 || skprodukt <= -2.5) //Messsystem zu ungenau für Skalarprodukt = 0
		return false;
	else
		return true;
}

double Vektor::scalarProd(const Vektor& input) const
{
	return ((this->getX()*input.getX())+(this->getY()*input.getY())+(this->getZ()*input.getZ()));
}

double Vektor::angle(const Vektor& input) const //Skalarprodukt/Länge
{
	double winkel = acos(this->scalarProd(input)/(this->length()*input.length()));
return winkel;
}

/**
 * @brief Lässt Vektor um z-Achse rotieren
 *
 * Dazu wird ein Winkel in radiant übergeben. Um die korrekte Rotation zu erreichen muss die
 * gegebene Matrix (S. 83 im Skript) mit den x- und y-Koordinaten multipliziert werden.
 *
 *@param rad Der Winkel um den rotiert werden soll
 */

void Vektor::rotateAroundZ(const double rad) //Vektor rotiert um z-Achse mit Winkel in radiant, hier wird Matrix (2x2) benötigt
{
	this->x = ((cos(rad)* this->getX()) - (sin(rad) * this->getY()));
	this->y = ((sin(rad)* this->getX()) + (cos(rad) * this->getY()));
}

void Vektor::ausgabe() const
{
	std::cout << "die Werte des Vektors sind:" << std::endl;
	std::cout << this->getX() << std::endl;
	std::cout << this->getY() << std::endl;
	std::cout << this->getZ() << std::endl;
}

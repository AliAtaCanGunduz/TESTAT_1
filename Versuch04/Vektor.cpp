//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;

}
double Vektor::laenge() const {
    return sqrt((x * x) + (y * y) + (z * z)); //es ist Formel fur vectoren
}
double Vektor::skalarProd(const Vektor& input) const {
    return (x * input.x + y * input.y + z * input.z); //VektorKlass enhaelt sich auch x,y,z
}
double Vektor::winkel(const Vektor& input)const {
    double division = Vektor::laenge() * sqrt(input.x * input.x + input.y * input.y + input.z * input.z);//Gleiche formel impleantieren fur Klass Vektor
    double rad=acos(Vektor::skalarProd(input)/(division));
    return (rad * (180.00 / M_PI));

}
bool Vektor::ortogonalitaet(const Vektor& input)const {
    if (Vektor::winkel(input) == acos(0)) {
    
        return true;
    }
    else {
        return false;
    }
}
Vektor Vektor::sub(const Vektor& input)const {
    return Vektor(x - input.x, y - input.y, z - input.z);
}
void Vektor::rotiereUmZ(const double rad) {//Kein Magic.Ich habe die Formel Benutzt
    double c = cos(rad);
    double s = sin(rad);
    double newX = c * x - s * y;
    double newY = s * x + c * y;
    x = newX;
    y = newY;
    ausgabe();
    
    
}
void Vektor::WerteX()const {
    std::cout << "X-Komponente: " << x << std::endl;

}
void Vektor::WerteY()const {
    std::cout << "Y-Komponente: " << y << std::endl;
}
void Vektor::WerteZ()const {
    std::cout << "Z Komponente: " << z << std::endl;
}
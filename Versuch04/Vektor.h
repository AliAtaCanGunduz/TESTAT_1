//
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


#include <iostream>
#include <cmath>
#include <iomanip>


class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor& input) const;
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(const double rad);
    bool ortogonalitaet(const Vektor& input)const;
    void WerteX() const;
    void WerteY() const;
    void WerteZ() const;
   private:
    double x;
    double y;
    double z;

};

#endif

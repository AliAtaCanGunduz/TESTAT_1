//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <numbers>
//Testing vektors
//Probleme const:
const double Radius = 6371000;
const double Platform = 555.7;
const double height = 1.7;


int main()
{
    Vektor position(0, Radius + height+Platform, 0);
    Vektor radiusvec(Radius, 0, 0);
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    //Testing methoden:
    vector1.ausgabe();
    vector2.ausgabe();
    vector1.laenge();
    vector2.laenge();
    if (vector1.ortogonalitaet(vector2)) {
        std::cout << "Ortogonal" << std::endl;
    }
    else {
        std::cout << "Nicht Ortogonal" << std::endl;
    }
   
    Vektor vector4 = vector1.sub(vector2);
    vector4.ausgabe();
    vector4.skalarProd(vector2);
    vector4.winkel(vector2);
    vector4.rotiereUmZ(acos(0));
    vector4.WerteX();
    vector4.WerteY();
    vector4.WerteZ();
    //Bruteforce technique benutzen
    /*
    * Scaler(Q-R,R)=0 => Scaler(Q,R)=R^2
    * Q ist position
    * R ist Radius Vektoren
    */
    //while (position.skalarProd(radiusvec)<Radius*Radius) {
        //radiusvec.rotiereUmZ(step);
        //counter++;

        

    //}
    double step = 0.01;
    int totalSteps = 0;
    double lastDot = position.skalarProd(radiusvec);

    while (true) {
        int localSteps = 0;

        // Wenn die weg ist richtig fortsetzen
        while ((step > 0 && position.skalarProd(radiusvec) < Radius * Radius) || //Effizienter weg ?
            (step < 0 && position.skalarProd(radiusvec) > Radius * Radius)) {
            if (position.skalarProd(radiusvec) - Radius * Radius > 100000) { //erhöhen
                step *= 3;
            }
            if (position.skalarProd(radiusvec) - Radius * Radius > 10000 && position.skalarProd(radiusvec) - Radius * Radius< 100000) {
                step *= 1.5; //erhöhen niedriger
            }
            if (position.skalarProd(radiusvec) - Radius * Radius > 1000 && position.skalarProd(radiusvec) - Radius * Radius < 10000 && std::abs(step)>0.01) {
                step /= 3; //reduzieren
            }

            if (position.skalarProd(radiusvec) - Radius * Radius < 1000 && std::abs(step)>0.01) {
                step /= 1.5; //reduzieren

            }
            
            
            radiusvec.rotiereUmZ(step);
            localSteps++;
            totalSteps++;
        }

        // Entscheiden ob man vorwaerts oder rueckwaerts geht.
        std::cout << "Zu weit " << (step > 0 ? "vorwaerts" : "ruckwaerts") << " gedreht. ";
        std::cout << "Ändere Schrittweite von " << std::fixed << std::setprecision(12) << step;

        step = -step/10.00; //rueckwaertsgehen

        std::cout << " zu " << std::fixed << std::setprecision(12) << step << std::endl;
        std::cout << "Winkel: " << std::fixed << std::setprecision(12) << 90-radiusvec.winkel(position);
        std::cout << "    Schritte in diesem Durchlauf: " << localSteps << std::endl;

        if (std::abs(position.skalarProd(radiusvec) - Radius * Radius) < 1e-8) {
            break;
        }
    }

    Vektor result = position.sub(radiusvec);
    std::cout << "Sie konnen " << std::fixed << std::setprecision(10)
        << result.laenge() / 1000 << " Km weit sehen.\n";
    std::cout << "Sie sind " << std::fixed << std::setprecision(10)
        << Platform + height << " Meter hoch.\n";
    std::cout << "Der Winkel betraegt " << std::fixed << std::setprecision(10)
        << radiusvec.winkel(position) << " Grad.\n";
    std::cout << "Anzahl Schritte: " << totalSteps << std::endl;



    
    return 0;


}

// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
struct Person {
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;

};
int main()
{
    Person nBenutzer;
    std::cout << "Geben Sie bitte deine Vorname an" << std::endl;
    std::cin >> nBenutzer.sVorname;
    std::cout << "Geben Sie bitte deine Nachname an" << std::endl;
    std::cin >> nBenutzer.sNachname;
    std::cout << "Geben Sie bitte deine Geburtsjahr an" << std::endl;
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Geben Sie bitte deine Alter an" << std::endl;
    std::cin >> nBenutzer.iAlter;
    std::cout << "Vorname: " << std::endl;
    std::cout << nBenutzer.sVorname << std::endl;
    std::cout << "Nachname: " << std::endl;
    std::cout << nBenutzer.sNachname << std::endl;
    std::cout << "Geburtsjahr: " << std::endl;
    std::cout << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << std::endl;
    std::cout << nBenutzer.iAlter << std::endl;
    Person nKopieGesamt = nBenutzer;
    Person nKopieEinzeln;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    std::cout << "KopieEinzelnVorname: "<<nKopieEinzeln.sVorname<<"\n"<<"KopieEinzelnNachname: "<<nKopieEinzeln.sNachname<<"\n"<<"KopieEinzelnGeburtsjahr: "<<nKopieEinzeln.iGeburtsjahr<<"\n"<<"KopieEinzelnAlter: "<<nKopieEinzeln.iAlter<<"\n" << std::endl;
    std::cout << "KopieGesamtVorname: " << nKopieGesamt.sVorname << "\n" << "KopieGesamtNachname: " << nKopieGesamt.sNachname << "\n" << "KopieGesamtGeburtsjahr: " << nKopieGesamt.iGeburtsjahr << "\n" << "KopieGesamtAlter: " << nKopieGesamt.iAlter << "\n" << std::endl;



    return 0;

}

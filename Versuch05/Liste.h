//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData); //aktualisiert
    void popFront(); //aktualisert
    void popMatrikelnnummer(unsigned int matrikel); //popMatrikelnnummer wird hergestellt
    void pushFront(Student pData); //pushFront wird hergestellt
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const; //programiert
};

#endif /*LISTE_H_*/

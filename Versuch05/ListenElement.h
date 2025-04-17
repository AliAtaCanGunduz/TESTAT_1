//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev; //neue data wird hergestellt für doppelte verketteteliste

public:
    ListenElement(Student pData, ListenElement* pNext,ListenElement*pPrev);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* pPrev); //neue Methoden für setting prev.Es macht die nutzung der prev einfacher

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const; //Die Methode getPrev erlaubt den Zugriff auf das private Attribut prev außerhalb der Klasse.
};

#endif

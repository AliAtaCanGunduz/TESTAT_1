//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr,nullptr); //neue Element wird hergestellt

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement; //es gibt nur ein Element,deswegen front=back;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);  //Durch das neu erstellte Listenelement wird das next-Attribut des back-Elements so gesetzt, dass es auf das neue Element zeigt
        neuesElement->setPrev(back);    //Anschließend habe ich das prev-Element des erhaltenen neuesElement mit back verbunden. Optional hätte man zusätzlich den Code neuesElement->setNext(nullptr) hinzufügen können
        back = neuesElement;            //jetzt neuesElement ist back
    }
}
void Liste::pushFront(Student pData) {
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr); //neue Element wird hergestellt
    if (front == nullptr) {                                                   //Liste leer?
        front = neuesElement; //es gibt nur ein Element,deswegen front=back;
        back = neuesElement;
    }
    else {
        front->setPrev(neuesElement);        //Nun zeigt das prev von front auf das neuesElement und das next von neuesElement zeigt auf front. Das prev von neuesElement kann optional auf nullptr gesetzt werden
        neuesElement->setNext(front);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;// Listenelement löschen
        front = nullptr; //es gibt kein Element;
        back = nullptr; //es gibt kein Element;
        
    }
    else
    {
        front = front->getNext(); 
        cursor->setNext(nullptr);
        front->setPrev(nullptr);
        delete cursor;
        /*
        * Das front-Element wird auf das zweite Element der Liste gesetzt. Das next von cursor, also das erste Element, wird auf nullptr gesetzt. 
        Danach wird die Verbindung vom neuen front zum vorherigen cursor mit setPrev(nullptr) aufgehoben. 
        Schließlich wird das ursprüngliche erste Element gelöscht. 
        An dieser Stelle hatte ich sogar einen Memory-Leak-Fehler, weil ich den prev-Pointer vergessen hatte
        * 
        */
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
void Liste::ausgabeRueckwaerts() const {
    if (back == nullptr) {
        std::cout << "Fehler: back ist null!" << std::endl; //Liste ist leer?
        return;
    }

    ListenElement* cursor = back; //Wir brauchen SuchePointer.Wir starten mit back

    
    while (cursor != nullptr) {
        cursor->getData().ausgabe();    //Starten mit back
        cursor = cursor->getPrev();     //Wir können anderen Dateien mit prev erreichen,dank der doppelte verketteteList
    }
}

void Liste::popMatrikelnnummer(unsigned int matrikeln) {
    if (Liste::empty()) {
        std::cout << "Liste ist leer" << std::endl;     //Liste ist leer?
        return;
    }

    ListenElement* cursor = front;  //Suchepointer cursor!

    while (cursor != nullptr && cursor->getData().getMatNr() != matrikeln) { //Suche loop cursor hat auch datei wir können das mit getData() erreichen.cursor->getData() gehört eigentlich zur Klasse Student. Der Ausdruck cursor->getData().getMatNr() ist eine Methode, die die Matrikelnummer als unsigned int zurückgibt.
        cursor = cursor->getNext();
    }
    

    if (cursor == nullptr) {
        std::cout << "Kein Student mit dieser Matrikelnummer wurde gefunden" << std::endl;
        return;
    }
    //else

    cursor->getData().ausgabe(); //Wir können cursor ausgeben,weil wir die Student schon gefunden.

    if (cursor == front && cursor == back) {//Es gibt nur eine Elemente
        front = nullptr;
        back = nullptr;
    }
    else if (cursor == front) {//Student ist erste Element?
        front = front->getNext(); //wir können neue front entscheiden
        if (front != nullptr) front->setPrev(nullptr); //Durch front->setPrev(nullptr) wird die Verbindung zum cursor aufgehoben
    }
    else if (cursor == back) {
        back = back->getPrev(); //Wir können neue back entscheiden
        if (back != nullptr) back->setNext(nullptr); //Durch back->setNext(nullptr) wird die Verbindung zum cursor aufgehoben
    }
    else {
        cursor->getPrev()->setNext(cursor->getNext());
        cursor->getNext()->setPrev(cursor->getPrev());
    }
    /*
    * Mit cursor->getPrev()->setNext(cursor->getNext()) wird das vorherige Element so aktualisiert, dass es auf das nächste Element von cursor zeigt.
    Anschließend sorgt cursor->getNext()->setPrev(cursor->getPrev()) dafür, dass das nächste Element auf das vorherige Element zeigt. 
    Dadurch wird das aktuelle cursor-Element vollständig aus der doppelt verketteten Liste entfernt
    */

    delete cursor;
    //delete cursor von der Heap
}


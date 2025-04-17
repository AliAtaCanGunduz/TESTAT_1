/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"
#include <Windows.h>

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    if ( 8>posX && 8>posY) {
        if (posX >= 0 && posY >= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    // Hier erfolgt jetzt Ihre Implementierung ...
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1
    

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    if (!aufSpielfeld(posX, posY)) {
        return false;
    }
    if (spielfeld[posY][posX] != 0) {
        return false;
    }

    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            int number = 2;
            if (spielfeld[posY + j][posX + i]==gegner) {//Falls der Gegner in der Naehe des gescannten Bereichs entdeckt wird, soll dieselbe Diagonale weiterverfolgt werden
                while ( aufSpielfeld(posY + (j * number), posX+ (i* number)) == true) { //aufSpielfeld checken 
                    if (spielfeld[posY + (j * number)][posX + (i * number)] == 0) {
                        break; //Nichts gefunden go back to the loop
                    }
                    if (spielfeld[posY + (j * number)][posX + (i * number)] == aktuellerSpieler) {
                        return true; //moeglicheWeg
                    }
                    if (spielfeld[posY + (j* number)][posX + (i * number)] == gegner) {
                        number++;//Naechste Diagonale
                    }
                    

                }

            }
            

            // Hier erfolgt jetzt Ihre Implementierung ...
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{

    
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    if (zugGueltig(spielfeld,aktuellerSpieler,posX,posY) && (aktuellerSpieler==1 || aktuellerSpieler==2)) { //checken die gultigkeit
        for (int j = -1; j <= 1; j++)
        {
            for (int i = -1; i <= 1; i++)
            {
                int number = 2;
                
                if (spielfeld[posY + j][posX + i] == gegner) {
                    
                    while (aufSpielfeld(posY + (j * number), posX + (i * number)) == true) {
                        if (spielfeld[posY + (j * number)][posX + (i * number)] == 0) {
                            break; //go back to the loop
                        }
                        if (spielfeld[posY + (j * number)][posX + (i * number)] == aktuellerSpieler) {
                            for (int z = 1;z < number;z++) {
                                spielfeld[posY + (j * z)][posX + (i * z)] = aktuellerSpieler; //alle diagonale mit aktuellerSpieler wechseln
                            }

                            break;
                        }
                        if (spielfeld[posY + (j * number)][posX + (i * number)] == gegner) {//Weiteres diagonale checken
                            
                            number++;
                            

                        }


                    }

                }



                // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
                // allen Richtungen in Ihre eigenen Steine umgewandelt werden
                //
                // Hier erfolgt jetzt Ihre Implementierung ...
            }
        }
        spielfeld[posY][posX] = aktuellerSpieler;

    }


}

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int sayi = 0;
    for (int i = 0;i < GROESSE_Y;i++) {
        for (int j = 0;j < GROESSE_X;j++) {
            if (zugGueltig(spielfeld, aktuellerSpieler, j, i)) {
                sayi++; //alle map scannen und MoeglicheZuege sagen
            }
            
        }
    }
    
    return sayi;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    int gegner = 3 - aktuellerSpieler;
    zeigeSpielfeld(spielfeld);
    if (spielerTyp[0] == 1 && spielerTyp[1] == 1) {
        while (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, gegner) != 0) {
            if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0) {
                menschlicherZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, gegner) == 0) {
                menschlicherZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 && moeglicheZuege(spielfeld, gegner) != 0) {
                menschlicherZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
                menschlicherZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);

            }

        }
    }
    if (spielerTyp[0] == COMPUTER && spielerTyp[1] == COMPUTER) {
        while (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, gegner) != 0) {
            if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0) {
                computerZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);
                
                
            }
            if (moeglicheZuege(spielfeld, gegner) == 0) {
                computerZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 && moeglicheZuege(spielfeld, gegner) != 0) {
                computerZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
                computerZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);

            }

        }
    }
    if (spielerTyp[0] == MENSCH && spielerTyp[1] == COMPUTER) {
        while (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, gegner) != 0) {
            if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0) {
                computerZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, gegner) == 0) {
                menschlicherZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 && moeglicheZuege(spielfeld, gegner) != 0) {
                menschlicherZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
                computerZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);

            }

        }
    }
    if (spielerTyp[0] == COMPUTER && spielerTyp[1] == MENSCH) {
        while (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, gegner) != 0) {
            if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0) {
                menschlicherZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, gegner) == 0) {
                computerZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
            }
            if (moeglicheZuege(spielfeld, aktuellerSpieler) != 0 && moeglicheZuege(spielfeld, gegner) != 0) {
                computerZug(spielfeld, aktuellerSpieler);
                zeigeSpielfeld(spielfeld);
                menschlicherZug(spielfeld, gegner);
                zeigeSpielfeld(spielfeld);

            }

        }
    }
    
    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    switch (gewinner(spielfeld))
    {
    case 1:
        printf("Gewinner ist X");
        break;
    case 2:
        printf("Gewinner ist O");
        break;
    default:
        printf("Unentschieden");
        break;


        // Hier erfolgt jetzt Ihre Implementierung ...
    }
}

int main()
{
    char choice;
    char endgame;
    int spielertype1[2] = { MENSCH,MENSCH };
    int spielertype2[2] = { MENSCH,COMPUTER };
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];
    while (1) {
        std::cout << "Mochtest du mit dem Computer oder mit der Mensch spielen?(Fur Mensch schreiben Sie M fur Computer schreiben Sie C) " << std::endl;
        std::cin >> choice;
        if (choice == 'M') {
            spielen(spielertype1);
        }
        if (choice == 'C') {
            spielen(spielertype2);
        }
        else {
            std::cout << "Bitte schreiben Sie M oder C" << std::endl;
            return 0;
        }
        std::cout << "Mochtest du noch einmal spielen? J/N" << std::endl;
        std::cin >> endgame;
        if (endgame == 'J') {
            continue;

        }
        if (endgame == 'N') {
            return 0;
        }
        else {
            std::cout << "Bitte schreiben Sie J oder N" << std::endl;
            return 0;
        }
        

    }


    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COMPUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}

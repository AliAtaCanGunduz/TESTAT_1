//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <math.h>

int main()
{
    const int izweite = 1;
    int rest;
    std::string sVorname;
    std::string sNachname;
    int iFeld[2] = { 1,2 };
    int spielfeld[2][3] = { {1,2,3},{4,5,6} };
    double dErste;
    double dZweite;
    int iErste;
    int iZweite;
    std::cout << "Geben Sie erste Int Zahl an: ";
    std::cin >> iErste;
    std::cout << "Geben Sie zweite Int Zahl an: ";
    std::cin >> iZweite;
    std::cout << "Geben Sie erste Double Zahl an: ";
    std::cin >> dErste;
    std::cout << "Geben Sie zweite Double Zahl an: ";
    std::cin >> dZweite;
    std::cout << "Geben Sie Vorname an: ";
    std::cin >> sVorname;
    std::cout << "Geben Sie Nachname an: ";
    std::cin >> sNachname;
    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname + "," + sVorname;


    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    double dSummeCast = dErste + dZweite;
    double dQuotientCast = dErste / dZweite;

    if(iSumme<-2147483650 || iSumme>2147483649){
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    if (iQuotient < -2147483650 || iQuotient>2147483649) {
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    if (iZweite == 0) {
        std::cout << "Ungültige Ergebnis für Division"<<std::endl;
        std::cout << "Summe" + iSumme << std::endl;

    }
    else {
        std::cout << "Summe(int): " << std::endl;
        std::cout << iSumme << std::endl;

        std::cout << "Division(int):"  << std::endl;
        std::cout << iQuotient << std::endl;
        std::cout << "Summe(double): " << std::endl;
        std::cout << dSumme << std::endl;
        std::cout << "Division(double)" << std::endl;
        std::cout << dQuotient << std::endl;
        std::cout << "Summe(doublecast): " << std::endl;
        std::cout << dSummeCast << std::endl;
        std::cout << "Quotient(doublecast): " << std::endl;
        std::cout << dQuotientCast << std::endl;

    }
    if (dSumme <  -1.797693*pow(10,308) || dSumme>1.797693 * pow(10, 308)) {
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    if (dQuotient < -1.797693 * pow(10, 308) || dQuotient>1.797693 * pow(10, 308)) {
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    if (dSummeCast < -1.797693 * pow(10, 308) || dSummeCast>1.797693 * pow(10, 308)) {
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    if (dQuotientCast < -1.797693 * pow(10, 308) || dQuotientCast>1.797693 * pow(10, 308)) {
        std::cout << "Es gibt keine genug Speicherplatz";
        return 0;
    }
    std::cout << sVornameName << std::endl;
    std::cout << sNameVorname << std::endl;
    std::cout << "Fur iFeld" << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << iFeld[i] << std::endl;
    }
    std::cout << "Fur spielfeld" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << spielfeld[i][j] << std::endl;
        }
    }
    std::cout << "Constant: " << std::endl;
    std::cout << izweite << std::endl;
    int iName1 = sVorname[0];
    int iName2 = sVorname[1];
    std::cout << "ASC2 Tabelle erste Buchstabe:  "<<std::endl;
    std::cout << iName1 << std::endl;
    std::cout << "ASC2 Tabelle zweite Buchstabe: "<< std::endl;
    std::cout << iName2 << std::endl;
    if (iName1 > 90) {
        std::cout << "Position der erste Buchstabe: " << std::endl;
        std::cout << iName1 % 96 << std::endl;
    }
    if (iName1 < 90) {
        std::cout << "Position der erste Buchstabe: " << std::endl;
        std::cout << iName1 % 64 << std::endl;
    }
    if (iName2 > 90) {
        std::cout << "Position der zweite Buchstabe: " << std::endl;
        std::cout << iName2 % 96 << std::endl;
    }
    if (iName2 < 90) {
        std::cout << "Position der zweite Buchstabe: " << std::endl;
        std::cout << iName2 % 64 << std::endl;
    }



    

    //Aufgabe 1:Integer bölmesi ve toplamasi yapildi passt tik attim :D;
    //Aufgabe 2:Normal bölme ve toplama yapilmasi ve double boyutu kontrolü bunun için math.h kullanıyorum.math.h pow fonksiyonu sayesinde çalışacak program
    /*
    * Aufgabe 2 sonucu sadece kaydedilen tip double donustugu icin hicbir sey degismedi.
    */
    /*
    * Aufgabe 3:Ilk durumda ve ikinci durumda aslinda her zaman integerlarla ugrasiyoruz(ikinci durumda kaydedilen deger double olmasina ragmen)
    * Ama son durumda girilen degerler double olarak alindigi icin normal bolme yapilmis oldu ilk 2 degerden farki degerlerin double olarak kaydedilmesidir.
    * Aufgabe 4:Baya ezdi Name dedigini basta anlamadim ama sonrasinda namenin aslinda soyad olduğunu kavradım.
    * Aufgabe 5 a:1 sayisina 0 indisi ile 2 sayisina 1 indisi ile ulastim :D.
    * Aufgabe 5 b:belirtilen sayiya ulasmak icin matrislerdeki sütun satır eşalonu kullanılır.Örneğin 1 e ulaşmak için spielfeld[0][0]
    * gibi
    * Aufgabe 5 c:Emin degilim cunku izweite diye bir constant kullandim yani kucuk harfle yazdim hatali olabilir.
    */



    

    // Hier folgt Ihr eigener Code

    return 0;

}

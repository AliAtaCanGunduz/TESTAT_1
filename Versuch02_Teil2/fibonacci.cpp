//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>

int fibonacci(int n)
{
    int previousFib = 1;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if (n == 2) {//n=2 betrachten
        return 1;
    }
    for (int i = 3; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib;
        currentFib = newFib; //currentFib fixed
    }
    return  currentFib;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    int n = 42;//Beispiel iterative chrono
    auto start = std::chrono::high_resolution_clock::now();//Nutzung Chrono fur zeitmessung
    int result = fibonacci(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); //Man braucht nanoseconds

    std::cout << "\nBeispiel: f(" << n << ") = " << result
        << " [" << duration.count() << " ns]" << std::endl; //200 nseconds
    return 0;
    //Es ist O(n) für zeit deswegen iterativ ist schneller
    //Es ist O(2^n) für rekursiv
    // Ab einer bestimmten Fibonacci-Zahl liefert das Programm falsche Ergebnisse.
// Aufgabe 3: Vergleich der Geschwindigkeit für n = 42
//
// Die iterative Version (unsere aktuelle Implementierung) berechnet Fibonacci-Zahlen
// mit einer einfachen Schleife und hat eine lineare Laufzeit O(n).
// Daher ist sie sehr schnell, selbst bei größeren n wie n = 42.
//
// Die rekursive Version (aus der ursprünglichen Aufgabe) verwendet keine Zwischenspeicherung
// und ruft die Funktion mehrfach rekursiv auf. Dadurch entstehen viele doppelte Berechnungen.
// Die Laufzeit ist exponentiell: O(2^n)
//
// Beispiel:
// fibonacci(5) = fibonacci(4) + fibonacci(3)
//              = (fibonacci(3) + fibonacci(2)) + (fibonacci(2) + fibonacci(1))
//              = ...
//
// Bei n = 42 führt das zu Millionen von Funktionsaufrufen, was zu einer sehr langen Laufzeit führt.
//
// Ergebnis:
// Die iterative Methode liefert das Ergebnis nahezu sofort (< 1 ms),
// während die rekursive Methode mehrere Sekunden benötigen kann.
// Fazit: Die iterative Methode ist deutlich effizienter für große n.
// Der Grund dafür liegt in der Begrenzung des Datentyps `int`.
//
// Ein `int`-Wert ist in C++ normalerweise 32 Bit groß,
// was bedeutet, dass der maximale darstellbare Wert 2.147.483.647 beträgt.
//
// Fibonacci(46) = 1.836.311.903 → korrekt
// Fibonacci(47) = 2.971.215.073 → zu groß für int → Überlauf → falsches Ergebnis
//
// Lösung:
// Statt `int` sollte man `long long` verwenden, da dieser Datentyp 64 Bit groß ist
// und deutlich größere Zahlen darstellen kann (bis ca. 9,2 * 10^18).
//
// Mit `long long` lassen sich Fibonacci-Zahlen bis einschließlich F(92) korrekt berechnen.
// Ab F(93) ist auch `long long` nicht mehr ausreichend und man benötigt z. B. BigInteger-Lösungen.
}

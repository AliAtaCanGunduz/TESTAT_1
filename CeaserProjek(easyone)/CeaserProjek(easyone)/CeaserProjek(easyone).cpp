
#include <iostream>
std::string verschluesseln(const std::string& wort, char tabelle[2][26]) {
    std::string geheim;
    for (char c : wort) { //Alle char gucken für wort
        int index = c - 'A'; //A=65 für ASCII
        geheim += tabelle[1][index];
    }
    return geheim;
}
std::string entschluesseln(const std::string& wort, char tabelle[2][26]) {
    std::string klar;
    for (char c : wort) {
        for (int i = 0; i < 26; ++i) {
            if (tabelle[1][i] == c) {
                klar += tabelle[0][i];
                break;
            }
        }
    }
    return klar;
}
char reflektor(char c) {
    const char reflektor[26] = {
        'Y','R','U','H','Q','S','L','D','P','X','N','G','O',
        'K','M','I','E','B','F','Z','C','W','V','J','A','T'
    };
    return reflektor[c - 'A']; //es ist wie das f(a)=b f(b)=a f(c)=q f(q)=c es reflektiert
}
std::string enigma(const std::string& wort, char tabelle[2][26]) {
    std::string ergebnis;
    for (char c : wort) {
        char step1 = verschluesseln(std::string(1, c), tabelle)[0];  // f(g)
        char step2 = reflektor(step1);                                // R(f(g))
        char step3 = entschluesseln(std::string(1, step2), tabelle)[0]; // f⁻¹(R(f(g)))
        ergebnis += step3;
    }
    return ergebnis;
}


int main()
{
    char lookupman[2][26] = { {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},{'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'} };
    char AG[6];
    char CB[6];
    char BIGCB[6];
    std::cout << "Geben Sie bitte ein Wort bestehend aus 5 Grossbuchstaben an: ";
    std::cin >> AG;
    std::cout << verschluesseln(AG,lookupman)<< std::endl;
    std::cout << "Geben Sie etwas ein, das mit derselben Methode verschlUsselt wurde" << std::endl;
    std::cin >> CB;
    std::cout <<entschluesseln(CB,lookupman) << std::endl;
    std::cout << "Geben Sie ein Wort zur ENIGMA-Verschlüsselung ein: ";
    std::cin >> BIGCB;
    std::cout << "Enigma-Ergebnis: " << enigma(BIGCB, lookupman) << std::endl;



    





}

//f(g)=g-3 mod 26 abbildung benutzen;
//für entziffern benutzen f^-1(g)=g+3 Benutzen
//Zusatztaufgabe Enigma Projekt:
/*i)Für vergleichbares Verhalten brauchen wir Rotor,die f(g)=g-3 ist.Aber wir brauchen auch Reflektor.
* Unser Enigma Funktion:E(f^-1(R(f(g)))
* ii)Neue Funktion wurde geschrieben mit der Funktion
* iii)
* Vorteile:
* Hohe Sicherheit: Die Enigma-Maschine bot für ihre Zeit eine sehr komplexe und starke Verschlüsselung.
Flexibilität: Dank der veränderbaren Walzen und Stecker konnte die Verschlüsselung täglich geändert werden.
Effiziente Kommunikation: Militärische Nachrichten konnten schnell und sicher übermittelt werden.
Mobil einsetzbar: Die Enigma-Maschine war tragbar und konnte an verschiedenen Orten verwendet werden.
   Nachteile:
   Komplexität und Bedienungsfehler: Die Komplexität führte oft zu menschlichen Fehlern bei der Bedienung.
Fehlende absolute Sicherheit: Trotz der starken Verschlüsselung konnte die Enigma letztlich geknackt werden (z. B. durch Alan Turing und sein Team in Bletchley Park).
Abhängigkeit von regelmäßigen Änderungen: Wenn die Schlüssel nicht regelmäßig geändert wurden, wurde die Sicherheit gefährdet.
Technologische Einschränkungen: Im Vergleich zu heutigen Systemen war sie zwar fortschrittlich, aber nicht unknackbar.
* 
*/

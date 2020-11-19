// DZIEDZICZENIE
#include <cmath>
#include <iostream>

using namespace std;
class Figura
{
public:
    Figura(double i) { pole = i; }
    //  Figura(int a) : pole(a) {}
    // void   setPole(double poleWartosc) { pole = poleWartosc; }
    double getPole() { return pole; }
    void   id() const
    {
        cout << "Typ figury to Figura(?!?)" << endl;
        cout << "Pole figury wynosi: " << pole << endl;
    }

protected: // zmienna pole może teraz być czytana i zmieniana przez metody klasy dziedziczącej, (dla
           // private - tylko metody klasy bazowej mogą ją czytać i zmieniać)
    // double pole;
private:
    double pole;
};

class Kolo : public Figura
{
public:
    // Kolo(double r) { setPole(3.1415 * r * r); }// konstruktor, gdy pole było prywatnym dla klasy
    // Figura Kolo(double r) {pole = (3.1415 * r * r);} // konstruktor, gdy pole jest chronione w
    // klasie Figura
    Kolo(double r) : Figura(3.1415 * r * r)
    {
        promienKola = r;
        cout << "Podano promien kola r=" << r << endl;
    }
    void id()
    {
        cout << "Typ figury to Kolo" << endl;
        cout << "Pole figury wynosi: " << getPole() << endl;
    }

private:
    double promienKola;
};

class Kwadrat : public Figura
{
public:
    // Kwadrat(double a) { setPole(a * a); }// konstruktor, gdy pole było prywatnym dla klasy Figura
    // Kwadrat(double a) { pole = (a * a); } // konstruktor, gdy pole jest chronione w klasie Figura
    Kwadrat(double a) : Figura(a * a)
    {
        dlugoscBoku = a;
        cout << "Podano dlugosc boku a=" << a << endl;
    }
    void id()
    {
        cout << "Typ figury to Kwadrat" << endl;
        cout << "Pole figury wynosi: " << getPole() << endl;
    }

private:
    double dlugoscBoku;
};

void id(const Figura& obiektFigura) // UWAGA: referencja const zadziała, gdy w funckcji void id w
// klasie Figura dodam <const> przed ciałem funckji (jest juz
// wyżej dodane), ALE CZEMU TAK?!?, CO TO CONST DAJE W SAMJ
// FUNCKJI VOID ID WYŻEJ W KLASIE FIGURA?
{
    cout << "Niezalezna funkcja id" << endl;
    obiektFigura.id();
}
// NIE DRUKUJE SIĘ ŻADNA WIADOMOŚĆ, JAK TO JEST PODANE W INSTRUKCJI

int main()
{
    // puts("Hello, World!");
    Figura Fig(10.1);
    Fig.id();
    Kwadrat Kw(3);
    cout << "Pole kwadratu: " << Kw.getPole() << endl;
    Kw.id();
    // Kw.setPole(3.3);
    // cout << "Pole kwadratu po zmianie: " << Kw.getPole() << endl;

    Kolo Ko(1);
    cout << "Pole kola: " << Ko.getPole() << endl;
    Ko.id();
    // Ko.setPole(2.1);
    // cout << "Pole kola po zmianie: " << Ko.getPole() << endl;

    // do zadania nr 9:
    Kwadrat Kw2(7.1);
    id(Kw2);
    cout << endl << "Zadanie na rzutowanie" << endl << endl;
    Kwadrat Kw3(5);
    id(Kw3);
    Figura b = static_cast< Figura >(Kw3);
    id(Kw3);
    id(b);
}

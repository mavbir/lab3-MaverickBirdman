# Instrukcja III

## Wstęp
Na tych zajęciach zaznajomimy się z dziedziczeniem oraz dynamicznym (wirtualnym) polimorfizmem.
Są to podstawowe narzędzia programowania obiektowego, którym zawdzięcza ono w dużej mierze swoją popularność.
Pozwalają one na pisanie przejrzystego kodu i konstruowanie łatwych w użyciu interfejsów.
Dodajmy jednak, że współcześnie w C\+\+ odchodzi się od tych metod na rzecz statycznych (tzn. rozstrzyganych w czasie kompilacji) rozwiązań.
Powodem tej zmiany jest ich koszt w wydajności programu.
Warto je jednak znać, szczególnie, że w wielu przypadkach czytelność kodu może być ważniejsza od kilku milisekund czasu wykonania.

## Dziedziczenie
Dziedziczenie jest prostym, ale bardzo potężnym konceptem.
Sprowadza się do następującej zasady: jeżeli klasa `D` dziedziczy po klasie `B`, to `D` otrzymuje "w spadku" funkcjonalność (pola i metody) `B`, którą może dodatkowo rozszerzyć.
Mówiąc ściślej, obiekt typu `D` zawiera w sobie podobiekt klasy `B`.
Pozwala nam to na uproszczenie struktury kodu poprzez komponowanie nowych klas z już istniejących.
Na przykład, jeżeli mamy klasy `Ołówek` i `Gumka`, to chcąc zaimplementować klasę reprezentującą ołówek z gumką na końcu, możemy po prostu stworzyć pustą klasę, która dziedziczy po `Ołówek` i `Gumka`.
```C++
class Ołówek { /* ... */ };
class Gumka  { /* ... */ };

class OłówekZGumką : public Ołówek, public Gumka {};
```
Tego typu strategię możemy znaleźć w [bibliotece I/O](https://en.cppreference.com/w/cpp/io).
Klasy strumieni dziedziczą po odpowiednich klasach bazowych w zależności od tego czy mają być strumieniami wejścia, wyjścia, czy obu.

Inne możliwe zastosowanie dziedziczenia polega na użyciu klasy bazowej jako wspólnego interfejsu dla wielu klas pochodnych.
Zobaczmy, jak może to wyglądać w praktyce.

#### Zadanie 1
Napisz klasę `Figura`, która posiada prywatną zmienną `double pole`.

#### Zadanie 2
Napisz setter i getter dla pola tej klasy.

#### Zadanie 3
Napisz klasy `Kolo` i `Kwadrat`, które dziedziczą po `Figura`.

#### Zadanie 4
Dodaj do napisanych klas konstruktory, które liczą pole figury na podstawie podanych wymiarów geometrycznych.

Dzięki dziedziczeniu po klasie `Figura` omijamy wielokrotne definiowanie pola `pole` oraz settera i gettera.
Nie trudno wyobrazić sobie, że dla większych klas taki zabieg pozwala zaoszczędzić wiele linijek kodu.

### Modyfikatory dostępu

**modyfikator dostępu `private`**
| Dostęp w klasie bazowej | Dostęp w klasie pochodnej |
|-------------------------|---------------------------|
| `public`                | `public`                  |
| `protected`             | `protected`               |
| `private`               | brak dostępu              |

### Konstruktory klas pochodnych

## Metody wirtualne

### Metody i klasy abstrakcyjne

### Destruktor

## Przykłady zastosowań

### Heterogeniczny kontener

### Fabryka

### Wizytator

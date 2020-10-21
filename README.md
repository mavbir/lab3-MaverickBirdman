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
W przykładzie powyżej, w konstruktorach klas pochodnych zmuszeni byliśmy używać settera pola klasy bazowej, gdyż było ono prywatne.
Wygodniej nam jednak operować bezpośrednio na zmiennej.
Z drugiej strony, nie chcemy wystawiać tej zmiennej bezpośrednio do użytkownika.
Rozwiązaniem tego dylematu jest trzeci (i ostatni) specyfikator dostępu w C\+\+: `protected` (chroniony).
Pola chronione mogą być czytane i modyfikowane przez metody klas, które dziedziczą po klasie, do której chronione pole należy, ale nie przez żadne inne.

#### Zadanie 5
Uczyń pole `pole` chronionym.
Usuń setter tego pola i zmodyfikuj odpowiednio konstruktory klas `Kwadrat` i `Kolo`.

Dodatkowo możemy przy dziedziczeniu zmodyfikować dostęp do pól i metod klasy bazowej za pomocą modyfikatorów dostępu.
Nie będziemy tego ćwiczyć, ale dla kompletności bieżącego tekstu podajemy niżej wygodną "ściągawkę".

| Modyfikator dostępu | Dostęp w klasie bazowej | Dostęp w klasie pochodnej |
|--------------------:|:-----------------------:|:-------------------------:|
| `public`            |                         |                           |
|                     | `public`                | `public`                  |
|                     | `protected`             | `protected`               |
|                     | `private`               | brak dostępu              |
| `protected`         |                         |                           |
|                     | `public`                | `protected`               |
|                     | `protected`             | `protected`               |
|                     | `private`               | brak dostępu              |
| `private`           |                         |                           |
|                     | `public`                | `private`                 |
|                     | `protected`             | `private`                 |
|                     | `private`               | brak dostępu              |

### Konstruktory klas pochodnych
Fakt, że klasa pochodna zawiera w sobie podobiekt klasy bazowej ma konsekwencje dla sposobu jej konstrukcji.
Przypomnijmy, że dla niedziedziczących klas tworzenie obiektu przebiego wg. następującego schematu:
1. Następuje alokacja pamięci na obiekt (na stosie lub na stercie, dla przebiegu procesu konstrukcji nie jest to istotne)
2. Wołany jest konstruktor
3. Pola obiektu są inicjalizowane przy pomocy listy inicjalizacyjnej i/lub konstruktorów domyślnych tych pól
4. Wykonywane jest ciało konstruktora

Zobaczmy, co stanie się, gdy spróbujemy bezpośrednio przenieść ten schemat na klasy dziedziczące.

#### Zadanie 6
Zmodyfikuj konstruktory klas `Kolo` i `Kwadrat` tak, aby inicjalizowały pole `pole` w swojej liście inicjalizacyjnej.
Czy kod się skompiluje?

Błąd kompilacji w powyższym zadaniu wynika z tego, że - z punktu widzenia konstrukcji - klasa bazowa zachowuje się jak pole klasy pochodnej.
Ogólny schemat tworzenia obiektu wygląda więc nieco inaczej, niż ten przedstawiony powyżej:
1. Następuje alokacja pamięci na obiekt
2. Wołany jest konstruktor
3. Obiekty klas bazowych konstruowane są za pomocą wskazanych konstruktorów (lub, jeżeli takowe nie został wskazane, konstruktorów domyślnych)
4. Pola obiektu są inicjalizowane przy pomocy listy inicjalizacyjnej i/lub konstruktorów domyślnych tych pól
5. Wykonywane jest ciało konstruktora

W kodzie wygląda to następująco:
```C++
class B1 { /* ... */ };
class B2 { /* ... */ };
// ...
class D : public B1, public B2 // ...
{
    D(/* ... */) : B1{/* ... */}, B2{/* ... */} /* ... */
	{
	    // ...
	}
};
```

#### Zadanie 7
Zmodyfikuj konstruktory klas `Kolo` i `Kwadrat` tak, aby inicjalizowały odpowiednio obiekt bazowy.
Zauważ, że możesz teraz uczynić pole `pole` prywatnym, gdyż odwołujesz się nie bezpośrednio do niego, tylko do konstruktora `Figura`.

## Metody wirtualne


### Metody i klasy abstrakcyjne

### Destruktor

## Przykłady zastosowań

### Heterogeniczny kontener

### Fabryka

### Wizytator

# Zaliczenie Laboratorium III
Masz dane następujące 4 klasy:
- `Statek`: posiada abstrakcyjną metodę `unsigned int transportuj()`
- `Tankowiec`: dziedziczy po `Statek`, nadpisuje metodę `transportuj`
- `Zaglowiec`: dziedziczy po `Statek`, nadpisuje metodę `transportuj`
- `Stocznia`: posiada metodę `Statek* operator()()`, który tworzy (losowo wybrany) statek (`Tankowiec` lub `Zaglowiec`) i zwraca wskaźnik do niego, posiada konstruktor domyślny
Krótko mówiąc, `Stocznia` jest fabryką statków (w programistycznym tego słowa znaczeniu).
Możemy stworzyć nowy statek wołając
```C++
Stocznia stocznia{};
Statek* s1 = stocznia();
```

Możesz założyć, że wymienione wyżej klasy mają dobrze zdefiniowane wszystkie metody specjalne, choć zapewne nie będą Ci one do niczego potrzebne.

Masz za zadanie napisać funkcję `unsigned int transportujFlota(unsigned int towar)`, która transportuje podaną do funkcji ilość towaru.
Ma ona to robić wg. natępującego schematu:
1. tworzy przy pomocy fabryki statek
2. woła jego metodę `transportuj`, która zwróci ilość towaru, który dany statek przetransportował
3. dodaje tę liczbę do licznika przetransportowanego sumarycznie towaru
4. niszczy stworzony statek
5. jeżeli sumaryczna ilość przetransportowanego towaru jest większa lub równa podanemu argumentowi `towar`, funkcja kończy pracę.
W przeciwnym wypadku, wróć do punktu 1.

Dodatkowo funkcja powinna liczyć i zwracać liczbę żaglowców (tylko żaglowców, nie wszystkich statków), które stworzyła w celu przewiezienia towaru.

**Uwaga**: Podany argument `towar` może być równy 0, wtedy `transportujFlota` nie powinno tworzyć żadnego statku

**Podpowiedź**: Do sprawdzenia czy stworzony statek był żaglowcem wykorzystaj `dynamic_cast`.

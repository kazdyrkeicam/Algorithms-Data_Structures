/*

Partycja Logiczna zawsze była dociekliwą i upartą osobą, dlatego tuż po doktoracie z politologii zdecydowała się zająć dziennikarstwem śledczym.
I była w tym naprawdę dobra.
Od pewnego czasu z dużym niepokojem obserwowała zmiany w światowej polityce.
Decyzje gospodarcze i społeczne największych mocarstw stały się dość chaotyczne i (czego Partycja najbardziej nie lubiła) nielogiczne.
Czyżby kryło się za tym coś jeszcze?

Partycji udało się na razie zebrać n różnych tropów w tej sprawie.
Każdy z nich postanowiła dokładnie zbadać. Wiadome jest, że zbadanie tropu może doprowadzić do kilku kolejnych.
Partycja zna m różnych metod badania tropów.
Używając mi metody udaje się jej rozpracować xi tropów, lecz generuje yi nowych.
Jednorazowe wykorzystanie metody możemy nazwać fazą badań.
Spróbujmy odpowiedzieć na pytanie ile faz badań wystarczy przeprowadzić, by zbadać wszystkie tropy (zebrane na początku oraz wygenerowane w trakcie badań).
Zakładamy, że jeśli podczas danej fazy liczba tropów w wyniku zbadania będzie mniejsza lub równa 0, nowe tropy nie będą już w tej fazie generowane i uznajemy, że wszystkie tropy zostały zbadane.
Partycja może wykorzystywać każdą z metod wielokrotnie, w dowolnej kolejności.

## Wejście
W pierwszej linii wejścia znajduje się liczba naturalna t, czyli liczba zestawów danych.
Każdy zestaw danych składa się z dwóch liczb naturalnych n - liczba tropów oraz m - liczba metod badawczych. W kolejnych m liniach znajdują się pary liczb xi i yi, które oznaczają kolejno liczbę zbadanych tropów i liczbę nowych tropów w i-tej metodzie.

1 <= t <= 10
1 <= n,m <= 1 000 000

## Wyjście
Dla każdego zestawu danych należy wypisać liczbę naturalną, która oznacza minimalną liczbę faz badań, potrzebną do zbadania wszystkich tropów.
Jeżeli zestaw metod jest niewystarczający, należy wypisać na standardowym wyjściu BRAK METOD.

Przykład

Wejście:
3
10 4
6 5
8 4
4 2
3 1
10 4
5 1
3 2
6 100
1 1000
15 2
10 10
14 100

Wyjście:
2
2
BRAK METOD

*/


#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int zestaw;
    int tropy, metody;
    int bilans = 0;
    int max = 0;
    int x, y;
    cin >> zestaw;
    while(zestaw > 0){
        cin >> tropy >> metody;
        while(metody > 0){
            cin >> x >> y;
            if(bilans < x - y)
                bilans = x - y;
            if(max < x)
                max = x;
            metody--;
        }
        if(bilans <= 0 && tropy > max)
            cout << "BRAK METOD" << endl;
        else if(tropy <= max)
            cout << 1 << endl;
        else if((tropy - max) % bilans != 0)
            cout << (tropy - max) / bilans + 2 << endl;
        else if((tropy - max) % bilans == 0)
            cout << (tropy - max) / bilans + 1 << endl;
        zestaw--;
        bilans = max = 0;
    }
    return 0;
}

/*

Jak wiadomo w Lublinie często odbywają się spotkania kulinarne, degustacyjne i różne festiwale smaku. Jedna z koleżanek Partycji (z grupy społecznej, której nie wykluczyła:) ) zajmuje się organizacją festiwalu degustacji tradycyjnych polskich potraw. Chciałaby, aby to wydarzenie było jednym z najlepszych. Zależy jej na tym, aby każdy zjadł to, na co ma ochotę.

W związku z tym Jagoda, bo tak ma na imię koleżanka naszej bohaterki, poprosiła wszystkich zaproszonych na festiwal o wypełnienie ankiety. Ankieta polega na tym, że każdy uczestnik wydarzenia musi wybrać potrawy, które chciałby skosztować. Oczywiście taka osoba może zaznaczyć dowolną ilość potraw z listy, które chętnie by zjadła. Uczestnik może zaznaczyć wszystkie potrawy, ale równie dobrze może nie zaznaczyć żadnej - wtedy wiemy, że nie będzie on zadowolony. Ponieważ są to bardzo ekskluzywne potrawy i kunsztowne, ekskluzywne wydarzenie na każdego uczestnika przypada tylko jedna degustacja. Niestety dobranie odpowiednich posiłków dla każdego z gości, jest ogromnym wyzwaniem organizacyjnym. Wynika to przede wszystkim z tego, że każdej potrawy zostanie przygotowana taka sama, ograniczona ilość. Dodatkowo Jagoda chce aby, jak najwięcej osób wyszło z wydarzenia zadowolonych. To zadowolenie gwarantuje jedynie to, że przybysze zjedzą potrawę, która była na ich liście życzeń.

WEJŚCIE
W pierwszej linii wejścia znajdują się liczby naturalne n m l, n - to liczba uczestników wydarzenia, m - to ilość dostępnych potraw, zaś l - to ilość zestawów degustacyjnych każdej z potraw. Następnie program powinien wczytać wyniki ankiety, które są podane w macierzy o wymiarach n x m. Gdy uczestnik chce spróbować potrawy wprowadził ‘x’, a w przeciwnym wypadku ‘o’.

0 <= n, m, l <= 2000000000

WYJŚCIE
Na wyjściu algorytm powinien wypisać jedną liczbę całkowitą, która jest największą możliwą liczbą osób zadowolonych z uczestnictwa w wydarzeniu.

PRZYKŁADOWE DANE WEJŚCIOWE
6 3 2
o o x
x x x
o o x
x o o
x o x
x o o
PRZYKŁADOWE DANE WYJŚCIOWE
5
UWAGI
Rozwiązane zadania powinno być implementacją metody wyszukiwania maksymalnego skojarzenia w grafie dwudzielnym.

*/

#include <iostream>
using namespace std;

bool bpm(int size, bool **bpGraph, int u, bool seen[], int matchR[]) {
    for (int v = 0; v < size; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(size, bpGraph, matchR[v], seen, matchR)){
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int row, int col, bool **bpGraph) {
    int matchR[col];
    for(int i = 0; i < col; ++i)
        matchR[i] = -1;

    int result = 0;

    for (int u = 0; u < row; u++) {
        bool seen[col];

        for(int i = 0; i < col; ++i)
            seen[i] = false;

        if (bpm(col, bpGraph, u, seen, matchR))
            result++;
    }

    /*cout << endl;
    for(int i = 0; i < row; ++i)
        cout << i << ": " << "M " << matchR[i] << endl;
    cout << endl;*/

    return result;
}

int main(){
    int participant, dish, taste_set;
    char decision;

    cin >> participant >> dish >> taste_set;
    bool **bp_graph = new bool * [participant];

    for(int i = 0; i < participant; ++i)
        bp_graph[i] = new bool [dish * taste_set];

    for(int i = 0; i < participant; ++i)
        for(int j = 0; j < dish; ++j)
            bp_graph[i][j] = false;

    for(int i = 0; i < participant; ++i){
        for(int j = 0; j < dish; ++j){
            cin >> decision;
            if(decision == 'x'){
                bp_graph[i][j] = true;
                for(int k = 1; k < taste_set; ++k)
                    bp_graph[i][j + (dish * k)] = true;
            }
        }
    }

   /* cout << "  ";
    for(int i = 0; i < participant; ++i)
        cout << i << " ";
    cout << endl;
    for(int i = 0; i < participant; ++i){
        cout << i << " ";
        for(int j = 0; j < dish * taste_set; ++j){
            cout << bp_graph[i][j] << " ";
        }
        cout << endl;
    }/**/


    cout << maxBPM(participant, dish * taste_set, bp_graph) << endl;

    return 0;
}

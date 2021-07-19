/*

Problemy z przekazaniem dokumentów od eksperta sprawiły, że Partycja postanowiła obsadzić stacje kolejowe współpracującymi z nią wolontariuszami w taki sposób, żeby każdy pociąg musiał przejeżdżać przez co najmniej jedną stację, na której wolontariusz mógłby odebrać dokumenty od kuriera. Oznacza to, że na co najmniej jednym końcu każdego odcina torów łączącego dwie stacje musi być wolontariusz. Oczywiście do obsadzenia wszystkich końców znajdujących się na jednej stacji wystarczy jeden wolontariusz. Niestety liczba wolontariuszy współpracujących z Partycją jest mocno ograniczona. Partycja zastanawia się czy ich liczba jest wystarczająca do obsadzenia końców wszystkich odcinków linii kolejowych.

Wejście:
Pierwsza linia wejścia zawiera liczbę całkowitą t - liczbę zestawów danych, których opisy występują kolejno po sobie. W pierwszej linii zestawu danych podane są trzy liczby naturalne n, m i r - odpowiednio liczba stacji kolejowych , liczba odcinków kolejowych bezpośrednio łączących ze sobą dwie stacje kolejowe oraz liczba wolontariuszy. Każda z kolejnych m linii zawiera dwie liczby naturalne a i b - numery stacji kolejowych połączonych bezpośrednim odcinkiem torów.

1 ≤ t ≤ 150
1 ≤ n ≤ 30
1 ≤ m ≤ 100
1 ≤ r ≤ 20
1 ≤ a, b ≤ n
Wyjście:
Dla każdego zestawu danych program powinien wypisać jedną linię zawierającą napis

TAK
, jeśli liczba wolontariuszy jest wystarczająca albo
NIE
w przeciwnym przypadku.
Przykładowe wejście:
3
2 1 1
1 2
4 6 2
1 2
1 3
1 4
2 3
2 4
3 4
6 1 1
4 5

Przykładowe wyjście:
TAK
NIE
TAK

Zadanie należy rozwiązać za pomocą przeszukiwania z nawrotami.

*/

#include <iostream>

using namespace std;

struct Edge{
    int one, two;
};

bool backtracking(bool *station, Edge *pairs, int pairSize, int volunteers, int level){

    if(level >= pairSize)
        return true;

    if(station[pairs[level].one] == false && station[pairs[level].two] == false){
        if(volunteers){
            station[pairs[level].one] = true;
            if(backtracking(station, pairs, pairSize, volunteers - 1, level + 1))
                return true;
            else{
                station[pairs[level].one] = false;
                station[pairs[level].two] = true;
                if(backtracking(station, pairs, pairSize, volunteers - 1, level + 1))
                    return true;
                else{
                    station[pairs[level].two] = false;
                    return false;
                }
            } 
        }
        else
            return false;
    }
    else{
        if(backtracking(station, pairs, pairSize, volunteers, level + 1))
            return true;
        else
            return false;
    }
}

int main(){
    int kit;
    int stations, connections, volunteers;
    int tmp, i;

    cin >> kit;
    while(kit > 0){
        cin >> stations >> connections >> volunteers;

        bool *station = new bool[stations];

        for(i = 0; i < stations; ++i)
            station[i] = false;

        Edge *pairs = new Edge[connections];

        for(i = 0; i < connections; ++i){
            cin >> tmp;
            pairs[i].one = tmp;
            cin >> tmp;
            pairs[i].two = tmp;
        }

        if(backtracking(station, pairs, connections, volunteers, 0))  cout << "TAK" << endl;
        else                cout << "NIE" << endl;
        kit--;
    }
    return 0;
}

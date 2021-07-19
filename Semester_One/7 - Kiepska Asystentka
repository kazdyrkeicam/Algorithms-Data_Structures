/*

Spotkanie z informatorem zaowocowało dalszym planem działań. Partycja dostała namiary na ludzi, którzy mogli wiele wnieść do śledztwa. Zauważyła jednak, że czasem daną osobę warto jest odwiedzić wcześniej niż inne, bo może mieć informacje przydatne w kolejnych rozmowach. Poprosiła swoją główną asystentkę, by sporządziła jej propozycje planów wizyt na podstawie ustawionych przez Partycję priorytetów. Nasz bohaterka otrzymała już plany, ale ma podejrzenie, że asystentka nie zrobiła tego jak należy. Woli więc sprawdzić, czy jej lista zgadza się z ustalonymi wcześniej priorytetami.

Wejście
W pierwszej linii wejścia znajduje się liczba naturalna t, czyli liczba zestawów danych. Każdy zestaw danych składa się z dwóch liczb naturalnych n oznaczającej liczbę nazwisk i m oznaczającej liczbę par nazwisk. W kolejnych n liniach znajduje się lista wszystkich nazwisk jako jednowyrazowe łańcuchy znaków. W dalszych m liniach znajdują się pary nazwisk. Każda para oznacza, że pierwszą osobę z pary należy odwiedzić wcześniej niż drugą osobę z pary.

W ostatniej linii zestawu znajduje się lista nazwisk, oznaczająca proponowaną przez asystentkę kolejność.

1 ≤ t ≤ 10
1 ≤ n ≤ 1000000
Wyjście
Na wyjściu dla każdego zestawu danych należy wypisać słowo TAK, jeżeli proponowana kolejność jest zgodna z założeniami lub NIE w przeciwnym wypadku.

Przykład

Wejście:
2
6 5
Abramczyk 
Bednarski
Cajzer
Dzik
Elert
Frackowiak
Abramczyk Bednarski
Abramczyk Cajzer
Bednarski Dzik
Elert Frackowiak
Cajzer Dzik
Elert Abramczyk Frackowiak Cajzer Bednarski Dzik
6 5
Abramczyk 
Bednarski
Cajzer
Dzik
Elert
Frackowiak
Abramczyk Bednarski
Abramczyk Cajzer
Bednarski Dzik
Elert Frackowiak
Cajzer Dzik
Elert Frackowiak Bednarski Cajzer Abramczyk Dzik

Wyjście:
TAK
NIE

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Content{
    vector<string> neighbors;
    int counter = 0;
};
int elements = 0;
map<string, Content*> input(){
    int long long pairs;
    map<string, Content*> graph;
    string tmpStr1, tmpStr2;
    Content *tmpCont;

    cin >> elements >> pairs;
    for(int i = 0; i < elements; ++i){
        tmpCont = new Content;
        cin >> tmpStr1;
        graph[tmpStr1] = tmpCont;
    }
    while(pairs > 0){
        cin >> tmpStr1 >> tmpStr2;
        graph[tmpStr1]->neighbors.push_back(tmpStr2);
        graph[tmpStr2]->counter++;
        pairs--;
    }
    return graph;
}
int main(){
    ios_base::sync_with_stdio(false);
    map<string, Content*> new_map;
    string tmpStr;
    int kit;
    vector<string>::iterator it;

    cin >> kit;
    while(kit > 0){
        new_map = input();
        //cout << "elementy: " << elements << endl;
        while(elements > 0){
            cin >> tmpStr;
            //cout << tmpStr << " ";
            if(new_map[tmpStr]->counter != 0){
                elements--;
                break;
            }
            else
                for(it = new_map[tmpStr]->neighbors.begin(); it != new_map[tmpStr]->neighbors.end(); ++it)
                    new_map[*it]->counter--;
            elements--;
            if(elements == 0)
                cout << "TAK" << endl;
        }
        while(elements > 0){
            cin >> tmpStr;
            //cout << tmpStr << " ";
            elements--;
            if(elements == 0)
                cout << "NIE" << endl;
        }
        //cout << endl;
        kit--;
    }
    return 0;
}

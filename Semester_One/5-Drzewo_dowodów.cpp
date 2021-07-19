/*

Grupa operacyjna Partycji (którą udało się skompletować w ostatnim czasie) działała bardzo prężnie i każdego dnia wprowadzała do ich współdzielonego arkusza kalkulacyjnego dane o nowych materiałach dowodowych. Umówili się na dokładne kategoryzowanie danych i przykładowy wpis do arkusza wyglądał następująco:

"Kategoria 1 - Podkategoria 4 - Rodzaj 2 - Typ 7 - Wpis 2" lub "Kategoria 3 - Podkategoria 2 - Rodzaj 6" czy też "Kategoria 3 - Podkategoria 2 - Rodzaj 3" co w skrócie można zapisać jako: 1 4 2 7 2 dla pierwszego przykładu, 3 2 6 dla drugiego przykładu i 3 2 3 dla trzeciego przykładu.

Danych było coraz więcej i śledczy zaczęli się coraz bardziej gubić. Partycja doszła do wniosku, że dużo lepiej wyglądałoby to w formie drzewa, takiego jak poniżej.

          0
         / \
        1   3
       /     \
      4       2
     /       / \
    2       6   3
   /
  7
 /
2

Potrzebowała więc małego systemu, który na podstawie ponumerowanych i skategoryzowanych wpisów umieszczałby poszczególne wartości w odpowiednim miejscu drzewa materiałów dowodowych. Zakładamy, że korzeń drzewa ma numer 0 i od niego zaczynają się wszystkie wpisy.

Wejście
W pierwsze linii wejścia znajduje się liczba naturalna n oznaczająca liczbę wpisów w arkuszu materiałów dowodowych. W kolejnych n liniach znajdują się wpisy. Każdy wpis składa się z liczby naturalnej x, po której następuje x liczb, tworzących wpis.

1 ≤ n ≤ 10000
0 ≤ x ≤ 10000
Wyjście
Na wyjściu należy wyświetlić tak zbudowane drzewo w kolejności preorder. Korzeń o wartości "0" należy na wyjściu pominąć.

UWAGA! W zadaniu nie można używać bibliotek STL.

Przykład
Wejście:
10
5 3 1 5 2 7
4 3 1 2 6
3 3 4 1
2 5 6
3 2 6 7
3 2 6 8
3 2 5 6
1 1
1 3
2 1 3 
Wyjście:
3 1 5 2 7 2 6 4 1 5 6 2 6 7 8 5 6 1 3

*/

#include <iostream>
using namespace std;
struct node{
    int value;
    node *parent, *son, *bro;
    node(int v){value = v; parent = bro = son = NULL;}
    void show(){
        if(parent != NULL)
            cout << value << " ";
    }
};
struct tree{
    node *root, *link;
    tree(){root = link = NULL;}
    void newBro(int v){
        node *news = new node(v);
        link->bro = news;
        news->parent = link->parent;
        link = news;
    }
    void newSon(int v){
        node *news = new node(v);
        news->parent = link;
        link->son = news;
        link = news;
    }
};
void preorder(node *st){
    st->show();
    if(st->son != NULL)
        preorder(st->son);
    if(st->bro != NULL)
        preorder(st->bro);
}

int main(){
    ios_base::sync_with_stdio(false);
    tree *t = new tree();
    t->root = new node(0);
    t->link = t->root;
    int num;
    cin >> num;
    int size, buf;
    while(num > 0){
        cin >> size;
        while(size > 0){
            cin >> buf;
            if(t->link->son == NULL)
                t->newSon(buf);
            else{
                if(t->link->son->value == buf)
                    t->link = t->link->son;
                else{
                    t->link = t->link->son;
                    while(t->link->bro != NULL && t->link->value != buf)
                        t->link = t->link->bro;
                    if(t->link->value != buf)
                        t->newBro(buf);
                }
            }
            size--;
        }
        t->link = t->root;
        num--;
    }
    node *st = t->root;
    preorder(st);
    return 0;
}

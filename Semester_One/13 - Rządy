/*

Partycja ostatnio zastanawia się, które rządy wiedzą o zbliżającej się katastrofie. Postanowiła na podstawie zdobytych informacji zrobić zestawienie mające wytypować, które państwa wiedzą, a które nie wiedzą o katastrofie. Każdemu państwu przypisywany jest współczynnik będący liczbą całkowitą z zakresu od 0 do 1000000 mówiący o tym jak bardzo pewne jest, że rząd danego państwa wie o czekającej ziemię katastrofie. Partycja wraz ze współpracownikami z całego świata aktualizuje współczynniki przypisane poszczególnym państwom po uzyskaniu nowych informacji. Na przykład fakt, że jakiś rząd blokuje porozumienie klimatyczne albo składa nierealne obietnice socjalne jest dla niej argumentem za tym, że ten rząd wie iż od września 2020 roku żadne obietnice nie będą miały znaczenia (pojawienie się tego typu informacji powoduje zwiększenie współczynnika przypisanego danemu państwu). Z kolei jeżeli jakiś rząd prowadzi odpowiedzialną politykę, wprowadza oszczędności budżetowe itp. jest to dla Partycji poszlaką świadczącą o tym, że dany rząd nie wie nic o zbliżającej się katastrofie (co zmniejsza wartość współczynnika przypisanego danemu państwu).

Partycja uruchomiła działający w Darknecie serwer umożliwiający wolontariuszom z całego świata aktualizację współczynników na podstawie zdobytych przez nich dokumentów. Wraz ze wzrostem liczby wolontariuszy stary serwer zaczął się ,,zapychać''. Partycja postanowiła oszacować potrzeby przed zakupem nowego. W tym celu zaczęła zliczać operacje wykonywane na serwerze. Ponieważ lista państw jest przechowywana w kopcu binarnym posortowanym względem rozważanego współczynnika to Partycja postanowiła zliczać liczbę zamian ojca z synem w trakcie przesiewania w kopcu. Kopiec jest zaimplementowany w taki sposób, że w trakcie przesiewania w dół, w przypadku gdy obaj synowie przesiewanego wierzchołka mają równą wartość współczynnika, wierzchołek zamieniany jest z tym z synów, który znajduje się w komórce tablicy o mniejszym indeksie. Ze względów konspiracyjnych państwom przypisano liczby z przedziału od 0 do 1000, które są używane zamiast ich nazw.

Wejście
Na wejściu program otrzymuje liczbę n rozważanych państw a następnie n opisów państw w kolejności w jakiej odpowiadające tym państwom węzły znajdują się w tablicy przechowującej kopiec. Opisy poszczególnych państw składają się z par p, w liczb oznaczających kolejno numer przypisany do państwa oraz jego współczynnik. Następnie program otrzyma liczbę m oraz m opisów zmian rozważanego współczynnika. Każdy opis składa się z pary p, w oznaczającej, że współczynnik państwa p otrzymuje nową wartość w.

1<=n<=1000
1<=m<=2000000
Wyjście
Na standardowym wyjściu program powinien wypisać liczbę zamian wykonanych w trakcie przesiewania elementów kopca.

Przykłady

Wejście
4
48 1000
1 999
7 999
44 997
3
48 996
1 1001
7 995

Wyjście
2

Wejście
4
48 1000
1 999
7 999
44 997
2
7 995
48 1001

Wyjście
0

Wejście
4
48 1000
1 999
7 999
44 997
3
48 998
44 1000
1 1001

Wyjście
4

*/

#include <iostream>
#include <unordered_map>

using namespace std;
struct State{
    int name, coefficient;
};
void swap(unordered_map<int, int> &map, int i, int j){
    int tmp = map[i];
    map[i] = map[j];
    map[j] = tmp;
}
void swap(State *st, int index_one, int index_two){
    State temp = st[index_one];
    st[index_one] = st[index_two];
    st[index_two] = temp;
}


int parity_bufer, greater_bufer, counter;


unordered_map<int, int> helper;

bool sift_up(State*, int);
bool sift_down(State*, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    
    int size, changes;
    State *state;
    int i, tmp_name, tmp_coe;

    cin >> size;
    state = new State[size];
    for(i = 0; i < size; ++i){
        cin >> tmp_name >> tmp_coe;
        helper[tmp_name] = i;
        state[i].name = tmp_name;
        state[i].coefficient = tmp_coe;
    }

    cin >> changes;
    counter = 0;
    while(changes > 0){
        cin >> tmp_name >> tmp_coe;
        i = helper[tmp_name];
        state[i].coefficient = tmp_coe;

        while(i >= 0 && i < size){
            if(sift_up(state, i)){
                swap(helper, tmp_name, state[parity_bufer].name);
                swap(state, i, parity_bufer);
                counter++;
                i = parity_bufer;
            }//if
            else if(sift_down(state, size, i)){
                swap(helper, tmp_name, state[greater_bufer].name);
                swap(state, i, greater_bufer);
                counter++;
                i = greater_bufer;
            }//else if
            else
                break;
        }
        changes--;
    }//while

    cout << counter << endl;
    return 0;
}
//=====================================FUNKCJE===============================================
//jesli jest jakis blad, to tutaj   if(mistake) find_it(!);

bool sift_up(State *st, int index){
    if(index != 0){
        if(index % 2){
            if(st[(index - 1) / 2].coefficient < st[index].coefficient){
                parity_bufer = (index - 1) / 2;
                return true;
            }
            return false;
        }
        else{
            if(st[(index - 2) / 2].coefficient < st[index].coefficient){
                parity_bufer = (index - 2) / 2;
                return true;
            }
            return false;
        }
    }
    return false;
}

bool sift_down(State *st, int size, int index){
    if(index * 2 + 1 < size){
        if(index * 2 + 2 < size){
            greater_bufer = st[index * 2 + 1].coefficient >= st[index * 2 + 2].coefficient ? index * 2 + 1 : index * 2 + 2;
            if(st[greater_bufer].coefficient > st[index].coefficient){
                return true;
            }
            return false;
        }
        greater_bufer = index * 2 + 1;
        if(st[greater_bufer].coefficient > st[index].coefficient){
            return true;
        }
        return false;
    }
    return false;
}

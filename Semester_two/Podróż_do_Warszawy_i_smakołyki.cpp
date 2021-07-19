/*

Partycja Logiczna przemyślała swoje plany i doszła do wniosku, że może obniżyć swój stres na niektórych postojach. W końcu uwielbia jeść, a to na pewno obniża kortyzol w jej organizmie. Przynajmniej będzie tak pomiędzy postojami. Nasza bohaterka rozbudowała opis postojów na siatce o dodatkową wartość v. Ta wartość to liczba, która reprezentuje ilość jednostek stresu, jaką może obniżyć dany postój.

Usprawnij poprzedni program tak by brał pod uwagę ewentualne przyjemności kulinarne na postojach.

WEJŚCIE
W pierwszej linii wejścia znajduje się liczba naturalna n, mówiąca o ilości postojów. Następnie program powinien wczytać n sekwencji danych: x y v, które są współrzędnymi postojów na naniesionej przez Partycje siatce. Na koniec program powinien wczytać dwie liczby naturalne s i d, które są odpowiednio postojem startowym i postojem docelowym, czyli siedzibą instytucji, do której zmierza nasza bohaterka. Każdy postój ma inne współrzędne.

0 <= n, v <= 32000
0 <= x, y, s, d <= 2000000000

WYJŚCIE
Na wyjściu algorytm powinien wypisać jedną liczbę całkowitą, która jest możliwie najmniejszą liczbą jednostek stresu, które przeżyje nasza bohaterka na trasie z punktu s do punktu d. Może dojść do sytuacji, gdy podróżowanie na pewnym odcinku będzie przynosiło Partycji ciągłe przyjemności. W takiej sytuacji należy zmusić naszą bohaterkę by szybko wróciła na trasę do Warszawy wyświetlając komunikat: NIE ZA DOBRZE?

PRZYKŁADOWE DANE WEJŚCIOWE
I

5
2 2 0
1 1 0
4 5 1
7 1 0
6 7 0
0 4
II

5
2 2 0
1 1 1
4 5 1
7 1 0
6 7 0
0 4
PRZYKŁADOWE DANE WYJŚCIOWE
I

2
II

NIE ZA DOBRZE?

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2147483647

struct In{
    int index, x, y, tidbit;

    void assing(int i, int a, int b, int c){
        index = i;  x = a;  y = b; tidbit = c;
    }

    void show(){
        cout << index << " " << x << " " << y << " " << tidbit << endl;
    }
};

struct Edge{
    int src, dist, cost;
};

bool compareX(In a, In b){ return a.x < b.x; }
bool compareY(In a, In b){ return a.y < b.y; }

int input(int ver, vector<Edge> &graph){
    In *arr = new In [ver];
    int edge = 0;
    //temponaries
    int x, y, t;
    Edge tmp;

    for(int i = 0; i < ver; ++i){
        cin >> x >> y >> t;
        arr[i].assing(i, x, y, t);
    }
    sort(arr, arr + ver, compareX);

    for(int i = 1; i < ver; ++i){
        tmp.src = arr[i - 1].index;
        tmp.dist = arr[i].index;
        tmp.cost = arr[i].x - arr[i - 1].x - arr[i].tidbit;
        graph.push_back(tmp);

        tmp.src = arr[i].index;
        tmp.dist = arr[i - 1].index;
        tmp.cost = arr[i].x - arr[i - 1].x - arr[i - 1].tidbit;
        graph.push_back(tmp);
        edge += 2;
    }

    sort(arr, arr + ver, compareY);

    for(int i = 1; i < ver; ++i){
        tmp.src = arr[i - 1].index;
        tmp.dist = arr[i].index;
        tmp.cost = arr[i].y - arr[i - 1].y - arr[i].tidbit;
        graph.push_back(tmp);

        tmp.src = arr[i].index;
        tmp.dist = arr[i - 1].index;
        tmp.cost = arr[i].y - arr[i - 1].y - arr[i - 1].tidbit;
        graph.push_back(tmp);
        edge += 2;
    }
    return edge;
}

void bellman_ford(int ver, vector<Edge> graph){
    int *dist = new int [ver];
    int start, end;
    //temponaries
    vector<Edge>::iterator it;
    int v, u, w;
    bool show = true;

    cin >> start >> end;

    for(int i = 0; i < ver; ++i)
        dist[i] = MAX;
    dist[start] = 0;

    for(int i = 1; i < ver; ++i){
        for(it = graph.begin(); it != graph.end(); ++it){
            u = it->src;
            v = it->dist;
            w = it->cost;
            if(dist[u] != MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(it = graph.begin(); it != graph.end(); ++it){
        u = it->src;
        v = it->dist;
        w = it->cost;
        if(dist[u] != MAX && dist[u] + w < dist[v]){
            cout << "NIE ZA DOBRZE?" << endl;
            show = false;
            return;
        }
    }
    if(show)
        cout << dist[end] << endl;
}

int main(){
    int ver, edge;

    cin >> ver;

    vector<Edge> net;
    edge = input(ver, net);
    bellman_ford(ver, net);

    return 0;
}

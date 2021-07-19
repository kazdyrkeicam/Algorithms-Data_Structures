/*

Partycja Logiczna podczas ferii wpadła na innowacyjne rozwiązanie dotyczące technologii elastycznych ekranów. Chciałaby sfinalizować swój pomysł, a więc wymaga to odwiedzenia naszej pięknej stolicy i siedziby Agencji Techniki i Technologii. Niestety to kawałek drogi, a Partycje jazda samochodem bardzo stresuje. W związku z tym wpadła na pomysł, że zabierze ze sobą swoją koleżankę Magistrale. Ona również nie cieszy się wizją prowadzenia samochodu, jednakże bardzo chciałaby zobaczyć Warszawę.

Partycja wymyśliła system, który pozwala zminimalizować czas prowadzenia samochodu, co narazi ją na mniejszy stres. Po drodze do Warszawy znajduje się n postojów, które numerujemy liczbami od 0 do n - 1. Numerem s jest oznaczone miejsce, z którego dziewczyny ruszają w trasę, zaś numerem d miejsce docelowe - Warszawa. Po naniesieniu odpowiedniej siatki na mapę, Partycja zauważyła pewną ciekawą zależność. Mianowicie doszła do wniosku, że mogą poruszać się tylko w jednym z czterech kierunków świata. Dodatkowo zgodnie z naniesioną siatką każdy z postojów był na przecięciu osi odciętych i rzędnych.

Nasza inteligentna bohaterka wpadła na pomysł, że za każdym razem, gdy zmienią swój kierunek o 90 stopni zamieniają się miejscami przy kierownicy. Dodatkowo po drodze mogą zatrzymać się na dowolnej ilości postojów, nie ma znaczenia, jak długo będzie trwała cała trasa. Dla Partycji liczy się tylko to, że powinna być za kierownicą możliwie najkrócej. Na koniec aby dać sobie więcej możliwości do zrezygnowania z prowadzenia automobila, Partycja zaproponowała jeszcze jedną zasadę. Dziewczyny ustaliły, że po każdym postoju Partycja może zdecydować, czy usiądzie za kierownicą. Innymi słowy na każdym fragmencie trasy prowadzącym z postoju do postoju jedna z kobiet usiądzie za kierownicą, gdy poruszają się północ, południe, zaś druga z nich prowadzi podczas jazdy na wschód lub zachód. W szczególności, jeśli pewien odcinek trasy prowadzi dokładnie w jednym z czterech kierunków świata, wtedy na tym odcinku prowadzi tylko jedna z kobiet.

Partycja zastanawia się, jak zaplanować trasę do siedziby Agencji Techniki i Technologii oraz podział pracy, by spędzić za kierownicą jak najmniej czasu. Przyjmujemy, że jedna jednostka na siatce jest równa jednej jednostce stresu Partycji, który należy zminimalizować.

WEJŚCIE
W pierwszej linii wejścia znajduje się liczba naturalna n, mówiąca o ilości postojów. Następnie program powinien wczytać n sekwencji danych: x y, które są współrzędnymi postojów na naniesionej przez Partycje siatce. Na koniec program powinien wczytać dwie liczby naturalne s i d, które są odpowiednio postojem startowym i postojem docelowym, czyli siedzibą instytucji, do której zmierza nasza bohaterka. Każdy postój ma inne współrzędne.

0 <= n <= 32000
0 <= x, y, s, d <= 2000000000

WYJŚCIE
Na wyjściu algorytm powinien wypisać jedną liczbę całkowitą, która jest możliwie najmniejszą liczbą jednostek stresu, które przeżyje nasza bohaterka na trasie z punktu s do punktu d.

PRZYKŁADOWE DANE WEJŚCIOWE
5
2 2
1 1
4 5
7 1
6 7
0 4
PRZYKŁADOWE DANE WYJŚCIOWE
2
Uwaga program rozwiązujący zadanie powinien być implementacją algorytmu Dijkstry i nie powinien korzystać z kopców Fibonacciego

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 2147483647

struct In{
    int index, x, y;
};

struct Node{
    int neigh, cost;
};

struct Vertex{
    int value, priority;
};

class Compare{
public:
    int operator() (const Vertex &a, const Vertex &b){
        return a.priority > b.priority;
    }
};

bool compareX(In a, In b){ return a.x < b.x; }
bool compareY(In a, In b){ return a.y < b.y; }

void show(int n, In *a){
    for(int i = 0; i < n; ++i)
        cout << a[i].index << " " << a[i].x << " " << a[i].y << endl;
}

void input(int ver, vector<Node> graph[]){
    In *arr = new In [ver];
//temponaries
    Node tmp1, tmp2;
    int x, y;

    for(int i = 0; i < ver; ++i){
        cin >> x >> y;
        arr[i].index = i;
        arr[i].x = x;
        arr[i].y = y;
    }
    sort(arr, arr + ver, compareX);

    for(int i = 1; i < ver; ++i){
        tmp1.neigh = arr[i - 1].index;
        tmp2.neigh = arr[i].index;
        tmp1.cost = tmp2.cost = arr[i].x - arr[i - 1].x;

        graph[arr[i].index].push_back(tmp1);
        graph[arr[i - 1].index].push_back(tmp2);
    }
    sort(arr, arr + ver, compareY);

    for(int i = 1; i < ver; ++i){
        tmp1.neigh = arr[i - 1].index;
        tmp2.neigh = arr[i].index;
        tmp1.cost = tmp2.cost = arr[i].y - arr[i - 1].y;

        graph[arr[i].index].push_back(tmp1);
        graph[arr[i - 1].index].push_back(tmp2);
    }
}

void dijkstra(int ver, vector<Node> graph[], int start, int end){
    vector<Node>::iterator it;
    int *dist = new int [ver];
    bool *visited = new bool [ver];
    priority_queue<Vertex, vector<Vertex>, Compare> q;
    Vertex *arr = new Vertex [ver];
    Vertex current, tmp;

    for(int i = 0; i < ver; ++i){
        dist[i] = MAX, visited[i] = false;
        arr[i].value = i;
    }

    dist[start] = 0;    arr[start].priority = 0;
    q.push(arr[start]);

    while(!q.empty()){
        current = q.top();
        q.pop();

        if(!visited[current.value]){
            for(it = graph[current.value].begin(); it != graph[current.value].end(); ++it){
                if(dist[it->neigh] > dist[current.value] + it->cost){
                    dist[it->neigh] = dist[current.value] + it->cost;
                    tmp.value = it->neigh;
                    tmp.priority = dist[it->neigh];
                    q.push(tmp);
                }
            }
        }
    }
    cout << dist[end] << endl;
}

int main(){
    int ver, start, end;
    cin >> ver;

    vector<Node> net[ver];
    input(ver, net);
    //show_vec(ver, net);
    cin >> start >> end;
    dijkstra(ver, net, start, end);
    return 0;
}

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

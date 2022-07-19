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

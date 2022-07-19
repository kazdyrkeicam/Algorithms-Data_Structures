#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

bool circle = true;

struct Edge{
    int start, end;
    void add(int v, int e){
        start = v;
        end = e;
    }
};

void show_map(map<int, vector<int>> map){
    for(auto it : map){
        cout << it.first << ": ";
        for(auto iter : it.second)
            cout << iter << " ";
        cout << endl;
    }
}

void show_edge(vector<Edge> e){
    for(auto it : e)
        cout << it.start << " " << it.end << endl;
}

void _union(int x, int y, int *arr, int size){
    int rx = arr[x];
    int ry = arr[y];

    if(rx != ry){
        for(int i = 0; i < size; ++i)
            if(arr[i] == ry)
                arr[i] = rx;
    }
    else
        circle = false;
}

int main()
{
    map<int, vector<int>> map;
    vector<Edge> edge;
    int person, interest;
    int *set;
    //temponaries
    int x;
    Edge tmp;

    cin >> person;
    set = new int [person];
    for(int i = 0; i < person; ++i){
        set[i] = i;
        cin >> interest;
        for(int j = 0; j < interest; ++j){
            cin >> x;
            map[x].push_back(i);
        }
    }
    //show_map(map);
    for(auto it : map){
        if(map[it.first].size() > 1){
            for(unsigned i = 0; i < map[it.first].size() - 1; ++i){
                for(unsigned j = i + 1; j < map[it.first].size(); ++j){
                    tmp.start = map[it.first][i];
                    tmp.end = map[it.first][j];
                    edge.push_back(tmp);
                }
            }
        }
    }
    //show_edge(edge);

    for(auto it : edge)
        _union(it.start, it.end, set, person);

    if(circle)
        cout << "NIE" << endl;
    else
        cout << "TAK" << endl;
    return 0;
}

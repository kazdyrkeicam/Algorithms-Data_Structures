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

    cout << maxBPM(participant, dish * taste_set, bp_graph) << endl;

    return 0;
}

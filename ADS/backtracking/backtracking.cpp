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

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

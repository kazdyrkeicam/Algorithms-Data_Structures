#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Content{
    vector<string> neighbors;
    int counter = 0;
};
int elements = 0;
map<string, Content*> input(){
    int long long pairs;
    map<string, Content*> graph;
    string tmpStr1, tmpStr2;
    Content *tmpCont;

    cin >> elements >> pairs;
    for(int i = 0; i < elements; ++i){
        tmpCont = new Content;
        cin >> tmpStr1;
        graph[tmpStr1] = tmpCont;
    }
    while(pairs > 0){
        cin >> tmpStr1 >> tmpStr2;
        graph[tmpStr1]->neighbors.push_back(tmpStr2);
        graph[tmpStr2]->counter++;
        pairs--;
    }
    return graph;
}
int main(){
    ios_base::sync_with_stdio(false);
    map<string, Content*> new_map;
    string tmpStr;
    int kit;
    vector<string>::iterator it;

    cin >> kit;
    while(kit > 0){
        new_map = input();
        //cout << "elementy: " << elements << endl;
        while(elements > 0){
            cin >> tmpStr;
            //cout << tmpStr << " ";
            if(new_map[tmpStr]->counter != 0){
                elements--;
                break;
            }
            else
                for(it = new_map[tmpStr]->neighbors.begin(); it != new_map[tmpStr]->neighbors.end(); ++it)
                    new_map[*it]->counter--;
            elements--;
            if(elements == 0)
                cout << "TAK" << endl;
        }
        while(elements > 0){
            cin >> tmpStr;
            //cout << tmpStr << " ";
            elements--;
            if(elements == 0)
                cout << "NIE" << endl;
        }
        //cout << endl;
        kit--;
    }
    return 0;
}

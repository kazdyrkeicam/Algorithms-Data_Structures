#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned int uint;

struct Node {
    string key;
    vector<string> list;

    //Node *next;
    Node ( string key, string link ) : key(key) {
        //next = NULL;
        list.push_back(link);
    }
};

uint hash_one( string str, uint size ) {
    long double sum = 0;
    for( uint i = 0; i < str.length(); ++i )
        sum += str[i] * i;

    long double try0 = sum * 0.6180339887;

    try0 = fmod(try0, 1.f) * 32786;
    /*cout << endl;
    cout << try0 << endl;
    cout << try1 << " " << try2 << endl;
    cout << int(try2) << " " << int(try2) % size;*/

    return int(try0) % size;
}

void set( string key, string str, uint size, vector<Node *> v[] ) {
    uint h = hash_one(key, size);

    for( auto it : v[h] )
        if( it->key == key ) {
            it->list.push_back(str);
            return;
        }

    v[h].push_back(new Node (key, str) );
}

void get( string key, uint size, vector<Node *> v[] ){
    uint h = hash_one(key, size);

    for( auto it : v[h] )
        if( it->key == key )
            for( auto result : it->list )
                cout << result << endl;

}

void show( uint size, vector<Node *> v[] ){
    for( uint i = 0; i < size; ++i ){
        for( auto it : v[i] ){
            cout << it->key << ": ";
            for( auto iter : it->list ){
                cout << iter << " ";
            }
        }
        cout << endl;
    }

}


int main(){
    uint kit;
    string str, str1, str2, decision;
    Node *result;

    cin >> kit;
    vector <Node *> band[kit];
    vector <Node *> title[kit];

    for( uint i = 0; i < kit; ++i ) {

        cin >> decision;
        cin.ignore();

        if( decision == "d" ){
            getline(cin, str1);
            getline(cin, str2);

            set(str1, str2, kit, band);
            set(str2, str1, kit, title);
        }

        else if( decision == "w" ){
            getline(cin, str);

            get(str, kit, band);
        }

        else if( decision == "z" ){
            getline(cin, str);

            get(str, kit, title);
        }

        /*show(kit, band);
        cout << endl;
        show(kit, title);
        cout << "=============" << endl;/**/
    }


    return 0;
}

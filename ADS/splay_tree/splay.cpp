#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    string key;
    vector<string> list;
    Node *l_child, *r_child, *parent;

    Node(string key, string str) : key(key){
        list.push_back(str);
        l_child = r_child = parent = NULL;
    }
    Node(string key, string str, Node *parent) : key(key), parent(parent) {
        list.push_back(str);
        l_child = r_child = NULL;
    }
};

struct Splay{
    Node *root = NULL;

    void R_rotate(Node *link){
        Node *tmp = link->l_child;
        link->l_child = tmp->r_child;
        if( tmp->r_child != NULL )  tmp->r_child->parent = link;
        tmp->parent = link->parent;
        if( link->parent == NULL )  root = tmp;
        else if( link == link->parent->r_child )
            link->parent->r_child = tmp;
        else
            link->parent->l_child = tmp;
        tmp->r_child = link;
        link->parent = tmp;
    }
    void L_rotate(Node *link){
        Node *tmp = link->r_child;
        link->r_child = tmp->l_child;
        if( tmp->l_child != NULL )  tmp->l_child->parent = link;
        tmp->parent = link->parent;
        if( link->parent == NULL )  root = tmp;
        else if( link == link->parent->l_child )
            link->parent->l_child = tmp;
        else
            link->parent->r_child = tmp;
        tmp->l_child = link;
        link->parent = tmp;
    }

    void splay(Node *link){
        while( link->parent != NULL ){
            if( link->parent == root ){
                if( link == link->parent->l_child ) R_rotate(link->parent);
                else                                L_rotate(link->parent);
            }
            else{
                Node *nparent = link->parent;
                Node *gparent = nparent->parent;
                if( link->parent->l_child == link && nparent->parent->l_child == nparent ){
                    R_rotate(gparent);
                    R_rotate(nparent);
                }
                else if( link->parent->r_child == link && nparent->parent->r_child == nparent ){
                    L_rotate(gparent);
                    L_rotate(nparent);
                }
                else if( link->parent->r_child == link && nparent->parent->l_child == nparent ){
                    L_rotate(nparent);
                    R_rotate(gparent);
                }
                else{
                    R_rotate(nparent);
                    L_rotate(gparent);
                }
            }
        }
    }


    Node *search(string key){
        Node *tmp = root;
        if( tmp == NULL )   return NULL;

        while( tmp->key != key ){
            if( tmp->key < key && tmp->r_child != NULL )
                tmp = tmp->r_child;
            else if( tmp->key < key && tmp->r_child == NULL )
                break;
            else if( tmp->key > key && tmp->l_child != NULL )
                tmp = tmp->l_child;
            else if( tmp->key > key && tmp->l_child == NULL )
                break;
        }
        splay(tmp);
        return tmp;
    }

    void insert(string key, string str){
        if( root == NULL ){
            root = new Node (key, str);
        }
        else{
            Node *tmp = root;
            while( !( (tmp->key < key && tmp->r_child == NULL) || (tmp->key > key && tmp->l_child == NULL) ) ){
                if( tmp->key < key )
                    tmp = tmp->r_child;
                else if( tmp->key > key )
                    tmp = tmp->l_child;
                else{
                    tmp->list.push_back(str);
                    splay(tmp);
                    return;
                }
            }
            Node *news = new Node (key, str, tmp);
            if( tmp->key < key )    tmp->r_child = news;
            else                    tmp->l_child = news;
            splay(news);
        }
    }
    void inorder(Node *tmp){
        if( tmp->l_child )
            inorder(tmp->l_child);
        cout << tmp->key << ": ";
        for( auto it : tmp->list )
            cout << it << ", ";
        cout << endl;
        if( tmp->r_child )
            inorder(tmp->r_child);
    }
};

int main(){
    int kit;
    string decision;
    Splay title, band;
    string str, str1, str2;

    cin >> kit;
    for(int i = 0; i < kit; ++i){
        cin >> decision;
        cin.ignore();
        
        if( decision == "d" ){
            getline(cin, str1);
            getline(cin, str2);

            band.insert(str1, str2);
            title.insert(str2, str1);
        }
        else if( decision == "w" ){
            getline(cin, str);

            Node *tmp = band.search(str);
            if( tmp != NULL ){
                if( tmp->key == str ){
                    for( auto it : tmp->list )
                        cout << it << endl;
                }
            }
        }
        else if( decision == "z" ){
            getline(cin, str);

            Node *tmp = title.search(str);
            if( tmp != NULL )
                if( tmp->key == str ){
                    for( auto it : tmp->list )
                        cout << it << endl;
                }
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
struct node{
    int value;
    node *parent, *son, *bro;
    node(int v){value = v; parent = bro = son = NULL;}
    void show(){
        if(parent != NULL)
            cout << value << " ";
    }
};
struct tree{
    node *root, *link;
    tree(){root = link = NULL;}
    void newBro(int v){
        node *news = new node(v);
        link->bro = news;
        news->parent = link->parent;
        link = news;
    }
    void newSon(int v){
        node *news = new node(v);
        news->parent = link;
        link->son = news;
        link = news;
    }
};
void preorder(node *st){
    st->show();
    if(st->son != NULL)
        preorder(st->son);
    if(st->bro != NULL)
        preorder(st->bro);
}

int main(){
    ios_base::sync_with_stdio(false);
    tree *t = new tree();
    t->root = new node(0);
    t->link = t->root;
    int num;
    cin >> num;
    int size, buf;
    while(num > 0){
        cin >> size;
        while(size > 0){
            cin >> buf;
            if(t->link->son == NULL)
                t->newSon(buf);
            else{
                if(t->link->son->value == buf)
                    t->link = t->link->son;
                else{
                    t->link = t->link->son;
                    while(t->link->bro != NULL && t->link->value != buf)
                        t->link = t->link->bro;
                    if(t->link->value != buf)
                        t->newBro(buf);
                }
            }
            size--;
        }
        t->link = t->root;
        num--;
    }
    node *st = t->root;
    preorder(st);
    return 0;
}

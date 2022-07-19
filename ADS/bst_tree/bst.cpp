#include <iostream>
#include <set>
using namespace std;

struct Node{
    Node *parent, *l_child, *r_child;
    int key;
    Node(int k){
        key = k;
        parent = l_child = r_child = NULL;
    }
    Node(int k, Node *p){
        key = k;
        parent = p;
        l_child = r_child = NULL;
    }
};

struct BST{
    Node *root = NULL;
    Node *link;
    set <int> s;
    int a, b;
    bool can = true;

    void insert(int key){
        if(root == NULL)
            root = new Node(key);
        else{
            link = root;
            while( !( (link->key < key && link->r_child == NULL) || (link->key >= key && link->l_child == NULL) ) ){
                if( link->key < key )
                    link = link->r_child;
                else
                    link = link->l_child;
            }
            if( link->key < key )   link->r_child = new Node(key, link);
            else                    link->l_child = new Node(key, link);
        }
    }
    Node *min(){
        link = root;
        while(link->l_child != NULL)
            link = link->l_child;
        return link;
    }
    Node *max(){
        link = root;
        while(link->r_child != NULL)
            link = link->r_child;
        return link;
    }
    void _delete(int begin, int end){
        link = max();
        while( link->key > end ){
            if( link == root )
                root = root->l_child;
            if( link->l_child != NULL )
                link->l_child->parent = link->parent;
            if( link->parent != NULL && link->parent->r_child == link )
                link->parent->r_child = link->l_child ? link->l_child : NULL;
            delete link;
            link = max();
        }
        link = min();
        while( link->key < begin ){
            if( link == root )
                root = root->r_child;
            if( link->r_child != NULL )
                link->r_child->parent = link->parent;
            if( link->parent != NULL && link->parent->l_child == link )
                link->parent->l_child = link->r_child ? link->r_child : NULL;
            delete link;
            link = min();
        }
    }
    bool find_pair(Node *v, int sum){
        if(v == NULL)                   return false;
        if(find_pair(v->l_child, sum))  return true;
        if(s.count(sum - v->key) && can){
            if( (sum - v->key) > v->key){
                //cout << v->key << " " << sum - v->key << endl;
                can = false;
                a = v->key;
                b = sum - v->key;
            }
            else{
                //cout << sum - v->key << " " << v->key << endl;
                can = false;
                a = sum - v->key;
                b = v->key;
            }
            //return false;
        }
        else{
            s.insert(v->key);
            if(find_pair(v->r_child, sum))  return true;
        }
        return false;
    }
    void result(){
        if(!can)
            cout << a << " " << b << endl;
        else
            cout << "NIE ZNALEZIONO" << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    BST t;
    int kit, num, beg, en, s;

    cin >> kit;
    for(int i = 0; i < kit; ++i){
        cin >> num;
        t.insert(num);
    }
    cin >> beg >> en;
    t._delete(beg, en);

    cin >> s;
    Node *v = t.root;
    t.find_pair(v, s);

    t.result();
    return 0;
}

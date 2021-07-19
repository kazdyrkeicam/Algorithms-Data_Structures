/*

Partycja spędza ostatnio bardzo dużo czasu na analizowaniu listy potencjalnie zagrażających jej osób. Są wśród nich politycy, ukryci agenci specjalni a nawet pani z pobliskiego warzywniaka. Jak wszyscy wiemy, nasza bohaterka lubi porządek. Właśnie dlatego jej lista jest uszeregowana od osób najniebezpieczniejszych do tych mniej niebezpiecznych. Co ważne, miejsca na liście dynamicznie się zmieniają, np. jeżeli pani Krysia z warzywniaka podejrzanie długo wydaje resztę, to po chwili Partycja musi przepisywać listę przenosząc ją o kilka miejsc w górę. Oczywiście czasami wykonuje również inne operacje, takie jak zamiana osób miejscami czy dopisanie nowej. Nasza bohaterka obawia się jednak, że jej notes może wpaść w niepowołane ręce. Właśnie dlatego nadała wszystkim osobom unikalne pseudonimy. Jak można się domyślić prowadzenie takiego notatnika jest bardzo trudne i pracochłonne. Partycja chciałaby mieć program, który pomoże jej z tym zadaniem.

Wejście:
W pierwszej linii wejścia program otrzymuje liczbę n oznaczającą początkową liczbę osób na liście. Następnie w n liniach program otrzymuje ciągi znaków s będących pseudonimami osób. Zakładamy, że pierwsza osoba na liście najbardziej zagraża Partycji. W kolejnym kroku program otrzymuje liczbę m będącą ilością operacji do wykonania. Na koniec w m liniach program otrzymuje opisy operacji. Pierwszy znak zawsze oznacza akcję do wykonania, a po nim pojawiają się stosowne dane zgodnie z poniższym opisem:

a s – dodanie osoby o pseudonimie s na koniec listy, gdzie s jest ciągiem znaków
m s x – przesunięcie osoby o pseudonimie s na liście o x miejsc, gdzie s jest ciągiem znaków, a x liczbą całkowitą (jeżeli x jest dodatnie to przesuwamy osobę w górę listy, w przeciwnym wypadku w dół)
r s1 s2 – zamiana miejscami osoby o pseudonimie s1 z osobą o pseudonimie s2, gdzie s1 i s2 są ciągiem znaków
Wyjście:
Na wyjściu program powinien wypisać listę pseudonimów poczynając od osoby najniebezpieczniejszej.

1 < n ≤ 50000

1 < m ≤ 10000

Przykładowe wejście:
5
Okruszek
Tester
Interfejs
Agent
Scyzoryk
4
r Okruszek Interfejs
a Kontakt
m Kontakt 2
m Interfejs -1
Przykładowe wyjście:
Tester
Interfejs
Okruszek
Kontakt
Agent
Scyzoryk
Uwaga:
Zadanie ma zostać rozwiązane przy pomocy samodzielnie zaimplementowanych drzew czerwono-czarnych bez wykorzystania bibliotek STL.

*/

#include <iostream>
using namespace std;
#define RED 0
#define BLACK 1
struct Node_list{
    string data;
    Node_list *next, *prev;
    Node_list(string data) : data(data){
        next = prev = NULL;
    }
};
struct List{
    Node_list *head = NULL,
         *tail = NULL;
    int size = 0;
    Node_list* add(string d){
        Node_list *news = new Node_list (d);
        if( head == NULL ){
            head = news;
            news->next = news->prev = NULL;
            tail = head;
        }
        else{
            tail->next = news;
            news->prev = tail;
            tail = news;
        }
        size++;
        return news;
    }
    void print(){
        Node_list *link = head;
        while( link != NULL ){
            cout << link->data << endl;
            link = link->next;
        }
    }
    void swap(Node_list *a, Node_list *b){
        if( (a == head && b == tail) || (a == tail && b == head) ){ //a jest H b jest T lub odwrotnie
            if( a == head ){                                        //a jest H
                b->prev->next = a;  a->next->prev = b;
                tail = a;           head = b;
                b->next = a->next;  a->prev = b->prev;
                a->next = NULL;     b->prev = NULL;
            }
            else if( b == head ){                                   //b jest H
                a->prev->next = b;  b->next->prev = a;
                tail = b;           head = a;
                a->next = b->next;  b->prev = a->prev;
                a->prev = NULL;     b->next = NULL;
            }
            return;
        }

        if( (a != head && b != head) && (a != tail && b != tail) ){                                                       //zarowno a i b nie sa H i T
            if( a->next == b ){                                     //a jest sasiadem b
                a->prev->next = b;  b->next->prev = a;
                a->next = b->next;  b->prev = a->prev;
                b->next = a;        a->prev = b;
            }
            else if( b->next == a ){                                //b jest sasiadem a
                b->prev->next = a;  a->next->prev = b;
                b->next = a->next;  a->prev = b->prev;
                a->next = b;        b->prev = a;
            }
            else{                                                   //nie sa sasiadami
                a->prev->next = a->next;    b->prev->next = b->next;
                a->next->prev = a->prev;    b->next->prev = b->prev;
                b->next = a->next;          a->next = b->prev->next;
                b->prev = a->prev;          a->prev = a->next->prev;
                b->prev->next = b;          b->next->prev = b;
                a->prev->next = a;          a->next->prev = a;
            }
            return;
        }

        if( a == head ){                                            //a jest H
            if( a->next == b ){                                     //a jest sasiadem b
                head = b;
                b->prev = NULL;     a->prev = b;
                a->next = b->next;  b->next = a;
                a->next->prev = a;
            }
            else{                                                   //a nie jest sasiadem b
                head = a->next;     head->prev = b;
                a->next = b->next;  a->next->prev = a;
                a->prev = b->prev;  a->prev->next = a;
                b->prev = NULL;     b->next = head;
                head = b;
            }
            return;
        }

        else if( a == tail ){                                       //a jest T
            if( a->prev == b ){                                     //b jest sasiadem a
                tail = b;
                b->next = NULL;     a->next = b;
                a->prev = b->prev;  b->prev = a;
                a->prev->next = a;
            }
            else{                                                   //b nie jest sasiadem a
                tail = a->prev;     tail->next = b;
                a->prev = b->prev;  a->prev->next = a;
                a->next = b->next;  a->next->prev = a;
                b->next = NULL;     b->prev = tail;
                tail = b;
            }
            return;
        }

        if( b == head ){                                            //b jest H
            if( b->next == a ){                                     //b jest sasiadem a
                head = a;
                a->prev = NULL;     b->prev = a;
                b->next = a->next;  a->next = b;
                b->next->prev = b;
            }
            else{                                                   //b nie jest sasiadem a
                head = b->next;     head->prev = a;
                b->next = a->next;  b->next->prev = b;
                b->prev = a->prev;  b->prev->next = b;
                a->prev = NULL;     a->next = head;
                head = a;
            }
            return;
        }

        else if( b == tail ){                                       //b jest T
            if( b->prev == a ){                                     //a jest sasiadem b
                tail = a;
                a->next = NULL;     b->next = a;
                b->prev = a->prev;  a->prev = b;
                b->prev->next = b;
            }
            else{                                                   //a nie jest sasiadem b
                tail = b->prev;     tail->next = a;
                b->prev = a->prev;  b->prev->next = b;
                b->next = a->next;  b->next->prev = b;
                a->next = NULL;     a->prev = tail;
                tail = a;
            }
        }
    }
    void move(Node_list *a, int shift){
        Node_list *link = a;

        while( shift > 0 ){                     //idziemy w gore
            link = link->prev;
            shift--;
            if( shift == 0 ){
                if( a == tail ){                //a jest T
                    if( link == head ){         //link jest T
                        tail = tail->prev;  tail->next = NULL;
                        a->next = head;     head->prev = a;
                        head = a;
                    }
                    else if( link->next == a ){ //link sasiaduje z a
                        a->next = link;         link->prev->next = a;
                        a->prev = link->prev;   link->prev = a;
                        tail = link;            link->next = NULL;
                    }
                    else{                       //link nie sasiaduje z a i nie jest H
                        tail = tail->prev;  tail->next = NULL;
                        a->next = link;     a->prev = link->prev;
                        a->prev->next = a;  link->prev = a;
                    }
                    return;
                }
                if( a->prev == link ){          //a sasiaduje z link
                    if( link == head ){
                        link->next = a->next;   a->next = link;
                        a->prev = NULL;         link->prev = a;
                        head = a;
                    }
                    else{
                        a->next->prev = link;   link->prev->next = a;
                        link->next = a->next;   a->prev = link->prev;
                        a->next = link;         link->prev = a;
                    }
                }
                else{                           //a nie sasiaduje z link
                    a->next->prev = a->prev;    a->prev->next = a->next;
                    link->prev->next = a;       a->next = link;
                    a->prev = link->prev;       link->prev = a;
                }
            }
        }
        while( shift < 0 ){
            link = link->next;
            shift++;
            if( shift == 0 ){
                if( a == head ){
                    if( link == tail ){
                        tail = a;       link->next = a;
                        head = a->next; a->next = NULL;
                        a->prev = link;
                    }
                    else if( a->next == link ){
                        head = link;            link->next->prev = a;
                        a->next = link->next;   link->prev = NULL;
                        a->prev = link;         link->next = a;
                    }
                    else{
                        head = a->next;         a->next->prev = NULL;
                        a->next = link->next;   a->prev = link;
                        a->next->prev = a;      link->next = a;
                    }
                    return;
                }
                if( a->next == link ){
                    if( link == tail ){
                        link->prev = a->prev;   a->prev->next = link;
                        link->next = a;         a->next = NULL;
                        a->prev = link;         tail = a;
                    }
                    else{
                        link->next->prev = a;   link->prev = a->prev;
                        a->prev->next = link;   a->prev = link;
                        a->next = link->next;   link->next = a;
                    }
                    return;
                }
                else{
                    a->next->prev = a->prev;    a->prev->next = a->next;
                    a->next = link->next;       a->prev = link;
                    a->next->prev = a;          link->next = a;
                }
            }
        }
    }
};
struct Node{
    string key;
    bool color;
    Node *l_child, *r_child, *parent;
    Node_list *pointer;

    Node(string key, Node_list *p) : key(key){
        l_child = r_child = parent = NULL;
        color = RED;
        pointer = p;
    }
//sprawdza czy this jest lewym synem ojca
    bool is_on_left(){ return this == parent->l_child; }
//wskaznik na wuja
    Node *uncle(){
        if( parent == NULL || parent->parent == NULL )
            return NULL;
        if( parent->is_on_left() )
            return parent->parent->r_child;
        else
            return parent->parent->l_child;
    }
//this na dol, a new_parent w jego miejsce
    void move_down(Node *new_parent){
        if( parent != NULL ){
            if( is_on_left() )
                parent->l_child = new_parent;
            else
                parent->r_child = new_parent;
        }
        new_parent->parent = parent;
        parent = new_parent;
    }
};

struct RBT{
    Node *root = NULL;
    Node* search(string key){
        Node *link = root;
        while(link != NULL){
            if( key < link->key ){
                if( link->l_child != NULL )
                    link = link->l_child;
                else    break;
            }
            else if( key > link->key ){
                if( link->r_child != NULL )
                    link = link->r_child;
                else    break;
            }
            else
                break;
        }
        return link;
    }

    void swap_color(Node *a, Node *b){
        bool tmp = a->color;
        a->color = b->color;
        b->color = tmp;
    }

    void left_rotate(Node *link){
        Node *new_parent = link->r_child;
        if( link == root )
            root = new_parent;
        link->move_down(new_parent);
        link->r_child = new_parent->l_child;

        if( new_parent->l_child != NULL )
            new_parent->l_child->parent = link;
        new_parent->l_child = link;
    }
    void right_rotate(Node *link){
        Node *new_parent = link->l_child;
        if( link == root )
            root = new_parent;
        link->move_down(new_parent);
        link->l_child = new_parent->r_child;

        if( new_parent->r_child != NULL )
            new_parent->r_child->parent = link;
        new_parent->r_child = link;
    }

//poprawia red->red
    void fix_red_red(Node *x){
        if(x == root){
            x->color = BLACK;
            return;
        }

        Node *parent = x->parent,
             *grandparent = parent->parent,
             *uncle = x->uncle();

        if( parent->color != BLACK ){
            if( uncle != NULL && uncle->color == RED ){
                parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;
                fix_red_red(grandparent);
            }
            else{
                if( parent->is_on_left() ){
                    if( x->is_on_left() )
                        swap_color(parent, grandparent);
                    else{
                        left_rotate(parent);
                        swap_color(x, grandparent);
                    }
                    right_rotate(grandparent);
                }
                else{
                    if( x->is_on_left() ){
                        right_rotate(parent);
                        swap_color(x, grandparent);
                    }
                    else
                        swap_color(parent, grandparent);
                    left_rotate(grandparent);
                }
            }
        }
    }

    void insert(string key, Node_list *node){
        Node *news = new Node(key, node);
        if(root == NULL){
            news->color = BLACK;
            root = news;
        }
        else{
            Node *link = search(key);
            news->parent = link;
            if( key < link->key )
                link->l_child = news;
            else
                link->r_child = news;
            fix_red_red(news);
        }
    }
};

void decide_a(RBT &t, List &l){
    string str;
    cin >> str;
    t.insert(str, l.add(str));
}
void decide_m(RBT &t, List &l){
    string str;
    int shift;
    Node *x;
    cin >> str >> shift;
    x = t.search(str);

    l.move(x->pointer, shift);
}
void decide_r(RBT &t, List &l){
    string str1, str2;
    Node *temp1, *temp2;
    cin >> str1 >> str2;

    temp1 = t.search(str1);
    temp2 = t.search(str2);

    l.swap(temp1->pointer, temp2->pointer);
}

int main()
{
    List l;
    RBT t;
    int list_size, operation;
    string str;
    char decision;

    cin >> list_size;

    for(int i = 0; i < list_size; ++i){
        cin >> str;
        t.insert(str, l.add(str));
    }

    cin >> operation;
    for(int i = 0; i < operation; ++i){
        cin >> decision;
        if( decision == 'a')
            decide_a(t, l);
        else if( decision == 'm' )
            decide_m(t, l);
        else if( decision == 'r' )
            decide_r(t, l);

        /*cout << endl << "===============================" << endl;
        l.print();/**/
    }

    l.print();

    return 0;
}

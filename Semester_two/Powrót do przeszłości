/*

Wracając do zmagań naszej bohaterki z października 2019 roku, wiemy o dużych zawirowaniach i nielogicznych decyzjach w światowej polityce. Te nielogiczne decyzje i nierozwiązane tropy męczą naszą bohaterkę do dzisiaj.

Przez okres tych paru miesięcy Partycja sporo przemyślała i chce dalej kontynuować swoje zmagania z odkryciem źródła tych decyzji. Tym razem ma inny pomysł na połączenie poszlak i tropów. Wszystkie tropy zostały opatrzone pewną wartością. Wartość, jaką Partycja opisała każdą z poszlak to wpływ poglądów politycznych. Gdy wartość jest większa poglądy są bardziej prawicowe. Należy dodać, że kolejność pojawiających się tropów ma ogromne znaczenie. Wynika to z tego, że poprzednie wydarzenia mają wpływ na to, jak postrzegane politycznie są kolejne tropy.

Pani doktor z politologii w oparciu o swoje poprzednie badania twierdzi, że prawidłowe tropy należą do relatywnie wąskiej grupy wszystkich poszlak. Jest nawet w stanie w prosty sposób odrzucić przesłanki, które do tej wąskiej grupy nie należą. Doświadczenia naszej bohaterki mówią, że tylko w obrębie pewnych wpływów poglądów politycznych znajduje się poprawny trop, zaś skrajne tropy może pominąć w swoich rozważaniach.

Dotychczas Partycja była przekonana, że tylko jeden trop może być tym prawidłowym, jednak zmieniła zdanie. Twierdzi, że w całym tym zamieszaniu źródło nielogicznych decyzji wynika z dwóch poszlak. Niestety zna jedynie sumę politycznych wpływów obu tych przesłanek, ponieważ ich konsekwencją jest aktualny stanu rzeczy. Trzeba pamiętać, że wartość wpływu poglądów politycznych na dzisiejsze wydarzenia jest jedynie estymowany. W związku z tym nasza dociekliwa Pani detektyw może nie znaleźć pary tropów, które wskazywałyby na przyczynę współczesnych faktów.

Niestety tylko jedna para tropów jest poprawna i doprowadzi naszą bohaterkę do rozwiązania tej zagadki. Partycja wie, że wybór odpowiedniej pary tropów zależny jest od chronologicznej kolejności ich poznawania. Dodatkowo zauważyła, że aby odnaleźć odpowiednią parę dwóch poszlak będących źródłem nielogicznych decyzji, należy znaleźć taką parę tropów, których różnica wpływów politycznych jest najmniejsza.

WEJŚCIE
W pierwszej linii wejścia znajduje się liczba naturalna n, która jest ilością tropów. Następnie program powinien odczytać n wartości wpływów politycznych dla chronologicznie przedstawionych tropów. W kolejnym kroku program powinien odczytać dwie wartości a i b, które są granicami domkniętego przedziału wartości wpływów politycznych dla przesłanek, które warto rozważać. Na koniec program powinien odczytać estymowaną wartość k , która jest wpływem poglądów politycznych na dzisiejsze wydarzenia.

0 <= n, k, a, b, wartości wpływów politycznych dla tropów <= 2000000000

WYJŚCIE
Na wyjściu program powinien wypisać parę wartości wpływów poglądów politycznych tropów, które spełniałyby wartość k lub “NIE ZNALEZIONO” w przeciwnym wypadku. Wartości pary powinny być wypisane w kolejności niemalejącej.

PRZYKŁADOWE DANE WEJŚCIOWE
7                                                                               
15 10 20 8 12 16 25                                                             
9 16                                                                            
25 
PRZYKŁADOWE DANE WYJŚCIOWE
10 15
UWAGI
W rozwiązaniu zadania powinna pojawić się implementacja drzew BST, precyzując powinny pojawić się operacje tj. dodawanie nowych węzłów, przycinanie drzewa BST do określonego przedziału oraz wyszukiwanie pary liczb spełniających podaną sumę.

*/

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

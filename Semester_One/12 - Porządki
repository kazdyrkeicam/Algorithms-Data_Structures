/*

Sylwestra Partycja spędziła w domu. Nie miała ochoty iść tego dnia na jakąkolwiek imprezę. No bo czego miałby życzyć innym o północy? Szczęśliwych ostatnich dziewięciu miesięcy ludzkiej cywilizacji? Nie, Partycja zdecydowanie nie miała na to ochoty. Postanowiła posegregować zebrane do tej pory akta prowadzonego przez nią śledztwa.

Wszystkie dokumenty zebrane przez Partycję mają swoj unikalne numery (od 1 do n, gdzie n jest liczbą dokumentów), priorytety (liczba całkowita z zakresu od 0 do 10), losowe kody z zakresu od 0 do 10000000 (niekoniecznie unikalne) oraz zostały oznaczone symbolami tematyki dokumentu (maksymalnie 4 liczby z zakresu od 0 do 255 uporządkowane od symbolu najbardziej istotnego do najmniej istotnego, czasami przez pomyłkę ten sam symbol może wystąpić wielokrotnie, ale Partycji nie chce się tego poprawiać). Partycja chce móc sortować dokumenty:

rosnąco po numerach,
rosnąco po priorytetach,
rosnąco po kodach,
leksykograficznie względem listy kodów tematów (w pierwszej kolejności porównuje symbole najbardziej istotne na poszczególnych listach, potem drugie itd., jeżeli jakiś ciąg symboli jest początowym podciągiem innego, to jest wcześniej w kolejności lekykograficznej)
Partycja, chciałaby móc sortować po wszystkich wyżej wymienionych parametrach, ale przy różnym uszeregowaniu ważności poszczególnych prametrów (na przykład w pierwszej kolejności po priotytetach, w drugiej po kodach itd.).

Wejście
Na wejściu program otrzymuje liczbę n, a następnie n opisów dokumentów. Opis każdego z dokumentów składa się z unikalnego numeru, priorytetu, losowego kodu, liczby m kodów tematów dotyczących danego dokumentu (z zakresu od 1 do 4) a następnie m liczb z zakreso do 0 do 255. Na końcu program otrzyma liczby 1, 2, 3 i 4 odpowiadające kolejno numerom, priorytetom, kodom dokumentów oraz kodom tematów uporządkowane względem ich wagi przy sortowaniu.

1<=n<=2000000
Wyjście
Na standardowym wyjściu program powinien wypisać sumę losowych kodów poszczególnych dokumentow pomnożonych przez finalny indeks elementu w posortowanej tablicy. Wynik powinien zostać wypisany modulo 100000007.

Przykłady

Wejście
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24
4 2 3 1

Wyjście
203508

Wejście
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24 
4 3 2 1

Wyjście
204625

Wejście
1
1 10 0 2 0 1
1 2 3 4

Wyjście
0

UWAGA rozwiąż problem przy pomocy samodzielnie zaimplementowanych algorytmów sortujących w czasie liniowym.

*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 100000007
#define FIN 10000000
#define PRO 11
#define DOC 257

using namespace std;

typedef unsigned long long ull;

struct Document{
    int unique_num, priority;
    ull random_code;
    int doc[4] = {-1, -1, -1, -1};

    void add(int a, int b, ull c, int d){
        unique_num = a; priority = b; random_code = c;
        int x;

        for(int i = 0; i < d; ++i){
            cin >> x;
            doc[i] = x;
        }
    }
};


bool compare(const Document & a, const Document & b){
    return a.random_code < b.random_code;
}

void id_sort(Document *arr, int n){
    Document *tmp = new Document [n];

    for(int i = 0; i < n; ++i)
        tmp[arr[i].unique_num - 1] = arr[i];

    for(int i = 0; i < n; ++i)
        arr[i] = tmp[i];

    delete [] tmp;
}

void priority_sort(Document *arr, int n){
    vector<Document> tmp[PRO];

    for(int i = 0; i < n; ++i)
        tmp[arr[i].priority].push_back(arr[i]);

    vector<Document>::iterator it;
    int j = 0;
    for(int i = 0; i < PRO; ++i)
        for(it = tmp[i].begin(); it != tmp[i].end(); ++it)
            arr[j++] = *it;
}

void random_sort(Document *arr, int n){
    vector<Document> tmp[n];
    vector<Document>::iterator it;
    int index;

    for(int i = 0; i < n; ++i){
        index = (n * arr[i].random_code) / FIN;
        tmp[index].push_back(arr[i]);
    }

    index = 0;
    for(int i = 0; i < n; ++i){
        sort(tmp[i].begin(), tmp[i].end(), compare);
        for(it = tmp[i].begin(); it != tmp[i].end(); ++it)
            arr[index++] = *it;
    }
}

void doc_sort(Document *arr, int n){
    //vector<Document>::iterator it;
    int count[DOC], doc_ind = 3;
    Document result[n];

    //cout << "TU" << endl;
    while(doc_ind >= 0){
        //vector<Document> tmp[DOC];
        //cout << "DEK" << endl;
        for(int i = 0; i < DOC; ++i)
            count[i] = 0;
        //cout << "DEK2" << endl;
        for(int i = 0; i < n; ++i)
            count[arr[i].doc[doc_ind] + 1]++;
        //cout << "DEK3" << endl;
        --count[0];
        for(int i = 1; i < DOC; ++i)
            count[i] += count[i - 1];
        //cout << "DEK4" << endl;
        for(int i = n - 1; i >= 0; i--){
            result[count[arr[i].doc[doc_ind] + 1]] = arr[i];
            --count[arr[i].doc[doc_ind] + 1];
        }
        //cout << "DEK5" << endl;
        for(int i = 0; i < n; ++i)
            arr[i] = result[i];
        //cout << "DEK6" << endl;
        --doc_ind;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int size, a, b, d;
    ull c, result = 0;
    Document *arr;

    cin >> size;
    arr = new Document [size];

    for(int i = 0; i < size; ++i){
        cin >> a >> b >> c >> d;
        arr[i].add(a, b, c, d);
    }

    int pls[4];
    int i = 3;
    while(i >= 0){
        cin >> a;
        pls[i--] = a;
    }

    for(i = 0; i < 4; ++i){
        switch(pls[i]){
        case 1:
            id_sort(arr, size);
            break;
        case 2:
            priority_sort(arr, size);
            break;
        case 3:
            random_sort(arr, size);
            break;
        case 4:
            doc_sort(arr, size);
            break;
        default:
            break;
        }
    }

    for(i = 0; i < size; ++i){
        result += i * arr[i].random_code;
        result %= MOD;
    }

    cout << result % MOD << endl;

    delete [] arr;
    return 0;
}

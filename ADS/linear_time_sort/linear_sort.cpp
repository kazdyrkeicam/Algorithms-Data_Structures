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
    int count[DOC], doc_ind = 3;
    Document result[n];

    while(doc_ind >= 0){
        for(int i = 0; i < DOC; ++i)
            count[i] = 0;

        for(int i = 0; i < n; ++i)
            count[arr[i].doc[doc_ind] + 1]++;

        --count[0];
        for(int i = 1; i < DOC; ++i)
            count[i] += count[i - 1];

        for(int i = n - 1; i >= 0; i--){
            result[count[arr[i].doc[doc_ind] + 1]] = arr[i];
            --count[arr[i].doc[doc_ind] + 1];
        }

        for(int i = 0; i < n; ++i)
            arr[i] = result[i];

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

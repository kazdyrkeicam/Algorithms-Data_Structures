/*

Napisz program, który sortuje otrzymaną w argumencie listę liczb całkowitych losowanych z podanego zakresu z jednostajnym rozkładem prawdopodobieństwa.

Wejście
Program na wejściu dostaje liczbę n elementów listy oraz liczby p i k początek i koniec przedziału do którego należą elementy listy a następnie n losowych liczb całkowitych z zakresu od p do k.

0 < n<=1000000
-2000000<=p<=k<=2000000
Wyjście
Na standardowym wyjściu program powinien wypisać posortowane rosnąco elementy przetwarzanej listy.

Przykłady
Wejście
6 -10 10
-9
0
3
10
-10
5
Wyjście
-10 -9 0 3 5 10
Uwaga
Magiczna linijka: ios_base::sync_with_stdio(false);

Program musi być próbą rozwiązania przedstawionego problemu. Programy, które będą próbowały zgadnąć rozwiązanie bez rozwiązania problemu (np. zgadując wynik) będą dyskwalifikowane. W rozwiązaniu tego zadania nie można używać STL-a.

*/

#include <iostream>
using namespace std;

int absolute(int a){
    return -a;
}

int main()
{
    int size, begin, end, *arr, *count, amount, *result;
    //temponaries
    int i, a;
    bool sign = false;

    cin >> size;
    arr = new int [size];
    result = new int [size];

    cin >> begin >> end;

    if(begin < 0 && end > 0)
        sign = true;

    amount = absolute(begin) + end + sign;
    count = new int [amount + 1];

    for(i = 0; i < amount; ++i)
        count[i] = 0;

    for(i = 0; i < size; ++i){
        cin >> a;
        arr[i] = a;
    }/**/

    /*cout << amount << endl;
    for(i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;/**/

    for(i = 0; i < size; ++i){
        if(begin < 0)
            count[arr[i] + (-begin)]++;
        else
            count[arr[i] - begin]++;
    }/**/

    count[0]--;
    if(begin < 0)
        for(i = 1; i < amount; ++i)
            count[i] += count[i - 1];
    else
        for(i = 1; i <= amount; ++i)
            count[i] += count[i - 1];


    /*for(i = 0; i < amount; ++i)
        cout << i << " ";
    cout << endl;
    for(i = 0; i < amount; ++i)
        cout << count[i] << " ";
    cout << endl;/**/

    for(i = 0; i < size; ++i){
        if(begin < 0){
            result[count[arr[i] + (-begin)]] = arr[i];
            count[arr[i] + (-begin)]--;
        }
        else{
            result[count[arr[i] - begin]] = arr[i];
            count[arr[i] - begin]--;
        }
    }

    for(i = 0; i < size; ++i)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

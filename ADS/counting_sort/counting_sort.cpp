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
    }

    for(i = 0; i < size; ++i){
        if(begin < 0)
            count[arr[i] + (-begin)]++;
        else
            count[arr[i] - begin]++;
    }

    count[0]--;
    if(begin < 0)
        for(i = 1; i < amount; ++i)
            count[i] += count[i - 1];
    else
        for(i = 1; i <= amount; ++i)
            count[i] += count[i - 1];

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

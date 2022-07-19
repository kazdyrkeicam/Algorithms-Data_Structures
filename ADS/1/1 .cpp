#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int zestaw;
    int tropy, metody;
    int bilans = 0;
    int max = 0;
    int x, y;
    cin >> zestaw;
    while(zestaw > 0){
        cin >> tropy >> metody;
        while(metody > 0){
            cin >> x >> y;
            if(bilans < x - y)
                bilans = x - y;
            if(max < x)
                max = x;
            metody--;
        }
        if(bilans <= 0 && tropy > max)
            cout << "BRAK METOD" << endl;
        else if(tropy <= max)
            cout << 1 << endl;
        else if((tropy - max) % bilans != 0)
            cout << (tropy - max) / bilans + 2 << endl;
        else if((tropy - max) % bilans == 0)
            cout << (tropy - max) / bilans + 1 << endl;
        zestaw--;
        bilans = max = 0;
    }
    return 0;
}

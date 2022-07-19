#include <iostream>
using namespace std;

struct Osoba{
    string nazwisko;
    int minuty;
};

void sort(Osoba *os, int rozmiar);
void show(Osoba *os, int rozmiar);

int main(){
    ios_base::sync_with_stdio(false);
    int zestaw, planDnia;
    int liczbaOsob;
    unsigned long long int wynik = 0;
    cin >> zestaw;
    while(zestaw > 0){
        cin >> liczbaOsob >> planDnia;
        Osoba gosc[liczbaOsob];
        for(int i = 0; i < liczbaOsob; ++i)
            cin >> gosc[i].nazwisko >> gosc[i].minuty;
        sort(gosc, liczbaOsob);
        show(gosc, planDnia);
        for(int i = 0; i < liczbaOsob; ++i){
            wynik += (gosc[i].minuty * i) + 1;
        }
        cout << wynik % (1000003) <<  endl;
        wynik = 0;
        zestaw--;
    }
    return 0;
}

void sort(Osoba *os, int rozmiar){
    Osoba current;
    int index;
    for(int i = 1; i < rozmiar; ++i){
        current = os[i];
        index = i;
        while((index > 0 && current.minuty > os[index - 1].minuty) ||
              (current.minuty == os[index - 1].minuty && current.nazwisko < os[index - 1].nazwisko)){
            os[index] = os[index - 1];
            index--;
        }
        os[index] = current;
    }
}

void show(Osoba *os, int rozmiar){
    for(int i = 0; i < rozmiar; ++i)
        cout << os[i].nazwisko << " ";
    cout << endl;
}

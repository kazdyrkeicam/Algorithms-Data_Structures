#include <iostream>
#include <vector>
using namespace std;
struct Passenger{
    int getIN, getOFF;
};
void quicksort(Passenger *tablica, int lewy, int prawy);
int main(){
    ios_base::sync_with_stdio(false);
    int kit, passengers;
    int statiON, statiOFF;



    cin >> kit;
    while(kit > 0){
        cin >> passengers;
        int lastCheck = 0;
        int coverCounter = 0;
        Passenger passenger[passengers];
        for(int i = 0; i < passengers; ++i){
            cin >> statiON >> statiOFF;
            passenger[i].getIN = statiON;
            passenger[i].getOFF = statiOFF;
        }
        quicksort(passenger, 0, passengers - 1);
        for(int i = 0; i < passengers; ++i)
            if(lastCheck <= passenger[i].getIN){
                //cout << lastCheck << " " << passenger[i].getOFF << endl;
                coverCounter++;
                lastCheck = passenger[i].getOFF;
            }
        cout << coverCounter << endl;
        kit--;
    }
    return 0;
}


void quicksort(Passenger *tablica, int lewy, int prawy)
{
    int v = tablica[(lewy+prawy)/2].getOFF;
    int i, j;
    Passenger x;
    i = lewy;
    j = prawy;
    do
    {
        while(tablica[i].getOFF < v) i++;
        while(tablica[j].getOFF > v) j--;
        if(i<=j)
        {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j > lewy) quicksort(tablica,lewy, j);
    if(i < prawy) quicksort(tablica, i, prawy);
}

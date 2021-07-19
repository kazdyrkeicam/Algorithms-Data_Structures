/*

Partycja odkryła straszną prawdę.
Światem od wieków rządzą tajne organizacje.
Nasza bohaterka uwielbia demaskować ich tajemnice.
Podobno na odwrocie deklaracji podległości spisanej przez samych ojców stworzycieli jest zapisany szyfr.
Dotarcie do niego zajęło naszej bohaterce nieco czasu.
Wykorzystując znajomości udało się jej otrzymać tajną fotografię dokumentu od konserwatorki.
Oczom Partycji ukazał się jednak dziwny zestaw słów oraz cyfr.
Postanowiła, że ze swoim problemem uda się do znanego historyka specjalizującego się w starych szyfrach.
Specjalista przyjrzał się dokumentowi i rzekł:

- Widziałem już kiedyś taki szyfr.
Używały go tajne organizacje wiele lat temu.
Jak widzisz mamy dwa zestawy słów.
Pierwszy składa się z par zbudowanych z jednego słowa oraz liczby.
Dla ułatwienia liczbę z pary będziemy nazywać wartością słowa.
Poruszamy się po liście słów przechodząc od jednego do następnego, dodając je do zdania wynikowego.
Wartość w parze oznacza o ile słów od obecnego należy się przesunąć.
Jeżeli jest ona dodatnia poruszamy się zgodnie z kierunkiem wprowadzania.
Gdyby jednak wartość była ujemna poruszamy się w kierunku przeciwnym.
Jeżeli dotrzesz do końca listy przeglądanie rozpoczynasz z drugiej strony.
Pamiętaj jednak, że każde słowo może być użyte tylko raz.
Przeglądanie powinno zostać rozpoczęte od ustalonego numerem słowa.

- Więc do czego jest ta druga lista słów?

- Jeżeli podczas przeglądania pierwszej listy trafisz na słowo którego wartość jest równa 0 to zamiast dodawać ją do wynikowego zdania należy dodać nowe słowo do listy jako poprzednik obecnie znalezionego zgodnie z kierunkiem wprowadzania.
Pobiera się je właśnie z tej drugiej listy.
Ponieważ nie zostało jeszcze wykorzystane nie powinno być usuwane.
Musisz pamiętać, żeby zmodyfikować wartość znalezionego słowa.
Jak widzisz lista słów oczekujących na dodanie oprócz pary ma dodatkową liczbę.
To wartość która zastąpi znalezione 0.
Na koniec wyszukujesz nowe słowo przemieszczając się właśnie o tą zmodyfikowaną wartość.
Możesz być pewna, że ilość słów dodatkowych zawsze jest wystarczająca.
Ba, zwykle jest ich nawet za dużo.
Wyszukiwanie kończy się kiedy skończą się elementy w pierwszej liście.

Partycja miała już plan.
Zostało zatem tylko odczytać szyfr …

## Wejście:
Na wejściu program otrzymuje liczbę n oznaczającą rozmiar listy słów oraz s będącą numerem słowa startowego.
Następnie w n liniach program otrzymuje parę składającą się z pojedynczego słowa s oraz liczby x.
W kolejnym kroku podawana jest liczba p, która określa ilość słów oczekuje na dodanie.
Następnie w p liniach program otrzymuję listę oczekujących par s oraz x oraz y, gdzie ostatnia wartość jest liczbą zastępującą 0 które spowodowało dodanie nowego elementu.

## Wyjście:
Na wyjściu program powinien wypisać odtworzone zdanie.
Działanie kończy się kiedy cała lista zostanie opróżniona.

1 ≤ n ≤ 30000
0 ≤ p ≤ 30000
-1000000 ≤ x, d ≤ 1000000

Przykładowe wejście:
7 5
spadaniem 5
czestym 0
kamien 7
drazy -2
sila 2
Kropla -2
nie -1
3
lecz 1 -5
tak 8 2
syzbko -9 6

Przykładowe wyjście:
Kropla drazy kamien nie sila lecz czestym spadaniem

Uwaga:
Rozwiązanie ma być samodzielną implementacją list bez wykorzystania bibliotek STL.

*/

#include <iostream>
using namespace std;
class Element{
public:
    string slowo;
    int liczba;
    Element* next;
    Element* prev;
    Element(){next = prev = this;}
};
class Lista{
public:
    Element* link;
    Lista(){link = NULL;}
    int size = 0;

    int redukcja(int num){
            if(num > 0){
                num = num % size;
                if(((num > size / 2) || (num < (size / 2) * -1)))
                    return num - size;
                else
                    return num;
            }
            else if(num < 0){
                num = num % ((-1) * size);
                if(((num > size / 2) || (num < (size / 2) * -1)))
                    return num + size;
                else
                    return num;
            }
            else
                return num;
    }
    int zapamietaj(){
        return link->liczba;
    }
    void wynik(){
        cout << link->slowo << " ";
    }
    void zero(string s, int l, int num){
        link->liczba = num;
        dodajPrzed(s, l);
    }
    void ruch(int oIle){
        if(oIle > 0)
            while(oIle > 0){
                link = link->next;
                oIle--;
            }
        else if(oIle < 0)
            while(oIle < 0){
                link = link->prev;
                oIle++;
            }
    }
    void dodajPrzed(string s, int l){
        Element* nowy = new Element();
        nowy->slowo = s;
        nowy->liczba = l;
        if(size == 0) link = nowy;
        else{
            Element* pop = link->prev;
            link->prev = nowy;
            nowy->next = link;
            nowy->prev = pop;
            pop->next = nowy;
            if(size == 1)   link->next = nowy;
        }
        size++;
    }
    void dodajZa(string s, int l){      //DODAJESZ MIEDZY LINK A NEXT !!!ZAWSZE!!!
        Element* nowy = new Element();
        nowy->slowo = s;
        nowy->liczba = l;
        if(size == 0) link = nowy;
        else{
            Element* nast = link->next;
            link->next = nowy;
            nowy->next = nast;
            nowy->prev = link;
            nast->prev = nowy;
            if(size == 1)   nowy->next = link;
        }
        size++;
    }
    bool usunLP(){    //LINK WCHODZI NA POPRZEDNI!
        if(size == 0)   return false;
        if(size == 1){
            delete link;
            link = NULL;
        }
        else{
            Element* tmp = link;
            link = link->prev;
            link->next = tmp->next;
            link->next->prev = link;
            delete tmp;
        }
        size--;
        return true;
    }
    bool usunLN(){
        if(size == 0)   return false;
        if(size == 1){
            delete link;
            link = NULL;
        }
        else{
            Element* tmp = link;
            link = link->next;
            link->prev = tmp->prev;
            link->prev->next = link;
            delete tmp;
        }
        size--;
        return true;
    }
    void show(){    //NIE MA KOŃCA!!!
        if(link)    cout<<"L="<<link->slowo<<" "<<link->liczba<<"\t";
        Element* tmp = link;
        if(size)
            for(int i = 1; i <= size; ++i){
                cout << tmp->slowo<<"["<<tmp->liczba<<"]"<<" > ";
                tmp = tmp->next;
                if(i == size)   cout << " :> ";
            }
        cout << "\t[" << size << "]" << endl;
    }
};

int main(){
    int pamietanie = 0;
    Lista* l = new Lista();
    int num1;
    string str;
    int num;
    int liczbaSlow, rozmiarDodatkowejListy, slowoStartowe;
    cin >> liczbaSlow >> slowoStartowe;
    for(int i = 0; i < liczbaSlow; ++i){
        cin >> str >> num;
        l->dodajZa(str, num);
        l->ruch(1);
    }
    l->ruch(1);
    cin >> rozmiarDodatkowejListy;
    if((slowoStartowe > l->size / 2) || (slowoStartowe < (l->size / 2) * -1))
        l->redukcja(slowoStartowe);
    l->ruch(slowoStartowe);


    while(l->size > 0){
        if((pamietanie > l->size / 2) || (pamietanie < (l->size / 2) * -1))
            pamietanie = l->redukcja(pamietanie);
        l->ruch(pamietanie);
        pamietanie = l->zapamietaj();
        if(pamietanie > 0){
            l->wynik();
            l->usunLP();
        }
        else if(pamietanie < 0){
            l->wynik();
            l->usunLN();
        }
        else{
            cin >> str >> num >> num1;
            l->zero(str, num, num1);
            pamietanie = num1;
            rozmiarDodatkowejListy--;
        }
    }
    if(rozmiarDodatkowejListy > 0){
        while(rozmiarDodatkowejListy > 0){
            cin >> str >> num >> num1;
            rozmiarDodatkowejListy--;
        }
    }
    return 0;
}

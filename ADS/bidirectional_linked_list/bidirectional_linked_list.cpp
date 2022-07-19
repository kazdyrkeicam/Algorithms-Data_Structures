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

/*

W pracy każdego dziennikarza śledczego bardzo ważna jest konspiracja. Szczególnie ważne jest to w przypadku dziennikarza prowadzącego śledztwo w sprawach w które zamieszane są agencje rządowe. Wiadomo, że państwo ma wiele narzędzi, żeby takiego dziennikarza zniszczyć. Władza za pośrednictwem osób trzecich (na przykład żony ministra) może zarządzać niepublikowania tekstów takiego dziennikarza w mediach pod groźbą wycofania reklam spółek skarbu państwa z tych mediów. Może też oczernić go w rządowej telewizji wykorzystując ,,przecieki'' z organów ścigania (na przykład o policyjnej notatce, że dziennikarz w młodości był widywany w stanie nietrzeźwym i co więcej mieszkał w tym samym akademiku co studenci filologii rosyjskiej). W skrajnym przypadku taki dziennikarz może być aresztowany i pod zarzutem przyjęcia korzyści o dużej wartości (na przykład zegarka produkcji japońskiej) w zamian za opublikowanie artykułów wychwalających zalety jednego nadmorskiego kurortu ponad zalety innego kurortu (na podstawie zeznań skruszonego burmistrza pierwszego kurortu).

Aby dochować zasad konspiracja Partycja postanowiła w korespondencji ze swoimi współpracownikami używać szyfru RSA. Partycja nie ufa jednak powszechnie używanym implementacjom tego szyfru gdyż za dobrze pamięta aferę z OpenSSL-em. W związku z tym potrzebuje między innymi programu, który na podstawie liczb pierwszych p i q, których iloczyn jest równy n (wszystkie obliczenia w wykonywane są modulo n) oraz klucza publicznego e wygeneruje klucz prywatny d i rozszyfruje zaszyfrowaną wiadomość c.

Wyjście
Na standardowym wyjściu program otrzyma liczbę zestawów danych t a następnie t zestawów zawierających liczby p, q, e oraz c.

1<=n<4294967296
p,g,e,c< n
Wyjście
Dla każdego zestawu danych wypisz rozszyfrowaną wiadomość.

Przykłady
Wejście
5
2 5 3 3
3 5 9 4
13 17 5 11
19 3 7 55
7 5 11 22
Wyjście
7
4
7
16
8
Uwaga program powinien używać własnych implementacji algorytmów Euklidesa i potęgowania metodą wielokrotnych kwadratów.

*/

#include <iostream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull private_key, public_key, phi, n;

ull xeuk(){
    ull div = phi / public_key;
    ull mod = phi % public_key;
    
    ll x = 1, y = 0;
    ll buff, tmphi, tmp_key = public_key;

    while(mod > 0){
        buff = y - div * x;
        if(buff >= 0)
            buff = buff % phi;
        else
            buff = phi - ((-buff) % phi);
        
        y = x;
        x = buff;
        tmphi = tmp_key;
        tmp_key = mod;
        
        div = tmphi / tmp_key;
        mod = tmphi % tmp_key;
    }
    return x;
}

ull code(ull a){
    ull power = a;
    ull result = 1;
    
    for(ull i = private_key; i > 0; i /= 2){
        if(i % 2)
            result = (result * power) % n;
        power = (power * power) % n;
    }
    return result;
}

int main()
{
    ull p, q, mess;
    int kit;

    cin >> kit;
    while(kit > 0){
        cin >> p >> q >> public_key >> mess;

        n = p * q;
        phi = ((p - 1) * (q - 1)) % n;

        private_key = xeuk();
        private_key = private_key % n;
        ull result = code(mess);

        cout << result % n << endl;

        kit--;
    }
    return 0;
}

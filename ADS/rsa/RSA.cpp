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

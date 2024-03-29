#include <iostream>
using namespace std;

int top(int t[], int n){
    return t[0];
}

void push(int t[], int &n, int e){
    int index = n;
    t[n] = e;
    n++;

    if(index == 0)
        return;
    while(index > 0){
        if(index % 2)
                if(t[index] > t[(index - 1) / 2]){
                    int tmp = t[index];
                    t[index] = t[(index - 1) / 2];
                    t[(index - 1) / 2] = tmp;

                    index = (index - 1) / 2;
                }
                else
                    return;

        else if(!(index % 2))
                if(t[index] > t[(index - 2) / 2]){
                    int tmp = t[index];
                    t[index] = t[(index - 2) / 2];
                    t[(index - 2) / 2] = tmp;

                    index = (index - 2) / 2;
                }
                else
                    return;
    }
}

void pop(int t[], int &n){
    if(n == 0) return;

    //cout << t[0] << " ";
    t[0] = t[n - 1];
    n--;

    int i = 0, buf, tmp;
    while(i < n){
        //cout << "jestem" << endl;
        if(i * 2 + 1 < n){
            if(i * 2 + 2 < n){
                buf = t[i * 2 + 1] > t[i * 2 + 2] ? i * 2 + 1 : i * 2 + 2;
                if(t[i] < t[buf]){
                    tmp = t[i];
                    t[i] = t[buf];
                    t[buf] = tmp;

                    i = buf;
                }
                else return;
            }
            else{
                buf = i * 2 + 1;
                if(t[i] < t[buf]){
                    tmp = t[i];
                    t[i] = t[buf];
                    t[buf] = tmp;

                    i = buf;
                }
                else return;
            }
        }
        else return;
    }
}

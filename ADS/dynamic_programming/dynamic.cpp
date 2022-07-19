#include <iostream>
#include <vector>

#define DAYS 7
#define MOD 100000007

using namespace std;

struct Info{
    int name, paper, day;

    Info(int n, int p, int d){
        name = n;
        paper = p;
        day = d;
    }

    void show(){
        cout << "n: " << name << ", p: " << paper << ", d: " << day << "::";
    }
};

int main()
{
    vector<Info> arr[DAYS];

    long long **matrix = new long long * [DAYS];
    int size, first_mass, public_day, spread, edge;
    vector<Info>::iterator it;
    int a, b, c, d;
    long long result = 1;

    cin >> size >> first_mass >> public_day >> spread >> edge;

    for(int i = 0; i < DAYS; ++i){
        matrix[i] = new long long [size];
        for(int j = 0; j < size; ++j)
            matrix[i][j] = 0;
    }

    for(int i = 0; i < edge; ++i){
        cin >> a >> b >> c >> d;
        Info tmp(a, c, d);          //UWAGA tu mozesz tracic pamiec, bo mozna stworzyc jeden obiekt i przypisywac
        arr[b].push_back(tmp);      //tu poprostu wartosci, zamiast w konstruktorze
    }

    matrix[public_day][first_mass] = 1;

    int i = (public_day + 1) % 7;

    while(spread > 1){

	for(int j = 0; j < size; ++j)
                matrix[i][j] = 0;	

        for(it = arr[i].begin(); it != arr[i].end(); ++it){
            matrix[i][it->name] += matrix[it->day][it->paper];

            matrix[i][it->name] %= MOD;
        }
	for(int j = 0; j < size; ++j)
                result += matrix[i][j];
	result %= MOD;
        i++;
        if(i == 7)
            i = 0;

        spread--;
    }

    cout << result % MOD << endl;
    return 0;
}

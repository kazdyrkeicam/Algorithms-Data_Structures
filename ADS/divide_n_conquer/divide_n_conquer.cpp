#include <iostream>
using namespace std;
unsigned roomX, roomY;

void searchFor(unsigned botX, unsigned botY, unsigned id){
    unsigned areaUP, areaDOWN, areaLEFT, areaRIGHT;
    areaUP = roomY; areaRIGHT = roomX;
    areaDOWN = 0;   areaLEFT = 0;
    string direction;

    direction = test(botX, botY, id);
    while(direction != ""){
        if(direction == "N"){
            areaDOWN = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
        }
        if(direction == "NE"){
            areaLEFT = botX;    areaDOWN = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        if(direction == "NW"){
            areaRIGHT = botX;    areaDOWN = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        if(direction == "S"){
            areaUP = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
        }
        if(direction == "SE"){
            areaLEFT = botX;    areaUP = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        if(direction == "SW"){
            areaRIGHT = botX;    areaUP = botY;
            botY = areaDOWN + ((areaUP - areaDOWN) / 2);
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        if(direction == "E"){
            areaLEFT = botX;
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        if(direction == "W"){
            areaRIGHT = botX;
            botX = areaLEFT + ((areaRIGHT - areaLEFT) / 2);
        }
        direction = test(botX, botY, id);
    }
    cout << botX << " " << botY << endl;
}

int main(){
    unsigned bugs;
    unsigned i, botX, botY;

    cin >> roomX >> roomY >> bugs;
    botX = roomX / 2;   botY = roomY / 2;
    for(i = 0; i < bugs; ++i){
        searchFor(botX, botY, i);
    }
    return 0;
}

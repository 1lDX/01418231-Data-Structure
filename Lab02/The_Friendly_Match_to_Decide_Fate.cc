#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double calDmg(double atk, double def){
    return pow(atk, 2) / def;
}

struct Robot{
    string name;
    double health;
    double atk;
    double def;
    int energy;
    bool alive = true;
};

struct Setting{
    int robot;
    double atkMultiply;
    double defMultiply;
    int powerUp;
};

int main(){
    int n;
    cin>>n;

    vector<Setting> TeamA(1), TeamB(1);
    vector<Robot> robotA(n), robotB(n);
        cin>>TeamA[0].robot>>TeamA[0].atkMultiply>>TeamA[0].defMultiply>>TeamA[0].powerUp;
    for(int i=0;i<n;i++){
        cin>>robotA[i].name>>robotA[i].health>>robotA[i].atk>>robotA[i].def>>robotA[i].energy;
    }
        cin>>TeamB[0].robot>>TeamB[0].atkMultiply>>TeamB[0].defMultiply>>TeamB[0].powerUp;
    for(int i=0;i<n;i++){
        cin>>robotB[i].name>>robotB[i].health>>robotB[i].atk>>robotB[i].def>>robotB[i].energy;
    }

int turn = 0;
int aliveA = 0, aliveB = 0;

    while(1){
        double powerUpAtk = robotA[indexA].atk;
        if (robotA[indexA].powerUp > 0) {
            powerUpAtk *= TeamA[0].atkMultiply;
            robotA[indexA].powerUp--;
        }
        // If Mena has enough energy for ultimate ability, double her attack
        if (robotA[indexA].energy >= 5) {
            powerUpAtk *= 2;  // Ultimate power
            robotA[indexA].energy = 0;  // Reset energy after using ultimate
        }

        // Luna (Robot B) defense
        double powerUpDef = robotB[indexB].def;
        if (robotB[indexB].powerUp > 0) {
            powerUpDef *= TeamB[0].defMultiply;
        }

        // Calculate damage to Luna
        double damageMena = calDmg(powerUpAtk, powerUpDef);
        robotB[indexB].health -= damageMena;

        if (robotB[indexB].health <= 0) {
            indexB++;
            aliveB--;
        }

        if (aliveB == 0) break;



       




        
       
    

    if(aliveA == 0 || aliveB == 0){
            if(aliveA > 0){
                cout <<"Miena is victorious with " << aliveA << " character";
                if(aliveA > 1) cout << "s";
                cout << " left.\n";
            }else{
                cout <<"Luna is victorious with " << aliveB << " character";
                if(aliveB > 1) cout << "s";
                cout << " left.\n";
            }

            cout << "The battle took " << turn << " turn";
            if(turn > 1) cout << "s";
            cout << ".\n";
    }
    return 0;
    }
}
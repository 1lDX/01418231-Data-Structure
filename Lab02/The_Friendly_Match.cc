#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int calDmg(double atk, double def){
    return (int)((atk * atk) / def);
}

struct Robot{
    double health;
    double atk;
    double def;
    int energy;
    int math = 0;
    int cc;
};

struct Setting{
    int robot;
    double atkMultiply;
    double defMultiply;
    int powerUp;
};

void applyPowerUp(Setting& x, Setting& y, Robot& z, Robot& c, int xx, int yy){
    double stat = z.atk;
    double multiplier = c.def;
    if(xx == x.robot && z.cc < x.powerUp){
        stat *= x.atkMultiply;
    }

    if(yy == y.robot && c.cc < y.powerUp){
        multiplier *= y.defMultiply;
    }

    if(z.math == z.energy){
        stat *= 2;
        z.math = 0;
    }else{
        z.math +=1;
    }
    c.health -= calDmg(stat, multiplier);
    z.cc +=1;
}

int main(){
    int n;
    string name;
    cin>>n;

    //Miena team
    Setting TeamA;
    cin>>TeamA.robot>>TeamA.atkMultiply>>TeamA.defMultiply>>TeamA.powerUp;

    vector<Robot> robotA(n);
    for(int i = 0; i < n; i++){
        cin>>name>>robotA[i].health>>robotA[i].atk>>robotA[i].def>>robotA[i].energy;
    }
    

    //Luna team
    Setting TeamB;
    cin>>TeamB.robot>>TeamB.atkMultiply>>TeamB.defMultiply>>TeamB.powerUp;

    vector<Robot> robotB(n);
    for (int i = 0; i < n; i++){
        cin>>name>>robotB[i].health>>robotB[i].atk>>robotB[i].def>>robotB[i].energy;
    }
    
    int turn = 0;
    int indexA = 0, indexB = 0;

    while(indexA < robotA.size() && indexB < robotB.size()){
        // ===== Miena's turn =====
        turn++;
        applyPowerUp(TeamA, TeamB, robotA[indexA], robotB[indexB], indexA, indexB);

        if(robotB[indexB].health <= 0){
            indexB++;
        }
        // ===== Luna's turn =====
        if(indexB < robotB.size()){
            turn++;
            applyPowerUp(TeamB, TeamA, robotB[indexB], robotA[indexA], indexB, indexA);
            if(robotA[indexA].health <= 0){
                indexA++;
            }

        }
    }
    int aliveA = n - indexA;
    int aliveB = n - indexB;
    if(aliveA > 0){
        cout<<"Miena is victorious with "<<aliveA<<" character";
        if(aliveA > 1) cout<<"s";
        cout<<" left.\n";
    }else{
        cout<<"Luna is victorious with "<<aliveB<<" character";
        if(aliveB > 1) cout<<"s";
        cout<<" left.\n";
    }

    cout<<"The battle took "<<turn<<" turn";
    if(turn > 1) cout<<"s";
    cout<<".\n";

    return 0;
}

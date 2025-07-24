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
    int turn;
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
    cin >> n;

    vector<Setting> TeamA(1), TeamB(1);
    vector<Robot> robotA(n), robotB(n);

    for(int i=0;i<1;i++){
        cin >> TeamA[i].robot>>TeamA[i].atkMultiply>>TeamA[i].defMultiply>>TeamA[i].powerUp;
    }

    for(int i=0;i<n;i++){
        cin >> robotA[i].name>> robotA[i].health>>robotA[i].atk>>robotA[i].def>>robotA[i].turn;
    }

    for(int i=0;i<1;i++){
        cin >> TeamB[i].robot>>TeamB[i].atkMultiply>>TeamB[i].defMultiply>>TeamB[i].powerUp;
    }

    for(int i=0;i<n;i++){
        cin >> robotB[i].name>> robotB[i].health>>robotB[i].atk>>robotB[i].def>>robotB[i].turn;
    }

    for(int i=0;i<1;i++){
        int index = TeamA[i].robot;
        if(TeamA[i].powerUp > 0 && index < robotA.size()) {
            robotA[index].atk *= TeamA[i].atkMultiply;
            robotA[index].def *= TeamA[i].defMultiply;
        }
    }

    for(int i=0;i<1;i++){
        int index = TeamA[i].robot;
        if(TeamB[i].powerUp > 0 && index < robotB.size()) {
            robotB[index].atk *= TeamB[i].atkMultiply;
            robotB[index].def *= TeamB[i].defMultiply;
        }
    }

int turn = 0;
while(1){
        turn++;
        //TESTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
        // for(int i=0;i<n;i++){
        //     if(!robotA[i].alive || turn % robotA[i].turn != 0){
        //         continue;
        //     } 
        //     for(int j=0;j<n;j++){
        //         if(robotB[j].alive){
        //             double dmg = calDmg(robotA[i].atk, robotB[j].def);
        //             robotB[j].health -= dmg;
        //             if(robotB[j].health <= 0) robotB[j].alive = 0;
        //             break;
        //         }
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(!robotB[i].alive || turn % robotB[i].turn != 0){
        //         continue;
        //     }
        //     for(int j=0;j<n;j++){
        //         if(robotA[j].alive){
        //             double dmg = calDmg(robotB[i].atk, robotA[j].def);
        //             robotA[j].health -= dmg;
        //             if(robotA[j].health <= 0) robotA[j].alive = 0;
        //             break;
        //         }
        //     }
        // }
        //TESTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

        for(int i = 0; i < n; i++){
            if(turn % robotA[i].turn == 0 && robotA[i].alive){
                for(int j = 0; j < n; j++){
                    if(robotB[j].alive){
                        double dmg = calDmg(robotA[i].atk, robotB[j].def);
                        robotB[j].health -= dmg;
                        if(robotB[j].health <= 0) robotB[j].alive = false;
                        break;
                    }
                }
            }

            if(turn % robotB[i].turn == 0 && robotB[i].alive){
                for(int j = 0; j < n; j++){
                    if(robotA[j].alive){
                        double dmg = calDmg(robotB[i].atk, robotA[j].def);
                        robotA[j].health -= dmg;
                        if(robotA[j].health <= 0) robotA[j].alive = false;
                        break;
                    }
                }
            }
        }


        for(int i = 0; i < n; i++){
            if(turn % robotA[i].turn == 0 && robotA[i].alive){
        for(int j = 0; j < n; j++){
            if(robotB[j].alive){
                double dmg = calDmg(robotA[i].atk, robotB[j].def);
                robotB[j].health -= dmg;
                if(robotB[j].health <= 0) robotB[j].alive = false;
                break;
            }
        }
    }

    if(turn % robotB[i].turn == 0 && robotB[i].alive){
        for(int j = 0; j < n; j++){
            if(robotA[j].alive){
                double dmg = calDmg(robotB[i].atk, robotA[j].def);
                robotA[j].health -= dmg;
                if(robotA[j].health <= 0) robotA[j].alive = false;
                break;
              }
        }
    }
}


        int aliveA = 0, aliveB = 0;
        for(int i = 0; i < n; i++){
            if(robotA[i].alive) aliveA++;
            if(robotB[i].alive) aliveB++;
        }

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
            break;
        }
    }

    return 0;
}

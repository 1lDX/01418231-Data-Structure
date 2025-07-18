#include <iostream>
#include <vector>
#include <string>
using namespace std;


double myMax(double take,double noTake){
    if(take > noTake){
        return take;
    }else if (noTake > take){
        return noTake;
    }
    return take;
}

double knapSackRecur(int i, int count,int limit,int capacity, vector<double> val, vector<int> wt) {
    if (count == limit ||i==val.size()) return 0;
    
    double take = 0;
    if (wt[i]<=capacity) {
        take = val[i] + knapSackRecur(i, count +1,limit,capacity-wt[i], val, wt);
    }
    
    double noTake = knapSackRecur(i+1, count,limit,capacity, val, wt);

    
    return myMax(take, noTake);
}

// int cal(vector<int> spell_cost,
//              vector<int> spell_level,
//              vector<char> spell_char,
//              int magic,int requirement, int mana){
            

//             for(int i=0;i<magic;i++){
                
//             }
//     }


double calScore(char spell_char,int spell_level){
    double score = 0.0;
    double score_level;
    if (spell_char == 'F') {
        score = 12;
    } else if (spell_char == 'A') {
        score = 15;
    } else if (spell_char == 'W') {
        score = 12; 
    } else if (spell_char == 'E') {
        score = 10; 
    } else if (spell_char == 'L') {
        score = 20;
    }  else if (spell_char == 'D') {
        score = 20;
    }

    if (spell_level >= 1 && spell_level <= 5){
        score_level = spell_level * 10;
    }else if (spell_level == 6){
        score_level = 65;
    }else if (spell_level == 7){
        score_level = 80;
    }else if (spell_level == 8){
        score_level = 100;
    }

    double result = (score * score_level)/100;
    return result;
}


int main() {
    int requirement, mana, magic;
    cin >> requirement >> mana >> magic;

    vector<char> spell_char(magic);
    vector<int> spell_level(magic);
    vector<int> spell_cost(magic);
    vector<double> score(magic);

    for (int i = 0; i < magic; i++) {
        char type;
        int level;
        string name1, name2;
        int cost;

        cin >> type >> level >> name1;
        cin >> name2;


        if (isdigit(name2[0])) {
            cost = stoi(name2);
        } else {
   
            cin >> cost;
        }

        score[i] = calScore(type,level);
        spell_char[i] = type;
        spell_level[i] = level;
        spell_cost[i] = cost;
        
    }

    cout << knapSackRecur(0,0,requirement,mana,score,spell_cost) << endl;

    
    // for (int i = 0; i < magic; i++) {
    //     cout << "Index " << i << ": ";
    //     cout << "Char = " << spell_char[i] << ", ";
    //     cout << "Level = " << spell_level[i] << ", ";
    //     cout << "Cost = " << spell_cost[i] << endl;
    // }

    return 0;
}

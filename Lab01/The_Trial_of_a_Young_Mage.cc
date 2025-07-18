#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calScore(vector<int> spell_cost,
             vector<int> spell_level,
             vector<char> spell_char,
             int requirement, int mana){
                
             }

int main() {
    int requirement, mana, magic;
    cin >> requirement >> mana >> magic;

    vector<char> spell_char;
    vector<int> spell_level;
    vector<int> spell_cost;

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

        spell_char.push_back(type);
        spell_level.push_back(level);
        spell_cost.push_back(cost);
    }

    
    // for (int i = 0; i < magic; i++) {
    //     cout << "Index " << i << ": ";
    //     cout << "Char = " << spell_char[i] << ", ";
    //     cout << "Level = " << spell_level[i] << ", ";
    //     cout << "Cost = " << spell_cost[i] << endl;
    // }

    return 0;
}

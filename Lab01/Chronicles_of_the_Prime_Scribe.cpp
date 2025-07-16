#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

string stringCheck(int n) {
    if(n % 100 >= 11 && n % 100 <= 13)return to_string(n) + "th";
    switch(n % 10){
        case 1: return to_string(n) + "st";
        case 2: return to_string(n) + "nd";
        case 3: return to_string(n) + "rd";
        default: return to_string(n) + "th";
    }
}

string prime(int x){
    vector<bool> isPrime(x + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // start prime
    for(int j=2;j*j<=x;j++){
        // if prime
        if(isPrime[j] == true){
            for(int i=j*j;i<=x;i+=j){
                isPrime[i] = false;
            }
        }
    }

    //check output
    // cout << "Prime numbers up to " << x << " are: ";
    // for (int p = 2; p <= x; ++p) {
    //     if (isPrime[p])
    //         cout << p << " ";
    // }

    string result = "";
    if(isPrime[x] == true){
        int count = 0;
        for(int i=2; i<=x;i++){
            if(isPrime[i] == true){
                count++;
            }
        }
        result = stringCheck(count);
    }else{
        result = "Unrelated";
    }

    return result;
}

int main(){
    int x;
    cin >> x;
    if (x<0){
        cout<<"ERROR!";
    }else{
        cout<<prime(x);
    }

    
    return 0;
}
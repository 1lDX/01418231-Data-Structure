#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

bool comparePromax(double a, double k, double ELP = 1e-9) {
    return fabs(a - k) <= ELP;
}

bool compareNormal(double a, double k, double ELP = 1e-9) {
    return (a >= k || fabs(a-k)<ELP);
}


int main(){
    int seed,j,d = 0;
    double k = 0.0;
    cin>>j>>k;
    cin>>d;

    double  p = pow(10.0,j);
    int milk = 0, promax = 0;
    double nutrient = 0.0;
    double uncle = 0.0,cow = 0.0;
        
    for(int i=0;i<d;i++){
        cin >> seed;
        uncle = p*seed;

        for(int i=0;i<seed;i++){
            cow += p;

        }
        nutrient += cow;

        if(comparePromax(cow+uncle,k)){
            promax++;
        }
       
        else if(compareNormal(cow,k)){
            milk++;
        }


        cow = 0.0;
    }

    cout<<"Milk : "<<milk<<endl;
    cout<<"ProMax Milk : "<<promax<< endl;
    cout<<"Nutrient : "<<setprecision(17)<<fixed<<showpoint<<nutrient<< endl;

    // for(int i=0;i<d;i++){
    //     cout << seed[i];
    // }
    // return 0;


    return 0;

}
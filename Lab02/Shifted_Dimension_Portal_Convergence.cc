#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Rectangle{
    double x1, y1, x2, y2;
};

void swap(Rectangle &r){
    if(r.x1 > r.x2){
        double temp = r.x1;
        r.x1 = r.x2;
        r.x2 = temp;
    }
    if(r.y1 > r.y2){
        double temp = r.y1;
        r.y1 = r.y2;
        r.y2 = temp;
    }
}

double mymin(double a, double b){
    if(a < b){
        return a;
    }
    return b;
}

double mymax(double a, double b){
    if(a > b){
        return a;
    }
    return b;
}

double cal(Rectangle a, Rectangle b){
    double x = mymin(a.x2, b.x2) - mymax(a.x1, b.x1);
    double y = mymin(a.y2, b.y2) - mymax(a.y1, b.y1);
    if(x > 0 && y > 0){
        return x * y;
    }
    return 0.0;
}

int main(){
    int n;
    cin >> n;
    vector<Rectangle>rects(n);

    for(int i = 0; i < n; ++i){
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        swap(rects[i]);
    }
    double overlap,maxOverlap = 0.0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            overlap = cal(rects[i], rects[j]);
            if(overlap > maxOverlap){
                maxOverlap = overlap;
            }
        }
    }
    cout<<fixed<<setprecision(6)<<maxOverlap<<endl;
    return 0;
}

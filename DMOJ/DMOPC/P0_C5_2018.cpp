#include <bits/stdc++.h>

using namespace std;

float screen(float x1,float x2) {
    return 1 - (1-x1)*(1-x2);
}

float overlay(float x1,float x2) {
    float r;
    if (x1 < 0.5f) {
        r=2*x1*x2;
    } else {
        r=1-(2*(1-x1)*(1-x2));
    }
    
    return r;
}

int main() {
    string type;
    cin >> type;
    float r1,g1,b1;
    float r2,g2,b2;
    cin >> r1 >> g1 >> b1;
    cin >> r2 >> g2 >> b2;
    if (type=="Multiply") {
        cout << r1*r2 << " " << g1*g2 << " " << b1*b2 << "\n"; 
    } else if (type == "Screen") {
        cout << screen(r1,r2) << " " << screen(g1,g2) << " " << screen(b1,b2) << "\n";
    } else {
        cout << overlay(r1,r2) << " " << overlay(g1,g2) << " " << overlay (b1,b2) << "\n";
    }
}
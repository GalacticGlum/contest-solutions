#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<double> > grid;
    double avg=0;
    for (int i=0;i<n;++i) {
        vector<double> line;
        for(int j=0;j<m;++j) {
            double p;
            cin >> p;
            line.push_back(p);
            avg+=p;
        }
        grid.push_back(line);
    }
    
    int size = n*m;
    avg /= size;
    avg=roundf(avg*100000)/100000;
    // avg = static_cast<float>(static_cast<int>(avg * 100000 + 0.5f) / 100000);
    // cout << avg << "\n"; 
    
    bool ce=false;
    if (avg < 0.48f) {
        cout << "underexposed\n";
    } else if(abs(avg-0.48f)<=1e-05) {
        cout << "correctly exposed\n";
        ce=true;
    } else {
        cout << "overexposed\n";
    }
    
    double c = 0.48f/avg;
    double adjusted=0;
    double oc=0;
    for(auto& px : grid) {
        for(double& pixel : px) {
            double v=pixel*c;
            if(v > 1) {
                oc+=1;
            } else {
                adjusted+=pixel;
            }
        }
    }
    c=(0.48f*size-oc)/adjusted;
    if(!ce) {
        cout << c << "\n";
    }
    
    return 0;
}
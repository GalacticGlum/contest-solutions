#include <iostream>
#include <set>
#include <cmath>
#include <stdio.h>
#include <limits>
#define INF 0x3f3f3f3f

int main() {
    int n;
    std::cin >> n;

    std::pair<double, double> coordinates[n];
    for(int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        coordinates[i] = {x,y};
    }

    std::set<int> result;

    double dx = 0;
    while(dx <= 1000.00) {
        double min_distance = INF;
        int t=0;
        for(int i = 0; i < n; ++i) {
            double x = coordinates[i].first-dx;
            double y = coordinates[i].second;
            double distance = (x*x+y*y);
            if (distance < min_distance) {
                t=i;
                min_distance = distance;
            }
        }
        
        result.insert(t);

        dx += 0.01;
    }

    for(auto& i : result) {
        // the only time I would consider using C stdio is when
        // I need to format and round and I'm too lazy to set C++ iostream
        // precision
        printf("The sheep at (%.2f, %.2f) might be eaten.\n", coordinates[i].first, coordinates[i].second);
    }
}
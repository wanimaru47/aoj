#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> P;

bool pariCompare (const P& FElof, const P& SElof) {
    if (FElof.first == SElof.first) return FElof.second < SElof.second;
    return FElof.first < SElof.first;
}

double DIST (double x, double y) {
    return x * x + y * y;
}

double dist (P a, P b) {
    return DIST(a.frist - b.first);
}

int main ()
{
    int n;
    cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), pariCompare);

    double dis = 100000.0;
    for (int i = 0; i < n-1; i++) {
        
    }

    printf("%.6f\n", sqrt(dis));

    return 0;
}

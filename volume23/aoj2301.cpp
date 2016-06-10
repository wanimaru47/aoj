#include <bits/stdc++.h>
using namespace std;

int K;
double R, L, P, E, T;

double dfs(int d, double p, double r, double l) {
    double h = (r + l) / 2.;
    if (d == K) {
        if (abs(T - h) <= E) {
            return 0.;
        } else {
            return p;
        }
    }

    if (l < T - E || T + E < r) return p;
    if (T - E < r && l < T + E) return 0.;

    double good_r, good_l, but_r, but_l;

    if (h >= T) {
        good_r = r;
        good_l = h;
        but_r = h;
        but_l = l;
    } else {
        good_r = h;
        good_l = l;
        but_r = r;
        but_l = h;
    }

    return dfs(d + 1, p * (1.0 - P), good_r, good_l) + dfs(d + 1, p * P, but_r, but_l);
}

int main() {
    cin >> K >> R >> L >> P >> E >> T;
    printf("%.12f\n", 1. - dfs(0, 1., R, L));

    return 0;
}

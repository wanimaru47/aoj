#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int f, a, t;
    double x, y;
    cin >> f >> a >> t >> x >> y;
    double T[2] = {-1, -1}, L[2] = {-1, -1};
    for(int i = 1; i < n; i++) {
        int f_, a_, t_;
        double x_, y_;
        cin >> f_ >> a_ >> t_ >> x_ >> y_;
        if(t == t_ && a != a_) {
            double len = (x - x_) * (x - x_) + (y - y_) * (y - y_);
            double flames = f_ - f;
            if(L[t] < len) {
                L[t] = len;
                T[t] = flames;
            } else if (L[t] == len && T[t] > flames) {
                T[t] = flames;
            }
        }
        f = f_, a = a_, t = t_, x = x_, y = y_;
    }
    if(L[0] > 0)
        printf("%.8f %.8f\n", sqrt(L[0]), (T[0] / 60));
    else 
        cout << -1 << " " << -1 << endl;
    if(L[1] > 0)
        printf("%.8f %.8f\n", sqrt(L[1]), (T[1] / 60));
    else 
        cout << -1 << " " << -1 << endl;

    return 0;
}

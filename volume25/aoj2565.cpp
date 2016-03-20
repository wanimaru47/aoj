#include<bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main() {
    int n; 
    while (cin >> n, n > 0) {
        vector<int> a(n);
        for (auto &i : a) {
            char c[100]; cin >> c;
            if (!strcmp("x", c)) i = INF;
            else i = atoi(c);
        }

        int l = -INF, u = INF;
        bool flag = false;
        for (int i = 0; !flag && i < n; i++) {
            if (i > 0 && a[i-1] == INF && a[i] == INF) flag = true;
            if (i % 2 && a[i-1] != INF && a[i] != INF && a[i] <= a[i-1]) flag = true;
            if (i + 1 < n && i % 2 == 0 && a[i+1] != INF && a[i] != INF && a[i] >= a[i+1]) flag = true;
            if (a[i] == INF) {
                if (i % 2) {
                    if (i > 0) l = max(l, a[i-1]+1);
                    if (i + 1 < n) l = max(l, a[i+1]+1);
                } else {
                    if (i > 0) u = min(u, a[i-1]-1);
                    if (i + 1 < n) u = min(u, a[i+1]-1);
                }
            }
        }

        if (flag || l > u) cout << "none" << endl;
        else if (l == u) cout << l << endl; 
        else cout << "ambiguous" << endl;
    }

    return 0;
}

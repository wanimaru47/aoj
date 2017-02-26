#include <bits/stdc++.h>
using namespace std;

int v[10][10];

bool check1(vector<int> d) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (d[i] == j) continue;
            auto t = d;
            t[i] = j;

            int e = 0;
            for (int k = 0; k < 5; k++) e = v[e][t[k]];

            if (!e) return false;
        }
    }

    return true;
}

bool check2(vector<int> d) {
    for (int i = 0; i < 4; i++) {
        auto t = d;
        if (t[i] == t[i+1]) continue;
        swap(t[i], t[i+1]);
        
        int e = 0;
        for (int j = 0; j < 5; j++) e = v[e][t[j]];

        if (!e) return false;
    }

    return true;
}

int main() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) cin >> v[i][j];

    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        vector<int> d(5);
        for (int j = 0, x = i; j < 4; j++) {
            d[3-j] = x % 10;
            x /= 10;
        }

        int e = 0;
        for (int j = 0; j < 4; j++) e = v[e][d[j]];
        d[4] = e;

        bool flag = true;
        if (!check1(d)) flag = false;
        if (!check2(d)) flag = false;

        if (!flag) ans++;
    }

    cout << ans << endl;

    return 0;
}

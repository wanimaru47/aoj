#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(m);
    for (auto &i : s) cin >> i;
    for (auto &i : t) cin >> i;

    vector<int> r(s);
    int c = 0;
    int l = 0;
    int ans1 = 0;
    for (int i = 0; ans1 >= 0 && i < m; i++) {
        for (int j = 0; j < t[i]; j++) {
            if (c != s[l]) {
                int k = l + 1;
                while (k < n && c != s[k]) k++;
                if (k == n) {ans1 = INF; break;}
                ans1 += (k - l);
                s[k] = !c;
            }
            l++;
        }
        c = c ? 0 : 1;
    }

    c = 1;
    l = 0;
    int ans2 = 0;
    for (int i = 0; ans2 >= 0 && i < m; i++) {
        for (int j = 0; j < t[i]; j++) {
            if (c != r[l]) {
                int k = l + 1;
                while (k < n && c != r[k]) k++;
                if (k == n) {ans2 = INF; break;}
                ans2 += (k - l);
                r[k] = !c;
            }
            l++;
        }
        c = c ? 0 : 1;
    }

    cout << min(ans1, ans2) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int K;
string t;

int dfs(string s, int d, int k) {
    if (s == t) return d;

    int diff = t[k] - s[k];
    if (diff == 0) {
        return dfs(s, d, k+1);
    }
    int ret = 1111;
    for (int i = k; i < K; i++) {
        s[i] = (char)((10 + diff + s[i] - '0')%10 + '0');
        ret = min(ret, dfs(s, d+1, k+1));
    }

    return ret;
}

int main() {
    while (cin >> K, K) {
        string s;
        cin >> s >> t;
        cout << dfs(s, 0, 0) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<int> v(N + M);
        for (auto& i : v) cin >> i;
        v.push_back(0);
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size()-1; i++)
            ans = max(ans, v[i+1]-v[i]);
        cout << ans << endl;
    }

    return 0;
}

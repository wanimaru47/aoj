#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    while (cin >> N >> K, N || K) {
        vector<int> v(N + 2);
        for (int i = 0; i < K; i++) {
            int x; cin >> x;
            v[x]++;
        }


        vector<pair<int,int> > d;
        int left;
        for (int i = 1, flag = false; i <= N; i++) {
            if (!flag && v[i]) left = i-1, flag = true;
            if (flag && !v[i]) d.push_back(pair<int,int>(left, i-1)), flag = false;
        }

        int ans = 0;
        for (int i = 0; i < (int)d.size(); i++) {
            if (!v[0]) ans = max(ans, d[i].second - d[i].first);
            else {
                ans = max(ans, d[i].second - d[i].first + 1);
                if (i + 1 < (int)d.size() && d[i].second + 1 == d[i+1].first) {
                    ans = max(ans,
                              d[i].second - d[i].first + 1
                              + d[i+1].second - d[i+1].first);
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}

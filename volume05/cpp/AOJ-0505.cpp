#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &f, const pair<int,int> &s) {
    if (f.first == s.first) return f.second < s.second;
    return f.first > s.first;
}

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<pair<int,int> > v;
        for (int i = 1; i <= m; i++) {
            v.push_back(pair<int,int>(0, i));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                if (x) v[j].first++;
            }
        }

        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < m; i++) {
            cout << v[i].second << (i < m - 1 ? " " : "\n");
        }
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;

    int min = 0;
    while (m--) {
        int e;
        cin >> e;

        idx[e-1] = min = min - 1;
    }

    vector<pair<int,int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(idx[i], i));
    }

    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i.second+1 << endl;
    }

    return 0;
}

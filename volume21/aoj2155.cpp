#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main ()
{
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<pair<int,P> > data(m);
        vector<bool> v(n+1, false);
        v[1] = true;

        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            P p;
            cin >> p.first >> p.second;
            data[i] = pair<int,P>(t,p);
        }

        sort(data.begin(), data.end());

        for (int i = 0; i < m; i++) {
            if (v[data[i].second.first]) v[data[i].second.second] = true; 
        }

        int res = 0;
        for (auto i : v) {
            if (i) res++;
        }

        cout << res << endl;
    }

    return 0;
}

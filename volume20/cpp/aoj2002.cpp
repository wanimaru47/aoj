#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;

    while (cin >> n >> m, n + m) {
        vector<string> v(n);
        set<char> s;
        for (int i = 0; i < n; i++) { 
            cin >> v[i];
            s.insert(v[i].begin(), v[i].end());
        }
            
        for (auto i : s) {
            int wl = 0, wr = m - 1, ht = 0, hb = n - 1;

        }
    }

    return 0;
}

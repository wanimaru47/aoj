#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q;
    while(cin >> p >> q, q || p) {
        vector<string> s(p), t(q);
        for(auto &i : s) cin >> i;
        for(auto &i : t) cin >> i;

        vector<int> v(p);
        for(int i = 0; i < p; i++) {
            auto str = s[i];
            int x = count(str.begin(), str.end(), '(');
            int y = count(str.begin(), str.end(), '[');
            int z = count(str.begin(), str.end(), '{');
            cout << x << ' ' << y << ' ' << z << endl;
            int c = 0, j = 0;
            while(str[j++] == '.') c++;
            v[i] = c;
            if (i > 0 && c > v[i-1])
                cout << c - v[i-1] << endl;
            else if (i > 0 && )
        }
        
        for(auto i : v) cout << i << endl;
    }

    return 0;
}


/*
 *  {{ 2x
 *  ........( 1x 
 *  ..........)
 *  ........}
 *  .....}
 *
 *
 *
 *
 */

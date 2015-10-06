#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main () { 
    int N, m; cin >> N >> m;
    vec c(m), d(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }

    vec h(N + 1);
    for (int i = 0; i < m; i++) {
        if (c[i] < d[i]) { 
            for (int j = c[i] + 1; j <= d[i]; j++) {
                h[j] = 1;
            }
        }
    }

    int res = N + 1;
    for (int i = 1; i <= N; i++) {
        if (h[i]) {
            res += 2;
        }
    }

    cout << res << endl;
    
    return 0;
}

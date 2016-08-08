#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        cout << v[0];
        for (int i = 1; i < N; i++) {
            if (v[i-1]+1==v[i]) {
                if (i == N-1 || v[i+1]!=v[i]+1) {
                    cout << "-" << v[i];
                }
            }
            else cout << " " << v[i];
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int main() {
    int N; cin >> N;
    mat v(N, vec(N));
    for (auto &i : v) for (auto &j : i) cin >> j;
    int ans = 0;
    for (int i = 0; i < N - 1; i++) for (int j = i + 1; j < N; j++) ans += min(v[i][j], v[j][i]);
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> v(N);
    for (auto& i : v) cin >> i;

    int sum = 0;
    for (int i = 0; i < N-1; i++) {
        if (v[i+1]-v[i] > M*2) {
            sum += v[i+1]-v[i]-2*M;
        }
    }

    sum += (v[0] - M) + max(0, T - v[N-1] - M);
    cout << sum << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N, K, T, U, V, L;
int DL[10001];

int main() {
    cin >> N >> K >> T >> U >> V >> L;
    for (int i = 0; i < N; i++) {
        int D; cin >> D;
        DL[D]++;
    }

    vector<bool> used(L+1, false);
    int count = 0, s;
    bool flag = false;
    for (int i = 0; i < L; i++) {
        if (DL[i] > 0) count++;
        if (flag) {
            if (count > K) s = i, count = K;
            used[i] = true;
        } else if (count > 0) {
            used[i] = true;
            flag = true;
            s = i;
            count--;
        }
        if (flag && s + V * T == i + 1) flag = false;
    }

    double ans = 0;
    for (int i = 0; i < L; i++)
        ans += used[i] ? 1./V : 1./U;
    printf("%.10f\n", ans);

    return 0;
}

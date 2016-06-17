#include <bits/stdc++.h>
using namespace std;

int N;
void solve() {
    vector<int> own(N * 2);
    vector<int> used(N * 2, false);
    int count_h = 0, count_t = 0;

    for (int i = 0, input = 0; i < N; i++) {
        cin >> input; input--; own[input] = true;
    }
    int curr = true;
    while (count_t != N && count_h != N) {
        for (int i = 0; i < N * 2; i++) {
            if (curr == own[i] && !used[i]) {
                used[i] = true;
                if (curr) count_t++;
                else count_h++;
                curr = !curr;
            }
        }
        curr = !curr;
    }

    cout << N - count_h << endl << N - count_t << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}

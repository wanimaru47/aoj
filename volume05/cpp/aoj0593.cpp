#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> voting_count(N);
    vector<int> cost(N);
    for (auto &i : cost) cin >> i;
    for (int i = 0; i < M; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < N; j++) {
            if (cost[j] <= p) {
                voting_count[j]++;
                break;
            }
        }
    }

    int ans = 0, count = 0;
    for (int i = 0; i < N; i++) {
        if (voting_count[i] > count) {
            ans = i + 1;
            count = voting_count[i];
        }
    }

    cout << ans << endl;

    return 0;
}

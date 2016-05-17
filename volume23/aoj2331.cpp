#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(100005);
    V[0]++;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        V[a]++;
        V[b+1]--;
    }

    int res = 0;
    for (int i = 0; i <= 100001; i++) {
        V[i + 1] += V[i];
        if (i <= V[i]) res = i;
    }

    cout << res - 1 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        int dis = min(min(x-1, y-1), min(N-x, N-y));
        cout << dis % 3 + 1 << endl;
    }

    return 0;
}

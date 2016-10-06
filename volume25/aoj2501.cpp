#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;

    int ans = 1000000;
    for (int i = 1; i <= N; i++) {
        int ax = A / i;
        int ay = A % i;
        int bx = B / i;
        int by = B % i;
        int cx = C / i;
        int cy = C % i;
        int dx = D / i;
        int dy = D % i;

        int dis1 = abs(ax - bx) + abs(ay - by);
        int dis2 = abs(cx - dx) + abs(cy - dy);

        ans = min(ans, dis1 + dis2);
    }

    cout << ans << endl;

    return 0;
}

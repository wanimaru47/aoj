#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W, H;
    cin >> N >> H >> W;
    vector<int> vh(H + 1), vw(W + 1);
    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        if (x - w < 0) vh[0]++;
        else vh[x - w]++;
        if (x + w > H) vh[H]--;
        else vh[x + w]--;
        if (y - w < 0) vw[0]++;
        else vw[y - w]++;
        if (y + w > W) vw[W]--;
        else vw[y + w]--;
    }

    bool res1 = true;
    for (int i = 0; res1 && i < H; i++) {
        if (vh[i] <= 0) res1 = false;
        else {
            if (i + 1 < H) vh[i + 1] += vh[i];
        }
    }
    bool res2 = true;
    for (int i = 0; res2 && i < W; i++) {
        if (vw[i] <= 0) res2 = false;
        else {
            if (i + 1 < W) vw[i + 1] += vw[i];
        }
    }

    cout << (res1 | res2 ? "Yes" : "No") << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int main() {
    int M, N, K;
    cin >> N >> M >> K;
    mat J(N+2, vec(M+2)), O(N+2, vec(M+2)), I(N+2, vec(M+2));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c; cin >> c;
            if (c == 'J') J[i][j]++;
            else if (c == 'O') O[i][j]++;
            else if (c == 'I') I[i][j]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            J[i][j] += J[i-1][j] + J[i][j-1] - J[i-1][j-1];
            O[i][j] += O[i-1][j] + O[i][j-1] - O[i-1][j-1];
            I[i][j] += I[i-1][j] + I[i][j-1] - I[i-1][j-1];
        }
    }

    for (int k = 0; k < K; k++) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        cout << J[gx][gy] - J[gx][sy-1] - J[sx-1][gy] + J[sx-1][sy-1] << " ";
        cout << O[gx][gy] - O[gx][sy-1] - O[sx-1][gy] + O[sx-1][sy-1] << " ";
        cout << I[gx][gy] - I[gx][sy-1] - I[sx-1][gy] + I[sx-1][sy-1] << endl;
    }

    return 0;
}

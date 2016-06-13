#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<string> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    vector<bool> h(N, false), w(M, false);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (v[i][j] != '.') h[i] = true, w[j] = true;

    for (int i = 0; i < N; i++) {
        if (i > 0 && !h[i] && h[i-1]) {
            h[i] = true;
            i++;
        }
    }
    for (int i = 0; i < M; i++) {
        if (i > 0 && !w[i] && w[i-1]) {
            w[i] = true;
            i++;
        }
    }


    vector<string> V;
    for (int i = 0, count = 0; i < N; i++) {
        if (!h[i]) continue;
        V.push_back("");
        for (int j = 0; j < M; j++) {
            if (w[j]) V[V.size() - 1] += v[i][j];
        }
    }

    int ans = 0;
    while (1) {
        int pre = ans;

        for (int i = 0, H = V.size(); i < H; i++) {
            for (int j = 0, W = V[i].size(); j < W; j++) {
                if (V[i][j] != '.') continue;
                int up = i, down = i, left = j, right = j;
                while (up >= 0 && V[up][j] == '.') up--;
                while (down < H && V[down][j] == '.') down++;
                while (left >= 0 && V[i][left] == '.') left--;
                while (right < W && V[i][right] == '.') right++;

                string tmp;
                if (up >= 0) tmp += V[up][j];
                if (down < H) tmp += V[down][j];
                if (left >= 0) tmp += V[i][left];
                if (right < W) tmp += V[i][right];

                string same;
                for (int k = 0; k < tmp.size(); k++) {
                    for (int l = k + 1; l < tmp.size(); l++) {
                        if (tmp[k] == tmp[l]) same += tmp[k];
                    }
                }

                if (up >= 0 && same.find(V[up][j]) != string::npos) V[up][j] = '.';
                if (left >= 0 && same.find(V[i][left]) != string::npos) V[i][left] = '.';
                if (down < H && same.find(V[down][j]) != string::npos) V[down][j] = '.';
                if (right < W && same.find(V[i][right]) != string::npos) V[i][right] = '.';

                ans += same.size() * 2;
            }
        }

        if (ans == pre) break;
    }

    cout << ans << endl;

    return 0;
}

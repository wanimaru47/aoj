#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> PP;

int N, K, S;
vector<PP> V;

bool check(PP a, PP b) {
    if (!(a.first.first > b.first.first + S || a.first.first + S < b.first.first)) {
        if (!(a.first.second > b.first.second + S || a.first.second + S < b.first.second)) {
            if (a.second >= b.second + S || a.second + S <= b.second) return false;
            else return true;
        }
    }

    return false;
}

int diff(int a, int b) {
    int sub_x = S - abs(V[a].first.first - V[b].first.first);
    int sub_y = S - abs(V[a].first.second - V[b].first.second);
    int sub_z = S - abs(V[a].second - V[b].second);

    return (sub_x * sub_y + sub_z * sub_y + sub_z * sub_x) * 2;
}

int dfs(vector<vector<bool>>& inter, vector<bool>& used, int now, int k, int men, int pre) {
    if (k == K- 1) {
        for (int i = 0; i < N; i++) {
            if (inter[now][i] && used[i] && pre != i) {
                return diff(i, now);
            }
        }
        return 0;
    }
    used[now] = true;

    int res = -(1<<28);
    for (int i = 0; i < N; i++) {
        if (used[i] == false && inter[now][i])
            res = max(res ,dfs(inter, used, i, k + 1, men, now) + diff(now, i));
    }
    used[now] = false;

    return res;
}

void solve() {
    V.resize(N);
    for (int i = 0; i < N; i++) cin >> V[i].first.first >> V[i].first.second >> V[i].second;
    vector<vector<bool>> inter(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inter[i][j] = check(V[i], V[j]);
        }
    }

    int ans = 1 << 28;
    for (int i = 0; i < N; i++) {
        vector<bool> used(N);
        ans = min(ans, S * S * 6 * K - dfs(inter, used, i, 0, 0, -1));
    }

    if (ans == 1 << 28) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    while (cin >> N >> K >> S, N || K || S) {
        solve();
    }

    return 0;
}

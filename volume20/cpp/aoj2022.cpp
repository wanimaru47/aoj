#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> Vp;
typedef vector<Vp> Mp;

int N;
int objective_flag;
int objective_number;
vector<string> s;
vector<int> in_count;
string longest = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
string ans;

void dfs(Mp& up, int now, int point, string str, int used) {
    str += string(s[now].begin() + point, s[now].end());
    for (int i = 0; i < N; i++) {
        if (objective_flag & (1<<i) && ~used & (1<<i)) {
            if (str.find(s[i]) != string::npos)
                used |= (1 << i);
        }
    }
    if ((~used & objective_flag) == 0) {
        if (str.size() < ans.size() || (ans.size() == str.size() && str < ans)) ans = str;
    }

    if (ans.size() < str.size()) return ;

    auto res = ans;

    for (int i = 0, len = up[now].size(); i < len; i++) {
        int next = up[now][i].first;
        int npoint = up[now][i].second;

        if (used & (1 << next)) continue;
        dfs(up, next, npoint, str, used | (1 << next));
    }

    if (up[now].size() == 0) {
        for (int i = 0; i < N; i++) {
            if (objective_flag & (1 << i) && ~used & (1<<i)) {
                dfs(up, i, 0, str, used | (1<<i));
            }
        }
    }
}

void solve() {
    s.resize(N);
    for (auto& i : s) cin >> i;
    in_count.resize(0);
    in_count.resize(N);
    sort(s.begin(), s.end());

    Mp unite_point(N);
    vector<bool> erased(N, false);
    objective_flag = 0;
    objective_number = 0;
    for (int i = 0; i < N; i++) {
        if (!erased[i]) objective_flag |= (1<<i);
        if (erased[i])objective_number++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i == j) continue;
            if (erased[i] || erased[j]) continue;
            int K = 0;
            for (int k = 1, len = min(s[i].size(), s[j].size()); k < len; k++) {
                auto s1 = string(s[i].end() - k, s[i].end());
                auto s2 = string(s[j].begin(), s[j].begin() + k);
                if (s1 == s2) {
                    K = max(k, K);
                    in_count[j]++;
                }
            }
            unite_point[i].push_back(P(j, K));
        }
    }

    ans = longest;
    for (int i = 0; i < N; i++) {
        if (!erased[i]) {
            dfs(unite_point, i, 0, "", 1 << i);
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}

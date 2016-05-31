#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

int N;
vector<string> A, B;
string y, s;

string sed(string str, string pattern, string object) {
    string ret;
    while (str.find(pattern) != string::npos) {
        ret += string(str.begin(), str.begin() + str.find(pattern));
        ret += object;
        str = string(str.begin() + str.find(pattern) + pattern.size(), str.end());
    }

    return ret + str;
}

int dfs(string str, int d) {
    if (str.size() >= s.size()) {
        if (str == s) return d;
        else return INF;
    }

    int ret = INF;
    for (int i = 0; i < N; i++) {
        string tmp = sed(str, A[i], B[i]);
        if (tmp == str) continue;
        ret = min(ret, dfs(tmp, d + 1));
    }

    return ret;
}

void solve() {
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    cin >> y >> s;

    int ret = dfs(y, 0);
    if (ret == INF) cout << -1 << endl;
    else cout << ret << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}

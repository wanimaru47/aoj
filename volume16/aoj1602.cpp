#include <bits/stdc++.h>
using namespace std;

int N;

int dfs(vector<string> s) {

    char op = s[0][0];
    int ans;
    if (op == '+') {
        ans = 0;
        auto s_ = s;
        s_.erase(s_.begin());
        for (auto& i : s_)
            i = string(i.begin() + 1, i.end());
        vector<string> tmp;
        for (auto i : s_) {
            if ('0' <= i[0] && i[0] <= '9') {
                if (tmp.size() > 0) ans += dfs(tmp);
                ans += (int)(i[0] - '0');
                tmp.resize(0);
            } else if (i[0] == '*' || i[0] == '+') {
                if (tmp.size() > 0) ans += dfs(tmp);
                tmp.resize(0);
                tmp.push_back(i);
            } else {
                tmp.push_back(i);
            }
        }
        if (tmp.size() > 0)
            ans += dfs(tmp);
    }
    else if (op == '*') {
        ans = 1;
        auto s_ = s;
        s_.erase(s_.begin());
        for (auto& i : s_)
            i = string(i.begin() + 1, i.end());
        vector<string> tmp;
        for (auto i : s_) {
            if ('0' <= i[0] && i[0] <= '9') {
                if (tmp.size() > 0) ans *= dfs(tmp);
                ans *= (int)(i[0] - '0');
                tmp.resize(0);
            } else if (i[0] == '+' || i[0] == '*') {
                if (tmp.size() > 0) ans *= dfs(tmp);
                tmp.resize(0);
                tmp.push_back(i);
            } else {
                tmp.push_back(i);
            }
        }
        if (tmp.size() > 0)
            ans *= dfs(tmp);
    }
    else {
        ans = (int)(op - '0');
    }

    return ans;
}

void solve() {
    vector<string> v(N);
    for (auto& i : v) cin >> i;

    cout << dfs(v) << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}

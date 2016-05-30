#include <bits/stdc++.h>
using namespace std;

int N;

string Input(map<string, set<string> >& m) {
    string str;
    int count = 0;
    stringstream ss;
    cin >> str;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == ':' || str[i] == ',' || str[i] == '.') {
            count++;
            str[i] = ' ';
        }
    }

    ss << str;
    string top;
    ss >> top;
    for (int i = 0; i < count - 1; i++) {
        string s;
        ss >> s;
        m[top].insert(s);
    }

    return top;
}

void solve() {
    map<string, set<string> > m;
    vector<string> sSet(N);
    for (int i = 0; i < N; i++) sSet[i] = Input(m);

    set<string> ans;
    queue<string> que;
    for (auto i : m[sSet[0]]) que.push(i);
    map<string,bool> used;
    while (que.size()) {
        string str = que.front(); que.pop();
        used[str] = true;
        if (m.find(str) == m.end()) ans.insert(str);
        else {
            for (auto i : m[str])
                if (used.find(i) == used.end()) que.push(i);
        }
    }

    cout << ans.size() << endl;
}

int main() {
    while (cin >> N, N) solve();

    return 0;
}

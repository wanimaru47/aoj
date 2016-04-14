#include <bits/stdc++.h>
using namespace std;

map<string,bool> m;

bool check(string str) {
    // cout << "# " << str << endl;
    if (m.find(str) != m.end()) return m[str];
    if (str == "S") return true;
    bool res = false;
    if (str.find("()") != string::npos) {
        string next =
            string(str.begin(), str.begin() + str.find("()"))
            + "S"
            + string(str.begin() + str.find("()") + 2, str.end());
        res |= check(next);
    }
    if (str.find("(S)") != string::npos) {
        string next =
            string(str.begin(), str.begin() + str.find("(S)"))
            + "S"
            + string(str.begin() + str.find("(S)") + 3, str.end());
        res |= check(next);
    }
    if (str.find(")(") != string::npos) {
        string next =
            string(str.begin(), str.begin() + str.find(")("))
            + "S"
            + string(str.begin() + str.find(")(") + 2, str.end());
        res |= check(next);
    }
    if (str.find(")S(") != string::npos) {
        string next =
            string(str.begin(), str.begin() + str.find(")S("))
            + "S"
            + string(str.begin() + str.find(")S(") + 3, str.end());
        res |= check(next);
    }
    if (str.find("SS") != string::npos) {
        string next =
            string(str.begin(), str.begin() + str.find("SS"))
            + "S"
            + string(str.begin() + str.find("SS") + 2, str.end());
        res |= check(next);
    }

    return m[str] = res;
}

int main() {
    int N;
    cin >> N;
    string s;
    int left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        int n, p;
        char c;
        cin >> p >> c >> n;

        if (c == '(') left += n;
        else right += n;

        for (int i = 0; i < n; i++) {
            s.insert(s.begin() + p, c);
        }

        if (right == left && check(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

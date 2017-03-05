#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string sb, tb;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2) sb += s[i];
        else tb += s[i];
    }

    bool ans = false;
    int c = 0;
    for (int i = 0; i < t.size(); i++) {
        if (sb[c] == t[i]) c++;
    }
    if (c == sb.size()) ans = true;
    c = 0;
    for (int i = 0; i < t.size(); i++) {
        if (tb[c] == t[i]) c++;
    }
    if (c == tb.size()) ans = true;

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}

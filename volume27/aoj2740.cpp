#include <bits/stdc++.h>
using namespace std;

pair<int,int> get_mid(string t) {
    int mid_s = t.size();
    int mid_e = 0;

    for (int i = 1, c = 1; i < t.size(); i++) {
        if (t[i] == ')') c--;
        else if (t[i] == '(') c++;
        else if (!c) {
            mid_s = min(mid_s, i);
            mid_e = max(mid_e, i);
        }
    }

    return make_pair(mid_s, mid_e);
}

pair<string,string> get_subtree(string t, int mid_s, int mid_e) {
    string a;
    string b;

    a = string(t.begin() + 1, t.begin() + mid_s -1);
    b = string(t.begin() + mid_e + 2, t.end() - 1);

    return make_pair(a,b);
}

string get_tree(string a, string b) {
    if (a.size() == 0 || b.size() == 0) {
        return "";
    }

    auto ma = get_mid(a);
    auto sta = get_subtree(a, ma.first, ma.second);

    auto mb = get_mid(b);
    auto stb = get_subtree(b, mb.first, mb.second);

    stringstream ss, cc;
    ss << string(a.begin() + ma.first + 1, a.begin() + ma.second)
        + " "
        + string(b.begin() + mb.first + 1, b.begin() + mb.second);

    int A, B;
    ss >> A >> B;
    cc << (A+B);
    string m;
    cc >> m;

    string ret = "(" + get_tree(sta.first, stb.first) + ")["
        + m + "](" + get_tree(sta.second, stb.second) + ")";

    return ret;
}


int main() {
    string a, b;
    cin >> a >> b;

    cout << get_tree(a, b) << endl;

    return 0;
}

#include <bits/st dc++.h>
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
    b = string(t.begin() + mid_e + 1, t.end() - 1);

    return make_pair(a,b);
}

string get_tree(string t) {
    string ret;

    auto m = get

    return ret;
}


int main() {
    string a, b;
    cin >> a >> b;

    cout << get_tree(a, b) << endl;

    return 0;
}

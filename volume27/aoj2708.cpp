#include <bits/stdc++.h>
using namespace std;

vector<int> idx(string str) {
    vector<int> res;
    for (int i = 0; i < str.size() - 2; i++) {
        if (str[i] == 'A' && str[i+1] == 'B' && str[i+2] == 'C')
            res.push_back(i);
    }

    return res;
}

bool dfs(string str) {
    if (str == "ABC") return true;
    if (str.size() < 3) return false;

    string next;
    int n = str.size();
    int flag = 0;
    auto d = idx(str);

    if (d.size() == 0) return false;
    d.push_back(n);

    for (int i = 0, x = 0; i < n; i++) {
        if (d[x] + 2 < i) x++;
        if (i < d[x]) {
            if (str[i] == 'A') flag |= 1;
            else if (str[i] == 'B') flag |= (1<<1);
            else flag |= (1<<2);
        }
    }

    char x;
    if (flag == 3) x = 'C';
    else if (flag == 6) x = 'A';
    else if (flag == 5) x = 'B';
    else return false;

    for (int i = 0, c = 0; i <= n; i++) {
        if (d[c] + 2 < i) c++, next += x;
        if (i == n) break;
        if (i < d[c]) next += str[i];
    }

    return dfs(next);
}

int main() {
    string str;
    cin >> str;
    
    cout << (dfs(str) ? "Yes" : "No") << endl;

    return 0;
}

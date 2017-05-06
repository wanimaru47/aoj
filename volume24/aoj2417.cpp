#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<string> vs = {"w", "", "k", "s", "t", "n", "h", "m", "y", "r"};

    for (int i = 0; i < str.size(); i += 2) {
        int c = str[i] - '0';
        if (str[i+1] == 'R') cout << vs[c] + "e";
        if (str[i+1] == 'T') cout << vs[c] + "a";
        if (str[i+1] == 'L') cout << vs[c] + "i";
        if (str[i+1] == 'U') cout << (c == 0 ? "nn" : (vs[c] + "u"));
        if (str[i+1] == 'D') cout << vs[c] + "o";
    }
    cout << endl;

    return 0;
}

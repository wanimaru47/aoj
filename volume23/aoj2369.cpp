#include <bits/stdc++.h>
using namespace std;

bool dfs(string str) {
    if (str == "mew") return true;

    for (int i = 1; i < str.size() - 3; i++) {
        string tmp = string(str.begin() + i, str.begin() + i + 3);
        if (tmp == "mew" && ((str[i - 1] == 'm' && str[i + 3] == 'e') || (str[i - 1] == 'e' && str[i + 3] == 'w'))) {
            return dfs(string(str.begin(), str.begin() + i) + string(str.begin() + i + 3, str.end()));
        }
    }

    return false;
}

int main () {
    string str;
    cin >> str;
    if (dfs(str)) cout << "Cat" << endl;
    else cout << "Rabbit" << endl;

    return 0;
}

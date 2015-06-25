#include <bits/stdc++.h>
using namespace std;

vector<string> str;
int n;
string res;

void dfs ( int b ) {
    if ((1 << n) - 1 == b) {

        return ;
    }

    for (int i = 0; i < n; i++) {

    }
}

int main () {
    while (cin >> n , n) {
        str.resize(n);
        res = "";
        for (auto &i : str) {
            cin >> i;
            res += i;
        }

        dfs (0);
    }
    
    return 0;
}

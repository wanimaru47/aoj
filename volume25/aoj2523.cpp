#include <bits/stdc++.h>
using namespace std;

int N, T;

long long int calc(int x) {
    long long int t = 1LL;
    for (int i = 0; i < x; i++) {
        t *= N;
        if (t * T > 1e9) break;
    }

    return t * T;
}

int main() {
    cin >> N >> T;
    string str;
    cin >> str;

    str+="+";

    vector<string> vs;
    for (int i = 0, pre = -1; i < (int)str.size(); i++) {
        if (str[i] == '+' ) {
            vs.push_back(string(str.begin() + pre + 1, str.begin() + i));
            pre = i;
        }
    }

    long long int sum = 0;
    for (int i = 0; i < (int)vs.size(); i++) {
        sum += calc(vs[i][2] - '0');
        if (sum > 1e9) break;
    }

    if (sum <= 1e9) {
        cout << sum << endl;
    }
    else {
        cout << "TLE" << endl;
    }

    return 0;
}

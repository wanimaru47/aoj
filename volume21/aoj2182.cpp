#include <bits/stdc++.h>
using namespace std;

string str;
int v[80001];
int d[80001];
int sum[80001];

int solve() {
    for (int i = 0; i < str.size(); i++) {
        int c = str[i] - '0';
        if (i % 2 == 0) {
            v[i] = c + (i ? v[i-1] : 0);
            d[i] = (i ? d[i-1] : 0);
        } else {
            d[i] = c + (i ? d[i-1] : 0);
            v[i] = (i ? v[i-1] : 0);
        }
    }

    for (int i = 0; i < str.size(); i++) {
        sum[i] = (11 + (((v[i] - d[i]) % 11))) % 11;
    }

    int m[11] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ans += m[sum[i]];
        if (i + 1 < str.size() && (str[i+1] - '0') != 0) {
            m[sum[i]]++;
        }
    }

    return ans;
}

int main() {
    while (cin >> str, str != "0") cout << solve() << endl;

    return 0;
}

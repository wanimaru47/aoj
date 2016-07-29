#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    map<int,char> m;
    m[0] = '0';
    m[1] = '1';
    m[2] = '2';
    m[3] = '3';
    m[4] = '5';
    m[5] = '7';
    m[6] = '8';
    m[7] = '9';
    while (cin >> N, N) {
        string ans;
        while (N) {
            int mod = N % 8;
            ans = m[mod] + ans;
            N /= 8;
        }
        cout << ans << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
    for (int i = 1; i < 1000001; i++) {
        int num = i;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        if (num == 1) dp[i] = 1;
        dp[i] += dp[i-1];
    }

    int M, N;
    while (cin >> M, M) {
        cin >> N;
        cout << dp[N] - dp[M-1] << endl;
    }


    return 0;
}

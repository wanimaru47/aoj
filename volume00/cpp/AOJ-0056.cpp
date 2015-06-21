#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 50000
using namespace std;

int dp[MAX + 1];
int prm[MAX + 1];

int main()
{
    for (int i = 2; i <= MAX; i++) prm[i] = 1;
    for (int i = 2; i <= MAX; i++)
        for (int j = 2; j * i <= MAX; j++)
            prm[i * j] = 0;
    int n;
    for (int i = 0; i <= MAX; i++)
        for (int j = i; j + i<= MAX; j++)
            if (prm[i] == 1 && prm[j] == 1) dp[i + j]++;
    while (cin >> n, n > 0) {
        cout << dp[n] << endl;
    }

    return 0;
}

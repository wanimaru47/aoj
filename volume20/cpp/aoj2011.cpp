#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 30
using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        int date[N][MAX];
        int dp[N][MAX];
        int tmp[MAX];
        memset(dp, 0, sizeof(dp));
        memset(tmp, 0, sizeof(tmp));
        for  (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            date[i][0] = n;
            for (int f = 1; f <= n; f++) {
                cin >> date[i][f];
                tmp[dp[i][f]]++;
            }
        }
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < N; j++)
                ;
            
    }

    return 0;
}

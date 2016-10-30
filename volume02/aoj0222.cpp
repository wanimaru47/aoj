#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        if (N < 19) cout << 13 << endl;
        else {
            for (int i = (N-19)/30; i > -1; i--) {
                int num = (i*30+19);
                int sq = sqrt((N-19)/30*30+19);
                bool flag = true;
                for (int j = 2; flag && j <= sq; j++) {
                    if (num - 8 > 0 && ((num-8)%j==0 || (num-6)%j==0 || (num-2)%j==0 || num%j==0)) flag = false;
                }
                if (flag) {
                    cout << num << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

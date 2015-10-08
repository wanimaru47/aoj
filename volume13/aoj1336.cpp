#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main () {
    int N, L;
    while (cin >> N >> L, N || L) {
        vec V[2];
        V[0].resize(L + 2);
        V[1].resize(L + 2);

        for (int i = 1; i <= N; i++) {
            char d; int p;
            cin >> d >> p;
            if (d == 'R') {
                V[1][p] = i;
            } else {
                V[0][p] = i;
            }
        }
        bool flag = true;
        int ans = -1;
        int t = -1;
        for (int k = 0; k <= L; k++) {
            for (int i = 1; i <= L + 1; i++) 
                V[0][i-1] = V[0][i];
            for (int i = L + 1; i > 0; i--)
                V[1][i] = V[1][i-1];
            for (int i = 1; i <= L; i++) {
                if (V[0][i] > 0 && V[1][i] > 0) {
                    int tmp = V[0][i];
                    V[0][i] = V[1][i];
                    V[1][i] = tmp;
                }
            }
//          for (int i = 0; i < L + 2; i++) {
//              cout << i <<  ">>" << V[0][i] << " " << V[1][i] << endl;
//          }
//          cout  << " " << t << " " << ans << endl;
//          cout << endl << endl;
            if (V[0][1] > 0) t = k + 2, ans = V[0][1];
            else if (V[1][L-1] > 0) t = k + 2, ans = V[1][L-1];
        }
        cout << t << " " << ans << endl;
//      cout << endl << endl;
    }

    return 0;
}

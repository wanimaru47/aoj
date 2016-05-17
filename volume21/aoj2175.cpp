#include <bits/stdc++.h>
using namespace std;

int main() {
    char T;
    while (cin >> T, T != '#') {
        int table[4][13];
        char suit[4][13];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                char a, b;
                cin >> a >> b;
                suit[i][j] = b;
                if ('0' <= a && a <= '9') table[i][j] = a - '0';
                else if (a == 'A') table[i][j] = 14;
                else if (a == 'T') table[i][j] = 10;
                else if (a == 'J') table[i][j] = 11;
                else if (a == 'Q') table[i][j] = 12;
                else if (a == 'K') table[i][j] = 13;
                if (b == T) table[i][j] += 14;
            }
        }

        int ns = 0;
        int we = 0;

        int leader = 0;
        for (int i = 0; i < 13; i++) {
            char suit_ = suit[leader][i];
            int max_ = table[leader][i];
            for (int j = 0; j < 4; j++) {
                if ((suit_ == suit[j][i] || T == suit[j][i]) && table[j][i] > max_) {
                    max_ = table[j][i];
                    leader = j;
                }
            }
            if (leader % 2) we++;
            else ns++;
        }

        if (ns > we) cout << "NS " << ns - 6 << endl;
        else cout << "EW " << we - 6 << endl;
    }

    return 0;
}

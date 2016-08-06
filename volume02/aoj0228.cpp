#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<string> str(10);
    str[0] = "0111111";
    str[1] = "0000110";
    str[2] = "1011011";
    str[3] = "1001111";
    str[4] = "1100110";
    str[5] = "1101101";
    str[6] = "1111101";
    str[7] = "0100111";
    str[8] = "1111111";
    str[9] = "1101111";

    while (cin >> N, N != -1) {
        int s;
        string start = "0000000";
        while (N--) {
            cin >> s;
            for (int i = 0; i < 7; i++) {
                if (str[s][i] == '1') {
                    if (start[i] == '1') cout << '0';
                    else cout << '1';
                } else {
                    if (start[i] == '0') cout << '0';
                    else cout << '1';
                }
            }
            cout << endl;
            start = str[s];
        }
    }

    return 0;
}

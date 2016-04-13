#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    vector<vector<string>> invalid(2, vector<string>(10));
    invalid[0][1] = "23968";
    invalid[0][2] = "369";
    invalid[0][3] = "";
    invalid[0][6] = "";
    invalid[0][9] = "";
    invalid[0][8] = "369";
    invalid[0][7] = "23698";
    invalid[0][4] = "23698";
    invalid[1][1] = "";
    invalid[1][4] = "";
    invalid[1][7] = "";
    invalid[1][2] = "147";
    invalid[1][8] = "147";
    invalid[1][3] = "78412";
    invalid[1][6] = "78412";
    invalid[1][9] = "78412";
    while (cin >> str, str != "#") {
        int rcount = 0;
        int lcount = 0;
        int r = 1;
        int l = 0;
        for (int i = 0; i < str.size() - 1; i++) {
            if (invalid[r % 2][(int)(str[i] - '0')].find(str[i + 1]) != string::npos) {
                rcount++;
                r--;
            }
            if (invalid[l % 2][(int)(str[i] - '0')].find(str[i + 1]) != string::npos) {
                lcount++;
                l--;
            }

            r++, l++;
        }

        cout << min(rcount, lcount) << endl;
    }

    return 0;
}

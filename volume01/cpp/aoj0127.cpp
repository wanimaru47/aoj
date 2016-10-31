#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    vector<string> vs = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z.?! "};
    while (cin >> str) {
        if (str.size() % 2) {
            cout << "NA" << endl;
            continue;
        }
        string ans;
        for (int i = 0; i < str.size(); i+=2) {
            int a = str[i] - '0' - 1;
            int b = str[i+1] - '0' - 1;

            if (0 <= a && a < 6 && 0 <= b && b < 5) {
                ans += vs[a][b];
            } else {
                ans = "NA";
                break;
            }
         }

        cout << ans << endl;
    }

    return 0;
}

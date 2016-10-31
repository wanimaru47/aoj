#include <bits/stdc++.h>
using namespace std;

string sub(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    string res;
    for (int i = 0, c = 0; c || i < max(l1, l2); i++) {
        int tmp = c;
        if (l1 - 1 - i > -1) tmp += (s1[l1 - 1 - i] - '0');
        if (l2 - 1 - i > -1) tmp += (s2[l2 - 1 - i] - '0');

        c = tmp / 10;

        tmp %= 10;

        res = (char)('0' + tmp) + res;
    }

    return res;
}

int main() {
    string str;
    while (cin >> str) {
        int ans = -1;
        for (int i = 0; i < 10; i++) {
            string tmp = str;
            for (auto& j : tmp) if (j == 'X') j = '0' + i;
            bool flag = true;
            // for (int j = 0; j < tmp.size(); j++) {
            //     if (j == 0 && tmp[0] == '0') flag = false;
            //     if (j > 0 && tmp[j-1] == '+' && tmp[j] == '0') flag = false;
            //     if (j > 0 && tmp[j-1] == '=' && tmp[j] == '0') flag = false;
            // }
            if (!flag) continue;
            string a, b, c;
            a = string(tmp.begin(), tmp.begin() + tmp.find('+'));
            b = string(tmp.begin() + tmp.find('+') + 1, tmp.begin() + tmp.find('='));
            c = string(tmp.begin() + tmp.find('=') + 1, tmp.end());

            string p = sub(a, b);

            if (c == p) {
                ans = i;
                break;
            }
        }
        if (ans < 0) cout << "NA" << endl;
        else cout << ans << endl;
    }

    return 0;
}

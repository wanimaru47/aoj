#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        string ans;
        ans += str[0];
        int corsor = 0;
        for (int i = 1; i * 3 + 1 <= str.size(); i++) {
            auto pre = string(str.begin() + (i-1)*3+1, str.begin() + (i-1)*3+3);
            if (pre == "<-") corsor--;
            else corsor++;

            if (corsor < 0) corsor = 0, ans = str[i*3] + ans;
            if (corsor >= ans.size()) ans += str[i*3];

        }
        cout << ans << endl;
    }

    return 0;
}

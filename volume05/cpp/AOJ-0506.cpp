#include <bits/stdc++.h>
using namespace std;

string _itoa(int num) {
    string res = "";
    while (num) {
        int mod = num % 10;
        char n = '0' + mod;
        res = n + res;
        num /= 10;
    }

    return res;
}

int main() {
    int n;
    while (cin >> n, n) {
        string str;
        cin >> str;

        for (int c = 0; c < n; c++) {
            char num = str[0];
            int count = 0;
            string tmp = "";
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == num) count++;
                else {
                    string s = _itoa(count);
                    tmp += (s + num);
                    num = str[i];
                    count = 1;
                }
            }
            str = tmp;
            if (count > 0) {
                string s = _itoa(count);
                str += (s + num);
            }
        }
        cout << str << endl;
    }

    return 0;
}

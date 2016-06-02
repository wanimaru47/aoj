#include <bits/stdc++.h>
using namespace std;

vector<string> opr{"->", "+", "*", "-"};
vector<string> num{"1", "2", "3", "4"};

bool calc(string exp, int bits) {
    // cout << exp << endl;
    if (exp == "T") return true;
    if (exp == "F") return false;
    if ('a' <= exp[0] && exp[0] <= 'k') return (bits & (1 << (exp[0] - 'a')) ? true : false);
    if (exp[0] == '4') return !calc(string(exp.begin() + 1, exp.end()), bits);

    int idx = -1;
    for (int i = (exp[0] == '(' ? 1 : 0), count = 0, len = exp.size() - (exp[0] == '(' ? 1 : 0); i < len; i++) {
        if (exp[i] == '(') count++;
        else if (exp[i] == ')') count--;
        if (count == 0 && '1' <= exp[i] && exp[i] <= '3') {
            idx = i;
            break;
        }
    }

    if (exp[0] == '(') {
        auto exp1 = string(exp.begin() + 1, exp.begin() + idx);
        auto exp2 = string(exp.begin() + idx + 1, exp.end() - 1);
        if (exp[idx] == '1') return !(calc(exp1, bits) && !calc(exp2, bits));
        if (exp[idx] == '2') return calc(exp1, bits) | calc(exp2, bits);
        if (exp[idx] == '3') return calc(exp1, bits) & calc(exp2, bits);
    }
}

void solve(string str) {
    bool flag = true;
    for (int i = 0, len = opr.size(); i < len; i++) {
        auto idx = str.find(opr[i]);
        while (idx != string::npos) {
            str.replace(idx, (int)opr[i].size(), num[i]);
            idx = str.find(opr[i]);
        }
    }
    int eq_idx = str.find("=");

    string exp1 = string(str.begin(), str.begin() + eq_idx);
    string exp2 = string(str.begin() + eq_idx + 1, str.end());
    for (int i = 0; i < (1 << 11); i++) {
        if (calc(exp1, i) != calc(exp2, i)) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    string str;
    while (cin >> str, str != "#") solve(str);

    return 0;
}

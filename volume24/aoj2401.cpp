#include <bits/stdc++.h>
using namespace std;

vector<string> opr{"->", "+", "*", "-"};
vector<string> num{"1", "2", "3", "4"};

void add_para(string exp) {
    auto find_idx = exp.find("4");
    while (find_idx != string::npos) {
        if (exp[find_idx + 1] == "(") {
            int end_idx = find_idx + 2;
            int count = 1;
            while (count) {
                if (exp[end_idx] == '(') count++;
                else if (exp[end_idx] == ')') count++;
                end_idx++;
            }
            exp.insert(end_idx, ")");
            exp[find_idx] = '5';
            exp.insert(find_idx, "(");
        } else {
            exp.insert(find_idx + 2, ")");
            exp[find_idx] = '5';
            exp.insert(find_idx, "(");
        }

        find_idx = exp.find("4");
    }
}

bool calc(string exp, int bits) {
    if (exp == "T") return true;
    else if (exp == "F") return false;
    else if (exp.size() == 1) {
        if (bits & (1 << (exp[0] - 'a'))) return true;
        else return false;
    }

    if (exp[1] == '5') return !calc(string(exp.begin() + 2, exp.end() - 1));
    int idx;
    for (int i = 0, len = exp.size(), count = 0; i < len; i++) {
        if (exp[i] == '(') count++;
        else if (exp[i] == ')') count--;
    }
}

void solve(string str) {
    for (int i = 0, len = opr.size(); i < len; i++) {
        auto find_idx = str.find(opr[i]);
        while (find_idx != string::npos) {
            str.repalce(find_idx, (int)opr[i].size(), num[i]);
            find_idx = str.find(opr[i]);
        }
    }
    int eq_idx = str.find("=");
    string exp1 = string(str.begin(), str.begin() + eq_idx);
    string exp2 = string(str.begin() + eq_idx + 1, str.end());

    for (int i = 0; i < (1 << 11); i++) {
        bool flag = true;
        if (calc(exp1, i) != calc(exp2, i)) {
            flag = false;
            break;
        }
    }

    if (flag == true) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    string Input;
    while (cin >> Input, Input != "#") solve(Input);

    return 0;
}

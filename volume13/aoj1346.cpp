#include <bits/stdc++.h>
using namespace std;

string str;
int ans;

int ruleM (string ex) {
    int num = ex[0] - '0';
    for (int i = 1; i < ex.size(); i += 2) {
        if (ex[i] == '*') {
            num *= ex[i + 1] - '0';
        } else {
            string tmp = string(ex.begin() + i + 1, ex.end());
            num += ruleM(tmp);
            break;
        }
    }

    return num;
}

bool ruleL (string ex) {
    int num = ex[0] - '0';
    for (int i = 1; i < ex.size(); i += 2) {
        if (ex[i] == '+') {
            num += ex[i+1] - '0';
        } else {
            num *= ex[i+1] - '0';
        }
    }

    return num == ans;
}

int main () {
    cin >> str >> ans;

    bool m = ruleM(str) == ans, l = ruleL(str);
    if (!l && m) {
        cout << "M" << endl;
    } else if (!m && l) {
        cout << "L" << endl;
    } else if (m && l) {
        cout << "U" << endl;
    } else {
        cout << "I" << endl;
    }
    
    return 0;
}

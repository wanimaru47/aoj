#include <bits/stdc++.h>
using namespace std;

string op = "+*()";

int calc (string exp) {
    if (exp[0] == '(') {
        int count = 0;
        string lhs_;
        for (int i = 1; count || (exp[i] != '*' && exp[i] != '+'); i++) {
            lhs_ += exp[i];
            if (exp[i] == '(') count++;
            if (exp[i] == ')') count--;
        }
        int lhs = calc(lhs_);
        char op = exp[lhs_.size() + 1];
        count = 0;
        string rhs_;
        for(int i = lhs_.size()+2;; i++) {
            if (exp[i] == '(') count++;
            if (exp[i] == ')') if (count == 0) break; else count--;
            rhs_ += exp[i];
        }
        int rhs = calc(rhs_);
        if (op == '*') return min(lhs,rhs);
        else return max(rhs,lhs);
        
    } else {
        int count = 0;
        int i = 0;
        while (exp[i] == '-') i++, count++;
        int num;
        if (exp[i] == '(') num = calc(string(exp.begin()+i, exp.end()));
        else num = atoi(&exp[i]);

        if (num == 1) return 1;
        else if (count % 2) return num == 2 ? 0 : 2;
        else return num;
        
    }
}

int main () {
    string str;
    while (cin >> str, str != ".") {
        int res = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    string tmp(str.begin(), str.end());
                    for (int c = 0; c < str.size(); c++) {
                        if (tmp[c] == 'P') tmp[c] = ('0' + i);
                        if (tmp[c] == 'Q') tmp[c] = ('0' + j);
                        if (tmp[c] == 'R') tmp[c] = ('0' + k);
                    }
                    if (calc(tmp) == 2) res++; 
                }
            }
        }

        cout << res << endl;
    }
    
    return 0;
}

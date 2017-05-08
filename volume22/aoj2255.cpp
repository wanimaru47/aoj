#include <bits/stdc++.h>
using namespace std;

set<int> solve(string exp) {
    vector<int> idx;
    map<int, int> rev;
    for (int i = 0, c = 0; i < exp.size(); i++) {
        if (exp[i] == '(')
            c++;
        if (exp[i] == ')')
            c--;
        if (c == 0 && (exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-')) {
            rev[i] = idx.size();
            idx.push_back(i);
        }
    }

    if(idx.size() == 0) {
        if (exp[0] == '(') return solve(string(exp.begin()+1, exp.end()-1));
        stringstream ss;
        ss << exp;
        int num;
        ss >> num;
        set<int> ans;
        ans.insert(num);
        return ans;
    }

    vector<set<int> > res(idx.size() + 1);
    for (int i = 0; i < idx.size() + 1; i++) {
        int l = i == 0 ? 0 : idx[i - 1] + 1;
        int r = i == idx.size() ? exp.size() : idx[i];
        res[i] = solve(string(exp.begin() + l, exp.begin() + r));
    }


    set<int> ans;
    do {
        vector<set<int> > ret = res;
        vector<int> ridx(idx.size());
        for (int i = 0; i < idx.size(); i++) {
            ridx[rev[idx[i]]] = i;
        }
        for (int i = 0; i < idx.size(); i++) {
            int l = -1;
            int r = rev[idx[i]] + 1;
            set<int> num;
            for (int j = rev[idx[i]]-1, ml = -1; j >= 0 && i > ridx[j]; j--)
                if (ml < ridx[j]) {ml = ridx[j], l = j;}
            if (l == -1) l = rev[idx[i]];
            for (int j = r, mr = -1; j < idx.size() && i > ridx[j]; j++)
                if (mr < ridx[j]) {mr = ridx[j], r = j;}
             for (auto lhs : ret[l]) {
                for (auto rhs : ret[r]) {
                    if (exp[idx[i]] == '+')
                        num.insert(lhs + rhs);
                    if (exp[idx[i]] == '-')
                        num.insert(lhs - rhs);
                    if (exp[idx[i]] == '*')
                        num.insert(lhs * rhs);
                    if (exp[idx[i]] == '/') {
                        if (rhs == 0)
                            continue;
                        num.insert(lhs / rhs);
                    }
                }
            }

            ret[rev[idx[i]]] = num;
        }

        for (auto i : ret[rev[idx[idx.size()-1]]]) ans.insert(i);
    } while (next_permutation(idx.begin(), idx.end()));

    return ans;
}

int main() {
    string str;
    while (cin >> str, str != "#")
        cout << solve(str).size() << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
auto isalf = [](char c) {if ('A' <= c && c <= 'Z') return true; return false; };
auto isnum = [](char c) {if ('0' <= c && c <= '9') return true; return false; };
auto ispare = [](char c) {if (c == '(') return 1; if (c == ')') return -1; return 0; };

string S;
int N;

string dfs(string s) {
    string res = "";

    int i;
    for (i = 0; i < s.size(); i++) {
        if (isalf(s[i])) res += s[i];
        else break;
    }

    string num = "";


    string tmp(s.begin() + i, s.end());

    if (tmp.size()) {
        res += dfs();
    }
}

int main() {
    while (cin >> S >> N, S != "0" && N != 0) {
        tmp = "";
    }

    return 0;
}

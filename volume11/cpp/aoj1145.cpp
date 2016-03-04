#include <bits/stdc++.h>
using namespace std;
auto isalf = [](char c) {if ('A' <= c && c <= 'Z') return true; return false; };
auto isnum = [](char c) {if ('0' <= c && c <= '9') return true; return false; };
auto ispare = [](char c) {if (c == '(') return 1; if (c == ')') return -1; return 0; };

string S;
int N;

string dfs(string s, int count) {
    if (count > N) return "";
    string res = "";

    if (isalf(s[0])) {
        int i;
        for (i = 0; i < s.size(); i++) {
            if (isalf(s[i])) res += s[i];
            else break;
        }
        
        res += dfs(string(s.being() + i, s.end()), count + res.size());
    } else {
        string num = "";

        int i = 0;
        while (isnum(s[i])) num += s[i++];

        string tmp = "";
        if (ispare(s[i])) { // paretheese
            int j = 0;
            i++;
            while (j > 0) {

            }
        // charactor
    }
}

int main() {
    while (cin >> S >> N, S != "0" && N != 0) {
        tmp = "";
    }

    return 0;
}

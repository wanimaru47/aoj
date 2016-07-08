#include <bits/stdc++.h>
using namespace std;

string str;
string ans;
int N;

int cal(string s) {
    if (s == "") return 1;
    stringstream ss;
    ss << s;
    int ret;
    ss >> ret;
    return ret;
}

string make_str(string s, int left) {
    if (s.size() == 1) return s;

    string ret;
    string ch;
    string num;
    for (int i = 0, len = s.size(), count = 0; i < len; i++) {
        if (!count && '0' <= s[i] && s[i] <= '9') num += s[i];
        else {
            ch += s[i];
            if (s[i] == '(') count++;
            if (s[i] == ')') count--;
            if (count == 0) {
                if(ch.size() > 0 && ch[0] == '(') {
                    ch.erase(ch.begin());
                    ch.erase(ch.end()-1);
                }

                string tmp = make_str(ch, left + ret.size());
                for (int j = 0, len = cal(num); j < len; j++) {
                    if (ret.size() + left > N + 1) break;
                    ret += tmp;
                }
                ch = "";
                num = "";
            }
        }
    }

    return ret;
}

void calc_char(int c, string s, int sum) {
    string ans_str = make_str(s, N - sum);
    string ans_;
    for (int i = 0; i < c; i++) {
        ans_ += ans_str;
        if (ans_.size() > sum + 1) break;
    }
    ans = ans_[sum];
}

int dfs(string s, int left) {
    if (s.size() == 1) return 1;
    int sum = 0;

    string num;
    string ch;
    for (int i = 0, len = s.size(), count = 0; i < len; i++) {
        if (!count && '0' <= s[i] && s[i] <= '9') num += s[i];
        else {
            ch += s[i];
            if (s[i] == '(') count++;
            if (s[i] == ')') count--;
            if (count == 0) {
                int c = cal(num);
                if(ch.size() > 0 && ch[0] == '(') {
                    ch.erase(ch.begin());
                    ch.erase(ch.end()-1);
                }

                int tmp = dfs(ch, sum + left);
                if (tmp < 0) return -1;
                sum += c * tmp;
                if (sum + left > N) {
                    calc_char(c, ch, N - (sum - c * tmp) - left);
                    return -1;
                }
                ch = "";
                num = "";
            }
        }
    }

    return sum;
}

void solve() {
    ans = "0";

    if (str.size() > 1)
        dfs(str, 0);
    else if (N == 0)
        ans = str;

    cout << ans << endl;
}

int main() {
    while (cin >> str >> N, str != "0" || N) solve();

    return 0;
}

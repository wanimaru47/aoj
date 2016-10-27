#include <bits/stdc++.h>
using namespace std;

string get_term(string, int&);
int get_num(string);
int get_exp(string);

int get_num(string str) {
    int num = 0;

    if (str.size() == 0) return 0;

    int i = 0;
    if (str[i] == '(') {
        i++;
        string exp;
        for (int count = 1; count; i++) {
            if (str[i] == '(') count++;
            if (str[i] == ')') count--;
            if (count) exp += str[i];
        }

        num = get_exp(exp + "=");
    } else {
        for (; i < str.size() && '0' <= str[i] && str[i] <= '9'; i++) {
            num = num * 10 + (str[i] - '0');
        }
    }

    for (; i < str.size(); i++) {
        if (str[i] == '*') {
            i++;
            int tmp = 0;
            if (str[i] == '(') {
                i++;
                string exp;
                for (int count = 1; count; i++) {
                    if (str[i] == '(') count++;
                    if (str[i] == ')') count--;
                    if (count) exp += str[i];
                }

                tmp = get_exp(exp + "=");
            } else {
                for (; i < str.size() && '0' <= str[i] && str[i] <= '9'; i++) {
                    tmp = tmp * 10 + (str[i] - '0');
                }
            }
            num *= tmp;
            i--;
        } else {
            i++;
            int tmp = 0;
            if (str[i] == '(') {
                i++;
                string exp;
                for (int count = 1; count; i++) {
                    if (str[i] == '(') count++;
                    if (str[i] == ')') count--;
                    if (count) exp += str[i];
                }

                tmp = get_exp(exp + "=");
            } else {
                for (; i < str.size() && '0' <= str[i] && str[i] <= '9'; i++) {
                    tmp = tmp * 10 + (str[i] - '0');
                }
            }
            num /= tmp;
            i--;
        }
    }

    return num;
}


void solve(string str) {
    cout << get_exp(str) << endl;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string str;
        cin >> str;
        solve(str);
    }

    return 0;
}

string get_term(string str, int& i) {
    string init_str;
    for (int count = 0; i < str.size(); i++) {
        if (str[i] == '(') count++;
        if (count > 0 || ('0' <= str[i] && str[i] <= '9') || str[i] == '/' || str[i] == '*') {
            init_str += str[i];
        }
        if (str[i] == ')') count--;

        if (count == 0 && (str[i] == '+'|| str[i] == '-' || str[i] == '=')) {
            break;
        }
    }

    return init_str;
}

int get_exp(string str) {
    int num  = 0;
    int i = 0;

    string init_str = get_term(str, i);
    num = get_num(init_str);

    while (str[i] != '=') {
        if (str[i] == '-') {
            i++;
            string term = get_term(str, i);
            num -= get_num(term);
        } else if (str[i] == '+') {
            i++;
            string term = get_term(str, i);
            num += get_num(term);
        }
    }

    return num;
}

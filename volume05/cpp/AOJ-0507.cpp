#include <bits/stdc++.h>
using namespace std;

vector<string> s;

void Print(int n, int g, string str) {
    int n_ = 0;
    while (n - n_ >= 0) {
        if (n - n_ == 0) {
            if (n == 0) 
                cout << str << endl;
            break;
        }
        if (g >= n - n_)
            Print(n_, n - n_, str + (str == "" ? "" : " ") + s[n - n_]);
        n_++;
    }
}

int main() {
    for (int i = 0; i <= 30; i++) {
        int num = i;
        string tmp = "";
        while (num) {
            int nn = num % 10;
            char ss = '0' + nn;
            tmp = ss + tmp;
            num /= 10;
        }
        s.push_back(tmp);
    }


    int n;
    while (cin >> n, n) {
        Print(n, n, "");
    }
    
    return 0;
}

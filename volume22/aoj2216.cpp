#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        int a, b, c;
        int sub = M - N;
        c = sub / 1000;
        sub %= 1000;
        b = sub / 500;
        sub %= 500;
        a = sub / 100;

        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}

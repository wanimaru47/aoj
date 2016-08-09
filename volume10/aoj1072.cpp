#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M)
        if (N % 2 == 0 || M % 2 == 0) cout << "yes" << endl;
        else cout << "no" << endl;

    return 0;
}

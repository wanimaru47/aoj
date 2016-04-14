#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    long long int left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        long long int n, p;
        char c;
        cin >> p >> c >> n;

        if (c == '(') left += n;
        else right += n;

        if (right == left) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

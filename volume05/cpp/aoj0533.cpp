#include <bits/stdc++.h>
using namespace std;

int Sum(vector<int>& x) {
    int ret = 0;
    for (int i = 0; i < 3; i++) ret += x[9 - i];
    return ret;
}

int main() {
    vector<int> a(10), b(10);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << Sum(a) << " " << Sum(b) << endl;

    return 0;
}

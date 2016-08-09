#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        vector<int> add;
        int ans = 0;
        for (auto i : v) {
            ans += i;
            add.push_back(ans);
        }

        int sum = 0;
        for (auto i : add) sum += i;
        cout << sum << endl;
    }

    return 0;
}

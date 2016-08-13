#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        int count = 0;
        while (1) {
            bool flag = false;
            for (int i = 0; i < v.size()-1; i++) {
                if (v[i] > v[i+1]) {
                    count++;
                    swap(v[i], v[i+1]);
                    flag = true;
                }
            }
            if (!flag) break;
        }
        cout << count << endl;
    }

    return 0;
}

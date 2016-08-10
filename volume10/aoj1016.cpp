#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, d;
    while (cin >> V >> d) {
        vector<int> fib_mod(V);
        fib_mod[0] = 2;
        fib_mod[1] = 3;
        for (int i = 2; i < V ; i++) {
            fib_mod[i] = fib_mod[i-1] + fib_mod[i-2];
            fib_mod[i] %= 1001;
        }
        sort(fib_mod.begin(), fib_mod.end());
        int count = 1;
        for (int i = 1; i < V; i++) {
            if (fib_mod[i] - fib_mod[i-1] >= d) count++;
        }
        cout << count << endl;
    }

    return 0;
}

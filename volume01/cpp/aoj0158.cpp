#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        
        function<int(int)> count = [&](int x) -> int {
            if (x == 1) return 0;

            if (x % 2) x = x * 3 + 1;
            else x /= 2;
            return count(x) + 1; 
        };
        
        cout << count(n) << endl;
    }

    return 0;
}

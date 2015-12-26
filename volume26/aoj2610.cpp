#include <bits/stdc++.h>
using namespace std;

vector<bool> v(100000, true);
vector<int> prime;

int main() {
    int n;
    cin >> n;

    if (n >= 3) cout << 0 << endl;
    else if (n == 2) cout << 1 << endl;
    else if (n == 1) cout << 2 << endl;
    else cout << 1 << endl;
    
    return 0;
}

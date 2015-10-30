#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        vector<int> v(7);
        for(int i = 0; i < n; i++) {
            int s; cin >> s;
            if(s / 10 >= 6) {
                v[6]++;
            } else {
                v[s / 10]++;
            }
        }
        for(auto i : v) cout << i << endl;
    }
    
    return 0;
}

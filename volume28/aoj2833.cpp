#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<28;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    vector<int> depth(n, INF);

    int count = 0;
    for (int i = n-1; i >= 0; i--) {
        if (depth[i] == INF) {
            count++;
            depth[i] = 0;
        } else if (depth[i] < k) {
            count++;
        } else if (a[i] == 0) {
            count++;
        }
        
        if (a[i] > 0) {
            depth[a[i]-1] = min(depth[a[i]-1], depth[i] + 1);
        }
    }

    cout << count << endl;

    return 0;
}

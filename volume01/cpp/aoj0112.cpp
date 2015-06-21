#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        vector<long long> n;
        long long t, res = 0;
        while (N--) {
            cin >> t;
            n.push_back(t);
        }
        t = 0;
        sort(n.begin(), n.end());
        for (int i = 0; i < n.size() - 1; i++) {
            t = t + n[i];
            res += t;
        }
        cout << res << endl;
    }
    
    return 0;
}

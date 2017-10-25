#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> t(n+2), f(n+2);
    for (int i = 0; i < n; i++) {
	cin >> t[i+1] >> f[i+1];
    }
    f[0] = 1;

    long long int sum = 0, count = 0;
    for (int i = 1; i <= n; i++) {
	if ( abs(f[i] - f[i-1]) > t[i] - t[i-1]) {
	    cout << -1 << endl;
	    return 0;
	}

	if ( f[i] + f[i-1] - 2 <= t[i] - t[i-1]) {
	    sum += count * (f[i-1] - 1);
	    count = 0;
	} else {
	    sum += count * (t[i] - t[i-1]);
	}

	count++;

	if (count > d) {
	    cout << -1 << endl;
	    return 0;
	}
    }

    cout << sum + count * (f[n] - 1) << endl;

    return 0;
}

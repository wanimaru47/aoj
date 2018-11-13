#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;

    while (cin >> n >> l >> r, n || l || r) {
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int count = 0;
	for (int x = l; x <= r; x++) {
	    int i;
	    for (i = 0; i < n; i++) {
		if (x % a[i] == 0)
		    break;
	    }

	    if ((i < n && i % 2 == 0) || (i >= n && n % 2 == 0))
		count++;
	}

	cout << count << endl;
    }

    return 0;
}

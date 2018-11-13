#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
    lli b;

    while (cin >> b, b) {
	lli t = 0, n = 0;
	lli d = 1;

	while (2LL * b - d * d - d >= 0) {
	    if ((2LL * b - d * d - d) % (2LL * d) == 0) {
		t = d;
		n = (2LL * b - d * d - d) / (2LL * d);
	    }
	    d++;
	}

	cout << n + 1 << " " << t << endl;
    }

    return 0;
}

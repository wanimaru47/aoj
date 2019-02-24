#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		n %= 4;
		if (s[i] == 'R') {
			n++;
		} else {
			n--;
		}
		if (n == 4) {
			ans++;
			n = 0;
		}
	}

	cout << ans << endl;

	return 0;
}

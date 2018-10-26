#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
	vector<int> vec(n);
	for (auto& i : vec) cin >> i;
	int sum = 0;
	for (auto i : vec) sum += i;

	int count = 0;
	for (auto i : vec)
	    if (i <= sum / n) count++;

	cout << count << endl;
    }

    return 0;
}

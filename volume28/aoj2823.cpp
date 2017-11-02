#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
	vector<int> max_num(M);
	for (int i = 0; i < N; i++) {
	    int d, v;
	    cin >> d >> v;
	    max_num[d-1] = max(max_num[d-1], v);
	}

	int sum = 0;
	for (auto i : max_num) sum += i;
	cout << sum << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;
    char pre = 'o';
    while (count < N) {
	char now;
	cin >> now;
	if (pre == 'x' && now == pre) break;
	count++;
	pre = now;
    }

    cout << count << endl;

    return 0;
}

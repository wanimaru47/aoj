#include <bits/stdc++.h>
#define vec(T) vector<T>
#define mat(T) vector<vector<T>>
using namespace std;

const int INF = 1 << 28;

int main() {
    int d, w;
    while(cin >> d >> w, d || w) {
	mat(int) n(d, vec(int)(w));

	for (auto& i : n) for (auto& j : i) cin >> j;

	int ans = 0;
	for (int sx = 0; sx < d; sx++) {
	    for (int sy = 0; sy < w; sy++) {
		for (int gx = sx + 2; gx < d; gx++) {
		    for (int gy = sy + 2; gy < w; gy++) {
			int min_value = INF;

			for (int i = sx; i <= gx; i++) {
			    min_value = min(min_value, n[i][sy]);
			    min_value = min(min_value, n[i][gy]);
			}

			for (int i = sy; i <= gy; i++) {
			    min_value = min(min_value, n[sx][i]);
			    min_value = min(min_value, n[gx][i]);
			}

			int sum = 0;
			bool flag = true;
			for (int i = sx + 1; flag && i < gx; i++) {
			    for (int j = sy + 1; flag && j < gy; j++) {
				if (n[i][j] < min_value) {
				    sum += min_value - n[i][j];
				} else {
				    flag = false;
				}
			    }
			}

			if (flag) {
			    ans = max(ans, sum);
			}
		    }
		}
	    }
	}

	cout << ans << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int ans = 0, n, x;

bool dfs(int i, int sum, int node)
{
	if (node == 3) {
		if(sum == x) ans++;
	}else {
		i++;
		if (node < 3 && i <= n) dfs(i, sum, node);
		if (node < 3 && i <= n) dfs(i, sum+i, ++node);
	}
}

int main(void)
{
	while (cin >> n >> x) {
		if (n == 0 && x == 0) break;
		ans = 0;
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int n, s, ans;

void dfs(int i, int count, int sum)
{
	if (n == count) {
		if (s == sum) ans++;
	}else if (i < 10) {
		dfs(i+1, count, sum);
		dfs(i+1, count+1, sum+i);
	}
}
int main(void)
{
	while (cin >> n >> s) {
		if (n == 0 && s == 0) break;
		ans = 0;
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
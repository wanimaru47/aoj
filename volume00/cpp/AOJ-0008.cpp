#include <iostream>
#define MAX 10
using namespace std;

int num, ans = 0;
int ary[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void dfs(int sum, int count) 
{
	if (count == 4 || sum == num) {
		if (sum == num) ans++;
	}else {
		for (int j = 0; j < MAX; j++) {
			dfs(sum+ary[j], count+1);
		}
	}
}

int main(void)
{
	while (cin >> num) {
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
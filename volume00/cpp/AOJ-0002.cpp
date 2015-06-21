#include "iostream"
using namespace std;

int main(void)
{
	int a,b,sum,ans;
	cin >> a >> b;
	sum = a + b;
	ans = 0;
	while(sum > 0) {
		sum %= 10;
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}
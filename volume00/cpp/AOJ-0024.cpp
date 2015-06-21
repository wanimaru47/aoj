#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	double v, times, hight, street;
	int ans;

	while (cin >> v) {
		times = v / 9.8;
		hight = 4.9 * times * times;
		street = (hight + 5.0) / 5.0;
		if (street - (int)street) ans = (int)(street + 1.0);
		else ans = street;
		printf("%d\n", ans);
	}
	
	return 0;
}
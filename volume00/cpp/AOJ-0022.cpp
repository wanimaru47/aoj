#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> numbers;
	int count, tmp, ans[5000], Max;

	while (cin >> count) {
		if (count == 0) break;
		for (int i = 0; i < 5000; i++) ans[i] = 0;
		Max = -100000;
		for (int i = 0; i < count; i++) {
			cin >> tmp;
			for (int j = 0; j <= i; j++) {
				ans[j] += tmp;
				if (Max < ans[j]) Max = ans[j];
			}
		}
		cout << Max << endl;
	}
	
	return 0;
}

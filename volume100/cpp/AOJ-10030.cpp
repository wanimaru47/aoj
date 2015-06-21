#include <iostream>
using namespace std;

int main(void)
{
	int count1, count2, num1[100] = {0}, num2[100] = {0}, ans = 0;
	cin >> count1;
	for (int i = 0; i < count1; i++) cin >> num1[i];
	cin >> count2;
	for (int i = 0; i < count2; i++) cin >> num2[i];

	for (int i = 0; i < count1; i++) {
		int flag = 0;
		for (int j = 0; j < count2; j++) {
			if (num1[j] == num2[i]) {
				flag = 1;
				num1[j] = -1;
			}
		}
		if (flag) ans++; 
	}
	cout << ans << endl;
	
	return 0;
}
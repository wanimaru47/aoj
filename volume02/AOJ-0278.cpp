#include "iostream"
using namespace std;

int main(void)
{
	int day=100, num1, num2, ckt1, ckt2;
	int ans1,ans2;
	cin >> day;
	for (int i = 0; i < day; i++)
	{
		cin >> num1 >> num2 >> ckt1 >> ckt2;
		//cout << num1 << num2 << ckt1 << ckt2 << endl;
		ans1 = num1*ckt1 + num2*ckt2;
		ans2 = ans1;
		if(ckt1 > 4 || ckt2 > 1) {
			if (ckt1 > 4 && ckt2 > 1) {
				ans2 = ans1*0.8;
			}else if(ckt1 > 4) {
				ans2 = (num1*ckt1 + num2*2)*0.8;
			}else if(ckt2 > 1) {
				ans2 = num1*5 + num2*ckt2;
			}
		}
		if (ans1 < ans2) {
			cout << ans1 << endl;
		}else {
			cout << ans2 << endl;
		}
	}

	return 0;
}
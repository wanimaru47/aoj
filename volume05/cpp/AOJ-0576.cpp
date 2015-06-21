#include "iostream"
using namespace std;

int main(void)
{
	int vac, jpn, math, jpn_d, math_d;
	cin >> vac >> jpn >> math >> jpn_d >> math_d;

	int jpnDay, mathDay;
	if ((jpn%jpn_d) == 0) {
		jpnDay = jpn / jpn_d;
	}else {
		jpnDay = jpn / jpn_d + 1;
	}
	if ((math%math_d) == 0) {
		mathDay = math / math_d;
	}else {
		mathDay = math / math_d + 1;
	}

	if (jpnDay > mathDay) {
		cout << vac - jpnDay << endl;
	}else {
		cout << vac - mathDay << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
	long long num = 100000, day;
	cin >> day;

	for (int i = 0; i < day; i++) {
		num *= 1.05;
		if (num % 1000) num = num - (num % 1000) + 1000;
	}
	cout << num << endl;
	
	return 0;
}
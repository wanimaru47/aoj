#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;

	while (1) {
		cin >> num1 >> num2;
		if (num1 == 0) break;

		for (int i = 0; i < num1; i++) {
			for (int j = 0; j < num2; j++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
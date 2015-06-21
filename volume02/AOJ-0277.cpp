#include "iostream"
using namespace std;

int main(void)
{
	int num1, num2;
	for (int i = 0; i < 4; i++)
	{
		cin >> num1 >> num2;
		switch(num1) {
			case 1:
				cout << 6000*num2 << endl;
				break;
			case 2:
				cout << 4000*num2 << endl;
				break;
			case 3:
				cout << 3000*num2 << endl;
				break;
			case 4:
				cout << 2000*num2 << endl;
				break;
		}
	}
	
	return 0;
}
/*
Ｓ席 6000円
Ａ席 4000円
Ｂ席 3000円
Ｃ席 2000円
*/
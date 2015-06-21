#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	string num;
	char s; 
	int sum, i=0;
	while (cin >> num) {
		if (num == "0") break; 
		sum = 0; i = 0;

		while (num.size() > i) {
			s = num[i];
			switch (s) {
				case '1': sum++; break;
				case '2': sum += 2; break;
				case '3': sum += 3; break;
				case '4': sum += 4; break;
				case '5': sum += 5; break;
				case '6': sum += 6; break;
				case '7': sum += 7; break;
				case '8': sum += 8; break;
				case '9': sum += 9; break;
			}
			i++;
		}

		cout << sum << endl;
	}
	
	return 0;
}
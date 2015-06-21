#include <iostream>
using namespace std;

int main(void)
{
	int n, r, card[4][13];
	char b;

	cin >> n;

	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 13; j++) card[i][j] = 1; 

	for (int i = 0; i < n; i++) {
		cin >> b >> r;

		switch (b) {
			case 'S':
				card[0][r-1] = 0;
				break;
			case 'H':
				card[1][r-1] = 0;
				break;
			case 'C':
				card[2][r-1] = 0;
				break;
			case 'D':
				card[3][r-1] = 0;
				break;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (card[i][j]) {
				switch (i) {
					case 0:
						cout << "S " << j+1 << endl;
						break;
					case 1:
						cout << "H " << j+1 << endl;
						break;
					case 2:
						cout << "C " << j+1 << endl;
						break;
					case 3:
						cout << "D " << j+1 << endl;
						break;
				}
			}
		}
	}
	
	return 0;
}
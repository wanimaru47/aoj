#include "iostream"
using namespace std;

int main(void)
{
	int num, player[200][3]={0};

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> player[i][0] >> player[i][1] >> player[i][2];
	}
	
	bool flag = false;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < num; i++) {
			flag = false;
			for (int k = 0; k < num; k++) {
				if (player[i][j] == player[k][j] && i != k) {
					player[k][j] = 0;
					flag = true;
				}
			}
			if (flag) player[i][j] = 0;
		}
	}

	for (int i = 0; i < num; i++) {
		cout << player[i][0] + player[i][1] + player[i][2] << endl;
	}
	

	return 0;
}
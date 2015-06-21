#include <iostream>
using namespace std;

int main(void)
{
	int n1, n2;

	while (1) {
		cin >> n1 >> n2;
		if (n1 == 0) break;

		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				if (i == 0 || i == n1-1 || j == 0 || j == n2-1) cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
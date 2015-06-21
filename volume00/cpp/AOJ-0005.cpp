#include <iostream>
using namespace std;

int main(void)
{
	long long  l1, l2, tmp1, tmp2, tmp;
	while (cin >> l1 >> l2) {
		tmp1 = max(l1, l2);
		tmp2 = min(l1, l2);
		while (tmp1 && tmp2) {
			tmp = tmp1 % tmp2;
			tmp1 = tmp2;
			tmp2 = tmp;
		}
		tmp2 = l1 * l2 / tmp1;

		cout << tmp1 << " " << tmp2 << endl;
	}

	return 0;
}
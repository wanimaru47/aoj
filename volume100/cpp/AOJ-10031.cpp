#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int count1, count2, ans = 0, tmp;
	vector<int> p1, p2;
	cin >> count1;
	for (int i = 0; i < count1; i++) {cin >> tmp; p1.push_back(tmp);}
	cin >> count2;
	for (int i = 0; i < count2; i++) {cin >> tmp; p2.push_back(tmp);}

	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());

	int j = 0, tmp2, flag = 0;
	for (int i = 0; i < count2; i++) {
		flag = 0;
		tmp2 = p2[i];
		while (tmp2 >= p1[j]) {
			if (tmp2 == p1[j]) flag = 1;
			j++;
		}
		if (flag) ans++;
		while (tmp2 == p2[i]) i++;
		i--;
	}
	cout << ans << endl;
	
	return 0;
}
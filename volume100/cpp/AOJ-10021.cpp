#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str,ans = "z";
	int num, flag;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str;
		flag  = 1;
		if (str[0] < ans[0]) {
			ans = str;
		}else if (str[0] == ans[0]) {
			for (int i = 1; i < str.size(); i++) {
				if (str[i] > ans[i]) flag = 0;
			}
			if (flag) ans = str;
		}
		
	}

	cout << ans << endl;
	
	return 0;
}
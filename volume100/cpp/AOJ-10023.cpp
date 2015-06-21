#include <iostream>
#include <string>
#include <queue>
#include <deque>
using namespace std;

int main(void)
{
	string str;
	int count, s;
	while (1) {
		queue<char> sssss;
		cin >> str;
		if (str == "-") break;
		for (int i = 0; i < str.size(); i++) sssss.push((char)str[i]);
		cin >> count;
		for (int i = 0; i < count; i++) {
			cin >> s;
			for (int j = 0; j < s; j++) {
				sssss.push(sssss.front());
				sssss.pop();
			}
		}
		for (int i = 0; i < str.size(); i++) {
			cout << sssss.front();
			sssss.pop();
		}
		cout << endl;
	}
	
	return 0;
}
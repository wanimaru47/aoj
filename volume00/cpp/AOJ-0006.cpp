#include <iostream>
using namespace std;

int main(void)
{
	string str;

	cin >> str;

	for (int i = str.size() -1; i >= 0 ; i--) cout << str[i];
	cout << endl;
	
	return 0;
}
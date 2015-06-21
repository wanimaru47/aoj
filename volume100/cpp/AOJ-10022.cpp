#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main(void)
{
	string str, w;
	bool flag;
	int count = 0;
	cin >> w;
	for (int i = 0; i < w.size(); i++) w[i] = tolower(w[i]);
	while (cin >> str) {
		if (str == "END_OF_TEXT") break;
		for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
		if (str == w) count++;
	}
	cout << count << endl;
	
	return 0;
}
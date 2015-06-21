#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main(void)
{
	string str;
	char s;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		s = str[i];
		str[i] = tolower(str[i]);
		if (str[i] == s) str[i] = toupper(str[i]);
	}
	cout << str << endl;
	
	return 0;
}
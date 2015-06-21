#include <iostream>
#include <stdio.h>
#include <string.h>
#define a 97
#define z 122
using namespace std;

int main(void)
{
	string str;
	char s;
	int i, atoz[26] = {0};
	while (cin >> str) {
		i = 0;
		while (str.size() > i) {
		 s = str[i];
		 s = tolower(s);
			if (a <= s && s <= z) atoz[(int)s-97]++;
			i++;
		}
	}

	for (int i = 0; i < 26; i++) {
		s = i + 97;
		cout << s << " : " << atoz[i] << endl;
	}
	
	return 0;
}
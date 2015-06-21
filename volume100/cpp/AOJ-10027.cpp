#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(void)
{
	string str1, str2;
	int num, a = 0, b = 0, tmp;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str1 >> str2;
		if (str1 > str2) a += 3;
		else if (str1 < str2) b += 3;
		else {a++; b++;}
	}

	printf("%d %d\n", a, b);
	
	return 0;
}
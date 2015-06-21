#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << (a/b) << " " << (a%b) << " ";
	printf("%f\n", (double)a/(double)b);
	
	return 0;
}
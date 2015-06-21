#include <iostream>
#include <cstdio>
#define MAX 30
using namespace std;

int main(void)
{
	int lot[MAX], w, n;
	cin >> w >> n;
	for (int i = 0; i < w; i++) lot[i] = i+1;
	for (int i = 0; i < n; i++) {
		int a, b, tmp;
		scanf("%d,%d", &a, &b);
		tmp = lot[a-1];
		lot[a-1] = lot[b-1];
		lot[b-1] = tmp;
	}
	for (int i = 0; i < w; i++) cout << lot[i] << endl;
	
	return 0;
}
#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(void)
{
	int n, tokuten[1000];
	double avg, hensa;
	while (1) {
		avg = 0;
		hensa = 0;
		cin >> n;
		if (n == 0) break;
			for (int i = 0; i < n; i++) {
			cin >> tokuten[i];
			avg += tokuten[i];
		}
		avg /= n;

		for (int i = 0; i < n; i++) {
			hensa += (tokuten[i]-avg)*(tokuten[i]-avg);
		}
		hensa /= n;
		hensa = sqrt(hensa);

		printf("%f\n", hensa);
	}
	
	return 0;
}
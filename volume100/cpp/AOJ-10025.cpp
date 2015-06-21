#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(void)
{
	int a, b, angle;
	double s, l, h;

	cin >> a >> b >> angle;
	s = (double)a * (double)b*sin((double)angle/180.0*M_PI) / 2.0;
	printf("%f\n", s);
	l = (double)(a*a) + (double)(b*b) -2*(double)a*(double)b*cos((double)angle/180.0*M_PI);
	printf("%f\n", sqrt(l)+(double)a+(double)b);
	h = (double)b*sin((double)angle/180.0*M_PI);
	printf("%f\n", h);
	
	return 0;
}
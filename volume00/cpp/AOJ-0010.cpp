#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

double sq (double x) {return (x * x);}

int main(void)
{
	double x1, x2, x3, y1, y2, y3;
	int num;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                //double a = sqrt(SQ(x2 - x1) + SQ(y2 - y1));
                //double b = sqrt(SQ(x3 - x2) + SQ(y3 - y2));
                //double c = sqrt(SQ(x1 - x3) + SQ(y1 - y3));
                double a = hypot(x2 - x1, y2 -y1);
                double b = hypot(x3 - x2, y3 -y2);
                double c = hypot(x1 - x3, y1 -y3);
                double r = (a * b * c) / sqrt( ( a + b + c ) * ( -1 * a + b + c) * ( a - b + c ) * ( a + b - c ) );


                double xp = ((sq(x1) + sq(y1)) * (y2 - y3) + (sq(x2) + sq(y2)) * (y3 - y1) + (sq(x3) + sq(y3)) * (y1 - y2)) / (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
                double yp = ((sq(x1) + sq(y1)) * (x2 - x3) + (sq(x2) + sq(y2)) * (x3 - x1) + (sq(x3) + sq(y3)) * (x1 - x2)) / (y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2)) / 2;
                
                printf("%.3f %.3f %.3f\n", xp, yp, r);
	}
	
	return 0;
}

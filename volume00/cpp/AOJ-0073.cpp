#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
     double r, h, S;
     while (cin >> r >> h && r && h) {
	  S = r * r + r * sqrt(r * r + h * h * 4);
	  printf("%f\n", S);
     }

     return 0;
}

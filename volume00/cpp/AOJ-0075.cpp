#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
     int id;
     double h, w;
     while (scanf("%d,%lf,%lf", &id, &w, &h) != EOF) {
	  double b = (double)w / (h * h);
	  if (b >= 25.0) cout << id <<endl;
     }

     return 0;
}

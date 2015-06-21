#include <iostream>
#include <cstdio>
#define EPS (1e-10)
using namespace std;

int main()
{
     int num[10], v1, v2;
     while (scanf("%d,", &num[0]) != EOF) {
	  for (int i = 1; i < 10; i++) scanf("%d,", &num[i]);
	  scanf("%d,%d", &v1, &v2);
	  
	  int sum = 0;
	  for (int i = 0; i < 10; i++) sum += num[i];
	  double dis;
	  dis = (double)sum / (double)(v1 + v2);
	  dis *= (double)v1;
	  sum = 0;
	  int i = 0;
	  do {
	       sum += num[i];
	       i++;
	  }while(sum < dis);
	  cout << i << endl;
     }
	  
     return 0;
}

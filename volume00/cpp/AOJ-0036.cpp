#include <iostream>
using namespace std;

int main()
{
     int num[8];
     int pattan[7][4] = {{11000000, 11000000, 0, 0},
			 {10000000, 10000000, 10000000, 10000000},
			 {11110000, 0, 0, 0},
			 {1000000, 11000000, 10000000, 0},
			 {11000000, 1100000, 0, 0},
			 {10000000, 11000000, 1000000, 0},
			 {1100000, 11000000, 0, 0} };
     while (cin >> num[0]) {
	  for (int i = 1; i < 8; i++) cin >> num[i];
	  int t = 0;
	  while (num[t] == 0) t++;
	  //char
	  for (int i = 0; i < 7; i++) {
	       //sift
	       for (int j = 0; j < 8;j++) {
		    //good mach
		    int flag = 1, tmp = 1;
		    for (int k = 0; k < j; k++) tmp *= 10;
		    for (int k = 0; k < 4; k++)
			 if (num[t + k] != (pattan[i][k] / tmp) && t + k < 8) flag = 0;
		    char str = 'A' + i;
		    if (flag) cout << str << endl; 
	       }
	  }
     }
     
     return 0;
}

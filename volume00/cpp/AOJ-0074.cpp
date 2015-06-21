#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
     int hours, minutes, seconds;

     while (cin >> hours >> minutes >> seconds) {
	  if (hours == -1) break;
	  int times = 120 * 60;
	  int sum = hours * 60 * 60 + minutes * 60 + seconds;
	  times -= sum;
	  seconds = times % 60;
	  times /= 60;
	  minutes = times % 60;
	  times /= 60;
	  hours = times % 24;

	  printf("%02d:%02d:%02d\n", hours, minutes, seconds);

	  sum = hours * 60 * 60 + minutes * 60 + seconds;
	  times = sum;
	  times *= 3;
	  seconds = times % 60;
	  times /= 60;
	  minutes = times % 60;
	  times /= 60;
	  hours = times % 24;

	  printf("%02d:%02d:%02d\n", hours, minutes, seconds);
	  
     }
	  
     return 0;
}

#include <iostream>
using namespace std;

int main()
{
     int n;
     int prm[1000000];
     for (int i = 0; i < 1000000; i++) prm[i] = 1;
     prm[0] = prm[1] = 0;
     for (int i = 2; i <= 123456; i++)
	  for (int j = 2; j * i <= 123456 * 2; j++)
	       prm[i * j] = 0;

     while (cin >> n, n) {
	  int count = 0;
	  for (int i = n + 1; i <= n * 2; i++)
	       if (prm[i] == 1)
		    count++;
	  cout << count << endl;
     }

     return 0;
}

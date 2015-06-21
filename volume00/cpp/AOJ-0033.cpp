#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef stack<int> S;
typedef queue<int> Q;

int main()
{
     int count;
     cin >> count;
     while(count--) {
	  int num[10];
	  for (int i = 0; i < 10; i++) cin >> num[i];
	  int max = num[0];
	  num[0] = 0;
	  for (int i = 1; i < 10; i++) {
	       if (num[i] > max) {
		    max = num[i];
		    num[i] = 0;
	       }
	  }
	  max = 0;
	  int flag = 1;
	  for (int i = 0; i < 10; i++) {
	       if (max <= num[i]) max = num[i];
	       else if (num[i] != 0) {
		    cout << "NO" << endl;
		    flag = 0;
		    break;
	       }
	  }
	  if (flag) cout << "YES" << endl;
     }

     return 0;
}

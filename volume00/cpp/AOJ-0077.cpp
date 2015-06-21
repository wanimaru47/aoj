#include <iostream>
#include <string>
using namespace std;

int main()
{
     string str;
     while (cin >> str) {
	  string res;
	  for (int i = 0; i < str.size(); i++) {
	       if (str[i] != '@') res += str[i];
	       else {
		    int tmp = str[i + 1] - '0';
		    for (int j = 0; j < tmp; j++) {
			 res += str[i + 2];
		    }
		    i += 2;
	       }
	  }
	  cout << res << endl;
     }

     return 0;
}

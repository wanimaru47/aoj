#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef stack<char> P;

int main()
{
     const char s[5] = "()[]";
     string str;
     while (getline(cin, str), str.size() > 1) {
	  P p;
	  bool flag  =true;
	  for (int i = 0; i < str.size(); i++) {
	       if (str[i] == s[0] || str[i] == s[2]) p.push(str[i]);
	       else if (str[i] == s[1] || str[i] == s[3]) {
		    if (p.size() < 1) {
			 flag = false;
			 break;
		    } else if (str[i] == s[1] && p.top() == s[0]) p.pop();
		    else if (str[i] == s[3] && p.top() == s[2]) p.pop();
		    else {
			 flag = false;
			 break;
		    }
	       }
	  }
	  if (flag && p.size() == 0) cout << "yes" << endl;
	  else cout << "no" << endl;
     }

     return 0;
}

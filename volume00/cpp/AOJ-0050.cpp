#include <iostream>
#include <string>
using namespace std;

int main()
{
     string str;
     char apple[6] = "apple", peach[6] = "peach";
     getline(cin, str);
     int i = 0;
     while (i < str.size()) {
	  if (str[i] == 'a') {
	       string tmp;
	       for (int k = 0; k < 5 && k + i < str.size(); k++) 
		    tmp += str[i+k];
	       if (tmp == "apple") {
		    for (int k = 0; k < 5; k++)
			 str[i+k] = peach[k];
		    i += 5;
	       }else i++;
	  }else if (str[i] == 'p') {
	       string tmp;
	       for (int k = 0; k < 5 && i + k < str.size(); k++) 
		    tmp += str[i+k];
	       if (tmp == "peach") {
		    for (int k = 0; k < 5; k++)
			 str[i+k] = apple[k];
		    i += 5;
	       }else i++;
	  }else i++;
     }
     
     cout << str << endl;
     
     return 0;
}

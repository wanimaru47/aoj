#include <iostream>
#include <string>
#include <set>
using namespace std;

int main ()
{
    string str = "yuiohjklnmp";
    set<char> s;
    
    for (int i = 0; i < str.size(); i++) {
        s.insert(str[i]);
    }

    while (cin >> str, str != "#") {
        int res = 0;
        bool pre, now;
        pre = (s.find(str[0]) == s.end()) ? false : true; 
        for (int i = 1; i < str.size(); i++) {
            if (s.find(str[i]) == s.end()) {
                now = false;
            } else {
                now = true;
            }
            if (now != pre) {
                res++;
            }
            pre = now;
        }
        cout << res << endl;
    }
    

    return 0;
}

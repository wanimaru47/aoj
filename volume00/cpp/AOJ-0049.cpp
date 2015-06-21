#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main ()
{
    string str;
    map<string,int> m;    
    m["A"] = 0;
    m["B"] = 0;
    m["AB"] = 0;
    m["O"] = 0;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ',') {
                str[i] = ' ';
            }
        }
        stringstream ss;
        int num;
        string s;
        ss << str;
        ss >> num >> s;
        m[s]++;
    }
    cout << m["A"] << endl;
    cout << m["B"]  << endl;
    cout << m["AB"] << endl;
    cout << m["O"] << endl;

    return 0;
}

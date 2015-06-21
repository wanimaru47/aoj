#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <sstream>
using namespace std;

bool in_word (string s1, string s2) {
    stringstream ss;
    ss << s1;
    while (ss >> s1) {
        if (s1 == s2) return true;
    }
    return false;
}

string affin (string str, int a, int b) {
    int tmp[26];
    for (int i = 0; i < 26; i++) tmp[i] = -1;
    for (int i = 0; i < str.size(); i++) {
        if (!(isalpha(str[i]))) continue;
        int s = str[i] - 'a';
        int g = (a * s + b) % 26;
        if (tmp[g] != -1 && tmp[g] != s) return "";
        else if (tmp[g] == -1) tmp[g] = s;
        str[i] = (char)(g + 'a');
    }
    
    return str;
}

int main ()
{
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    while (n--) {
        getline(cin, str);
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                string tmp = affin(str, i, j);
                if (tmp == "") continue;
                if (in_word(tmp, "this") || in_word(tmp, "that")) {
                    cout << tmp << endl;
                    goto escape;
                }
            }
        }
    escape:;
    }
    
    return 0;
}

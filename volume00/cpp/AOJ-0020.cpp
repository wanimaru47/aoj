#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
using namespace std;

int main ()
{
    string str;
    getline (cin, str);
    for (int i = 0; i < str.size(); i++ )
        putchar(toupper(str[i]));
    cout << endl;

    return 0;
}

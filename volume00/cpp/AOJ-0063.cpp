#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int res = 0;

    while (cin >> str) {
        bool flag = true;
        for (int i = 0; i < str.size(); i++)
            if (str[i] != str[str.size() - i - 1])
                flag = false;

        if (flag) res++;
    }

    cout << res << endl;

    return 0;
}

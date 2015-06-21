#include <iostream>
#include <cstring>
using namespace std;

bool cal (string n1, string n2, string n3) {
    cout << n1 << " " << n2 << " " << n3 << endl;
    bool res = false;
    string sum, num;
    if (n1.size() > n2.size()) {sum = n1; num = n2;}
    else {sum = n2; num = n1;}
    char t = '0';
    for (int i = 0; i < num.size() + 1; i++) { 
        int tmp = 0;
        int t1 = sum[sum.size() - 1 - i] - '0';
        int t2 = t - '0';
        if (i < num.size()) {
            int t3 = num[num.size() - 1 - i] - '0';
            tmp += t3;
        }
        tmp += t1 + t2;
        if (tmp >= 10) t = '1';
        tmp %= 10;
        sum[sum.size() - 1 - i] = (char)tmp;
    }
    cout << sum << endl;
    if (sum == n3) res = true;
    
    return res;
}

int main ()
{
    char str[127];
    while (cin >> str) {
        int ans = -1;
        for (int i = 0; i < 10; i++) {
            auto tmp = str;
            int k;
            for (k = 0; str[k] != '\0'; k++);
            for (int j = 0; j < k; j++)
                if (tmp[j] == 'X') tmp[j] = (char)i;
            cout << tmp << endl;
            char *tp;
            k = 0;
            string num[3];
            tp = strtok(tmp, "+=");
            while (tp != NULL) {
                num[k] = (string)tp;
                tp = strtok(NULL, "+=");
                k++;
            }
            cout << num[0] << " " << num[1] << " " << num[2] << endl;
            if (cal(num[0], num[1], num[2])) ans = i;
        }
        if (ans < 0) cout << "NA" << endl;
        else cout << ans << endl;
     }

    return 0;
}

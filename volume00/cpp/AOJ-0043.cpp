#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

bool search(int N[10]) {
    bool res = false;
    int count = 0;
    bool flag = true;
    for (int i = 1; i < 10; i++) {
        if (N[i] == 2) count++;
        else if (N[i] < 0) return false;
        else if (N[i] != 0 && N[i] != 3) flag = false;
    }
    if (flag && count == 1) return true;

    for (int i = 1; i + 2 < 10; i++) {
        //cout << i << endl;
        int tmp[10];
        for (int j = 1; j < 10; j++)
            tmp[j] = N[j];
        if (tmp[i] > 0) {
            for (int j = 0; j < 3; j++)
                --tmp[i + j];
            res = search(tmp);
            if (res) break;
        }
    }

    return res;
}

int main()
{
    long int num;
    while (scanf("%ld", &num) != EOF) {
        int N[10];
        memset(N, 0, sizeof(N));
        while (num) {
            int tmp = num % 10;
            ++N[tmp];
            num /= 10;
        }
        bool ans[10];
        memset(ans, false, sizeof(ans));
        for (int i = 1; i < 10; i++) {
            if (N[i] > 4) continue;
            int tmp[10];
            for (int j = 0; j < 10; j++)
                tmp[j] = N[j];
            ++tmp[i];
            ans[i] = search(tmp);
        }

        int t = 0;
        for (int i = 9; i > 0; i--)
            if (ans[i]) {
                t = i;
                break;
            }

        for (int i = 1; i < t; i++)
            if (ans[i]) cout << i << " ";
        cout << t << endl;
    }

    return 0;
}

#include <iostream>
#include <map>
#define MAX 12
using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        int n[MAX], t[MAX];
        for (int i = 0; i < N; i++) {cin >> n[i]; t[i] = n[i];}
        bool flag = true;
        int count = 0;
        while (flag) {
            map<int,int> m;
            for (int i = 0; i < N; i++) {
                m[n[i]]++;
            }
            for (int i = 0; i < N; i++)
                t[i] = m[n[i]];
            bool f = true;
            for (int i = 0; i < N; i++)
                if (t[i] != n[i]) f = false;
            if (f) flag = false;
            count++;
            for (int i = 0; i < N; i++) n[i] = t[i];
        }
        count--;
        cout << count << endl << t[0];
        for (int i = 1; i < N; i++) cout << " " << t[i];
        cout << endl;
    }

    return 0;
}

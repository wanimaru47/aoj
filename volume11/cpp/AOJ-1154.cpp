#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <stack>
#include <queue>
#include <cstdlib>
#include <tuple>
#define INF 1e9
#define EPS 1e-9
using namespace std;

typedef list<int> L;
typedef pair <int,int> P;
typedef vector<int> V;
typedef queue<int> Q;
typedef stack<int> S;
typedef map<string,int> M;

int main()
{
    int year;
    vector<bool> v(3000001, true);
    v[0] = v[1] = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == true) {
            if ((i - 6) % 7 == 0 || (i - 1) % 7 == 0) {
                for (int j = 2; j * i <= v.size(); j++) {
                    v[i * j] = false;
                }
            } else {
                v[i] = false;
            }
        }
    }
    while (cin >> year , year > 1) {
        L res;
        for (int i = 0; i <= year; i++) {
            if (v[i])
                if (year % i == 0)
                    res.push_back(i);
        }
        cout << year << ":";
        for (auto ite = res.begin(); ite != res.end(); ite++) {
            cout << " " << *ite;
        }
        cout << endl;
    }

    return 0;
}

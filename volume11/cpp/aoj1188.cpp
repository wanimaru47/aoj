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
using namespace std;

typedef list<int> L;
typedef pair <int,int> P;
typedef vector<int> V;
typedef queue<int> Q;
typedef stack<int> S;
typedef map<string,int> M;

int change (string s) {
    //cout << "s = " << s;
    int ten = 1;
    int res = atoi(&s[0]);
    res = (res / 2) + 1;
    //cout << " " << res << endl;
    
    return res;
}

int dfs (string str) {
    cout << str << endl;
    int corsor = 1;
    int i = 0;
    V v;
    while (i < str.size()) {
        corsor = 1;
        i++;
        string tmp;
        while (corsor) {
            if (str[i] == '[') corsor++;
            else if (str[i] == ']') corsor--;
            if (corsor)
                tmp += str[i];
            i++;
        }
        if (tmp[0] != '[') {
            //cout << tmp  << endl;
            v.push_back(change(tmp));
        }
        else
            v.push_back(dfs(tmp));
    }
    int res = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() / 2 + 1; i++) {
        res += v[i];
    }
    
    return res;
}

int main()
{
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        cout << dfs(str) << endl;
    }

    return 0;
}
/*
[
    [
        [
            [9]
            [7] 4
            [3] 2
        ]
        [
            [3] 2
            [5] 3  11
            [7]
        ]
        [
            [7] 4
            [9]
            [5] 3
        ]
    ]
    [
        [
            [9]
            [9] 5
            [3] 2
        ]
        [
            [5] 3  13   21
            [9] 5
            [9]
        ]
        [
            [7]
            [7] 4
            [3] 2
        ]
    ]
    [
        [
            [5] 3
            [9]
            [7] 4
        ]
        [
            [3] 2 10
            [9]
            [3] 2
        ]
        [
            [9]
            [5] 3
            [5] 3
        ]
    ]
]
*/



/*
.
 */

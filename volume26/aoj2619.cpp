#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> P;
int n;

void Print(vector<queue<P> > &qs, int dot, int target) {
    while(qs[target].size()) {
        for(int i = 0; i < dot; i++) cout << ".";
        P p  = qs[target].front(); qs[target].pop();
        cout << p.second << endl;
        if(p.first < n)
            Print(qs, dot + 1, p.first);
    }
}

int main() {
    cin >> n;
    vector<int> k(n);
    vector<string> m(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i] >> m[i];
    }

    vector<queue<P> > ques(n);
    for(int i = 0; i < n; i++) {
        ques[k[i]].push(P(i + 1, m[i]));
    }

    Print(ques, 0, 0);

    return 0;
}

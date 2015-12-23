#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

const ll INF = 1LL << 60;

void Print(PQ que) {
    while (que.size()) {
        P p = que.top(); que.pop();
        cout << p.first << " " << p.second << endl;
    }
    cout << "~" << endl;
}

int main() {
    int n;
    while (cin >> n, n) {
        PQ que;
        que.push(P(0LL,INF));
        map<P,ll> m;
        while (n--) {
            // puts("PRE");
            // Print(que);
            char c;
            cin >> c;
            if (c == 'W') {
                ll t, l;
                cin >> t >> l;
                P p;
                while (true) {
                    p = que.top(); que.pop();
                    ll s = p.first, g = p.second;
                    if (s + l - 1 <= g) {
                        if (s + l - 1 < g)
                            que.push(P(s + l, g));
                        m[P(s, s + l - 1)] = t;
                        break;
                    } else {
                        m[P(s, g)] = t;
                        l -= g - s + 1;
                    }
                }
            } else if (c == 'D') {
                ll t; cin >> t;
                auto tmp(m);
                for (auto i : tmp) {
                    if (i.second == t) {
                        que.push(i.first);
                        m.erase(m.find(i.first));
                    }
                }
            } else {
                ll x; cin >> x;
                bool flag = true;
                for (auto i : m) {
                    if (i.first.first <= x && x <= i.first.second) {
                        cout << i.second << endl;
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cout << -1 << endl;
            }
            // puts("POST");
            // Print(que);
        }
        cout << endl;
    }

    return 0;
}

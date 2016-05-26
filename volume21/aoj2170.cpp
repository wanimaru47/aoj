#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
int N, Q;

void dfs(int now, int d, vec& depth, mat& v, vec& pre) {
    depth[now] = d;

    for (int i = 0; i < v[now].size(); i++) {
        if (depth[v[now][i]] > -1) {
            pre[now] = v[now][i];
            continue;
        }
        dfs(v[now][i], d + 1, depth, v);
    }
}

int main() {
    while (cin >> N >> Q, N || Q) {
        mat v(N);
        for (int i = 1; i < N; i++) {
            int a; cin >> a;
            a--;
            v[i].push_back(a);
            v[a].push_back(i);
        }

        vec depth(N, -1);
        vec pre(N);
        dfs(0, 0, depth, v, pre);

        vec m(N, INF);
        vector<priority_queue<int, vec, greator<int> > > t(N);
        set<int> d;
        for (int i = 0; i < Q; i++) {
            char a;
            int b;
            cin >> a >> b;
            if (a == 'M') m[b-1] = min(i, m[b-1]);
            else {
                t[b-1].push(i);
                if (v[b-1].size() == 1) d.insert(b-1);
            }
        }

        priority_queue<P, vector<P>, greator<P> > que;
        for (auto i : d) {
            que.push(P(depth[i], i));
        }

        ll res = 0;
        while (que.size()) {
            P p = que.top(); que.pop();
            int now = p.second;

            if (m[now] != INF) {
                while (1) {
                    int p = t[now].top();
                    if (p < m[now]) res += (ll)now;
                }
            }
        }
    }

    return 0;
}

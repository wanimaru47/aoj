#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1<<28;


int Find(int p, vec& par) {
    if (p == par[p]) return (p);
    return (par[p] = Find(par[p], par));
}

void Merge(int x, int y, vec& par) {
    x = Find(x, par), y = Find(y, par);
    if (x != y) {
        par[x] = y;
    }
}

void dfs(int now, int p, vec& par, mat& T, vec& MarkedTime) {
    if (MarkedTime[now] != MarkedTime[p] && MarkedTime[now] != INF) return ;
    par[now] = p;
    for (int i = 0; i < T[now].size(); i++) {
        dfs(T[now][i], p, par, T, MarkedTime);
    }
}

void solve(int N, int Q) {
    mat T(N+1);
    vec Tr(N+1);
    Tr[1] = 1;
    for (int i = 2; i <= N; i++) {
        int v; cin >> v;
        T[v].push_back(i);
        Tr[i] = v;
    }

    vec MarkedTime(N+1, INF);
    vec TimeToMarkedVertex(Q+1);
    vec QueryTimeToVertex(Q+1);
    MarkedTime[1] = -1;
    for (int i = 0; i < Q; i++) {
        char q;
        int v;
        cin >> q >> v;
        if (q == 'M') MarkedTime[v] = min(MarkedTime[v], i), TimeToMarkedVertex[i] = v;
        else QueryTimeToVertex[i] = v;
    }

    vec par(N+1);
    for (int i = 1; i <= N; i++) par[i] = i;
    for (int i = 1; i <= N; i++) {
        if (MarkedTime[i] == INF) continue;
        dfs(i, i, par, T, MarkedTime);
    }

    long long int cost = 0LL;
    for (int i = Q - 1; i > -1; i--) {
        if (QueryTimeToVertex[i] > 0) cost += Find(par[QueryTimeToVertex[i]], par);
        else if (i == MarkedTime[TimeToMarkedVertex[i]])
            Merge(TimeToMarkedVertex[i], Tr[TimeToMarkedVertex[i]], par);
    }

    cout << cost << endl;
}

int main() {
    int N, Q;
    while (cin >> N >> Q, N || Q) solve(N, Q);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vec;

const int MAX = 1111111;

int main() {
    int N; cin >> N;
    vec A(N);
    for(auto &i : A) cin >> i;

    int M; cin >> M;
    vec B(M);
    vector<ll> C(M);
    for(auto &i : B) cin >> i;
    for(auto &i : C) cin >> i;

    vector<ll> V(MAX);
    for(int i = 0; i < N; i++) {
        V[A[i]]++;
    }
    V[0] = 0;
    for(int i = 1; i < MAX; i++) {
        V[i] = V[i] * i + V[i-1];
    }
    for(int i = 0; i < M; i++) {
        if(V[B[i]] >= C[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}

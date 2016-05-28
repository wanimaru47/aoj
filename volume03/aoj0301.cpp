#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int erased[200001];
int Right[200001];
int Left[200001];

int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) Right[i] = (i + 1) % N;
    for (int i = 0; i < N; i++) Left[Right[i]] = i;
    for (int i = 0; i < N; i++) erased[i] = 1;

    int c = 0;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        bool flag = a % 2 ? true : false;
        for (int j = 0; j < a - 1; j++) {
            if (flag) c = Left[c];
            else c = Right[c];
        }

        if (flag) erased[Left[c]] = 0;
        else erased[Right[c]] = 0;
        if (flag) {Left[c] = Left[Left[c]]; Right[Left[c]] = c;}
        else {Right[c] = Right[Right[c]]; Left[Right[c]] = c;}
        if (!flag) c = Right[c];
        N--;
    }

    for (int i = 0; i < Q; i++) {
        int a; cin >> a;
        cout << erased[a] << endl;
    }

    return 0;
}

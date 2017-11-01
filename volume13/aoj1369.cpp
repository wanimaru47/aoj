#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main() {
    int N, M;
    cin >> N >> M;
    vector<P> arm(M);
    for (int i = 0; i < M; i++) {
        cin >> arm[i].first >> arm[i].second;       
    }
    sort(arm.begin(), arm.end());

    vector<int> s1(N), s2(N);
    for(int i = 0; i < N; i++) s1[i] = 1, s2[i] = 1;

    for (int i = 0; i < M; i++) {
        int y = arm[i].second;

        s1[y-1] += s1[y];
        s1[y] = 0;
        s2[y] += s2[y-1];
        s2[y-1] = 0;
    }

    vector<int> sum(N+1);
    for (int i = 0; i < N; i++) {
        sum[i] += s1[i];
        sum[i+1] -= s2[i];
    }

    for (int i = 0; i < N-1; i++) {
        cout << sum[i] << " ";
        sum[i+1] += sum[i];
    }
    cout << sum[N-1] << endl;

    return 0;
}

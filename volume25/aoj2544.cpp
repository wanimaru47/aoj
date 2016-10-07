#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(N+2);
    vector<string> vs(N+2);
    vs[0] = "kogakubu10gokan";
    s[N+1] = 51;

    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> vs[i];
    }

    string ans;
    for (int i = 1; i <= N+1; i++) {
        if (s[i-1] <= M && M < s[i]) {
            ans = vs[i-1];
        }
    }

    cout << ans << endl;

    return 0;
}

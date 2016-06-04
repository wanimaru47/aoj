#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<int> vec;
typedef vector<vec> mat;
const ll INF = 100001LL;

int main() {
    ll a, b, d;
    while(cin >> a >> b >> d, a || b || d) {
        vector<P> v;

        for (ll i = 0LL; i <= 100000LL; i++) {
            ll X = a * i + d;
            if (X >= b && X % b == 0LL) v.push_back(P(i, X / b));
            ll Y = b * i + d;
            if (Y >= a && Y % a == 0LL) v.push_back(P(Y / a, i));
            ll Z = a * i;
            if (d > Z && (d - Z) % b == 0LL) v.push_back(P(i, (d - Z) / b));
            ll W = b * i;
            if (d > W && (d - W) % a == 0LL) v.push_back(P((d - W) / a, i));
        }

        ll ansX = INF, ansY = INF;
        for (int i = 0, len = v.size(); i < len; i++) {
            ll X = v[i].first;
            ll Y = v[i].second;
            if ((ansX + ansY) >= (X + Y) && (ansX * a + ansY * b) >= (X * a + Y * b)) {
                ansX = X;
                ansY = Y;
            }
        }

        cout << ansX << " " << ansY << endl;
    }

    return 0;
}

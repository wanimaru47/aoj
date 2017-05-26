#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fizzbuzz(ll x, ll y, ll r) {
    ll x1 = x / 3LL;
    ll x2 = x / 5LL;
    ll x3 = x / 15LL;

    ll y1 = y / 3LL;
    ll y2 = y / 5LL;
    ll y3 = y / 15LL;

    return ((x - y) - ((x1 + x2 - x3) - (y1 + y2 - y3))) * r + 4LL * ((x1 + x2) - (y1 + y2));
}

int main() {
    ll s;
    cin >> s;
    
    ll l = -1LL, r = 1.5e18;
    ll _sum;
    ll _c;
    while (r - l >= 1) {
        ll m = (r + l) / 2LL;
        ll sum = 0LL;
        ll c = 1LL;
        ll x = 1LL;
        bool flag = false;
        while (1) {
            ll add = fizzbuzz(x * 10LL - 1LL, x - 1LL, c);
            if (add < 0) {
                flag = true;
                break;
            }
            if (sum + add > s) break;
            if (x * 10LL > m) break;
            sum += add;
            x *= 10LL;
            c += 1LL;
        }

        ll fz = fizzbuzz(m, x-1LL, c);
        if (flag || fz < 0) {
            r = m;
            continue;
        }
        sum += fz;
        ll prefix = fizzbuzz(m, m-1LL, c);

        if (sum > s - 1 && sum - prefix < s) {
            l = r = m;
        }
        if (sum > s) {
            r = m;
        } else {
            l = m;
        }
        _sum = sum;
        _c = c;
    }

    string ans;
    for (ll i = l; (ll)ans.size() - fizzbuzz(l, l-1, _c) <= 20; i++) {
        if (i % 3LL == 0) {
            ans += "Fizz";
        }
        if (i % 5LL == 0) {
            ans += "Buzz";
        }
        if (i % 3LL && i % 5LL) {
            stringstream ss;
            ss << i;
            string tmp;
            ss >> tmp;
            ans += tmp;
        }
    }
    ll t = fizzbuzz(l, l-1, _c) - (_sum - s);
        
    cout << string(ans.begin() + t - 1, ans.begin() + t + 19) << endl;

    return 0;
}

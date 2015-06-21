#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
typedef pair<int,int> P;
 
int main(void)
{
	int friends[500], n, m, a, b;
	P p;
	while (cin >> n >> m && n && m) {
		queue<int> q;
		vector<P> v;
		for (int i = 0; i < n; i++) friends[i] = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v.push_back(P(a,b));
		}
		for (int i = 0; i < m; i++) {
			p = v[i];
			if (p.first == 1 || p.second == 1) {
				friends[p.first-1] = friends[p.second-1] = 1;
				if (p.first > 1) q.push(p.first);
				else q.push(p.second);
				v[i] = P(0,0);
			}
		}
		while (q.size()) {
			int number = q.front();
			q.pop();
			for (int j = 0; j < m; j++) {
				p = v[j];
				if (p.first == number || p.second == number) {
					friends[p.first-1] = friends[p.second-1] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < n; i++) 
			if (friends[i] > 0) ans++;
		cout << ans << endl;
	}
}
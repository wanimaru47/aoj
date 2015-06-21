#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
     int N;
     while (cin >> N, N) {
	  vector<int> v;
	  int tmp;
	  for (int i = 0; i < N; i++) {
	       cin >> tmp;
	       v.push_back(tmp);
	  }
	  stable_sort(v.begin(), v.end());
	  int sum = 0;
	  for (int i = 1; i < v.size() - 1; i++) sum += v[i];
	  sum /= (N - 2);
	  cout << sum << endl;
     }

     return 0;
}

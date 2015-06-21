#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int count, tmp;
	vector<int> p;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> tmp;
		p.push_back(tmp);
	}
	
	sort(p.begin(), p.end());

	for (int i = 0; i < count-1; i++) {
		cout << p[i] << " ";
	}
	cout << p[count-1] << endl;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> p;
	int num, tmp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		p.push_back(tmp);
	}
	for (int i = num-1; i > 0; i--) {
		cout << p[i] << " ";
	}
	cout << p[0] << endl;
	
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> s;
	int zug;

	while (cin >> zug) {
		if (zug > 0) s.push(zug);
		else {
			cout << s.top() << endl;
			s.pop();
		}
	}
	
	return 0;
}
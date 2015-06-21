#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main(void)
{
	stack<string> que;
	string synbol, tmp;
	while (1) {
		cin >> synbol;
		if (synbol == "push") {cin >> tmp; que.push(tmp);}
		else if (synbol == "pop") {cout << que.top() << endl; que.pop();}
		else break;
	}
	
	return 0;
}
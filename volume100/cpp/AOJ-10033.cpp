#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class St
{
public:
	stack<string> str;

	void Push_back(string s);
	void Pop_top();
	string Move();
};

void St::Push_back(string s)
{
	str.push(s);
}

void St::Pop_top()
{
	cout << str.top() << endl;
	str.pop();
}

string St::Move()
{
	string ss;
	ss = str.top();
	str.pop();
	return ss;
}

int main(void)
{
	St st;
	vector<St> stk;
	string op, str;
	int number;
	cin >> number;

	for (int i = 0; i < number; i++) stk.push_back(st);

	while (1) {
		cin >> op ;
		if (op == "push") {
			cin >> number >> str;
			st = stk[number-1];
			st.Push_back(str);
			stk[number-1] = st;
		}else if (op == "pop") {
			cin >> number;
			st = stk[number-1];
			st.Pop_top();
			stk[number-1] = st;
		}else if (op == "move") {
			int num;
			cin >> number >> num;
			st = stk[number-1];
			str = st.Move();
			stk[number-1] = st;
			st = stk[num-1];
			st.Push_back(str);
			stk[num-1] = st;
		}else break;
	}
	
	return 0;
}
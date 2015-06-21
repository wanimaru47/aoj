#include <iostream>
#include <string>
#include <stack>
using namespace std;

int changeNumber(char number)
{
	int num = 0;
	for (char i = 48; i < 58; i++) {
		if (number == i) return num;
		num++;
	}
}

void puls(string number1, string number2)
{
	stack<int> s;
	int tmp = 0;
	for (int i = 1; i <= number1.size() && i <= number2.size(); i++) {
		tmp =  tmp + changeNumber(number1[number1.size() - i]) + changeNumber(number2[number2.size() - i]);
		s.push(tmp % 10);
		tmp /= 10;
	}
	for (int i = number2.size() + 1; i <= number1.size(); i++) {
		tmp = tmp + changeNumber(number1[number1.size() - i]);
		s.push(tmp % 10);
		tmp /= 10;
	}
	if (tmp > 0) s.push(tmp);
	if (s.size() > 80) cout << "overflow" << endl;
	else {
		while(0 < s.size()) {
			cout << s.top();
			s.pop();
		}
		cout  << endl;
	}
}

int main(void)
{
	string number1, number2;
	int count;

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> number1 >> number2;
		if (number1.size() < number2.size()) puls(number2, number1);
		else puls(number1, number2);
	}
	
	return 0;
}
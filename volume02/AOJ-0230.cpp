#include "iostream"
using namespace std;	

int main(void)
{
	int num, street[2][100], cursor=0;

	cin >> num;
	for (int i = 0; i < num; i++){cin >> street[0][i];}
	for (int i = 0; i < num; i++){cin >> street[1][i];}
/*
	for (int i = 0; i < num; i++){cout << street[0][i];}
	printf("\n");
	for (int i = 0; i < num; i++){cout << street[1][i];}
	printf("\n");
*/
	int tmp, before, aufter, biuld, flag=false, step=0, i=0;
	if (street[0][0] == 1) biuld = 0;
	else biuld = 1;
	while(1) {
		switch(tmp=street[biuld][cursor]) {
			case 0:
				cursor += 2;
				step++;
				if(step >= num) flag = true;

				break;
			case 1:
				while(street[biuld][cursor]) {
					cursor++;
				}
				cursor--;
				if (cursor >= num) flag = true;

				break;
			case 2:
				i = 0;
				tmp = biuld == 1 ? 0 : 1;
				
				while(street[biuld][cursor] == 2) {
					i++;
					if(street[tmp][])
				}

				break;
			default:
				break;
		}
	}
	

	return 0;
}
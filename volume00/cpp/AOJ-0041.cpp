#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char op[] = {'+', '-', '*'};
int n[16];

int cal (int n1, int n2, int t) {
    if (t == 0) return (n1 + n2);
    else if (t == 1) return (n1 - n2);
    else return (n1 * n2);
}

bool C (int a, int b, int c, int d, int i, int j, int k) {
    int t1 = cal(cal(a,b,i),cal(c,d,k),j); //cout << t1 << endl;
    int t2 = cal(cal(cal(a,b,i),c,j),d,k); //cout << t2 << endl;
    int t3 = cal(a,cal(b,cal(c,d,k),j),i); //cout << t3 << endl;
    int t4 = cal(a,cal(cal(b,c,j),d,k),i); //cout << t4 << endl;
    int t5 = cal(cal(a,cal(b,c,j),i),d,k); //cout << t5 << endl << endl;
    if (t1 == 10) {
        cout << "((" << a << " " << op[i] << " " << b << ") " << op[j] << " (" << c << " " << op[k] << " " << d << "))" << endl; 
    } else if (t2 == 10) {
        cout << "(((" << a << " " << op[i] << " " << b << ") " << op[j] <<  " " << c <<") " << op[k] << " " << d << ")" << endl; 
    } else if (t3 == 10) {
        cout << "(" << a << " " << op[i] << " (" << b << " " << op[j] << " (" << c << " " << op[k] << " " << d << ")))" << endl;  
    } else if (t4 == 10) {
        cout << "(" << a << " " << op[i] << " ((" << b << " " << op[j] << " " << c << ") " << op[k] << " " << d << "))" << endl;
    } else if (t5 == 10) {
        cout << "((" << a << " " << op[i] << " (" << b << " " << op[j] << " " << c << ")) " << op[k] << " " << d << ")" << endl;
    } else return false;
    return true;
}

int main()
{
    while (cin >> n[1] >> n[2] >> n[4] >> n[8]) {
         bool f = true;
         if (!(n[1] || n[2] || n[4] || n[8])) break;
         // 3箇所の演算子に対して総当たりをして、それぞれの括弧の付け方について考える
         // DPの方が良いかも

         for (int n1 = 1; n1 < (1 << 4); n1 <<= 1)
             for (int n2 = 1; n2 < (1 << 4); n2 <<= 1)
                 for (int n3 = 1; n3 << (1 << 4); n3 <<= 1)
                     for (int n4 =1; n4 < (1 << 4); n4 <<= 1)
                         if ((n1 | n2 | n3 | n4) == (1 << 4) - 1) 
                             for (int i = 0; i < 3; i++) {
                                 for (int j = 0; j < 3; j++) {
                                     for (int k = 0; k < 3; k++) {
                                         if (C(n[n1], n[n2], n[n3], n[n4], i, j, k)) {
                                             f = false;
                                             goto bbb;
                                         }
                                     }
                                 }
                             }
    bbb:;
         if (f) cout << "0" << endl;
    }
    
    return 0;
}

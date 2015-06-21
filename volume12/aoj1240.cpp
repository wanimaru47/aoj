#include<iostream>
#include <string>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n--) {
        string st, tr;
        cin >> st >> tr;
        for (int i = st.size() - 1; i >= 0; i--) {
            char t;
            switch (st[i])
            {
            case 'J':
            {
                tr = tr[tr.size() - 1] + tr.substr(0, tr.size() - 1);
                break;
            }
            case 'C':
            {
                tr = tr.substr(1, tr.size() - 1) + tr[0];
                break;
            }
            //case 'C':
                /*
            {
                tr = tr[tr.size() - 1] + tr.substr(0, tr.size() - 1);
                break;
            }
                */
            case 'E':
            {
                if (tr.size() % 2) {
                    tr = tr.substr(tr.size() - tr.size() / 2, tr.size() / 2) + tr[tr.size() / 2] + tr.substr(0, tr.size() / 2);
                } else {
                    tr = tr.substr(tr.size() - tr.size() / 2, tr.size() / 2) + tr.substr(0, tr.size() / 2);
                }
                break;
            }
            case 'A':                              
            {
                string tmp = tr;
                for (int j = 0; j < tr.size(); j++) {
                    tr[j] = tmp[tr.size() - 1 - j];
                }
                break;
            }
            case 'M':
            {
                for (int j = 0; j < tr.size(); j++) {
                    if ('0' <= tr[j] && tr[j] <= '8') {
                        tr[j]++;
                    } else if (tr[j] == '9') {
                        tr[j] = '0';
                    }
                }
                break;
            }
            case 'P':
            {
                for (int j = 0; j < tr.size(); j++) {
                    if ('1' <= tr[j] && tr[j] <= '9') {
                        tr[j]--;
                    } else if (tr[j] == '0') {
                        tr[j] = '9';
                    }
                }
                break;
            }
            default: break;
            }
        }
        cout << tr << endl;
    }
    
    return 0;
}

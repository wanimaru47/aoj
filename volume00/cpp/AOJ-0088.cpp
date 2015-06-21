#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<char, string> preS;
int main ()
{
    preS[' '] = "101";
    preS['\''] = "000000";
    preS[','] = "000011";
    preS['-'] = "10010001";
    preS['.'] = "010001";
    preS['?'] = "000001";
    preS['A'] = "100101";
    preS['B'] = "10011010";
    preS['C'] = "0101";
    preS['D'] = "0001";
    preS['E'] = "110";
    preS['F'] = "01001";
    preS['G'] = "10011011";
    preS['H'] = "010000";
    preS['I'] = "0111";
    preS['J'] = "10011000";
    preS['K'] = "0110";
    preS['L'] = "00100";
    preS['M'] = "10011001";
    preS['N'] = "10011110";
    preS['O'] = "00101";
    preS['P'] = "111";
    preS['Q'] = "10011111";
    preS['R'] = "1000";
    preS['S'] = "00110";
    preS['T'] = "00111";
    preS['U'] = "10011100";
    preS['V'] = "10011101";
    preS['W'] = "000010";
    preS['X'] = "10010010";
    preS['Y'] = "10010011";
    preS['Z'] = "10010000";
    
    char aft[] = {' ', '.', ',', '-', '\'', '?'};

    string str;
    while (getline(cin, str)) {
        string p;
        for (int i = 0; i < str.size(); i++) {
            p += preS[str[i]];
        }
        while (p.size() % 5 != 0) {
            p += '0';
        }
        int s = 0;
        int t = 16;
        for (int i = 0; i < p.size(); i++) {
            if (i % 5 == 0) {t = 16; s = 0;}
            s += p[i] == '1' ? t : 0;
            t /= 2;
            if (i % 5 == 4) {
                if (0 <= s && s < 26) {
                    cout << (char)('A' + s);
                } else {
                    s -= 26;
                    cout << aft[s];
                }
            }
        }
        cout << endl;
    }

    return 0;
}

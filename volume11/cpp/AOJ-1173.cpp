//
//  main.cpp
//  AOJ-1173
//
//  Created by Wanikawa on 2013/05/31.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    string str;
    int cursor = 0,longs;
    bool ans = true;
    
    while (1) {
        cursor = 0;
        ans = true;
        getline(cin,str);
        longs = str.length();
        if (longs == 1) {
            if (str[0] == '.') {
                break;
            }
        }
        char word[longs];
        for (int i = 0; i < longs; i++) {
            if (str[i] == '(' || str[i] == '[') {
                if (str[i] == '(') {
                    word[cursor] = '(';
                }else{
                    word[cursor] = '[';
                }
                cursor++;
            }
            if (str[i] == ')' || str[i] == ']') {
                cursor--;
                if (str[i] == ')') {
                    if (word[cursor] != '(') {
                        ans = false;
                        break;
                    }
                }else{
                    if (word[cursor] != '[') {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (ans == true && cursor == 0) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}

//
//  main.cpp
//  AOJ-0257
//
//  Created by Wanikawa on 2013/08/29.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int code,code1,code2,code3;
    cin >> code1 >> code2 >> code3;
    //cout << code << endl;
    code = code1 * 100 + code2 * 10 + code3;
    if (code == 110 || code == 001) cout << "Open" << endl;
    else cout << "Close" << endl;
    
    return 0;
}


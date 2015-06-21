//
//  main.cpp
//  AOJ-0256
//
//  Created by Wanikawa on 2013/08/29.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int num,sum=0;
    for (int i = 0; i < 10; i++) {
        cin >> num ;
        sum += num;
    }
    
    cout << sum << endl;
    return 0;
}


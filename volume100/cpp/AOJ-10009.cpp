//
//  main.cpp
//  AOJ-10009
//
//  Created by Wanikawa on 2013/05/30.
//  Copyright (c) 2013年 Wanikawa. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double l,r,pai,s;
    pai = 3.141592653589;
    cin >> r;
    l = 2*r*pai;
    s = pai*r*r;
    printf("%lf %lf\n",s,l);
    
    return 0;
}

